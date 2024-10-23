#pragma once

namespace hh::needle {
    class ModifiedCamera : public FxCamera {
    public:
        csl::math::Matrix44 modifiedProjMatrix;
        FxCamera* originalCamera;

        ModifiedCamera(FxCamera* originalCamera);

        virtual csl::math::Vector3 GetEyePos() const override;
        virtual void GetEyePosF(float* eyePos) const override;
        virtual csl::math::Vector3 GetLookAtPos() const override;
        virtual void GetLookAtPosF(float* lookAtPos) const override;
        virtual csl::math::Matrix44 GetViewMatrix() const override;
        virtual void GetViewMatrixF(float* viewMatrix) const override;
        virtual csl::math::Matrix44 GetProjectionMatrix() const override;
        virtual void GetProjectionMatrixF(float* projectionMatrix) const override;
        virtual void GetClipPlanes(float* near, float* far) const override;
    };
}
