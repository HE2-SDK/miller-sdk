#pragma once

namespace app::dv{
    class DvElementLetterBox : public AppDvElementBase{
    public:
        struct Data {
        public:
            float curveData[32];
        };

        virtual void Setup(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementLetterBox)
    };
}