#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraInterpolator : public hh::fnd::ReferencedObject {
    public:
        uint64_t unk1;
        CameraFrame* cameraFrame;
        DEFAULT_CREATE_FUNC(CameraInterpolator);
    };
}
