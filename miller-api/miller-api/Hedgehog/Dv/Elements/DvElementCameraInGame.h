#pragma once

namespace hh::dv{
    class DvElementCameraInGame : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            float unk0[26];
        };

        Description binaryData;
        void* unk0;
        void* unk1;
        void* unk2;
        void* unk3;
        void* unk4;
        void* unk5;
        void* unk6;
        void* unk7;
        int unk8;
        char unk9;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraInGame)
    };
}
