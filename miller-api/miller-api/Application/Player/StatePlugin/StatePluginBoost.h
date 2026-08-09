#pragma once

namespace app::player {
    class StatePluginBoost : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginBoost";
        
        hh::snd::SoundHandle soundHandle;
        hh::fnd::HFrame* HFrame;
        hh::eff::EffectHandle wind;
        hh::eff::EffectHandle boost;
        float dword60;
        float maxBoost;
        float meter;
        uint32_t dword6C;
        float dword70;
        float dword74;
        float dword78;
        float dword7C;
        csl::ut::MoveArray<int64_t> unk1; // something interesting
        uint16_t wordA0;
        uint8_t byteA2; 
        float cameraEffectTime;
        float cameraPeakTime;
        float cameraEndTime;
        float cameraMaxFovY;
        float cameraMinFovY;
        float blurTime;
        float dwordBC;
        uint32_t dwordC0;
        float GroundedTime;
        float dwordC8;
        uint32_t dwordCC; // game allocates 208, though i haven't seen it anywhere,

        StatePluginBoost(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        void Boost();
    };
}
