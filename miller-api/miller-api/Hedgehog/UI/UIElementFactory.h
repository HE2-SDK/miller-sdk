#pragma once

namespace hh::ui {
    class UIElementFactory : public fnd::BaseObject, csl::fnd::Singleton<UIElementFactory> {
        static UIElementClass* staticUIElementClasses[5];
    public:
        UIElement* CreateElement(SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);
    };
}
