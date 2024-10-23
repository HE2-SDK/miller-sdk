#pragma once

namespace hh::fnd {
    template<size_t size = 128>
    class InplaceTempUri : public InplaceUri<size> {
    public:
        InplaceTempUri(const char* str, size_t strlen) : InplaceUri<size>{ str, strlen, MemoryRouter::GetTempAllocator() } {};

        template<size_t Len>
        InplaceTempUri(const char (&str)[Len]) : InplaceTempUri<size>{ str, Len } {};
    };
}
