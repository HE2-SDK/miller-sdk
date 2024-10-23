#pragma once

namespace hh::ut {
    class StateDesc;

    namespace internal {
        class StateDescImpl {
        public:
            typedef StateDesc* (*Instantiator)(csl::fnd::IAllocator* pAllocator);

            const char* name;
            Instantiator instantiator;
            int32_t unk;

            StateDescImpl(const char* name, Instantiator instantiator, int32_t unk);
        };
    };

    class StateDesc : public internal::StateDescImpl {
    public:
        StateDesc(const char* name, Instantiator instantiator, int32_t unk)
            : StateDescImpl { name, instantiator, unk } {}

        virtual ~StateDesc() {}
    };
}
