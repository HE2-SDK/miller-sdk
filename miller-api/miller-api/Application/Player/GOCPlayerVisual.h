#pragma once

namespace app::player {
    class GOCPlayerVisual : public hh::game::GOComponent {
    public:
        struct Unk1 {
            int unk1;
            uint32_t unk2;
        };
    
    private:
        hh::fnd::Reference<ComponentCollector> componentCollector;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::InplaceMoveArray<void*, 8> unk3; // has no allocator?
        PlayerVisual* playerVisual;
        uint64_t unk5;
        uint64_t unk6;
        Unk1 unk7[4];
        char unk8;
        hh::fnd::Reference<VisualLocatorManager> visualLocatorManager;
        uint32_t unk10;
        csl::ut::MoveArray<void*> unk11;
        uint16_t flags;

    public:
        struct Config {
            int unk2Count;
        };

        GOCPlayerVisual(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Initialize(const Config& config);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerVisual)
    };
}
