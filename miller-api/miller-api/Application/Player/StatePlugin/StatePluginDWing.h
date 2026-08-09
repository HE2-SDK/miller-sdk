#pragma once

namespace app::player {
    class StatePluginDWing : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginDWing"; // 0x2293CDEB

        // float dword28;
        // float dword2C;
        // float dword30;
        // float dword34;
        // float dword38;
        // float dword3C;
        // float dword40;
        // float dword44;
        // float dword48;
        // float dword4C;
        // float dword50;
        // float dword54;
        // float dword58;
        // hh::snd::SoundHandle soundHandle;
        // uint64_t qword60;
        // uint64_t qword68;
        // uint64_t qword70;
        // csl::fnd::IAllocator* allocator1;
        // uint64_t qword80;
        // uint64_t qword88;
        // uint64_t qword90;
        // uint64_t qword98;
        // csl::fnd::IAllocator* allocator2;
        // uint8_t charA8;
        // _BYTE gapA9[7];
        // uint32_t dwordB0;
        // float dwordB4;
        // float dwordB8;
        // float dwordBC;
        // uint64_t qwordC0;
        // uint64_t qwordC8;
        // uint64_t qwordD0;
        // uint16_t wordD8;

        StatePluginDWing(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
    };
}
