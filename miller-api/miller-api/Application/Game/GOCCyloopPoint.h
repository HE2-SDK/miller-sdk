#pragma once

namespace app::game {
    class GOCCyloopPoint : public hh::game::GOComponent {
        struct Unk1 {
            uint8_t flags;
            hh::game::ObjectId unk2;
        };

        uint64_t unk101;
        uint64_t unk102;
        uint32_t unk103;
        Unk1 unk104;

    public:
        struct SetupInfo {
            uint32_t unk1;
            bool unk2;
            bool unk3;
        };

		virtual void* GetRuntimeTypeInfo() override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCyloopPoint);
    };
}
