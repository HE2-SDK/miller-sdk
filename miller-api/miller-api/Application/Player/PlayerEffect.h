#pragma once

namespace app::player {
    class PlayerVisual;
    class GOCPlayerVisual;

    class PlayerEffect : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* playerObject;
        PlayerVisual* playerVisual;
        GOCPlayerVisual* gocPlayerVisual;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        uint16_t unk1;

        CREATE_FUNC(PlayerEffect, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual uint64_t UnkFunc1() = 0;
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
    };
}
