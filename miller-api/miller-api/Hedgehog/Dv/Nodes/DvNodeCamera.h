#pragma once

namespace hh::dv{
    class DvNodeCamera : public DvNodeBase {
    public:
        struct Data {
            int flags;
            int frameProgressionCount;
            int captionCount;
            int field0c;
        };

        struct CameraData {
            csl::math::Vector3 position;
            csl::math::Vector3 target;
            float unk0;
            float unk1;
            float unk2;
            float unk3;
            hh::gfnd::ViewportData::FovProjectionParameters fovProjectionParams;
        };

        Data binaryData;
        hh::game::CameraComponent* camComponent;
        int unk3;
        int unk4;
        CameraData data;
        csl::math::Vector4 unk5;
        csl::math::Vector4 unk6;
        float nearClip;
        float farClip;
        int64_t unk7;
        csl::math::Vector3 unk8;
        int unk9;
        int unk10;
        int64_t unk11;
        csl::math::Vector4 unk12;
        char unk13;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;
        virtual void Update(int curFrame) override;
        virtual void Update1() override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCamera)
    };
}