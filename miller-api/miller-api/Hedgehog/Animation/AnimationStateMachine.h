#pragma once

namespace hh::anim {
    class AnimationStateMachine;
    class AnimationStateListener {
    public:
        virtual ~AnimationStateListener() = default;
        virtual void ASL_MaybeOnStateChange() {}
    };

    class AnimationStateMachineListener {
    public:
        virtual ~AnimationStateMachineListener() = default;
        virtual void TransitionStartedCallback(AnimationStateMachine* animationStateMachine, int stateId) {}
        virtual void TransitionEndedCallback(AnimationStateMachine* animationStateMachine, int stateId) {}
        virtual void PostStepCallback(AnimationStateMachine* animationStateMachine, int stateId, float time) {}
        virtual void DeletedCallback(AnimationStateMachine* animationStateMachine) {}
    };

    class AnimationStateMachine : public fnd::ReferencedObject {
    public:
        struct VariableInfo {
            BindableCollection bindables;
        };

        class LayerStateBase : public fnd::ReferencedObject {
        public:
            AnimationStateMachine* animationStateMachine;
            uint32_t layerId;

            virtual void* GetRuntimeTypeInfo() const = 0;
            virtual BlendNodeBase* GetStateBlendTree() const = 0;
            virtual AnimationState* GetCurrentAnimationState() const = 0;
            virtual AnimationState* GetPreviousAnimationState() const = 0;
            virtual AnimationState* GetActiveAnimationState() const = 0;
            virtual bool IsTransitioning() = 0;
            virtual const TransitionType& GetTransitionType() const = 0;
            virtual TransitionEffect* GetTransitionEffect() const = 0;
            virtual void* UnkFunc9(void* unkParam1) const = 0;
            virtual void* UnkFunc10(csl::ut::MoveArray<void*>& unkParam1) const = 0;
            virtual void UnkFunc11(csl::ut::MoveArray<void*>& unkParam1) const = 0;
            virtual BlendNodeBase* GetStateBlendTreeForState(AnimationState* state) const = 0;
        };

        struct LayerInfo {
            uint32_t layerId;
            uint8_t unk2;
            uint8_t unk3;
            uint16_t nextSequenceNumber;
            uint8_t unk5;
            float speed;
            uint16_t transitionId;
            fnd::Reference<LayerStateBase> layerState;
            fnd::Reference<LayerBlendNode> blendNode;
            AnimationStateMachine* animStateMachine;
        };

        class LayerStateSimple : public LayerStateBase {
        public:
            fnd::Reference<AnimationState> animationState;

            virtual void* GetRuntimeTypeInfo() const override;
            virtual BlendNodeBase* GetStateBlendTree() const override;
            virtual AnimationState* GetCurrentAnimationState() const override;
            virtual AnimationState* GetPreviousAnimationState() const override;
            virtual AnimationState* GetActiveAnimationState() const override;
            virtual bool IsTransitioning() override { return false; }
            virtual const TransitionType& GetTransitionType() const override;
            virtual TransitionEffect* GetTransitionEffect() const override;
            virtual void* UnkFunc9(void* unkParam1) const override;
            virtual void* UnkFunc10(csl::ut::MoveArray<void*>& unkParam1) const override;
            virtual void UnkFunc11(csl::ut::MoveArray<void*>& unkParam1) const override {}
            virtual BlendNodeBase* GetStateBlendTreeForState(AnimationState* state) const override;
        };

        class LayerStateTransition : public LayerStateBase {
        public:
            TransitionType transitionType;
            uint8_t transitionUnk2;
            unsigned short transitionId;
            uint32_t unk2;
            float transitionTime;
            const char* targetAnimationName;
            fnd::Reference<LayerStateBase> prevLayerState;
            fnd::Reference<AnimationState> animationState;
            fnd::Reference<TransitionEffect> transitionEffect;
            fnd::Reference<BlendNodeBase> transitionBlendTree;

            CREATE_FUNC(LayerStateTransition, AnimationStateMachine** animationStateMachine, LayerInfo* layerInfo, LayerStateBase** prevLayerState, AnimationState** animationState, TransitionData::TransitionInfo* transitionInfo, unsigned short* transitionId);

