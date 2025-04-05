#pragma once

namespace app::dv{
    class DvElementSun : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool curveEnabled;
            float rotation;
            float finishRotation;
            float curveData[32];
        };

        void* unk0;
        hh::needle::FxAtmosphereParameter* fxAtmosphereParam;
        float rotation;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSun)
    };
}
