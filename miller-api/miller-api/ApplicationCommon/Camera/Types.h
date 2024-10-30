#pragma once

namespace app_cmn::camera {
    struct FrustumParameter {
        float nearClip;
        float farClip;
        float fov;
        FrustumParameter();
    };

    struct CameraParameter {
        struct Target {
            csl::math::Vector3 position;
            csl::math::Vector3 offset;
            csl::math::Vector4 unk3;
        };
        struct Offset {
            float angleX;
            float angleY;
            float distance;
        };
        struct Orientation {
            csl::math::Vector4 unk7;
            uint8_t unk8;
            csl::math::Vector4 unk9;
            uint32_t unk8b;  
        };
        Target target;
        Offset offset;
        Orientation orientation;
        FrustumParameter frustum;
        CameraParameter();
    };

    struct CameraPose {
        csl::math::Vector3 lookAtPos;
        csl::math::Vector3 position;
        csl::math::Vector4 unk3;
        CameraPose();
    };

}
