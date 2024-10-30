#pragma once

namespace app::level {
	class StageInfo : public hh::game::GameService, public app::fnd::AppResourceManagerListener
	{
	public:
		csl::ut::MoveArray<hh::fnd::Reference<StageData>> stages;
		csl::ut::MoveArray<void*> unk1;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

		StageData* GetStageData(const char* stageName);

        GAMESERVICE_CLASS_DECLARATION(StageInfo)
	};
}
