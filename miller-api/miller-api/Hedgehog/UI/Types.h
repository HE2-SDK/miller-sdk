#pragma once

namespace hh::ui {
    struct ScissorOffsets {
        uint32_t left;
        uint32_t top;
        uint32_t right;
        uint32_t bottom;
    };

    struct ViewportDimensions {
        float width;
        float height;
    };

    struct Dimensions {
        uint16_t width;
        uint16_t height;
    };

    struct Position {
        uint16_t x;
        uint16_t y;
    };

    struct Rectangle {
        Position position;
        Dimensions dimensions;
    };
}
