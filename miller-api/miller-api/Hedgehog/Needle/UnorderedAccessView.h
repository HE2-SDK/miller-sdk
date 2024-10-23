#pragma once

#define NEEDLE_RESOURCE_UNORDERED_ACCESS_VIEW 0x3030303030564155ui64 // '00000VAU'

namespace hh::needle {
    class UnorderedAccessView : public SurfaceBase {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_UNORDERED_ACCESS_VIEW;
    };
}
