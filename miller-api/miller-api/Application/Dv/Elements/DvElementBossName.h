#pragma once

namespace app::dv{
    class DvElementBossName : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class BossID : unsigned int {
                BIOLIZARD,
                METAL_OVERLORD,
                MEPHILES,
                DEVIL_DOOM,
                PERFECT_BLACK_DOOM
            };

            int unk0;
            BossID bossId;
        };

        hh::fnd::Reference<hh::game::GameObject> uiBossNameObject;

        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBossName)
    };
}