#pragma once

namespace app::dv{
    class DvElementDOFParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct DOFParam {
            public:
                float foregroundBokehMaxDepth;
                float foregroundBokehStartDepth;
                float backgroundBokehStartDepth;
                float backgroundBokehMaxDepth;
            };

            enum class Flags : unsigned int {
                USE_FOCUS_LOOK_AT,
                ENABLE_CIRCLE_DOF,
                DRAW_FOCAL_PLANE,
                CURVE_ENABLED
            };

            enum class RenderTargetSize : unsigned int {
                RTSIZE_FULL_SCALE = 0,
                RTSIZE_HALF_SCALE = 1,
                RTSIZE_QUARTER_SCALE = 2,
                RTSIZE_COUNT = 3,
                RTSIZE_INVALID = 3,
            };

            csl::ut::Bitset<Flags> flags;
            DOFParam param;
            DOFParam finishParam;
            float cocMaxRadius;
            float bokehRadiusScale;
            int bokehSampleCount;
            float skyFocusDistance;
            float bokehBias;
            RenderTargetSize rtScale;
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
