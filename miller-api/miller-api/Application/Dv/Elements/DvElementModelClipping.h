#pragma once

namespace app::dv{
    class DvElementModelClipping : public AppDvElementBase{
    public:
        struct Data {
        public:
            csl::math::Rotation unk0;
            float unk1;
        };

        int unk0;
        int unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::ut::MoveArray<void*> unk4;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementModelClipping)
    };
}