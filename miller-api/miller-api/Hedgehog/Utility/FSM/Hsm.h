#pragma once

namespace hh::ut {
    namespace internal {
        class alignas(8) HsmImpl : private csl::ut::NonCopyable {
            int32_t unk1;
            int32_t unk2;
            int32_t unk3;
            int32_t unk3b;
            StateDescImpl** stateDescImpls;
            csl::ut::InplaceMoveArray<void*, 5> unk6;
            uint32_t unk7;
        public:
            HsmImpl(csl::fnd::IAllocator* pAllocator);
            virtual ~HsmImpl();
        };
    }

    class HsmBase : public internal::HsmImpl {
    public:
        HsmBase(csl::fnd::IAllocator* pAllocator);

        void AddStateDesc(int stateId, StateDesc* stateDesc);
    };
}
