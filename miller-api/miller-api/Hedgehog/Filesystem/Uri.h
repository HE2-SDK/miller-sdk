#pragma once

namespace hh::fnd {
    class Uri {
        csl::ut::String buffer;
    public:
        Uri(csl::fnd::IAllocator* allocator);
        Uri(char* buffer, size_t bufSize, const char* str, size_t strlen, csl::fnd::IAllocator* allocator);
        virtual ~Uri();
    };
}
