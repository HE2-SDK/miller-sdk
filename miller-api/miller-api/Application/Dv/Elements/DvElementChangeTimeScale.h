#pragma once

namespace app::dv{
    class DvElementChangeTimeScale : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool enabled;
            float timeScale;
            int unk1;
            int unk2;
        };

        bool messageSent;
        int unkHandle;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementChangeTimeScale)
    };
}