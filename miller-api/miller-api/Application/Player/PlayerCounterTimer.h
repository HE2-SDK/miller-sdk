#pragma once

namespace app::player {
    class PlayerCounterTimer : public hh::fnd::BaseObject {
        struct TimerValue {
            uint64_t a;
            uint64_t b;
        };

        csl::ut::InplaceMoveArray<TimerValue, 20> timers;
        uint32_t unk1;
    public:
        PlayerCounterTimer(csl::fnd::IAllocator* pAllocator);
    };
}
