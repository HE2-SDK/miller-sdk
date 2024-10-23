#pragma once

#define NEEDLE_RESOURCE_PIXEL_SHADER 0x3052444853584950ui64 // '0RDHSXIP'

namespace hh::needle {
    class PixelShader : public NeedleRefcountResource {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_PIXEL_SHADER;
    };
}
