#pragma once

namespace hh::fnd {
    struct WorldPosition {
        csl::math::Vector3 m_Position{};
        csl::math::Quaternion m_Rotation{ 0.0f, 0.0f, 0.0f, 1.0f };

        WorldPosition();
        void SetRotation(csl::math::Quaternion rotation);
        void SetFromTransformedWorldPosition(const csl::math::Transform& transform, const WorldPosition& worldPosition);
        csl::math::Matrix34 GetTransformationMatrix() const;
    };
}
