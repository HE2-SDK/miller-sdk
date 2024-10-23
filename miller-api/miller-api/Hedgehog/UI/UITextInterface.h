#pragma once

namespace hh::ui {
    class UITextInterface : public fnd::ReferencedObject {
    public:
        virtual void* UnkFunc1(void* unkParam1, void* unkParam2) = 0;
        virtual hh::text::UnicodeString GetTranslation(const char* tag, uint32_t localeIdx) = 0;
        virtual void* UnkFunc3(void* unkParam1) = 0;
        virtual void* UnkFunc4(void* unkParam1, uint32_t unkParam3) = 0;
        virtual void* UnkFunc5(void* unkParam1, void* unkParam3) = 0;
        virtual TextListenerObject* CreateTextListener() = 0;
    };
}
