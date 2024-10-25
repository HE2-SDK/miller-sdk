#pragma once

namespace SurfRide {
    struct SRS_CROP {
        float left;
        float top;
        float right;
        float bottom;
    };

    struct SRS_CROPREF {
        short textureListIndex{};
        short textureIndex{};
        short cropIndex{};
    };

    enum class ECropSurface {
        SURFACE0,
        SURFACE1,
    };
}
