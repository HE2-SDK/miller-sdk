#pragma once

namespace hh::text {
    class TagReplaceable : public fnd::ReferencedObject {
        csl::ut::VariableString unk1;
    public:
        TagReplaceable(csl::fnd::IAllocator* pAllocator);

        virtual void* UnkFunc1() = 0;
        virtual void* UnkFunc2() = 0;
        virtual uint32_t UnkFunc3(void* unkParam1, void* unkParam2) = 0;
        virtual void* UnkFunc4(void* unkParam1) = 0;
        virtual bool UnkFunc5(void* unkParam1, void* unkParam2) = 0;
        virtual void* UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3) = 0;
        virtual void* UnkFunc7(void* unkParam1, void* unkParam2) = 0;
    };
}
