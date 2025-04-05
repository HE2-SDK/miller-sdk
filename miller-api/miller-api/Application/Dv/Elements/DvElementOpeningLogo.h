#pragma once

namespace app::dv{
    class DvElementOpeningLogo : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {};

        hh::fnd::Reference<hh::game::GameObject> handle;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOpeningLogo)
    };
}
