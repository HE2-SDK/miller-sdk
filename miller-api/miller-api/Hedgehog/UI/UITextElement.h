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

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update(const fnd::SUpdateInfo& updateInfo) override;
        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual bool IsVisible() const override;
        virtual bool UnkFunc14() override;
        virtual void TOUL_UnkFunc2() override;

        void SetLocalizationVariable(const char* name, const char* value);
        void SetLocalizationTag(const char* tag);
        void SetText(const char* text, unsigned int unkParam1);
    };
}
