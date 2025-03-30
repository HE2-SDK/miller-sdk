#pragma once

namespace app::ui {
    enum class OverlayType {
        WINDOW, // but also operation guide?
        COLLECTION_WINDOW,
        TUTORIAL_WINDOW,
        IMAGE_WINDOW,
        CAPTION,
        TALK,
        ITEM_POINT,
        GATE_ICON,
        INPUT_POINT,
        INPUT_POINT_STAGE,
        ROCKET_PARTS,
        TIME_RECOVERY,
        TARGET_NAVI,
        DPOWER_NAME,
    };

    class RequestOverlayBegin : public hh::fnd::ReferencedObject {
    public:
        OverlayType type;
        bool block;

        inline RequestOverlayBegin(csl::fnd::IAllocator* allocator, OverlayType type)
            : ReferencedObject{ allocator, true }, type{ type }, block{ false }
        {}
    };
}
