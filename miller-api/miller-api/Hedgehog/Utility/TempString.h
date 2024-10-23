#pragma once

namespace hh::ut {
    template<typename T = char>
    class TempString : public csl::ut::BasicString<T> {
        csl::ut::InplaceMoveArray32<T, 127> buffer{ fnd::GetTempAllocator() };
    };
}
