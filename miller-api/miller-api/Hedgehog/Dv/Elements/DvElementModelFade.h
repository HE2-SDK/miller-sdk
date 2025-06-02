#pragma once

namespace hh::dv{
    class DvElementModelFade : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            int unk0[8];
            float curveData[128];
        };

        Description binaryData;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementModelFade)
    };
}
