#pragma once

namespace hh::anim {
    class GOCAnimationBlend : public GOCAnimationSingle {
    public:
        struct SetupInfo : GOCAnimationSingle::SetupInfo {

        };

        uint64_t unk201;
        uint64_t unk202;
        uint64_t unk203;
        uint64_t unk204;
        csl::ut::MoveArray<void*> unk205;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual uint64_t UnkFunc4() override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimationBlend);
    };
}
