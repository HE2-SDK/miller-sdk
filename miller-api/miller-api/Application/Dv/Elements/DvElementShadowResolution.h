#pragma once

namespace app::dv{
    class DvElementShadowResolution : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int width;
            int height;
        };

        int unk0;
        int unk1;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementShadowResolution)
    };
}
