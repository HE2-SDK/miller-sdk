#pragma once

namespace app::dv{
    class DvElementLipAnimation : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            char lipAnimName[64];
            int unk1;
        };

        char unk0;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementLipAnimation)
    };
}
