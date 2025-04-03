#pragma once

namespace app::dv{
    class DvElementBloomParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct Parameters {
            public:
                float bloom;
                float sampleRadius;
                float blurQuality;
            };

            bool curveEnabled;
            Parameters params;
            Parameters finishParams;
            float unk5[4];
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;
        virtual void AppUnkFunc4(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBloomParam)
    };
}
