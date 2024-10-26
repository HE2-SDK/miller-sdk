#pragma once

namespace app::player {
    class PlayerStateActionBase : public PlayerStateBase {

    };

    class StateJumpBase : public PlayerStateActionBase {

    };

    class StateJump : public StateJumpBase {
        virtual bool ProcessMessage(void* hsm, const hh::fnd::Message& message);
        virtual void UnkFunc12(void* hsm, uint32_t unkParam2);
        virtual void UnkFunc13(void* hsm, uint32_t unkParam2);
        virtual bool Update(void* hsm, float unkParam2);
    };
}