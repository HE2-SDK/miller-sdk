#pragma once

namespace hh::path {
    class PathEvaluator {
    public:
        hh::fnd::Handle<PathComponent> pathObject{};
        float distance{};
        int key{};

        inline PathEvaluator() {}
        PathEvaluator(PathComponent* pathObject);

        void Reset();
        hh::path::PathComponent* GetPathObject() const;
        void SetPathObject(const hh::fnd::Handle<PathComponent>& pathObject);
        void SetPathObject(PathComponent* pathObject);
        float GetLength() const;
        csl::math::Vector3 GetWorldPosition(float distance) const;
        csl::math::Vector3 GetNormal(float distance) const;
        csl::math::Vector3 GetTangent(float distance) const;
        void GetPNT(float distance, csl::math::Vector3* position, csl::math::Vector3* normal, csl::math::Vector3* tangent);
        void GetPNT2(float distance, csl::math::Vector3* position, csl::math::Vector3* normal, csl::math::Vector3* tangent);
        float GetClosestPositionAlongSpline(const csl::math::Vector3& position, float start, float end, float* unkParam1, float* unkParam2);
        void SetDistance(float distance);
    };
}
