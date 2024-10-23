#pragma once

namespace hh::ui {
    class alignas(8) UIElement : public UIElementBase {
    public:
        class UIElementListener {
        public:
            virtual ~UIElementListener();
            virtual void UIEL_UnkFunc1() {}
        };
    
        UIElement(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);
        UITextInterface* GetTextInterface();
    };
}
