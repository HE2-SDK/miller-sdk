#pragma once

namespace Cyan::System {
    class RandomTable {
    public:
        unsigned int count;
        float* unkParam1;

        void Initialize(unsigned int count, float* unkParam1, float* unkParam2, Random* random);
        float GetValue(unsigned int index) const;
    };
}
