#pragma once

namespace app::dv{
    class DvElementLetterBox : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementLetterBox)
    };
}
