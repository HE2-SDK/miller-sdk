#pragma once

namespace SurfRide {
    struct SrTexCoord {
        float u;
        float v;

        SrTexCoord();
    };

    enum class EPivotType {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        CENTER_LEFT,
        CENTER_CENTER,
        CENTER_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT,
        CUSTOM,
    };

    enum class EOrientation {
        UP,
        LEFT,
        DOWN,
        RIGHT,
    };
}
