#pragma once

namespace hh::dv{
    class DvElementControllerVibration : public DvElementBase {
    public:
        struct Data {
        public:
            int flags;
            char groupName[64];
            char vibrationName[64];
            int unk0[3];
        };

        Data binaryData;
        void* unk0;
        void* unk1;
        void* unk2;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementControllerVibration)
    };
}