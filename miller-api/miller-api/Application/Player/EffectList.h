#pragma once

namespace app::player {
    class PlayerVisual;
    class GOCPlayerEffect;
    class EffectList : public hh::fnd::ReferencedObject {
    public:
        GOCPlayerEffect* gocPlayerEffect;
        PlayerVisual* visual;
        csl::ut::MoveArray<hh::fnd::Reference<PlayerEffect>> effects;
        bool loaded;

        CREATE_FUNC(EffectList, PlayerVisual* visual, int effectCount);

        void SetGOCPlayerEffect(GOCPlayerEffect* gocPlayerEffect);
        void AddEffect(PlayerEffect* effect);
    };
}
