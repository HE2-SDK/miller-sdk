#pragma once

namespace hh::pba{
    class GOCPhysicalAnimation : public hh::game::GOComponent, hh::anim::AnimationEnabledListener{
    public:
        int64_t unk0;
        int64_t unk1;
        PhysicalSkeletonBinding* physSkelBind;
        PbaManagerBullet* pbaManager;
        ResPhysicalSkeleton* physSkelRes;
        hh::anim::GOCAnimator* gocAnimator0;
        csl::ut::MoveArray<hh::anim::GOCAnimator*> gocAnimators;
        hh::anim::GOCAnimator* gocAnimator1;
        int64_t unk2;
        csl::fnd::Function<bool (class hh::anim::GOCAnimationSingle const *)>* function0Ptr;
        csl::fnd::Function<bool (class hh::anim::GOCAnimationSingle const *)> function0;
        float pbaBlendFactor;
        int32_t dword134;
        csl::ut::MoveArray<float> pbaBlendFactors;
        csl::math::Transform csl__math__transform160;
        csl::math::Transform csl__math__transform4190;
        int32_t dword1C0;
        int64_t qword1C8;
        csl::math::Vector4 csl__math__vector41D0;
        csl::math::Vector4 csl__math__vector41E0;
        float dword1F0;

        GOCPhysicalAnimation(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        virtual void UnkFunc0(int64_t a2, int64_t a3, double a4) {}
        virtual bool UnkFunc1(int64_t a2, int64_t a3, double a4) { return false; }
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4(int64_t a2) {}
        virtual void UnkFunc5(int64_t a2, int64_t a3) {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7(int64_t a2) {}
        virtual void UnkFunc8(int64_t a2, char a3) {}
        virtual void UnkFunc9(int64_t a2) {}
        virtual void UnkFunc10(int64_t a2, char a3) {}
        virtual int UnkFunc11(int64_t a2, int64_t a3) { return 0; }
        virtual void UnkFunc12() {}
        virtual void SetNumberOfBulletPhysIterations(int iterationCount) { }
        virtual int GetNumManifolds() { return 0; }
        virtual void UnkFunc15() {}
        virtual void UnkFunc16(hh::anim::GOCAnimator* gocAnimator) {}
        virtual void UnkFunc17() {}
        virtual void PBAUpdate(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) {}
        virtual void UnkFunc19(int a2) {}
        virtual void UnkFunc20() {}
        virtual void UnkFunc21(char a2) {}
        virtual void UnkFunc22(double a2) {}
        virtual void UnkFunc23(int64_t a2, int64_t a3) {}

        virtual void UnkFunc24();
        virtual void UnkFunc25();
        virtual void UnkFunc26(int64_t a2);
        virtual void UnkFunc27(int64_t a2);
        virtual void UnkFunc28(int64_t a2);
        virtual void UnkFunc29(int64_t a2, int64_t a3);
        virtual void UnkFunc30(int64_t a2, int64_t a3);
        virtual void UnkFunc31(int64_t a2, int64_t a3);
        virtual void UnkFunc32(int64_t a2, int64_t a3, int64_t a4);
        virtual void UnkFunc33(int a2);
        virtual void UnkFunc34(int a2, int64_t a3);

        virtual void AEL_UnkFunc2(void* unkParam1, bool enabled) override;
    };

    class GOCPhysicalAnimationBullet : public GOCPhysicalAnimation {
    public:
        struct SetupInfo {
            ResPhysicalSkeleton* resource;
            char reserved40;
            char reserved41;
            int64_t unk2;
            char unk3;
            void* gocColliderBullet; //hh::physics::GOCColliderBullet
            void* bulletCollisionShape0; //hh::physics::bullet::CollisionShape
            void* bulletCollisionShape1; //hh::physics::bullet::CollisionShape
            csl::math::Vector4 unk8;
            int nameHash;
            int gocDword1c0;
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

        int64_t dynamicsWorld; // btDiscreteDynamicsWorld
        int64_t unk3;
        csl::ut::MoveArray<int64_t> rigidBodies; // btRigidBody
        csl::ut::MoveArray<int64_t> constraints; // btGeneric6DofSpring2Constraint
        csl::ut::MoveArray<int64_t> softbodies;
        csl::ut::MoveArray<short> unkArray1;
        csl::ut::MoveArray<short> unkArray2;
        csl::ut::MoveArray<void*> unkArray3;
        bool hasSoftBody;
        csl::ut::MoveArray<void*> unkArray4;
        int64_t unk5[3]; //unkArray4 allocates here?
        int64_t unk6;
        int64_t unk7;
        csl::ut::MoveArray<void*> unkArray5;
        UnkStr0 unkStr0;
        UnkStr1 unkStr1[2];
        int numManifolds; //based on bullet lib

        virtual void UnkFunc0(int64_t a2, int64_t a3, double a4) override;
        virtual bool UnkFunc1(int64_t a2, int64_t a3, double a4) override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4(int64_t a2) override;
        virtual void UnkFunc5(int64_t a2, int64_t a3) override;
        virtual void UnkFunc6() override;
        virtual void UnkFunc7(int64_t a2) override;
        virtual void UnkFunc8(int64_t a2, char a3) override;
        virtual void UnkFunc9(int64_t a2) override;
        virtual void UnkFunc10(int64_t a2, char a3) override;
        virtual int UnkFunc11(int64_t a2, int64_t a3) override;
        virtual void UnkFunc12() override;
        virtual void SetNumberOfBulletPhysIterations(int iterationCount) override;
        virtual int GetNumManifolds() override;
        virtual void UnkFunc15() override;
        virtual void UnkFunc16(hh::anim::GOCAnimator* gocAnimator) override; // first, third, fifth function that gets executed
        virtual void UnkFunc17() override;
        virtual void PBAUpdate(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void UnkFunc19(int a2) override;
        virtual void UnkFunc20() override; // executed when jumping, perhaps related to stopping the sim?
        virtual void UnkFunc21(char a2) override; // second, fourth, sixth function that gets executed
        virtual void UnkFunc22(double a2) override;
        virtual void UnkFunc23(int64_t a2, int64_t a3) override;

        virtual void UnkFunc25() override;
        virtual void UnkFunc26(int64_t a2) override;
        virtual void UnkFunc27(int64_t a2) override;
        virtual void UnkFunc28(int64_t a2) override;
        virtual void UnkFunc29(int64_t a2, int64_t a3) override;
        virtual void UnkFunc30(int64_t a2, int64_t a3) override;
        virtual void UnkFunc31(int64_t a2, int64_t a3) override;
        virtual void UnkFunc32(int64_t a2, int64_t a3, int64_t a4) override;
        virtual void UnkFunc33(int a2) override;
        virtual void UnkFunc34(int a2, int64_t a3) override;

        void Setup(SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCPhysicalAnimationBullet);
    };
}