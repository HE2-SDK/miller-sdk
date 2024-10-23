#pragma once

namespace hh::fnd {
    template<typename T>
    struct alignas(8) RflArray {
        const T* items{};
        const uint32_t count{};
    public:
        RflArray(const T* items, uint32_t count) : items{ items }, count{ count } {}
    };
}
