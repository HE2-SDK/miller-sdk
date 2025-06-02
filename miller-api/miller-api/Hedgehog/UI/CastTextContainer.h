#pragma once

namespace hh::ui {
    class UITextElement;
    class CastTextContainer : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        UITextElement* textElement; // set in constructor, don't know what it is yet
    public:
        CastTextContainer(csl::fnd::IAllocator* pAllocator, UITextElement* textElement);

        UITextElement* GetTextElement() const;
        UITextElement* GetNamedTextElement(const char* name) const;

        void SetTextElementTextData(const char* unk1, int unk2);
        void SetNamedTextElementTextData(const char* name, const char* unk1, int unk2);

        void SetTextElementLocalizationTag(const char* tag);
        void SetNamedTextElementLocalizationTag(const char* name, const char* tag);

        void SetTextElementLocalizationTagAndLocaleId(const char* tag, const char* localeId);
        void SetNamedTextElementLocalizationTagAndLocaleId(const char* name, const char* tag, const char* localeId);

        void SetTextElementLocalizationVariable(const char* varName, const char* value);
        void SetNamedTextElementLocalizationVariable(const char* name, const char* varName, const char* value);

        void ClearTextElement();
        void ClearNamedTextElement(const char* name);
    };
}
