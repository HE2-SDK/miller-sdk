#pragma once

namespace csl::ut {
    constexpr unsigned int HashString(const char* str) {
        unsigned int hash{ 0 };

        while ( *str )
            hash = *str++ + 31 * hash;

        return hash & 0x7FFFFFFF;
    }
}
