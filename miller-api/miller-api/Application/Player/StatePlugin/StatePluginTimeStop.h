#pragma once

namespace app::player {
    class StatePluginTimeStop : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginTimeStop";
        
        uint64_t qword30;
        uint64_t qword38;
        uint64_t qword40;
        uint64_t qword48;
        uint64_t qword50;
        uint64_t qword58;
        uint8_t byte60;
        uint32_t dword68;
        uint32_t dword70;
        hh::snd::SoundHandle soundHandle;
        uint8_t byte7C;

        StatePluginTimeStop(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override; 
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
    };
}