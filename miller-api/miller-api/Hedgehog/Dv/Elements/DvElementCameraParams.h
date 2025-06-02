#pragma once

namespace hh::dv{
    class DvElementCameraParams : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class Flags : unsigned char {
                POSITION,
                TARGET_POSITION,
                FOV,
                ROTATION,
                FINISH_POSITION,
                FINISH_TARGET_POSITION,
                FINISH_FOV,
                FINISH_ROTATION
            };

            struct Camera {
            public:
                csl::math::Position position;
                csl::math::Position targetPosition;
                float fov;
                csl::math::Position direction;
            };

            csl::ut::Bitset<Flags> flags;
            Camera camera;
            Camera finishCamera;
            float unk1[5];
            float curveData[256];
        };

        Description binaryData;
        int unk0[10];

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraParams)
    };
}
