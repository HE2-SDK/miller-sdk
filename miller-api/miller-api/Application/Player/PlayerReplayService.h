#pragma once

namespace app::player {
    class PlayerReplayService : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        uint8_t unk200;
        csl::ut::String filename;
        hh::fnd::OptimizedFreeListHeapAllocator replayAllocator;
        csl::ut::MoveArray<void*> unk202;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void ResetTimeout();

        GAMESERVICE_CLASS_DECLARATION(PlayerReplayService);
    };
}
