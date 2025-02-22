#pragma once

namespace app::dv{
    class DvElementSun : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool curveEnabled;
            csl::math::Position rotation;
            csl::math::Position finishRotation;
            float curveData[32];
        };

        hh::needle::FxAtmosphereParameter* fxAtmosphereParam;

        virtual void Setup(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSun)
    };
}
