#pragma once

namespace app_cmn::fsm {
    enum class TinyFsmSignal : char {
        TiFSM_SIGNAL_LEAVE = -4,
        TiFSM_SIGNAL_ENTER = -3,
        TiFSM_SIGNAL_INIT = -2,
        TiFSM_SIGNAL_SUPER = -1,
        TiFSM_SIGNAL_UPDATE = 0,
        TiFSM_SIGNAL_UPDATE_PHASE_0 = 4,
        TiFSM_SIGNAL_UPDATE_PHASE_1 = 5,
        TiFSM_SIGNAL_UPDATE_PHASE_2 = 6,
        TiFSM_SIGNAL_MESSAGE = 7,
        TiFSM_SIGNAL_USER = 100,
    };

    enum class TinyFsmStateType : char {
        TFSM_STATE_TYPE_NULL = 0,      // Mostly used for initialization.
        TFSM_STATE_TYPE_DELEGATE = 1,  // Copied from LWAPI but not seen in Frontiers
        TFSM_STATE_TYPE_UNHANDLED = 2, // The event was not handled by last trigger. Doubles as top state.
        TFSM_STATE_TYPE_HANDLED = 3,   // The event was handled by the last trigger.
        TFSM_STATE_TYPE_DUMMY = 4,     // Dummy state that reports all standard events as handled.
    };

    class TinyFsmEvent {
        TinyFsmSignal signal;
    };

    template<typename T>
    class TinyFsmState {
        typedef TinyFsmState<T>* (T::*MemberPtr)(TinyFsmState &result, TinyFsmEvent *inputEvent);
    };

    template<typename T, typename TEvent = TiFsmBasicEvent<T>>
	class TTinyFsm
	{
	public:
		typedef TEvent Event_t;
		typedef TTinyFsmState<T, TEvent> State_t;

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
			if constexpr (Hierarchical)
			{
				csl::ut::InplaceMoveArray<State_t, 5> stateStack{ fnd::GetTempAllocator() };
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
			if constexpr (Hierarchical)
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
					csl::ut::InplaceMoveArray<State_t, 5> oldStates{ fnd::GetTempAllocator() };
					csl::ut::InplaceMoveArray<State_t, 5> newStates{ fnd::GetTempAllocator() };
					State_t oldState = m_Cur;
					State_t newState = in_state;

                    // Run up the hierarchy and collect all superstates of both the old and the new state.
					while (oldState != FSM_TOP())
					{
						oldStates.push_back(oldState);
						oldState = oldState.Super(obj);
					}

					while (newState != FSM_TOP())
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

	template<typename T, typename TEvent>
	class TTinyFsmState
	{
	public:
        typedef TTinyFsmState (T::*Delegate_t)(const TEvent& e);
		typedef TTinyFsmState (*Callback_t)(T* obj, TTinyFsmState prevState, const TEvent& e);

        struct alignas(8) Unk1 {
            uint64_t fst;
            uint64_t snd;
        }

        union Data_t {
            Delegate_t delegateFunc;
            Unk1 unk;
        };
        Data_t data;
        Callback_t callback;
        TinyFsmStateType type;

		TTinyFsmState() = default;
        TTinyFsmState(TinyFsmStateType type) : type(type) {}
        TTinyFsmState(TinyFsmStateType type, Callback_t callback) : type(type), callback(callback) {}

		void Clear()
		{
			m_Delegate = nullptr;
		}

		State_t Trigger(T* obj, const TEvent& in_event)
		{
			return callback(obj, this, in_event);
		}

		State_t Super(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_SUPER });
		}

		State_t Init(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_INIT });
		}

		State_t Enter(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_ENTER });
		}

		State_t Leave(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_LEAVE });
		}

        bool IsNull()
        {
            return type == 0;
        }
        
        bool IsUnhandled()
        {
            return type == 2;
        }

        bool IsHandled()
        {
            return type == 3;
        }

        bool IsValid()
        {
            return !IsNull();
        }

        TTinyFsmState& operator=(const TTinyFsmState& other) {
            callback = other.callback;
            type = other.type;

            if (other.signal == 1)
                data.delegateFunc = other.data.delegateFunc;
            else
            {
                data.unk.fst = 0;
                data.unk.snd = 0;
            }
        }

		bool operator==(const TTinyFsmState& other) const
		{
            return IsNotType0() && other.IsNotType0() && type == other.type && unk.fst == other.unk.fst;
		}

		bool operator!=(const TTinyFsmState& other) const
		{
			return !(this == other);
		}

        static TTinyFsmState CreateNull() {
            return { TFSM_STATE_TYPE_NULL };
        }

		static TTinyFsmState CreateUnhandled() {
			return { TFSM_STATE_TYPE_UNHANDLED }
		}

        static TTinyFsmState CreateHandled() {
            return { TFSM_STATE_TYPE_HANDLED };
        }

        static TTinyFsmState CreateDummy() {
            return {
                4,
                [](T* obj, TTinyFsmState prevState, const TEvent& e) {
                    if (e.signal == TiFSM_SIGNAL_LEAVE || e.signal == TiFSM_SIGNAL_ENTER || e.signal == TiFSM_SIGNAL_UPDATE)
                        return CreateHandled();
                    else
                        return CreateUnhandled();
                }
            };
        }
	};
}