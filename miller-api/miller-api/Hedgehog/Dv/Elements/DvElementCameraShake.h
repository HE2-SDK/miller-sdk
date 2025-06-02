#pragma once

namespace hh::dv{
    class DvElementCameraShake : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            int unk0; //unused
            bool enabled;
            float intensity;
            float frequency;
            int unk2[4]; //unused
        };

        Description binaryData;
        csl::math::Vector4 unk0;
        int unk1;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraShake)
    };
}
