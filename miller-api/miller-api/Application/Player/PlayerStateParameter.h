#pragma once

namespace app::player {
    class PlayerStateParameter : public hh::fnd::BaseObject {
        csl::ut::MoveArray<StateParameter*> stateParameters;

        DEFAULT_CREATE_FUNC(PlayerStateParameter)
    };
}
