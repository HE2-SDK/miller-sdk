#pragma once

namespace Cyan::System {
    class Random {
        unsigned int seed;
        unsigned int unk2;
    public:
        Random();
        Random(unsigned int);
        float GetFloat();
        float GetRange(float min, float max);
        int Get();
        void SetSeed(unsigned int seed);
    };
}
