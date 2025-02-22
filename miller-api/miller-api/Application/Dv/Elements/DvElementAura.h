#pragma once

namespace app::dv{
    class DvElementAura : public AppDvElementBase{
    public:
        struct Data {
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

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAura)
    };
}