#pragma once

namespace app::player {
    class GOCPlayerPosture : public hh::game::GOComponent {
    public:
        PostureContext* context;
        PostureMoveManager* moveManager;
        PostureInputManager* inputManager;
        uint8_t byte98;


        GOCPlayerPosture(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* data) override;
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;
    
        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerReplayPlayer);
    };
}