#pragma once

namespace hh::snd {
    class SoundManager : public game::GameService, game::GameStepListener {
    public:
        csl::ut::MoveArray<void*> unk101;
        csl::ut::StringMap<void*> unk102;
        csl::ut::MoveArray<void*> unk103;
        csl::ut::StringMap<void*> unk104;
        csl::ut::InplaceMoveArray<hh::fnd::Reference<hh::snd::ResAtomConfig>, 1> atomConfigs;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(SoundManager);
    };
}
