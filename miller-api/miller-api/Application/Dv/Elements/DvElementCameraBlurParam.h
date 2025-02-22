#pragma once

namespace app::dv{
    class DvElementCameraBlurParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct BlurParameter {
            public:
                float blurPower;
                float focusRange;
                float alphaSlope;
            };

            enum class BlurType : unsigned int {
                BLURTYPE_CAMERA,
                BLURTYPE_PREV_SURFACE,
                BLURTYPE_RADIAL
            };

            enum class Flags : unsigned int {
                ENABLED,
                SINGLE_DIRECTION_OPT,
                CURVE_ENABLED
            };
        
            csl::ut::Bitset<Flags> flags;
            int sampleAmount;
            BlurParameter params;
            BlurParameter finishParams;
            float curveData[32];
            BlurType blurType;
        };

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCameraBlurParam)
    };
}