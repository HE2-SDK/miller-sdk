#pragma once

#define NEEDLE_RESOURCE_BUFFER_COMMON 0x304E4D4346465542ui64 // '0NMCFFUB'

namespace hh::needle {
    struct BufferCreationInfo {
    };

    class Buffer : public NeedleRefcountResource {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_BUFFER_COMMON;
    };
}
