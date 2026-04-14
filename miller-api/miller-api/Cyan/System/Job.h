#pragma once

namespace Cyan::System {
    class Job {
    public:
        void* unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;

        virtual void Process(float unk) = 0;
        virtual uint64_t UnkFunc2(float unkParam1) = 0;
        virtual uint64_t UnkFunc3(void* unkParam1) = 0;
        virtual ~Job();
    };
}
