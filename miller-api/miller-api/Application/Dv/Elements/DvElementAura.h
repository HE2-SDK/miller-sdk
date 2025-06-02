#pragma once

namespace app::dv{
    class DvElementAura : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct AuraNode {
            public:
                unsigned int color[4];
                float distance;
                float noiseTextureScrollSpeed;
                float blurScale;
                float colorGain;
                float noiseGain;
            };

            enum class Flags : unsigned int {
                CURVE_ENABLED,
                ENABLED
            };

            AuraNode node;
            AuraNode finishNode;
            csl::ut::Bitset<Flags> flags;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAura)
    };
}
