#pragma once

namespace app::camera {
    class CameraBridge : public app_cmn::camera::CameraFrame::Listener {
    public:
        hh::game::CameraComponent* cameraComponent;

        CameraBridge();
        virtual void CFL_UnkFunc1(const app_cmn::camera::FrustumParameter& frustumParameter) override;
        virtual void CFL_UnkFunc2(const csl::math::Matrix34& viewMatrix, const app_cmn::camera::FrustumParameter& frustumParameter) override;

        void SetCameraComponent(hh::game::CameraComponent* component);
    };
}
