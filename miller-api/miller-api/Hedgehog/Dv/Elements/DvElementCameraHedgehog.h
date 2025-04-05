#pragma once

namespace hh::dv{
    class DvElementCameraHedgehog : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            struct Camera {
            public:
                float unk0[3];
                csl::math::Position position;
                csl::math::Position targetPosition;
                csl::math::Position rotation;
                float unk1[7];
                float nearClip;
                float farClip;
                float fov;
            };

            int flags;
            Camera camBefore;
            Camera camAfter;
            float unk0[3];
            float curveData[32];
        };

        struct UnkStruct {
        public:
            csl::math::Vector4 qword_00;
            csl::math::Vector4 qword_10;
            uint64_t qword_20;
            uint64_t qword_28;
            csl::math::Vector4 qword_30;
            uint32_t dword_40;
            uint32_t dword_44;
            uint32_t dword_48;
            uint32_t dword_4C;
            uint32_t dword_50;
            uint32_t dword_54;
            uint32_t dword_58;
            uint32_t dword_5C;
            uint32_t dword_60;           
            uint32_t dword_64;           
            uint32_t dword_80;
            uint32_t dword_84;
            uint32_t dword_88;
        };

        Description binaryData;
        void* unk0;
        int unk1;
        UnkStruct unk2;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraHedgehog)
    };
}
