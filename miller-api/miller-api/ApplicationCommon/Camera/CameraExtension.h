#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraExtension : public hh::fnd::ReferencedObject {
    public:
        CameraFrame* cameraFrame;
    };
}
