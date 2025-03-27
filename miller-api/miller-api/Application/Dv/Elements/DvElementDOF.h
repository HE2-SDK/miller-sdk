#pragma once

namespace app::dv{
    class DvElementDOF : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct DOFParam {
            public:
                float focalLengthInMilliMeters;
                float fNumber;
                float fixedFovY;
                float focusLength;
                float forceFocusRange;
                float foregroundBokehMaxDepth;
                float foregroundBokehStartDepth;
                float backgroundBokehStartDepth;
                float backgroundBokehMaxDepth;
                float cocMaxRadius;
                float foregroundBokehScale;
                float backgroundBokehScale;
            };

            enum class Flags : unsigned int {
                ENABLED,
                USE_FOCUS_LOOK_AT,
                DRAW_FOCAL_PLANE,
                LENS_MODE,
                CURVE_ENABLED
            };

            csl::ut::Bitset<Flags> flags;
            DOFParam params;
            DOFParam finishParams;
            float bladeCount;
            float bladeCurvature;
            float bladeRotation;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDOF)
    };
}
