#pragma once

namespace hh::anim {
    class AnimationEnabledListener {
    public:
        virtual void AEL_UnkFunc1() {}
        virtual void AEL_UnkFunc2(void* unkParam1, bool enabled) {}
    };

    class GOCCharacterIk : public game::GOComponent, public AnimationEnabledListener {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
        };

        struct Unk2 {
            csl::math::Vector4 unk1[3];
        };

        struct Unk3 {
            csl::fnd::IAllocator* allocator;
            Unk2* data;
            Unk2 reserved;
        };

        enum class SolverType {
            FOOT,
            HAND,
            LOOKAT,
        };

        struct SetupInfo {
            ResCharacterIk* resource{};
            CharacterIkInfo* characterIkInfo{};
            uint64_t unk2{};
            csl::fnd::Function<bool (const GOCAnimationSingle*)> unk150{};
            unsigned int gocAnimationSingleForUnk150NameHash{};
            RaycastInterface* raycastInterface{};
            csl::ut::InplaceMoveArray<iksolver::SolverBase*, 8> ikSolvers{ nullptr };
            uint8_t byte9A{};
        };
        
        uint64_t qword80;
        uint64_t qword88;
        uint8_t byte98;
        uint8_t byte99;
        uint8_t byte9A;
        fnd::Reference<ResCharacterIk> resource;
        fnd::Reference<CharacterIkInfo> characterIkInfo;
        csl::ut::InplaceMoveArray<fnd::Reference<fnd::ReferencedObject>, 1> unkB0;
        fnd::Reference<RaycastInterface> raycastInterface;
        csl::ut::InplaceMoveArray<fnd::Reference<iksolver::SolverBase>, 3> ikSolvers;
        uint64_t qword118;
        csl::ut::InplaceMoveArray<Unk1, 1> unk120;
        csl::fnd::Function<bool (const GOCAnimationSingle*)> unk150;
        csl::ut::InplaceMoveArray<Unk2, 2> unk1B0;

        GOCCharacterIk(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual iksolver::SolverBase* CreateSolver(SolverType solverType);

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterIk);
    };

    class GOCCharacterIkPxd : public GOCCharacterIk {
    public:
        GOCCharacterIkPxd(csl::fnd::IAllocator* allocator);

        virtual iksolver::SolverBase* CreateSolver(SolverType solverType) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterIkPxd);
    };
}
