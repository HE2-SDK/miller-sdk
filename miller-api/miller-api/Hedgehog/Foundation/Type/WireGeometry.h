#pragma once

namespace hh::fnd {
    struct WireGeometry {
        // Incorrect
        csl::ut::MoveArray<csl::math::Vector3> vertices;
        csl::ut::MoveArray<fnd::Triangle> triangles;
    };
}
