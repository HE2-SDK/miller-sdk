#pragma once

namespace app::player {
    class GOCPlayerCollider : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            bool unk1;
        };

        csl::ut::MoveArray<void*> unk201;
        csl::ut::MoveArray<void*> unk202;
        hh::fnd::Reference<hh::physics::PhysicsRaycastJob> physicsRaycastJob;
        csl::ut::MoveArray<void*> unk204;
        hh::fnd::Reference<PlayerCollision> playerCollision;
        hh::fnd::Reference<PlayerController> playerController;
        bool unk207;
        bool unk208;
        bool unk209;
        bool unk210;
        hh::fnd::Handle<hh::physics::GOCCollider> unk211;

        GOCPlayerCollider(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        PlayerCollision* GetPlayerCollision() const;
        PlayerController* GetPlayerController() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerCollider);
    };
}
