#pragma once

namespace hh::dv{
    class DvElementPathInterpolation : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            struct Interpolation {
            public:
                csl::math::Position position;
                csl::math::Position rotation;
                csl::math::Position scale;
            };

            bool useAbsolutePosition;
            Interpolation interpolation;
            Interpolation finishInterpolation;
            float unk0;
            float curveData[128];
        };

        Description binaryData;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementPathInterpolation)
    };
}
