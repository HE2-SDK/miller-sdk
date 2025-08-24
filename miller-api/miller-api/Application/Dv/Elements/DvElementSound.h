#pragma once

namespace app::dv{
    class DvElementSound : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class SoundID : unsigned int {
                Voice,
                SFX
            };

            enum class Flags : unsigned int {
                FACIAL_ANIMATION,
                STOP_IMMEDIATELY
            };

            char cueName[64];
            SoundID soundId;
            csl::ut::Bitset<Flags> flags;
        };

        hh::snd::SoundHandle soundHandle;
        csl::ut::MoveArray32<void*> unkArray;
        bool facialAnimation;
        bool stopImmediately;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSound)
    };
}
