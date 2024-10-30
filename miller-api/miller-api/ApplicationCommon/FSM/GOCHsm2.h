#pragma once

namespace app_cmn::fsm {
    class GOCHsm2 : public hh::game::GOComponent {
        uint64_t unk101;
        hh::ut::HsmBase hsm;
        int64_t unk102;
        bool unk103;
        uint32_t unk104;
        csl::ut::InplaceMoveArray<void*, 1> unk105;
        uint64_t unk106;
        uint64_t unk107;
    public:
        struct Config {

        };

        GOCHsm2(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        static GOCHsm2* Create(csl::fnd::IAllocator* pAllocator);
        void Initialize(const Config& config);
    };
}
