#pragma once

#define NEEDLE_RESOURCE_RENDER_TARGET_V0 0x30545245444E4552ui64 // '0TREDNER'

namespace hh::needle {
    class RenderTarget : public SurfaceBase {
    public:
        static size_t constexpr InterfaceId = NEEDLE_RESOURCE_RENDER_TARGET_V0;
    };
}
