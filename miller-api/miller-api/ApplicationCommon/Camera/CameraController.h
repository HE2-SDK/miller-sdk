#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraController : public hh::fnd::ReferencedObject {
    public:
        CameraParameter parameter;
        CameraFrame* cameraFrame;
        csl::ut::VariableString name;
        uint8_t unk2;

        CameraController(csl::fnd::IAllocator* allocator);

        void SetCameraFrame(CameraFrame* cameraFrame);
    };
}
