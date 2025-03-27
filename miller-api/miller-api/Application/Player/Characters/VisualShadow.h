#pragma once

namespace app::player {
    class VisualShadow : public VisualHuman {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void UnkFunc4(float unkParam1) override;
        virtual void SetupFacialAnimation() override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;

        PLAYER_VISUAL_CLASS_DECLARATION(VisualShadow);
    };
}
