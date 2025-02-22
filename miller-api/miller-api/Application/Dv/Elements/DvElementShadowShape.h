#pragma once

namespace app::dv{
    class DvElementShadowShape : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                UNK0,
                UNK1,
                UNK2,
                UNK3,
                UNK4
            };

            csl::ut::Bitset<Flags> flags;
            unsigned int color[3]; // color related probably
            int unk0[5];
            float unk1;
            float unk2;
            int unk3;
        };

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementShadowShape)
    };
}