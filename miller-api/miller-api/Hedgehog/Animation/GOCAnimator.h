#pragma once

namespace hh::anim {
    class GOCAnimator : public GOCAnimationSingle, public TriggerListener, public AnimationStateListener {
    public:
        AnimationStateMachine* animationStateMachine;
        AsmResourceManager* asmResourceManager;
        uint32_t activeTriggerBits;
        char flags;
        char unk204b;
        uint64_t unk205;
    
        struct SetupInfo : public GOCAnimationSingle::SetupInfo {
            AsmResourceManager* asmResourceManager;
            uint8_t unk102;
            uint8_t unk103; // This isn't referenced in Setup(), I don't understand...
            bool setUnk2Flag;
        };

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual bool GetDeltaMotion(csl::math::Transform* transform) override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual void TL_MaybeOnTrigger() override;
        virtual void ASL_MaybeOnStateChange() override;

        void Setup(const SetupInfo& setupInfo);
        bool ChangeState(const char* stateName);
        bool ChangeStateWithoutTransition(const char* stateName);
        bool ChangeToNull(int unkParam);
        bool Transit(const char* eventName, int layer);
        void SetTriggerEnabled(const char* name, bool enabled);
        bool IsFlagContained(const char* flag, int layer) const;
        bool IsInTransition(int layer) const;
        const char* GetCurrentAnimationName(int layer) const;
        float GetPlaybackSpeed() const;
        void SetPlaybackSpeed(float speed);
        float GetPlaybackSpeed(int layer) const;
        void SetPlaybackSpeed(int layer, float speed);
        bool SetFloat(const char* variableName, float value);
        bool GetFloat(const char* variableName, float* value);
        AsmResourceManager* GetResourceManager() const;
        AnimationState::Impl* GetActiveState(int layer) const;
        AnimationState::Impl* GetCurrentState(int layer) const;
        AnimationState::Impl* GetPreviousState(int layer) const;
        bool IsFinished(int layer) const;

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimator)
    };
}
