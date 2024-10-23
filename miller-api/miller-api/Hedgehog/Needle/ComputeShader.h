#pragma once

#define NEEDLE_RESOURCE_COMPUTE_SHADER 0x30524448534D4F43ui64 // '0RDHSMOC'

namespace hh::needle {
    class ComputeShader : public NeedleRefcountResource {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_COMPUTE_SHADER;
    };
}
