#pragma once

namespace app::game {
    class MenuSelect : public hh::game::GameObject {
    public:
        hh::fnd::Reference<hh::game::dmenu::Menu> menu;
        csl::ut::MoveArray32<void*> unk1;
        csl::ut::MoveArray32<void*> unk2;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
    };
}