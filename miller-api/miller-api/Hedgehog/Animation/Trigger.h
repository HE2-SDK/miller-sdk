#pragma once

namespace hh::anim {
    struct Trigger {
        enum class Type : unsigned char {
            STAY,
            ENTER,
            LEAVE,
        };

        Type type;
        short typeIndex;
        short clipIndex;
        short boneIndex;
        float unk2;
        float unk3;
        const char* triggerName;
        const char* colliderName;
        AnimationState::Impl* state;
    };

    class TriggerListener {
    public:
        virtual ~TriggerListener() = default;
        virtual void EventCallback(const Trigger& trigger) = 0;
    };
}
