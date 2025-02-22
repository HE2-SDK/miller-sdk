#pragma once

namespace app::dv{
    class DvElementCyberSpaceNoise : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            float curveData[32];
        };

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCyberSpaceNoise)
    };
}