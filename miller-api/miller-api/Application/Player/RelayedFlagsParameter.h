#pragma once

namespace app::player {
    class RelayedFlagsParameter : public StateParameter {
        uint32_t unk101;
    public:
        RelayedFlagsParameter();
        virtual uint64_t Clone(csl::fnd::IAllocator* allocator) override;
        virtual uint64_t GetNameHash() override;
        virtual uint64_t Clear() override;
    };
}
