#pragma once

namespace hh::ui {
    class UIElementGroup : public UIElement, public game::InputListener, public UIElement::UIElementListener {
        void SortElements();
    public:
        uint32_t unk101;
        csl::ut::MoveArray<fnd::Reference<UIElement>> elements;
        csl::ut::MoveArray<void*> unk103;
        csl::ut::MoveArray<void*> unk104;
        uint32_t sortOrderMaybe;
        uint32_t unk106;
        int focusedElementIndex;
        bool initialized;
        bool isCurrentGroup;

        UIElementGroup(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition, uint32_t unkParam1);
        UIElement* FindElement(const char* name);

        void AddElement(UIElement* element);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update(const fnd::SUpdateInfo& updateInfo) override;
        virtual void UpdateAsync(const fnd::SUpdateInfo& updateInfo) override;
        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual bool ProcessMessage(fnd::Message& message) override;
        virtual bool UnkFunc14() override;
        virtual void DoSomethingWithUnk7(const Unk1& unkParam) override;
        virtual void ActionInputReceived(const ActionInputInfo& actionInputInfo) override;
        virtual void AxisInputReceived(const AxisInputInfo& axisInputInfo) override;
        virtual void UIEL_UnkFunc1() override;
    };
}
