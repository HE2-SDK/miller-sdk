#pragma once

namespace hh::ut {
    class StateImpl;

    namespace internal {
        class StateDescImpl {
        public:
            typedef StateImpl* (*Instantiator)(csl::fnd::IAllocator* pAllocator);

            const char* name;
            Instantiator instantiator;
            int superState;

            StateDescImpl(const char* name, Instantiator instantiator, int superState);
        };
    };

    class StateDesc : public internal::StateDescImpl {
    public:
        StateDesc(const char* name, Instantiator instantiator, int superState)
            : StateDescImpl { name, instantiator, superState } {}

        virtual ~StateDesc() {}
    };
}
