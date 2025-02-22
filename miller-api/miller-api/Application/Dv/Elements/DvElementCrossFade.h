#pragma once

namespace app::dv{
    class DvElementCrossFade : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool curveEnabled;
            int unk1;
            float curveData[32];
        };

        int unkHandle;
        int unk0;
        void* unk1;
        void* unk2;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCrossFade)
    };
}