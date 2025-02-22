#pragma once

namespace app::dv{
    class DvElementCameraControlParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            int empty0;
            float exposureValue;
            int empty1[6];
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCameraControlParam)
    };
}