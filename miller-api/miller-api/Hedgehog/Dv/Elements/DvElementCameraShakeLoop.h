#pragma once

namespace hh::dv{
    class DvElementCameraShakeLoop : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            bool pattern;
        private:
            char padding[3];
        public:
            bool enabled;
            float frequency;
            float unk3; //unused
            float unk4;
            float unk5[3]; //unused
            float curveData[64];
        };

        Description binaryData;
        int64_t unk0;
        int64_t unk1;
        int64_t unk2;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraShakeLoop)
    };
}
