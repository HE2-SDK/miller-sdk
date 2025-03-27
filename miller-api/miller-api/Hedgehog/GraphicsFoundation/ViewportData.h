#pragma once

namespace hh::gfnd {
    struct ViewportDimensions {
        float x;
        float y;
        float resX;
        float resY;
        float renderResX;
        float renderResY;
    };

    struct alignas(16) ViewportData {
        enum class ProjectionType : uint32_t {
            PERSPECTIVE_FOV,
            PERSPECTIVE,
            ORTHOGONAL,
        };

        struct FovProjectionParameters {
            float fov;
            float aspectRatio;
            float nearClip;
            float farClip;
        };

        struct FrustumProjectionParameters {
            float top;
            float bottom;
            float left;
            float right;
            float nearClip;
            float farClip;
        };

        union ProjectionParameters {
            FovProjectionParameters fov;
            FrustumProjectionParameters frustum;
        };

        csl::math::Matrix34 viewMatrix;
        csl::math::Matrix34 inverseViewMatrix;
        ViewportDimensions viewportDimensions;
        csl::math::Matrix44 projMatrix;
        ProjectionType projectionType;
        csl::math::Vector3 lookAtPos;
        ProjectionParameters projectionParameters;

        ViewportData();
        ViewportData(const ViewportData& other);
        ViewportData& operator=(const ViewportData& other);
        void SetDimensions(const ViewportDimensions& other);
        void SetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
        void SetPerspectiveProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
        void SetOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
        void GetClipPlanes(float* nearClip, float* farClip);
        void GetPerspectiveProjectionParameters(float* fov, float* aspectRatio, float* nearClip, float* farClip);
        inline csl::math::Matrix34 GetInverseViewMatrix() {
            return inverseViewMatrix;
        }
        void Reset();
    };
}
