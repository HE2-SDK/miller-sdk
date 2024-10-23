#pragma once

#define NEEDLE_RESOURCE_DEPTH_STENCIL 0x304F544854504544ui64 // '0OTHTPED'

namespace hh::needle {
    class DepthStencil : public SurfaceBase {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_DEPTH_STENCIL;
    };
}
