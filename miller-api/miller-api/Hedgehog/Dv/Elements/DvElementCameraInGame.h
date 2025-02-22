#pragma once

namespace hh::dv{
    class DvElementCameraInGame : public DvElementBase {
    public:
        struct Data {
        public:
            float unk0[26];
        };

        Data binaryData;
        void* unk0;
        void* unk1;
        void* unk2;
        void* unk3;
        void* unk4;
        void* unk5;
        void* unk6;
        void* unk7;
        int unk8;
        char unk9;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraInGame)
    };
}