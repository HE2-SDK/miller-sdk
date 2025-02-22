#pragma once

namespace hh::dv{
    class DvElementCameraParams : public DvElementBase {
    public:
        struct Data {
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

        Data binaryData;
        int unk0[10];

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraParams)
    };
}