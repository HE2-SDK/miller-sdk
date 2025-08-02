#pragma once

namespace hh::anim {
    class TriggerListener {
    public:
        struct Trigger {
            uint8_t byte0;
            short type;
            uint16_t word4;
            uint16_t word6;
            uint32_t dword8;
            uint32_t dwordC;
            const char* soundEffectName;
            uint64_t qword18;
            uint64_t qword20;
        };

        virtual ~TriggerListener() = default;
        virtual void EventCallback(const Trigger& trigger) = 0;
    };
}
