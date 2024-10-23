#pragma once

namespace csl::ut {
    // No, this alignas is not a bug, this is actually how the game works!
    template<typename T>
    struct alignas(4) Color {
        T a{};
        T b{};
        T g{};
        T r{};

        Color() {}
        Color(T r, T g, T b, T a) : r{ r }, g{ g }, b{ b }, a{ a } {}

        inline bool operator==(const Color<T>& other) const {
            return r == other.r && g == other.g && b == other.b && a == other.a;
        }

        inline bool operator!=(const Color<T>& other) const {
            return !operator==(other);
        }
    };

    using Color8 = Color<uint8_t>;
    using Colorf = Color<float>;

    // struct Color8 : Color<uint8_t>{ using Color<uint8_t>::Color; };
    // struct Colorf : Color<float>{ using Color<float>::Color; };
}
