#pragma once

namespace app::dv{
    class DvElementPbaReset : public AppDvElementBase{
    public:
        struct Data { };

        hh::dv::DvNodeBaseAnimationModel* dvMdl;

        virtual bool AddCallback(int currentFrame, csl::math::Transform* transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementPbaReset)
    };
}
