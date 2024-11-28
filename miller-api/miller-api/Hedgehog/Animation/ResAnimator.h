#pragma once
#ifdef SYNCHRONIZE
#undef SYNCHRONIZE
#endif

#include <ucsl/resources/asm/v103.h>

namespace hh::anim {
    using ucsl::resources::animation_state_machine::v103::ClipData;
    using ucsl::resources::animation_state_machine::v103::TransitionEasingType;
    using ucsl::resources::animation_state_machine::v103::TransitionType;
    using ucsl::resources::animation_state_machine::v103::TransitionData;
    using ucsl::resources::animation_state_machine::v103::StateType;
    using ucsl::resources::animation_state_machine::v103::StateData;
    using ucsl::resources::animation_state_machine::v103::BlendNodeType;
    using ucsl::resources::animation_state_machine::v103::BlendNodeData;
    using ucsl::resources::animation_state_machine::v103::TransitionArrayData;
    using ucsl::resources::animation_state_machine::v103::EventData;
    using ucsl::resources::animation_state_machine::v103::LayerData;
    using ucsl::resources::animation_state_machine::v103::BlendMaskData;
    using ucsl::resources::animation_state_machine::v103::TriggerType;
    using ucsl::resources::animation_state_machine::v103::TriggerData;
    using ucsl::resources::animation_state_machine::v103::BlendSpaceData;
    UCSL_NEWTYPE_STRUCT_SIMPLE(AsmData, ucsl::resources::animation_state_machine::v103::AsmData);

    class EventArray {
    public:
        csl::ut::StringMap<EventData*> eventsByName;

        EventData* GetEventData(const char* name);
    };

    // A map of state id -> TransitionData
    class TransitionArray : public csl::ut::PointerMap<size_t, TransitionData> {
    public:
        const TransitionData& GetTransitionData(int stateId) const;
    };

    class ResAnimator : public fnd::ManagedResource {
    public:
        AsmData* binaryData;
        csl::ut::StringMap<int> stateIdsByName;
        csl::ut::StringMap<int> variableIdsByName;
        csl::ut::MoveArray<EventArray> eventArrays;
        csl::ut::MoveArray<TransitionArray> transitionArrays;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimator)

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        void LoadBinaryImage(AsmData* binaryData);

        int GetStateId(const char* stateName);
        int GetVariableId(const char* variableName);
        int GetLayerId(const char* layerName);
        int GetTriggerId(const char* triggerName);
    };
}
