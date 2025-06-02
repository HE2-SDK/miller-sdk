#pragma once

namespace app::dv{
    class DvElementFxColUpdate : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {};

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFxColUpdate)
    };
}
