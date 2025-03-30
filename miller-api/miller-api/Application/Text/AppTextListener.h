#pragma once

namespace app::text {
    class AppTextListener : public hh::ui::TextListenerObject {
        void* unkFromUnk1Param;
        hh::text::ConverseTextListener* converseTextListener;
        hh::text::TagReplacer* tagReplacer;
        uint32_t unk1;
        uint32_t unk2;

        virtual bool TL_UnkFunc1(void* unkParam1, void* unkParam2) override;
    public:
        AppTextListener(csl::fnd::IAllocator* pAllocator, void* unkParam1);
    };
}