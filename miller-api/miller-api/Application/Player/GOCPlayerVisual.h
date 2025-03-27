#pragma once

namespace app::player {
    class GOCPlayerVisual : public hh::game::GOComponent, public app::evt::EventPlayerListener {
    public:
        struct Unk1 {
            int unk1;
            uint8_t unk2;

            Unk1();
        };
    
    public:
        hh::fnd::Reference<ComponentCollector> componentCollector;
        csl::ut::MoveArray<PlayerVisualClass*> visualClasses;
        csl::ut::InplaceMoveArray<PlayerVisual*, 8> visuals; // has no allocator?
        PlayerVisual* playerVisual;
        hh::fnd::Reference<PlayerVisual> unk5;
        PlayerVisual* unk6;
        Unk1 unk7[1];
        char currentPlayerVisualId;
        char unk8;
        hh::fnd::Reference<VisualLocatorManager> visualLocatorManager;
        uint64_t unk9;
        uint64_t unk9a;
        uint32_t unk10;
        csl::ut::MoveArray<void*> unk11;
        uint16_t flags;
        uint32_t unk12;

        struct SetupInfo {
            unsigned int visualCount;
        };

        GOCPlayerVisual(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        void AddVisual(PlayerVisualClass* playerVisualClass, char id);
        void SetupEffects();

        PlayerVisual* GetPlayerVisual(unsigned int nameHash) const;
        PlayerVisual* GetCurrentPlayerVisual() const;

        bool SwitchPlayerVisual(char id, bool unkParam1);
        void TriggerSwitchPlayerVisual(char id, bool unkParam1);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerVisual)
    };
}
