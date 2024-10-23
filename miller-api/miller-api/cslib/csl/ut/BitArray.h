#pragma once

namespace csl::ut {
    class BitArray : public MoveArray<size_t> {
    public:
        using MoveArray<size_t>::MoveArray;
        size_t bitCount;

        struct iterator {
            BitArray& arr;
            size_t index;

            size_t FindNextSetBit(size_t startIndex);
        };
    };
}
