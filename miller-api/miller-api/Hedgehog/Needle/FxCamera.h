#pragma once

namespace hh::needle {
    class FxCamera {
    public:
        virtual csl::math::Vector3 GetEyePos() const = 0;
        virtual void GetEyePosF(float* eyePos) const = 0;
        virtual csl::math::Vector3 GetLookAtPos() const = 0;
        virtual void GetLookAtPosF(float* lookAtPos) const = 0;
        virtual csl::math::Matrix44 GetViewMatrix() const = 0;
        virtual void GetViewMatrixF(float* viewMatrix) const = 0;
        virtual csl::math::Matrix44 GetProjectionMatrix() const = 0;
        virtual void GetProjectionMatrixF(float* projectionMatrix) const = 0;
        virtual float GetFieldOfView() const;
        virtual void GetClipPlanes(float* near, float* far) const;
    };
}
