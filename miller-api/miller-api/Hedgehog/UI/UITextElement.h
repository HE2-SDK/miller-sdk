#pragma once

namespace hh::ui {
    class UITextElement : public UIElement, public TextObjectUpdaterListener {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        TextObjectUpdater* textObjectUpdater;

    public:
        UITextElement(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* uiComposition);
        void SetLocalizationVariable(const char* name, const char* value);
        void SetLocalizationTag(const char* tag);
        void SetText(const char* text, unsigned int unkParam1);
        virtual void TOUL_UnkFunc1() override;
    };
}
