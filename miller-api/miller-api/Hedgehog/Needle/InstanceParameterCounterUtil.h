#pragma once

namespace hh::needle {
    class InstanceParameterCounterUtil {
    public:
        struct SParameterValueMemorySize {
            size_t unk1;
            size_t unk2;
        };
        static size_t Measure(const InstanceParameterContainerData& ipcd, SParameterValueMemorySize& memorySize);
    };
}
