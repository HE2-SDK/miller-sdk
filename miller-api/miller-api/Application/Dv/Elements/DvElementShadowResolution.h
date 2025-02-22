#pragma once

namespace app::dv{
    class DvElementShadowResolution : public AppDvElementBase{
    public:
        struct Data {
        public:
            int width;
            int height;
        };

        int unk0;
        int unk1;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementShadowResolution)
    };
}