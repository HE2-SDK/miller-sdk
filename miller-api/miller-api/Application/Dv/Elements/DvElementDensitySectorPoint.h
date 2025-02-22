#pragma once

namespace app::dv{
    class DvElementDensitySectorPoint : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            csl::math::Position unk1;
            float unk2[4];
        };

        char unk0[56];

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDensitySectorPoint)
    };
}