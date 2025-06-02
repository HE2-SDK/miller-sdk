#pragma once

namespace app::dv{
    class DvElementChromaticAberrationFilterParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
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

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementChromaticAberrationFilterParam)
    };
}
