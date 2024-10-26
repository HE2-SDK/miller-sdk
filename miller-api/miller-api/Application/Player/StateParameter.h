#pragma once

namespace app::player {
    class StateParameter {
        uint32_t unk1;
    public:
        StateParameter(uint32_t unk1Param) {}

        virtual ~StateParameter() = default;
        virtual uint64_t Clone(csl::fnd::IAllocator* allocator) = 0;
        virtual uint64_t GetNameHash() = 0;
        virtual uint64_t Clear() {}
    };
}
