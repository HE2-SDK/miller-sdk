#pragma once

namespace app::dv{
    class DvElementFootIk : public AppDvElementBase{
    public:
        struct Data {
        public:
            char data[800];
        };

        void* unk0;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFootIk)
    };
}