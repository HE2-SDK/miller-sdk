#pragma once

namespace app::dv{
    class DvElementOcclusionCapsuleParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool enabled;
            unsigned int occlusionColor[4];
            float occlusionPower;
        };

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOcclusionCapsuleParam)
    };
}