#pragma once

namespace app::player {
    class StatePluginWallJump : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginWallJump";

        uint64_t unk1;
        csl::math::Vector4 unk2;
        float Timer;
        char isActive;
        bool isTouching;

        StatePluginWallJump(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
    };
}