#pragma once

namespace app::dv{
    class DvElementOcclusionCapsuleParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool enabled;
            unsigned int occlusionColor[4];
            float occlusionPower;
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOcclusionCapsuleParam)
    };
}
