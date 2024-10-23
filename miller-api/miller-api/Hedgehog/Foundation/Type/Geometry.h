#pragma once

namespace hh::fnd {
    struct Geometry {
        csl::ut::MoveArray<csl::math::Vector3> vertices;
        csl::ut::MoveArray<fnd::Triangle> triangles;
        Geometry(csl::fnd::IAllocator* allocator) : vertices{ allocator }, triangles{ allocator } {}
        void CreateIcoSphere(const csl::math::Vector3& position, float radius, unsigned int subdivisions);
        void CreateBox(const csl::math::Vector3& position, const csl::math::Vector3& scale, const csl::math::Quaternion& rotation);
    };
}
