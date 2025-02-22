#pragma once

namespace app::dv{
    class DvElementGodrayParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            float color[3];
            float intensity;
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementGodrayParam)
    };
}