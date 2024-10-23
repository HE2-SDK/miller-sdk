#pragma once

namespace hh::ut {
    enum class TinyFsmSignal : char {
        LEAVE = -4,
        ENTER = -3,
        INIT = -2,
        SUPER = -1,
        UPDATE = 0,
        UPDATE_PHASE_0 = 4,
        UPDATE_PHASE_1 = 5,
        UPDATE_PHASE_2 = 6,
        MESSAGE = 7,
        USER = 100,
    };

    enum class TinyFsmStateType : char {
        INVALID = 0,   // Mostly used for initialization.
        DELEGATE = 1,  // Copied from LWAPI but not seen in Frontiers
        UNHANDLED = 2, // The event was not handled by last trigger. Doubles as top state.
        HANDLED = 3,   // The event was handled by the last trigger.
        DUMMY = 4,     // Dummy state that reports all standard events as handled.
    };

    struct TinyFsmEvent
    {
        TinyFsmSignal signal;
    };

    template<typename T, typename TEvent>
    class TinyFsmState
    {
    public:
        typedef TinyFsmState (T::*Delegate_t)(const TEvent& e);
        typedef TinyFsmState (*Callback_t)(T* obj, const TinyFsmState& currentState, const TEvent& e);

        union Data_t {
            Delegate_t delegateFunc;
            void* unk[2];
        };
        Data_t data;
        Callback_t callback;
        TinyFsmStateType type;

        TinyFsmState() = default;
        TinyFsmState(TinyFsmStateType type) : type{ type } {}
        TinyFsmState(TinyFsmStateType type, Callback_t callback) : type{ type }, callback{ callback } {}
        TinyFsmState(TinyFsmStateType type, Callback_t callback, Data_t data) : type{ type }, callback{ callback }, data{ data } {}

        void Clear()
        {
            data.unk = { 0, 0 };
        }

        TinyFsmState Trigger(T* obj, const TEvent& in_event)
        {
            return callback(obj, this, in_event);
        }

        TinyFsmState Super(T* obj)
        {
            return Trigger(obj, { TinyFsmSignal::SUPER });
        }

        TinyFsmState Init(T* obj)
        {
            return Trigger(obj, { TinyFsmSignal::INIT });
        }

        TinyFsmState Enter(T* obj)
        {
            return Trigger(obj, { TinyFsmSignal::ENTER });
        }

        TinyFsmState Leave(T* obj)
        {
            return Trigger(obj, { TinyFsmSignal::LEAVE });
        }

        bool IsInvalid()
        {
            return type == TinyFsmStateType::INVALID;
        }
        
        bool IsUnhandled()
        {
            return type == TinyFsmStateType::UNHANDLED;
        }

        bool IsHandled()
        {
            return type == TinyFsmStateType::HANDLED;
        }

        bool IsValid()
        {
            return !IsInvalid();
        }

        TinyFsmState& operator=(const TinyFsmState& other) {
            callback = other.callback;
            type = other.type;

            if (other.type == TinyFsmStateType::DELEGATE)
                data.delegateFunc = other.data.delegateFunc;
            else
            {
                data.unk[0] = 0;
                data.unk[1] = 0;
            }

            return *this;
        }

        bool operator==(const TinyFsmState& other) const
        {
            return IsValid() && other.IsValid() && type == other.type && data == other.data;
        }

        bool operator!=(const TinyFsmState& other) const
        {
            return !(this == other);
        }

        static TinyFsmState CreateInvalid() {
            return { TinyFsmStateType::INVALID };
        }

        static TinyFsmState CreateDelegate(Delegate_t delegateFunc) {
            return {
                TinyFsmStateType::DELEGATE,
                [](T* obj, const TinyFsmState& currentState, const TEvent& e) {
                    return (obj->*(currentState.data.delegateFunc))(e);
                },
                Data_t{ delegateFunc },
            };
        }

        static TinyFsmState CreateUnhandled() {
            return { TinyFsmStateType::UNHANDLED };
        }

        static TinyFsmState CreateHandled() {
            return { TinyFsmStateType::HANDLED };
        }

        static TinyFsmState CreateDummy() {
            return {
                TinyFsmStateType::DUMMY,
                [](T* obj, const TinyFsmState& currentState, const TEvent& e) {
                    if (e.signal == TinyFsmSignal::LEAVE || e.signal == TinyFsmSignal::ENTER || e.signal == TinyFsmSignal::UPDATE)
                        return CreateHandled();
                    else
                        return CreateUnhandled();
                }
            };
        }
    };

