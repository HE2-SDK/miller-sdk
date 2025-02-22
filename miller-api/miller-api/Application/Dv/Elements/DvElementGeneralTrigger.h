#pragma once

namespace app::dv{
    class DvElementGeneralTrigger : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            char triggerName[64];
        };

        char triggerName[64];

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementGeneralTrigger)
    };
}