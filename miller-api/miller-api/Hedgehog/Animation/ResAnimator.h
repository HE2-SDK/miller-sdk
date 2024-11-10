#pragma once

#ifdef SYNCHRONIZE
#undef SYNCHRONIZE
#endif

namespace hh::anim {
    struct ClipData {
        struct AnimationSettings {
            enum class Flag : uint8_t {
                MIRROR, // create a mirror animation.
                PLAY_UNTIL_ANIMATION_END, // play until the end of the animation. ignore the `end` property.
                NO_ANIMATION_RESOLUTION, // don't look up the animation resource in resource manager?
            };

            const char* resourceName;
            float start;
            float end;
            float speed;
            csl::ut::Bitset<Flag> flags;
            bool loops;
        };

        const char* name;
        AnimationSettings animationSettings;
        unsigned short triggerCount;
        short triggerOffset;
        short blendMaskIndex;
        unsigned short childClipIndexCount;
        short childClipIndexOffset;
    };

    enum class TransitionEasingType : uint8_t {
        LINEAR,
        CUBIC,
    };

    enum class TransitionType : uint8_t {
        IMMEDIATE,
        FROZEN,
        SMOOTH,
        SYNCHRONIZE,
        HOLD_TO,
        HOLD_BOTH,
        WAIT_FROM,
        WAIT_FROM_HOLD_TO,
        USER_0,
        USER_1,
        USER_2,
    };

    struct TransitionData {
        struct TransitionInfo {
            TransitionType type;
            TransitionEasingType easingType;
            short targetStateIndex;
            float transitionTime;
        };

        TransitionInfo transitionInfo;
        short transitionTimeVariableIndex;
    };

    enum class StateType : char {
        NULL_STATE = -1,
        CLIP,
        BLEND_TREE,
        NONE,
    };

    struct StateData {
        enum class Flag : uint8_t {
            LOOPS,
            UNK1,
            DISABLE_PBA,
            USE_PBA_BLEND_FACTOR,
        };

        const char* name;
        StateType type;
        bool transitImmediately;
        csl::ut::Bitset<Flag> flags;
        char defaultLayerIndex;
        short rootBlendNodeOrClipIndex;
        short maxCycles;
        float speed;
        short speedVariableIndex;
        unsigned short eventCount;
        short eventOffset;
        short transitionArrayIndex;
        TransitionData stateEndTransition;
        unsigned short flagIndexCount;
        short flagIndexOffset;
        float pbaBlendFactor;
    };

    enum class BlendNodeType : uint8_t {
        LERP,
        ADDITIVE,
        CLIP,
        OVERRIDE,
        LAYER,
        MULTIPLY,
        BLEND_SPACE,
        TWO_POINT_LERP,
    };

    struct BlendNodeData {
        BlendNodeType type;
        short blendSpaceIndex;
        short blendFactorVariableIndex;
        float blendFactorTarget;
        // Points back into the blendNode array to specify this node's children.
        // This value is weird for LAYER type blend nodes: the childNodeArraySize is then
        // expected to be 0, and the childNodeArrayOffset is the layer ID.
        // For CLIP blend nodes it is the clip index.
        unsigned short childNodeArraySize;
        short childNodeArrayOffset;
    };

    // An array of transitions, defined as a slice of the large transition array in the top level struct.
    struct TransitionArrayData {
        // How many transitions this array contains.
        int size;
        // Where this array starts in the large array of transitions.
        int offset;
    };

    struct EventData {
        const char* name;
        TransitionData transition;
    };

    struct LayerData {
        const char* name;
        unsigned short probablyLayerId;
        short blendMaskIndex;
    };

    struct BlendMaskData {
        const char* name;
        unsigned short maskBoneCount;
        short maskBoneOffset;
    };

    enum class TriggerType : uint8_t {
        HIT,
        ENTER_LEAVE,
    };

    struct TriggerData {
        TriggerType type;
        float unknown2;
        float unknown3;
        unsigned short triggerTypeIndex;
        short colliderIndex;
        const char* name;
    };

    struct BlendSpaceData {
        struct Triangle {
            short nodeIndices[3];
            short unused;
        };

        short xVariableIndex;
        short yVariableIndex;
        float xMin;
        float xMax;
        float yMin;
        float yMax;
        unsigned short nodeCount;
        unsigned short triangleCount;
        csl::math::Vector2* nodes;
        short* clipIndices;
        Triangle* triangles;
    };

    struct AsmData {
        char magic[4];
        int version;
        int clipCount;
        ClipData* clips;
        int stateCount;
        StateData* states;
        int blendNodeCount;
        BlendNodeData* blendNodes;
        int eventCount;
        EventData* events;
        int transitionArrayCount;
        TransitionArrayData* transitionArrays;
        int transitionCount;
        TransitionData* transitions;
        TransitionData nullTransition;
        int flagIndexCount;
        short* flagIndices;
        int flagCount;
        const char** flags;
        int variableCount;
        const char** variables;
        int layerCount;
        LayerData* layers;
        int blendMaskCount;
        BlendMaskData* blendMasks;
        int maskBoneCount;
        const char** maskBones;
        int triggerCount;
        TriggerData* triggers;
        int triggerTypeCount;
        const char** triggerTypes;
        int colliderCount;
        const char** colliders;
        short blendTreeRootNodeId;
        int blendSpaceCount;
        BlendSpaceData* blendSpaces;
        int childClipIndexCount;
        short* childClipIndices;
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
