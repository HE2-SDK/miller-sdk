#pragma once

namespace app::player {
    class PlayerStateBase : public GOCPlayerStateBase<PlayerHsmContext> {
    public:
        PlayerStateBase(csl::fnd::IAllocator* pAllocator);
    };
}
