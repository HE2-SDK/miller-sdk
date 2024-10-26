#pragma once

namespace app::player {
    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        // GOCPlayerKineticParams* gocPlayerKineticParams;
        // GOCPlayerBlackboard* gocPlayerBlackboard;

    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}