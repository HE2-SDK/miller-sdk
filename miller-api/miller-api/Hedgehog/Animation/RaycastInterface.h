#pragma once

namespace hh::anim {
    class RaycastInterface : public fnd::ReferencedObject {
    public:
        virtual bool RayCast(const csl::math::Vector3& from, const csl::math::Vector3& to, unsigned int unkParam1, float& distance, float& unkParam2) = 0;
    };
}
