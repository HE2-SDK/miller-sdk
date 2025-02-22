#pragma once

namespace app::dv{
    class DvElementOverrideASM : public AppDvElementBase{
    public:
        struct Data {
            char asmName[64];
            char asmNameTarget[64];
        };

        void* unk0;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOverrideASM)
    };
}