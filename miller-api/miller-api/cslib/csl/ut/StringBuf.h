#pragma once

namespace csl::ut {
    template<size_t Size, typename T = char>
    class StringBuf {
        csl::ut::InplaceMoveArray<T, Size> buffer;
    public:
        StringBuf(csl::fnd::IAllocator* pAllocator) : buffer{ pAllocator } {}
    };
}
