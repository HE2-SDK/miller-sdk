#pragma once

namespace hh::animeff {
    class GOCParticleLocator;
    class ParticleLocatorListener {
    public:
        struct PreCreateParticleInfo {
            enum class Type : unsigned char {
                EFFECT,
                SOUND,
            };

            const char* resource;
            Type type;
            int id;
            bool discard;
            bool replaceResource;
            csl::ut::InplaceMoveArray32<char, 127> newResource;
        };

        virtual ~ParticleLocatorListener() = default;

        virtual void PreCreateParticle(GOCParticleLocator* gocParticleLocator, PreCreateParticleInfo& preCreateParticleInfo) {}
    };

    class GOCParticleLocator : public game::GOComponent, public anim::TriggerListener, public anim::AnimationStateMachineListener {
    public:
        struct SetupInfo {
            ResParticleLocation* resource{}; // ResParticleLocation
            unsigned int gocVisualModelNameHash{};
            unsigned int gocAnimatorNameHash{};
            uint8_t byteC0{};
            uint32_t qwordC8{};
        };

        template<typename T>
        struct BoundCollection {
            struct BoundItem {
                uint16_t stateSequenceNr;
                uint16_t id;
                bool looping;
                hh::animeff::Emitter* emitter;
                T item;
            };

            csl::ut::MoveArray<BoundItem> boundItems;
            csl::fnd::IAllocator* allocator;
        };

        struct EmitterConfig {
            union AnyEffectCreateInfo {
                hh::eff::EffectTransNodeCreateInfo node;
                hh::eff::EffectTransNodeAndFrameCreateInfo nodeAndFrame;
                hh::eff::EffectTransNodePositionCreateInfo nodePosition;
            };

            hh::eff::EffectCreateInfo* effectCreateInfo;
            AnyEffectCreateInfo anyEffectCreateInfo;
            bool mirrored;
            csl::math::Vector3 scale;
        };

        fnd::Reference<ResParticleLocation> resource;
        anim::GOCAnimator* gocAnimator;
        eff::GOCEffect* gocEffect;
        gfx::GOCVisualModel* gocVisualModel;
        uint8_t byteB0;
        short effectTriggerTypeIndex;
        short soundTriggerTypeIndex;
        unsigned int gocVisualModelNameHash{};
        unsigned int gocAnimatorNameHash{};
        uint8_t byteC0;
        uint32_t qwordC4;
        uint32_t qwordC8;
        csl::ut::MoveArray<void*> unkD0;
        csl::ut::MoveArray<BoundCollection<hh::eff::EffectHandle>*> boundEffectsByBoneIndex;
        csl::ut::MoveArray<BoundCollection<hh::snd::SoundHandle>*> boundSoundsByBoneIndex;
        csl::ut::InplaceMoveArray<ParticleLocatorListener*, 1> listeners;

        GOCParticleLocator(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void TransitionEndedCallback(anim::AnimationStateMachine* animationStateMachine, int stateId) override;
        virtual void EventCallback(const hh::anim::Trigger& trigger) override;

        void Setup(const SetupInfo& setupInfo);

        void AddListener(ParticleLocatorListener* listener);
        void RemoveListener(ParticleLocatorListener* listener);

        void AttachAnimator(anim::GOCAnimator* animator);
        void DetachAnimator();

        bool LoadEmitterConfig(Emitter* emitter, short clipIndex, EmitterConfig& config);

        GOCOMPONENT_CLASS_DECLARATION(GOCParticleLocator);
    };
}
