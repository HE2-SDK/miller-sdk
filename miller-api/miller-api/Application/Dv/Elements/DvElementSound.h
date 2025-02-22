#pragma once

namespace app::dv{
    class DvElementSound : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class SoundID : unsigned int {
                BGM,
                SFX,
                Voice
            };
            char cueName[64];
            SoundID soundId;
            int unk0;
        };

        short unk0;
        csl::ut::MoveArray32<void*> unkArray;
        short unk1;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSound)
    };
}