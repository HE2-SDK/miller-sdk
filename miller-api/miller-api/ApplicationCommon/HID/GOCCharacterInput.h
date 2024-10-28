#pragma once

namespace app_cmn::hid {
    class GOCCharacterInput : public hh::game::GOComponent {
    public:
        struct Unk1 {
            unsigned int leftMonitorId;
            unsigned int downMonitorId;
            unsigned int rightMonitorId;
            unsigned int upMonitorId;
            float xPosition;
            float yPosition;
            bool enabled;
        };

        uint32_t playerId;
        csl::math::Matrix34 viewMatrix;
        csl::ut::MoveArray<Unk1> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        uint8_t byte130;

        GOCCharacterInput(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void UpdateInput(const hh::fnd::SUpdateInfo& updateInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterInput);
    };
}
