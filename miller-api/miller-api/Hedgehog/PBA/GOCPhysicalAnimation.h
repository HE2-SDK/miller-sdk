#pragma once

namespace hh::pba{
    class GOCPhysicalAnimation : public hh::game::GOComponent, hh::anim::AnimationEnabledListener{
    public:
        struct RigidBodyTransInfo {
            hh::fnd::WorldPosition position;
            csl::math::Vector3 linearVelocity;
            csl::math::Vector3 angularVelocity;
        };

        struct ConstraintTransInfo {
            hh::fnd::WorldPosition positionA;
            hh::fnd::WorldPosition positionB;
        };

        struct RigidBodyState {
            bool active;
            RigidBodyTransInfo transInfo;
        };

        struct ConstraintState {
            bool active;
            ConstraintTransInfo transInfo;
        };

        int64_t unk200;
        int64_t unk201;
        PhysicalSkeletonBinding* physSkelBind;
        PbaManagerBullet* pbaManager;
        ResPhysicalSkeleton* physSkelRes;
        hh::anim::GOCAnimationSingle* gocAnimationSingle;
        csl::ut::MoveArray<hh::anim::GOCAnimationSingle*> gocAnimationSingles; // looks more like component class actually
        hh::anim::GOCAnimator* gocAnimator1;
        csl::fnd::Function<bool (class hh::anim::GOCAnimationSingle const *)> componentSelector;
        char unk202;
        unsigned char framesPerPhysicsStep;
        float frameTime;
        bool isRagdoll;
        bool enabled;
        bool isActive; // or maybe isBlending? This gets set to true if PBA should be applied according to masks when gocAnimationSingle is an animator, and to true if gocAnimationSingle is non-null but not an animator
        float speed;
        float minimumBoneWeight;
        csl::ut::MoveArray<float> boneWeights;
        csl::math::Transform csl__math__transform160;
        csl::math::Transform csl__math__transform4190;
        int32_t dword1C0;
        int64_t qword1C8;
        csl::math::Vector3 positionOffset;
        csl::math::Vector3 windVelocity;
        float airDensity;

        GOCPhysicalAnimation(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        virtual void GetRigidBodyAndConstraintStates(csl::ut::MoveArray<RigidBodyState>& rigidBodyStates, csl::ut::MoveArray<ConstraintState>& constraintStates) {}
        virtual bool GetSoftBodyNodePositions(int index, csl::ut::MoveArray<csl::math::Vector3>& positions) { return false; }
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4(int64_t a2) {}
        virtual void UnkFunc5(int64_t a2, int64_t a3) {}
        virtual unsigned int GetRigidBodyCount() const {}
        virtual void GetRigidBodyPositions(csl::ut::MoveArray<hh::fnd::WorldPosition>& positions) {}
        virtual void SetRigidBodyPositions(const csl::ut::MoveArray<hh::fnd::WorldPosition>& positions, bool a3) {}
        virtual void GetRigidBodyTransInfos(csl::ut::MoveArray<RigidBodyTransInfo>& transInfos) {}
        virtual void SetRigidBodyTransInfos(const csl::ut::MoveArray<RigidBodyTransInfo>& transInfos, bool a3) {}
        virtual int ApplyForce(int rigidBodyIndex, const csl::math::Vector3& force) { return 0; }
        virtual int GetIterationCount() const {}
        virtual void SetIterationCount(int iterationCount) { }
        virtual int GetManifoldCount() const { return 0; }
        virtual int GetSelectedManifoldCount() const {}
        virtual void Initialize(hh::anim::GOCAnimator* gocAnimator) {}
        virtual void Deinitialize() {}
        virtual void PBAUpdate(float timeStep) {}
        virtual void UnkFunc19(int a2) {}
        virtual void UnkFunc20() {}
        virtual void UnkFunc21(char a2) {}
        virtual void UnkFunc22(float timeStep) {}
        virtual void UnkFunc23(int64_t a2, int64_t a3) {}

        virtual void UnkFunc24();
        virtual void Reset();
        virtual void AddRigidBody(const RigidBody& rigidBody);
        virtual void AddConstraint(const Constraint& constraint);
        virtual void RemoveRigidBody(int index);
        virtual void RemoveConstraint(int index);
        virtual void UpdateRigidBody(int index, const RigidBody& rigidBody);
        virtual void UpdateConstraint(int index, const Constraint& constraint);
        virtual void AddSoftBody(const SoftBody& softBody);
        virtual void RemoveSoftBody(int index);
        virtual void UpdateSoftBody(int index, const SoftBody& softBody);

        virtual void AEL_UnkFunc2(anim::GOCAnimationSingle* gocAnimationSingle, bool enabled) override;

        float GetBoneWeight(int boneIdx);
        float GetClampedBoneWeight(int boneIdx);
        csl::math::Transform GetTransform() const;
        void SetEnabled(bool enabled);
    };

    class GOCPhysicalAnimationBullet : public GOCPhysicalAnimation {
    public:
        struct SetupInfo {
            ResPhysicalSkeleton* resource{};
            bool isRagdoll{};
            bool enabled{ true };
            csl::fnd::Function<bool (class hh::anim::GOCAnimationSingle const *)> componentSelector{};
            unsigned int animationComponentName{};
            int dword1C0{ 0x80 };
        };

