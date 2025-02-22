#pragma once

namespace app::dv{
    class DvElementAuraRoad : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            float curveData0[32];
            float curveData1[32];
        };

        int unk0;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAuraRoad)
    };
}