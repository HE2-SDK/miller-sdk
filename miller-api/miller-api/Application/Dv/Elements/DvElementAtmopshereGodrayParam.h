#pragma once

namespace app::dv{
    class DvElementAtmosphereGodrayParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool enabled;
            float density;
            float decay;
            float weight;
        };

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;
        virtual void AppUnkFunc4(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAtmosphereGodrayParam)
    };
}
