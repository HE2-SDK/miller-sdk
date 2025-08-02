#pragma once

namespace csl::ut {
    constexpr unsigned int HashString(const char* str) {
        unsigned int hash{ 0 };

        while ( *str )
            hash = *str++ + 31 * hash;

        return hash & 0x7FFFFFFF;
    }

    class HashedString {
        unsigned int hash;

    public:
        inline constexpr HashedString() : hash{} {}
        inline constexpr HashedString(unsigned int hash) : hash{ hash } {}
        inline constexpr HashedString(const char* str) : hash{ HashString(str) } {}
        inline bool operator==(HashedString other) const { return hash == other.hash; }
        inline bool operator!=(HashedString other) const { return hash != other.hash; }
        inline bool operator==(unsigned int other) const { return hash == other; }
        inline bool operator!=(unsigned int other) const { return hash != other; }
    };
}
