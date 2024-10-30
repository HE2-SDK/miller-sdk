#pragma once

namespace app_cmn::fsm {
    template<typename T>
    class GOCTinyFsm2;

    template<>
    class GOCTinyFsm2<hh::game::GameObject> : public hh::game::GOComponent {
    public:
        struct Event : public hh::ut::TinyFsmEvent {
            union EventData {
                hh::fnd::Message* message;
                float deltaTime;
            };

            EventData data;
        };
        typedef hh::ut::TinyFsm<hh::game::GameObject, Event> Fsm_t;
        typedef typename Fsm_t::State_t State_t;
        typedef typename Fsm_t::Event_t Event_t;
        struct alignas(8) Config {
            State_t initialState;
            bool setFlag3;
            hh::game::GameObject* targetObject;
            uint32_t unk1;
            uint32_t unk2;
            bool setGOCFlag0;
            bool setGOCFlag1;
            bool setGOCFlag2;
            bool setFlag4;
        };

        static hh::game::GOComponentClass* GetClass();
        void Initialize(const Config& config);
        void Transition(const State_t& state);
    };

    template<typename T>
    class GOCTinyFsm2 : public hh::game::GOComponent {
    public:
        enum Flags : char {
            RECEIVE_MESSAGES, // INITIALIZED? -- set when receiving activate goc event
            UNK2, // set in constructor
            HIERARCHICAL,
            TRANSITION_PENDING,
            UNK5,
        };

        struct Event : public hh::ut::TinyFsmEvent {
            union EventData {
                hh::fnd::Message* message;
                float deltaTime;
            };

            EventData data;
        };

        typedef hh::ut::TinyFsm<T, Event> Fsm_t;
        typedef typename Fsm_t::State_t State_t;
        typedef typename Fsm_t::Event_t Event_t;

    private:
        T* targetObject;
        Fsm_t fsm;
        State_t* state;
        State_t* pendingTransitionState;
        csl::ut::Bitset<Flags> flags;
        uint32_t transitionPhase;
        csl::ut::InplaceMoveArray<void*, 1> unk11;
        csl::ut::MoveArray<void*> unk20;
        void* unk21;
        
    public:
        struct alignas(8) Config {
            State_t initialState;
            bool setFlag3;
            T* targetObject;
            uint32_t unk1;
            uint32_t unk2;
            bool setGOCFlag0;
            bool setGOCFlag1;
            bool setGOCFlag2;
            bool setFlag4;
        };

        static hh::game::GOComponentClass* GetClass() {
            return GOCTinyFsm2<hh::game::GameObject>::GetClass();
        }
        void Initialize(const Config& config) {
            reinterpret_cast<GOCTinyFsm2<hh::game::GameObject>*>(this)->Initialize(reinterpret_cast<const GOCTinyFsm2<hh::game::GameObject>::Config&>(config));
        }

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        inline void DispatchFSM(void* e);
        void Transition(const State_t& state) {
            reinterpret_cast<GOCTinyFsm2<hh::game::GameObject>*>(this)->Transition(reinterpret_cast<const GOCTinyFsm2<hh::game::GameObject>::State_t&>(state));
        }
    };
}
