#pragma once

namespace app::player {
    class GOCPlayerHsm : public hh::game::GOComponent {
    public:
        struct StateDescRef {
            uint32_t id;
            const hh::ut::StateDesc* stateDesc;
        };
        struct SetupInfo {
            const StateDescRef* stateDescs;
            uint32_t stateDescCount;
            uint32_t unk1;
            uint32_t unk105bConfig;
            PlayerHsmContext* hsmContext;
            bool enablePreAnimUpdates;
            bool enablePostAnimUpdates;
            bool enableFinalUpdates;
        };
        enum class Flag : uint8_t {

        };

    public:
        hh::ut::HsmBase* hsm;
        hh::ut::HsmBase hsm2;
        hh::fnd::Reference<PlayerHsmContext> hsmContext;
        hh::fnd::Reference<PlayerStateParameter> playerStateParameter;
        hh::fnd::Reference<StatePluginManager<PlayerHsmContext>> statePluginManager;
        uint32_t unk105;
        uint32_t unk105b;
        uint32_t unk106;
        csl::ut::Bitset<Flag> flags;
        csl::ut::InplaceMoveArray<void*, 1> unk108;
        SetupInfo setupInfo;


        GOCPlayerHsm(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        void Setup(const SetupInfo& setupInfo);
        void SetState(uint32_t stateId, uint32_t unkParam1);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerHsm);
    };
}
