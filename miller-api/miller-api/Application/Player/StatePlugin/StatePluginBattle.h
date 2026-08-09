#pragma once

namespace app::player {
    class StatePluginBattle : public PlayerStatePlugin, public hh::physics::GOCColliderListener {
        static constexpr const char* name = "StatePluginBattle";

        uint32_t dword30;
        uint32_t dword34;
        uint64_t qword38;
        uint64_t qword40;
        uint64_t qword48;
        uint64_t qword50;
        uint64_t qword58;
        uint64_t qword60;
        csl::math::Vector4 unk
        csl::ut::MoveArray<int64_t> Unk1;
        csl::ut::MoveArray<int64_t> Unk2;
        app::ut::Timer timerC0;
        csl::ut::MoveArray<int64_t> Unk3;
        uint64_t qwordF0;
        uint64_t qwordF8;
        uint32_t dword100;
        
        StatePluginBattle(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
    };
}