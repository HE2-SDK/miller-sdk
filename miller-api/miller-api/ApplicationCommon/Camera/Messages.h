#pragma once

namespace app_cmn::camera {
    class MsgPushCameraController : public hh::fnd::Message {
    public:
        hh::fnd::Reference<CameraController> controller;
        unsigned int unk1;
        CameraInterpolator* interpolator;

        MsgPushCameraController();
    };

    class MsgPopCameraController : public hh::fnd::Message {
    public:
        hh::fnd::Reference<CameraController> controller;
        CameraInterpolator* interpolator;

        MsgPopCameraController();
    };
}