            virtual void* GetRuntimeTypeInfo() const override;
            virtual BlendNodeBase* GetStateBlendTree() const override;
            virtual AnimationState* GetCurrentAnimationState() const override;
            virtual AnimationState* GetPreviousAnimationState() const override;
            virtual AnimationState* GetActiveAnimationState() const override;
            virtual bool IsTransitioning() override;
            virtual const TransitionType& GetTransitionType() const override;
            virtual TransitionEffect* GetTransitionEffect() const override;
            virtual void* UnkFunc9(void* unkParam1) const override;
            virtual void* UnkFunc10(csl::ut::MoveArray<void*>& unkParam1) const override;
            virtual void UnkFunc11(csl::ut::MoveArray<void*>& unkParam1) const override;
            virtual BlendNodeBase* GetStateBlendTreeForState(AnimationState* state) const override;

            void CreateBlender();
        };

    // private:
        csl::ut::InplaceMoveArray<csl::math::Matrix44, 4> unk1;
        uint8_t unk2;
        uint64_t unk3;
        fnd::Reference<AsmResourceManager> asmResourceManager;
        fnd::Reference<SkeletonBlender> skeletonBlender;
        csl::ut::InplaceMoveArray<LayerInfo, 1> layers;
        csl::ut::InplaceMoveArray<AnimationStateMachineListener*, 1> listeners;
        csl::ut::InplaceMoveArray<void*, 1> unk7;
        csl::ut::InplaceMoveArray<AnimationStateListener*, 1> stateListeners;
        uint64_t unk9;
        csl::ut::MoveArray<VariableInfo> variables;
        fnd::Reference<BlendNodeBase> layerBlendTree;
        csl::ut::MoveArray<csl::ut::MoveArray<TriggerListener*>> triggerListeners;
        unsigned int totalTriggerListenerCount;
        float unk13;
        csl::math::Transform deltaMotion;
        bool hasDeltaMotion;
        bool initialized;
        uint8_t unk15;

    public:
        AnimationStateMachine(csl::fnd::IAllocator* allocator);
        void Setup(AsmResourceManager* resourceManager, SkeletonBlender* skeletonBlender);
        void Initialize();
        void Shutdown();
        void AddListener(AnimationStateMachineListener* listener);
        void RemoveListener(AnimationStateMachineListener* listener);
        void AddTriggerListener(int triggerTypeIndex, TriggerListener* listener);
        void RemoveTriggerListener(int triggerTypeIndex, TriggerListener* listener);
        void AddStateListener(AnimationStateListener* listener);
        void RemoveStateListener(AnimationStateListener* listener);
        void UnloadResource(fnd::ManagedResource* resource);
        void LoadResource(fnd::ManagedResource* resource);
        bool ChangeState(const char* stateName);
        bool ChangeStateWithoutTransition(const char* stateName);
        bool ChangeToNull(int layer);
        bool Transit(const char* eventName, int layer);
        bool DoTransit(const TransitionData& transitionData, int layer);
        int GetActiveInternalState(int layer) const;
        AnimationState::Impl* GetActiveState(int layer) const;
        AnimationState::Impl* GetCurrentState(int layer) const;
        AnimationState::Impl* GetPreviousState(int layer) const;
        int GetTriggerTypeIndexFromName(const char* name) const;
        bool GetDeltaMotion(csl::math::Transform* transform) const;
        bool GetFloat(const char* variableId, float* value) const;
        bool SetFloat(const char* variableId, float value);
        void GetInternalState(AnimationInternalState* internalState) const;
        void SetSkeletonBlender(SkeletonBlender* skeletonBlender);
        bool IsFlagContained(const char* flag, int layer) const;
        bool IsInTransition(int layer) const;

        BlendNodeBase* BuildLayerBlendTree(const BlendNodeData& blendNodeData);
        void UpdateTrigger(AnimationState& animationState, int layerId, float unkParam1, bool unkParam2, bool unkParam3);
    };
}