    template<typename T, typename TEvent = TinyFsmEvent>
	class TinyFsm
	{
	public:
        typedef TEvent Event_t;
        typedef TinyFsmState<T, TEvent> State_t;

	private:
		/*
		 * Source state of the current state.
		 */
		State_t m_Src;
		State_t m_Cur;
        bool hierarchical;

		void InitCurrentState(T* obj)
		{
			while (m_Cur.Init(obj).IsHandled())
			{
				m_Cur.Enter(obj);
			}
		}

		void InitFSM(T* obj)
		{
			if constexpr (hierarchical)
			{
				csl::ut::InplaceMoveArray<State_t, 5> stateStack{ hh::fnd::MemoryRouter::GetTempAllocator() };
				State_t state = m_Cur;

				while (state != State_t::CreateUnhandled())
				{
					stateStack.push_back(state);
					state = state.Super(obj);
				}

                // Enter states until we reach our target state.
                for(auto stateIt = stateStack.end(); stateIt != stateStack.begin(); ) {
                    stateIt--;
					stateIt->Enter(obj);
				}
			}
			else
			{
				m_Cur.Enter(obj);
			}

			InitCurrentState(obj);
		}

		void ShutdownFSM(T* obj)
		{
			if constexpr (hierarchical)
			{
				State_t state = m_Cur;
				while (state != State_t::CreateUnhandled())
				{
					state.Leave(obj);
					state = state.Super(obj);
				}

				m_Cur.Clear();
				m_Src.Clear();
			}
			else
			{
				Leave(m_Cur);
				m_Cur.Clear();
			}
		}

        void Transition(T* obj, const State_t& in_state) {
            if (m_Cur == in_state)
                return;

            if (m_Src.IsUnhandled()) {
                m_Src = m_Cur;
            }

            if (hierarchical) {
				for (State_t state = m_Cur; state != m_Src; state = state.Super(obj))
				{
					state.Leave(obj);
				}

				if (m_Src == in_state)
				{
					Leave(m_Src);
			        m_Cur = in_state;
					Enter(in_state);
				}
                else
                {
					csl::ut::InplaceMoveArray<State_t, 5> oldStates{ hh::fnd::MemoryRouter::GetTempAllocator() };
					csl::ut::InplaceMoveArray<State_t, 5> newStates{ hh::fnd::MemoryRouter::GetTempAllocator() };
					State_t oldState = m_Cur;
					State_t newState = in_state;

                    // Run up the hierarchy and collect all superstates of both the old and the new state.
					while (oldState != State_t::CreateUnhandled())
					{
						oldStates.push_back(oldState);
						oldState = oldState.Super(obj);
					}

					while (newState != State_t::CreateUnhandled())
					{
						newStates.push_back(newState);
						newState = newState.Super(obj);
					}

                    // Compare both lists starting from the topmost state and find the deepest superstate that's common to both states.
                    auto oldStateIt = oldStates.end();
                    auto newStateIt = newStates.end();

                    while (oldStateIt != oldStates.begin() && newStateIt != newStates.begin());
                    {
                        oldStateIt--;
                        newStateIt--;

                        if (*oldStateIt != *newStateIt)
                            break;
                    }
                    
                    // Leave states until we reach the nearest common state.
					for (auto i = oldStates.begin(); i <= oldStateIt; i++)
					{
						i->Leave(obj);
					}

                    // Enter states until we reach our target state.
					for(; newStateIt >= newStates.begin(); newStateIt--)
					{
                        m_Cur = *newStateIt;
						newStateIt->Enter(obj);
					}
                }
            }
			else
			{
				m_Cur.Leave(obj);
			    m_Cur = in_state;
				in_state.Enter(obj);
			}

			InitCurrentState(obj);
        }

    public:
		void Dispatch(T* obj, const TEvent& in_event)
		{
			if (hierarchical)
			{
				// Initialize the "source" state to the current state.
				m_Src = m_Cur;

				// Keep asking superstates to handle the event until we find one that
				// returns TFSM_STATE_TYPE_HANDLED, or until we reach the top state.
				while (!m_Src.IsUnhandled() && !m_Src.IsHandled())
				{
					State_t state = m_Src.Trigger(obj, in_event);

					if (state.IsHandled() || !state.IsValid()) break;

					m_Src = m_Src.Super(obj);
				}
			}
			else
			{
				m_Cur.Trigger(obj, in_event);
			}
		}
    };

}