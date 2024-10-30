#pragma once

namespace app::player {
    template<typename T>
    class GOCPlayerStateBase : public hh::ut::StateBase<T> {
    public:
        struct Unk1 {
            uint64_t a;
            uint64_t b;
            uint64_t c;
        };

        typedef bool MessageHandler(GOCPlayerHsm& gocPlayerHsm, hh::fnd::Message& message);

        csl::ut::MoveArray<MessageHandler*> messageHandlers;
        csl::ut::InplaceMoveArray<Unk1, 4> unk5;
        uint64_t unk9;
        uint32_t unk10;
        int unk11;

        virtual bool Init(PlayerHsmContext& context) override;
        virtual void Enter(PlayerHsmContext& context, int previousState) override;
        virtual void Leave(PlayerHsmContext& context, int nextState) override;
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual bool Step(PlayerHsmContext& context, float deltaTime) override;
        virtual bool Update(PlayerHsmContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
        virtual bool UpdateAsync(PlayerHsmContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;

        virtual bool InitPlayerState(PlayerHsmContext& context);
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState);
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState);
        virtual bool UpdatePlayerState(PlayerHsmContext& context, hh::fnd::UpdatingPhase phase, float deltaTime);
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime);
    };
}
