#pragma once

namespace app::dv{
    class DvElementPbaReset : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description { };

        hh::dv::DvNodeBaseAnimationModel* dvMdl;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementPbaReset)
    };
}
