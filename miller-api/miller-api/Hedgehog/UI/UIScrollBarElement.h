#pragma once

namespace hh::ui {
    class UIScrollBarElement : public UIElement {
        csl::fnd::Delegate<void ()> delegate101;
        csl::fnd::Delegate<void ()> delegate102;
        csl::fnd::Delegate<void ()> delegate103;
        LayerController* layerController;
        void* maybeColliderPane;
        uint16_t unk103;
        bool hasPRMSizeAnimation;
        uint32_t fPRMSizeRelatedFloat;
        uint32_t unk106;
        uint32_t unk107;
        int unk108;
    public:
        UIScrollBarElement(csl::fnd::IAllocator* allocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);
    };
}
