#pragma once

namespace app::dv{
    class DvElementDitherParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            float grassDitherStart;
            float grassDitherEnd;
        };

        int unk0;
        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDitherParam)
    };
}