#pragma once

namespace hh::anim {
    class GOCAnimationSimple : public GOCAnimationSingle {
    public:
        struct Unk1 {
            char pad1[32];
        };

        struct SetupInfo : GOCAnimationSingle::SetupInfo {
            unsigned int unkCount;
        };

        csl::ut::InplaceMoveArray<Unk1, 1> unk302;
        csl::ut::MoveArray<void*> unk303;
        csl::ut::StringMap<void*> unk304;
        csl::ut::InplaceMoveArray<uint32_t, 2> unk305;
        csl::ut::MoveArray<void*> unk306;
        csl::ut::MoveArray<void*> unk307;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void LoadReflection(const LoadReflectionInfo& loadReflectionInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimationSimple);
    };
}
