#pragma once

namespace csl::ut {
    template<size_t Len>
    class InplaceBitArray : public BitArray {
    public:
        size_t reserved[Len];

        using BitArray::BitArray;
    };
}
