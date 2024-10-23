#pragma once

namespace hh::anim {
    class TriggerListener {
    public:
        virtual ~TriggerListener() = default;
        virtual void TL_MaybeOnTrigger() = 0;
    };
}
