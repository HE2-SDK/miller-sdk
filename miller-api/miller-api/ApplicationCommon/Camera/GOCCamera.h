#pragma once

namespace app_cmn::camera {
    class GOCCamera : public hh::game::GOComponent {
    public:
        struct ControllerUnit {
            enum class Flag : uint8_t {
                PUSHED,
            };
            hh::fnd::Reference<CameraController> controller;
            hh::fnd::Handle<hh::fnd::Messenger> cameraFrame;
            unsigned int id;
            csl::ut::Bitset<Flag> flags;
        };
        csl::ut::MoveArray<ControllerUnit> controllerUnits;

        void AddController(CameraController* controller, unsigned int id);
        void DestroyController(unsigned int id, CameraInterpolator* interpolator);
        void DestroyControllerAll(CameraInterpolator* interpolator);
        bool PushController(hh::fnd::Handle<hh::fnd::Messenger>& cameraFrame, unsigned int controllerId, unsigned int unkParam1, CameraInterpolator* interpolator);
        bool PopController(unsigned int controllerId, CameraInterpolator* interpolator);

    private:
        void PopCameraController(ControllerUnit& controllerUnit, CameraInterpolator* interpolator);
        
        // bool PushCameraController(hh::fnd::Handle<hh::fnd::Messenger>& cameraFrame, ControllerUnit& unit, unsigned int unkParam1, CameraInterpolator* interpolator);

        GOCOMPONENT_CLASS_DECLARATION(GOCCamera)
    };
}
