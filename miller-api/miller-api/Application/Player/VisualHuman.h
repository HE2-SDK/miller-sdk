#pragma once

namespace app::player {
    class VisualHuman : public PlayerVisual, public hh::anim::TriggerListener {
    public:
        enum class AttachPointId : char {
            HEAD,
            HEAD_TOP,
            HIPS,
            UPPER_ARM_L,
            UPPER_ARM_R,
            FOREARM_L,
            FOREARM_R,
            HAND_L,
            HAND_R,
            THIGH_L,
            THIGH_R,
            CALF_L,
            CALF_R,
            FOOT_L,
            FOOT_R,
            FREE01,
            FREE02,
            CHR_SONICSPIN,
            COS_WEAPON_L,
            COS_WEAPON_R,
            TAIL3_L,
            TAIL3_R,
        };

        int actionTriggerTypeIndex;
        int footTriggerTypeIndex;
        int seTriggerTypeIndex;
        hh::fnd::Reference<hh::fnd::HFrame> attachPointFrames[18];
        uint8_t unk104;

        VisualHuman(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* unkParam1);
        
        virtual void SetupEffects() override;
        virtual void OnStart() override;
        virtual void OnEnd() override;
        virtual void SetupFacialAnimation() {}
        virtual void CreateEffects() {}
        virtual void BindEffects() {}
        virtual void UnbindEffects() {}
        virtual void TL_MaybeOnTrigger() override;

        void InitializeAttachPointFrames();
        hh::fnd::HFrame* GetAttachPointFrame(AttachPointId attachPointId) const;
        void AttachComponent(char componentId, AttachPointId attachPointId);
    };
}
