#pragma once

namespace hh::game{
    class VibrationManager : public GameService, GameStepListener {
    public:
        csl::ut::MoveArray<GOCVibration*> gocVibrations;
        csl::ut::MoveArray<void*> unkArray0;
        csl::ut::PointerMap<int, void*> unkPtrMap0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(VibrationManager)
    };
}
