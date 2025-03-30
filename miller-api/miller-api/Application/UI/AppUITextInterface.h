#pragma once

namespace app::ui {
    class AppUITextInterface : public hh::ui::UITextInterface {
        text::TextManager* textManager;

    public:
        AppUITextInterface(csl::fnd::IAllocator* pAllocator, app::text::TextManager* textManager);

        virtual void* UnkFunc1(void* unkParam1, void* unkParam2) override;
        virtual hh::text::UnicodeString GetTranslation(const char* tag, uint32_t localeIdx) override;
        virtual void* UnkFunc3(void* unkParam1) override;
        virtual void* UnkFunc4(void* unkParam1, uint32_t unkParam3) override;
        virtual void* UnkFunc5(void* unkParam1, void* unkParam3) override;
        virtual text::AppTextListener* CreateTextListener() override;
    };
}
