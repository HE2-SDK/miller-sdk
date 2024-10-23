#pragma once

namespace hh::text {
    class ConverseTextListener : public fnd::ReferencedObject, public font::TextListener {
        void* unk1;
        void* unk2;

        virtual bool TL_UnkFunc1(void* unkParam1, void* unkParam2) override;
    public:
        ConverseTextListener(csl::fnd::IAllocator* pAllocator);
    };
}
