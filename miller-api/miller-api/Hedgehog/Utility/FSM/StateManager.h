#pragma once

namespace hh::ut {
    namespace internal {
        class alignas(8) StateManagerImpl : public fnd::ReferencedObject {
            csl::ut::MoveArray<StateDescImpl*> stateDescs;
        public:
            StateManagerImpl(csl::fnd::IAllocator* pAllocator, size_t size);
            virtual ~StateManagerImpl();
        };
    }

    class StateManager : public internal::StateManagerImpl {
    public:
        StateManager(csl::fnd::IAllocator* pAllocator, size_t size);

        void AddStateDesc(int stateId, StateDesc* stateDesc);
    };
}
