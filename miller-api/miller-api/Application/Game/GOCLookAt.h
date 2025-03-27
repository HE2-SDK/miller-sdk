#pragma once

namespace app::game {
    class GOCLookAt : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            unsigned int gocCharacterIkNameHash;
            float unk1;
        };
        
        unsigned int gocCharacterIkNameHash;
        uint64_t qword88;
        uint16_t word90;
        uint64_t qword98;
        uint64_t qwordA0;
        csl::math::Vector3 csl__math__vector3B0;
        csl::math::Transform csl__math__transformC0;
        ut::TransitionValue<float> unkD0;
        uint8_t byte138;

        GOCLookAt(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCLookAt);
    };
}
