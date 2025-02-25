#pragma once

namespace app::dv{
    class DvElementFog : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct FogParameter {
            public:
                struct DistanceFogParameter {
                public:
                    float nearDist;
                    float farDist;
                    float influence;
                };

                struct HeightFogParameter {
                public:
                    float minHeight;
                    float maxHeight;
                    float nearDist;
                    float farDist;
                    float influence;
                };

                float color[3];
                float intensity;
                float skyBlend;
                float skyMips;
                DistanceFogParameter distanceFogParam;
                HeightFogParameter heightFogParam;
            };

            enum class Flags : unsigned int {
                DISTANCE_FOG_ENABLED,
                HEIGHT_FOG_ENABLED,
                CURVE_ENABLED
            };

            csl::ut::Bitset<Flags> flags;
            FogParameter params;
            FogParameter finishParams;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;
        virtual void AppUnkFunc4(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFog)
    };
}