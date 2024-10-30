#pragma once

namespace app::player {
    class PlayerState : public GOCPlayerStateBase<PlayerHsmContext> {
    public:
    };

    class PlayerStateBase : public PlayerState {
    public:
        PlayerStateBase(csl::fnd::IAllocator* pAllocator);
    };
}
