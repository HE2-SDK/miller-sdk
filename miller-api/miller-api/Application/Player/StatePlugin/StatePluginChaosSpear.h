#pragma once

namespace app::player {
    class StatePluginChaosSpear : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginChaosSpear";
        
        csl::ut::MoveArray<int64_t> unk1;
        float dword50;
        uint32_t dword54;
        uint32_t dword58;
        uint8_t byte5C;
        float dword60;
        uint32_t dword64;

        StatePluginChaosSpear(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        void Boost();
    };
}
