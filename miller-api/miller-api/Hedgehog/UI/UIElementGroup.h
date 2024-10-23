#pragma once

namespace hh::ui {
    class UIElementGroup : public UIElement, public game::InputListener, public UIElement::UIElementListener {
        uint32_t unk101;
        csl::ut::MoveArray<UIElement*> elements;
        csl::ut::MoveArray<void*> unk103;
        csl::ut::MoveArray<void*> unk104;
        uint32_t unk105;
        uint32_t unk106;
        uint32_t unk107;
        bool unk108;
        bool isCurrentGroup;
    public:
        UIElementGroup(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition, uint32_t unkParam1);
        UIElement* FindElement(const char* name);

        virtual void IL_UnkFunc1() override;
        virtual void IL_UnkFunc2() override;
        virtual void UIEL_UnkFunc1() override;
    };
}
