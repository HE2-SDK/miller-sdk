#pragma once

namespace app::dv{
    class DvElementSound : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
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

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSound)
    };
}
