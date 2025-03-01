#pragma once

namespace hh::ut {
    namespace internal {
        class HsmImpl : private csl::ut::NonCopyable {
        public:
            int bottomState;
            int currentDepth;
            StateManager* stateManager;
            void* context;
            csl::ut::InplaceMoveArray<fnd::Reference<StateImpl>, 5> stateStack;
            uint32_t unk7;

            HsmImpl(csl::fnd::IAllocator* pAllocator);
            virtual ~HsmImpl();
        };
    }

    class HsmBase : public internal::HsmImpl {
    public:
        HsmBase(csl::fnd::IAllocator* pAllocator);
        void Setup(StateManager* stateManager, void* context, int initialState);
        int GetSuperState(int stateId) const;
        void EnterState(int stateId, int previousStateId);
        void InitState(int previousStateId);
        void LeaveState(int nextStateId);
        void SetState(int stateId);
        void ChangeState(int stateId);
        void ChangeState(int stateId, int depth);
        void ChangeToTopState();
        int GetBottomStateId() const;
        internal::StateImpl* GetCurrentState(int depth) const;
        void Step(float deltaTime);
        void Update(fnd::UpdatingPhase phase, float deltaTime);
        void UpdateAsync(fnd::UpdatingPhase phase, float deltaTime);
        void ProcessMessage(const hh::fnd::Message& message);
    };
}
