#pragma once

namespace app::player {
    class StatePluginEffect : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginEffect";
        
        struct Effect {
            unsigned int nameHash;
            hh::eff::EffectHandle handle;
        };

        csl::ut::MoveArray<Effect> effectList;
        uint8_t byte48;

        StatePluginEffect(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        void PlayEffect(unsigned int nameHash, const char* effectName);
        void PlayEffect(unsigned int nameHash, const char* effectName, int nodeIdx);
        
    };
}
