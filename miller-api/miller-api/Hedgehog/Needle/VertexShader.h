#pragma once

#define NEEDLE_RESOURCE_VERTEX_SHADER 0x3052444853585456ui64 // '0RDHSXTV'

namespace hh::needle {
    class VertexShader : public NeedleRefcountResource {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_VERTEX_SHADER;
    };
}
