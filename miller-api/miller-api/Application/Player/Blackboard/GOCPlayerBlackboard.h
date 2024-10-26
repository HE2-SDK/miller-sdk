#pragma once

namespace app::player {
    class GOCPlayerBlackboard : public hh::game::GOComponent {
    public:
        hh::fnd::Reference<Blackboard> blackboard;

        GOCPlayerBlackboard(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo();
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) {}

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerBlackboard)
    };
}
