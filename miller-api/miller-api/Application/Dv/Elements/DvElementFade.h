#pragma once

namespace app::dv{
    class DvElementFade : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool enabled;
            int r;
            int g;
            int b;
            float curveData[32];
        };

        hh::fnd::Reference<hh::game::GameObject> dvFadeObject;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFade)
    };
}
