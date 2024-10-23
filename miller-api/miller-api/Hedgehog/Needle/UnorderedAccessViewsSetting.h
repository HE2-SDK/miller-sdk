#pragma once

namespace hh::needle {
    struct UnorderedAccessViewsSetting {
        uint32_t startSlot;
        uint32_t numUAVs;
        UnorderedAccessView* unorderedAccessViews[8];
        uint32_t uavInitialCounts[8];
    };
}
