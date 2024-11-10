#pragma once

namespace hh::anim {
    class BlendNodeBase;
    class ClipNode;
    class AnimationState : public fnd::ReferencedObject {
    public:
        class SpeedBindable : public Bindable {
        public:
            struct Unk2 {
                int variableIndex;
                Bindable* bindable;
            };

            struct Unk1 {
                csl::ut::InplaceMoveArray<Unk2, 6> unk1;
            };
            AnimationState* animationState;
            Unk1 unk4;

            virtual void Bind(float value, void* unkParam) override;
        };

        struct Animation {
            float duration;
            float speed;
            float maybeAnimationStart;
            float maybeAnimationEnd;
            float maybeAnimationCurrent;
            float maybeAnimationCurrent2;
            TriggerData* triggersStart;
            TriggerData* triggersEnd;
            bool loops;
            short clipIndex;
            AnimationControl* animationControl;
            csl::ut::InplaceBitArray<1> triggerFlags;

        };

        class Impl {
        public:
            const char* name;
            short stateId;
            csl::ut::Bitset<StateData::Flag> flags;
            uint16_t sequenceNumber;
            uint16_t word36; // may not exist
            float duration;
            float speed;
            float currentTime;
            float controlSpeed;
            uint32_t cycles;
            uint32_t maxCycles;
            EventArray* eventArray;
            TransitionArray* transitionArray;
            csl::ut::InplaceMoveArray<Animation, 3> animations;
            uint8_t stateBindInfoUnk2;
            uint16_t* flagIndicesStart;
            uint16_t* flagIndicesEnd;
            fnd::Reference<BlendNodeBase> blendTree;
            SpeedBindable speedBindable;
        };

        AsmResourceManager* asmResourceManager;
        StateData* stateData;
        Impl implementation;

        CREATE_FUNC(AnimationState, AsmResourceManager* asmResourceManager, int stateId);

        ClipNode* CreateClipNode(int clipIndex);
        BlendNodeBase* BuildBlendTree(BlendNodeData* rootBlendNode);
        void Update();
        bool IsFlagContained(int flagId) const;
        void SetTime(float time);
    };
}
