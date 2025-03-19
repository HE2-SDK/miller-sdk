#pragma once

namespace app::player {
    class PlayerRaycastInterface : public hh::anim::RaycastInterface {
    public:
        hh::fnd::Handle<hh::game::GameObject> playerObject;
        PlayerCollision* playerCollision;

        CREATE_FUNC(PlayerRaycastInterface, hh::game::GameObject* playerObject);

        virtual bool RayCast(const csl::math::Vector3& from, const csl::math::Vector3& to, unsigned int unkParam1, float& distance, float& unkParam2) override;
    };
}