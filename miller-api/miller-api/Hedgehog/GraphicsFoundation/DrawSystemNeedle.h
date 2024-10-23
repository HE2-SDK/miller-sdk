#pragma once

namespace hh::gfnd {
    class DrawSystemNeedle : public DrawSystem {
        static needle::PrimitiveRenderer* primitiveRenderer;
    public:
        static void Initialize(needle::PrimitiveRenderer* primitiveRenderer);
    };
}
