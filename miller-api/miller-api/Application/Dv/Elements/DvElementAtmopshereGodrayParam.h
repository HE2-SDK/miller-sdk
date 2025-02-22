#pragma once

namespace app::dv{
    class DvElementAtmosphereGodrayParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool enabled;
            float density;
            float decay;
            float weight;
        };

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAtmosphereGodrayParam)
    };
}