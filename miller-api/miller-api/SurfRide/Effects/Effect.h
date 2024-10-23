#pragma once

namespace SurfRide {
    enum SRE_EFFECT_TYPE : uint32_t {
        NONE = 0,
        BLUR = 1,
        REFLECT = 2,
    };

    enum SRE_BLEND_MODE : uint32_t {
        DEFAULT,
        ADD,
        MODE2,
        MODE3,
    };

    struct SRS_EFFECT {};
}
