#pragma once

namespace hh::fnd {
    template<size_t size>
    class InplaceUri : public Uri {
        char buffer[size];
    public:
        InplaceUri(const char* str, size_t strlen, csl::fnd::IAllocator* allocator)
            : Uri{ buffer, size, str, strlen, allocator } {}
    };
}