        struct UnkStr0 {
            int64_t unk8;
            csl::ut::MoveArray<void*> unkArray6;
            csl::ut::MoveArray<void*> unkArray7;
            csl::ut::MoveArray<void*> unkArray8;
            int64_t unk9;
            int64_t unk10[4]; //unkArray8 allocates here?
            csl::ut::MoveArray<void*> unkArray9;
            int64_t unk11;
            int64_t unk12[4]; //unkArray9 allocates here?
            short unk13;

            UnkStr0(csl::fnd::IAllocator* allocator);
        };

        struct UnkStr1 {
            int64_t unk14;
            int64_t unk15;
            csl::ut::MoveArray<void*> unkArray10;
            csl::ut::MoveArray<void*> unkArray11;
            csl::ut::MoveArray<void*> unkArray12;
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            csl::math::Vector3 scale;
            char unk16;
            int unk17;

            UnkStr1(csl::fnd::IAllocator* allocator);
        };

        struct Unk3 {
            uint8_t unk1;
            int unk2;
        };

        struct RigidBodyInfo {
            btRigidBody* rigidBody;
            int group;
            int mask;
        };

        struct ConstraintInfo {
            btGeneric6DofSpring2Constraint* constraint;
            bool maybeActive;
        };

        struct SoftBodyInfo {
            btSoftBody* softBody;
            uint32_t qword8;
            int group;
            int mask;
            bool maybeActive;
            csl::ut::MoveArray<void*> unk18;
        };

        btSoftRigidDynamicsWorld* dynamicsWorld;
        btRigidBody* rootRigidBody;
        csl::ut::MoveArray<RigidBodyInfo> rigidBodyInfos;
        csl::ut::MoveArray<ConstraintInfo> constraintInfos;
        csl::ut::MoveArray<SoftBodyInfo> softbodyInfos;
        csl::ut::MoveArray<short> dynamicRigidBodyIndices;
        csl::ut::MoveArray<short> staticRigidBodyIndices;
        csl::ut::MoveArray<short> constraintIndices;
        bool hasSoftBody;
        csl::ut::MoveArray<Unk3> unkArray4;
        int64_t unk305[3]; //unkArray4 allocates here?
        int64_t ragdollInstance;
        int64_t ragdollRigidBodyController;
        csl::ut::MoveArray<void*> unkArray5;
        UnkStr0 unkStr0;
        UnkStr1 unkStr1[2];
        int numManifolds; //based on bullet lib

        virtual void GetRigidBodyAndConstraintStates(csl::ut::MoveArray<RigidBodyState>& rigidBodyStates, csl::ut::MoveArray<ConstraintState>& constraintStates) override;
        virtual bool GetSoftBodyNodePositions(int index, csl::ut::MoveArray<csl::math::Vector3>& positions) override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4(int64_t a2) override;
        virtual void UnkFunc5(int64_t a2, int64_t a3) override;
        virtual unsigned int GetRigidBodyCount() const override;
        virtual void GetRigidBodyPositions(csl::ut::MoveArray<hh::fnd::WorldPosition>& positions) override;
        virtual void SetRigidBodyPositions(const csl::ut::MoveArray<hh::fnd::WorldPosition>& positions, bool a3) override;
        virtual void GetRigidBodyTransInfos(csl::ut::MoveArray<RigidBodyTransInfo>& transInfos) override;
        virtual void SetRigidBodyTransInfos(const csl::ut::MoveArray<RigidBodyTransInfo>& transInfos, bool a3) override;
        virtual int ApplyForce(int rigidBodyIndex, const csl::math::Vector3& force) override;
        virtual int GetIterationCount() const override;
        virtual void SetIterationCount(int iterationCount) override;
        virtual int GetManifoldCount() const override;
        virtual int GetSelectedManifoldCount() const override;
        virtual void Initialize(hh::anim::GOCAnimator* gocAnimator) override; // first, third, fifth function that gets executed
        virtual void Deinitialize() override;
        virtual void PBAUpdate(float timeStep) override;
        virtual void UnkFunc19(int a2) override;
        virtual void UnkFunc20() override; // executed when jumping, perhaps related to stopping the sim?
        virtual void UnkFunc21(char a2) override; // second, fourth, sixth function that gets executed
        virtual void UnkFunc22(float timeStep) override;
        virtual void UnkFunc23(int64_t a2, int64_t a3) override;

        virtual void Reset() override;
        virtual void AddRigidBody(const RigidBody& rigidBody) override;
        virtual void AddConstraint(const Constraint& constraint) override;
        virtual void RemoveRigidBody(int index) override;
        virtual void RemoveConstraint(int index) override;
        virtual void UpdateRigidBody(int index, const RigidBody& rigidBody) override;
        virtual void UpdateConstraint(int index, const Constraint& constraint) override;
        virtual void AddSoftBody(const SoftBody& softBody) override;
        virtual void RemoveSoftBody(int index) override;
        virtual void UpdateSoftBody(int index, const SoftBody& softBody) override;

        void Setup(const SetupInfo& setupInfo);

    private:
        btRigidBody* GetRootRigidBody();

        static btRigidBody* CreateBulletRigidBody(const RigidBody& rigidBody, btMotionState* motionState);
        static btGeneric6DofSpring2Constraint* CreateBulletConstraint(const Constraint& constraint, btRigidBody* parentRigidBody, btRigidBody* childRigidBody, const hh::fnd::WorldPosition& offset);
        static void LoadConstraintIntoBulletConstraint(btGeneric6DofSpring2Constraint* bulletConstraint, const Constraint& constraint);

        GOCOMPONENT_CLASS_DECLARATION(GOCPhysicalAnimationBullet);
    };
}
