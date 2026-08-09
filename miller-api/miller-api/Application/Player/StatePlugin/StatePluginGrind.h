#pragma once

namespace app::player {
    class StatePluginGrind : public PlayerStatePlugin {
        static constexpr const char* name = "StatePluginGrind";

        csl::ut::MoveArray<int64_t> Unk1;
        uint64_t qword48;
        uint64_t qword50;
        hh::eff::EffectHandle EffectHandle;
        float dword68;
        uint32_t dword6C; // 1 wind
        uint8_t byte70;
        
        StatePluginGrind(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
    };
}