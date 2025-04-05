#pragma once

namespace app::dv{
    class DvElementObjectTimeStop : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int type;
        };

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementObjectTimeStop)
    };
}
