#pragma once

#define NEEDLE_RESOURCE_CONSTANT_BUFFER 0x3046465542534E43ui64 // '0FFUBSNC'

namespace hh::needle {
    class ConstantBuffer : public NeedleRefcountResource {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_CONSTANT_BUFFER;
    };
}
