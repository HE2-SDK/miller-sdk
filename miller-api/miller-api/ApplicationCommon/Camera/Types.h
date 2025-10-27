#pragma once

namespace app_cmn::camera {
    struct FrustumParameter {
        float nearClip;
        float farClip;
        float fov;
        FrustumParameter();
    };

    struct CameraParameter {
        struct Positioning {
            csl::math::Vector3 position;
            csl::math::Vector3 offset;
            csl::math::Vector4 unk3;

            csl::math::Vector3& GetPosition() const;
            void SetPosition(csl::math::Vector3& position);
        };

        struct Orientation {
            struct Offset {
                float angleX;
                float angleY;
                float distance;
                csl::math::Vector3 targetPosition;
                bool usePosition;
            };
            struct Target {
                csl::math::Vector4 upVector;
                uint32_t unk8b;  

                void SetUnk8b(uint32_t unk8b);
                uint32_t GetUnk8b() const;
            };

            Offset offset;
            Target target;

            void SetTargetPosition(csl::math::Vector3& targetPosition);
        };

        Positioning positioning;
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
