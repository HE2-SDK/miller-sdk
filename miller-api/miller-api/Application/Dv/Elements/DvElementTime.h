#pragma once

namespace app::dv{
    class DvElementTime : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool curveEnabled;
            int unk1;
            int unk2;
            int unk3;
            int unk4;
            int unk5;
            int unk6;
            int unk7;
            int unk8;
            float curveData[32];
        };

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTime)
    };
}
