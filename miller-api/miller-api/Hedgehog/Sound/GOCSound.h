#pragma once

#ifdef PlaySound
#undef PlaySound
#endif

namespace hh::snd {
    class GOCSound : public game::GOComponent {
        uint64_t unk101;
        uint64_t unk102;
        uint32_t unk103;
        csl::ut::MoveArray<void*> unk104;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
    
    public:
        struct SetupInfo {
            int unk104Count{};
            int unk105Count{};
            uint32_t unk2;
            bool unk3;
        };

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        SoundHandle PlaySound(const char* resourceName, float time);

        GOCOMPONENT_CLASS_DECLARATION(GOCSound);
    };
}
