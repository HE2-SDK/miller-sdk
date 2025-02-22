#pragma once

namespace app::dv{
    class DvElementChromaticAberrationFilterParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct ChromaticAberrationParam {
            public:
                csl::math::Position colorOffset;
                float sphereCurve;
                csl::math::Vector2 scale;
                csl::math::Vector2 position;
            };

            ChromaticAberrationParam param;
            bool curveEnabled;
            ChromaticAberrationParam finishParam;
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementChromaticAberrationFilterParam)
    };
}