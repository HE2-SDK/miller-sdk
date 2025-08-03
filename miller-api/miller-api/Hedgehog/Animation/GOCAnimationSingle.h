#pragma once

namespace hh::anim {
    class GOCAnimationSingle;
    class AnimationEnabledListener {
    public:
        virtual void AEL_UnkFunc1() {}
        virtual void AEL_UnkFunc2(GOCAnimationSingle* gocAnimationSingle, bool enabled) {}
    };

    class AnimationManager;
    class GOCAnimationSingle : public GOCAnimation {
    public:
        enum class Type : uint8_t {
            UNK0,
            UNK1,
            UNK2,
        };
        enum class Flag : uint8_t {
            UNK2 = 2,
            HAS_SKELETON = 5, // uses model skeleton if not
            SET_POSE = 6,
        };

        Type type;
        uint8_t unk101a;
        csl::ut::Bitset<Flag> flags;
        uint8_t unk102;
        unsigned int modelComponentName;
        AnimationManager* animationManager;
        fnd::Reference<SkeletonBlender> skeletonBlender;
        gfx::GOCVisualModel* visualModel;
        fnd::Reference<ResSkeleton> skeleton;
        fnd::Reference<ResSkeleton> poseResource;
        void* visualVisibilityHandle;
        fnd::Reference<Pose> skeletonPose;
        fnd::Reference<Pose> pose;
        uint64_t unk110;
        csl::ut::MoveArray<AnimationEnabledListener*> animationEnabledListeners;
        csl::ut::LinkListNode linkListNode;
    //public:
        struct SetupInfo {
            Type type{ Type::UNK0 };
            uint8_t unk1a{};
            bool setPose{ false };
            unsigned int modelComponentName{};
            unsigned int name{};
            ResSkeleton* skeleton{};
            ResSkeleton* pose{};
        };

        GOCAnimationSingle(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        void Setup(const SetupInfo& setupInfo);
        void SetModel(gfx::GOCVisualModel* model);
        void ClearModel(gfx::GOCVisualModel* model);
        void CreateBlender();
        void DestroyBlender();
        void SetBlenderUpdateFlag(bool enabled);
        void SetStateUpdateFlag(bool enabled);
        void SetPose(bool enabled);
        Pose* GetPose() const;

        void AddAnimationEnabledListener(AnimationEnabledListener* listener);
        void RemoveAnimationEnabledListener(AnimationEnabledListener* listener);

        const csl::math::Transform& GetTransform() const;
    };
}
