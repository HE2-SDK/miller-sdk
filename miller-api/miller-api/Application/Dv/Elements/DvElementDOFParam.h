#pragma once

namespace app::dv{
    class DvElementDOFParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct DOFParam {
            public:
                float focus;
                float focusRange;
                float nearDist;
                float farDist;
            };

            enum class Flags : unsigned int {
                USE_FOCUS_LOOK_AT,
                ENABLE_CIRCLE_DOF,
                DRAW_FOCAL_PLANE,
                CURVE_ENABLED
            };

            csl::ut::Bitset<Flags> flags;
            DOFParam param;
            DOFParam finishParam;
            float cocMaxRadius;
            float focalTransition;
            int bokehSampleCount;
            int bokehQuality;
            float bokehIntensity;
            float rtScale;
            float unk5[5];
            float curveData[32];
        };

        int framesOnScreen;
        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDOFParam)
    };
}
