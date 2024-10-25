#pragma once

namespace hh::game {
    class GOCActivator : public hh::game::GOComponent, public hh::fnd::HFrame::Listener {
    public:
        float range;
        float distance;
        bool unk101;
        csl::math::Vector3 z;
        float unk103;
        bool enabled;

        struct RangeSpawningConfig {
            float m_distance;
            float m_range;
        };

        struct SetupInfo {
            RangeSpawningConfig rangeSpawningConfig;
            bool unk1;
        };

        GOCActivator(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void LoadReflection(const LoadReflectionInfo& loadReflectionInfo) override;
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;
        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCActivator)
    };
}
