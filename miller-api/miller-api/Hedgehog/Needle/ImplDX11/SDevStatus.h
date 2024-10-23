#pragma once

// hh::rsdx ?
namespace hh::needle::ImplDX11 {
    struct SDevStatus {
        struct Unk3 {
            uint64_t unk1[2][7];
            uint32_t count;
        };
        struct Unk5 {
            uint64_t unk1;
            uint64_t unk2;

            Unk5();
        };
        struct Unk4 {
            int unk1;
            char unk2[60];
            RsFlagMask rsFlagMask;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            uint64_t unk7;
            uint32_t unk8;
            uint32_t unk9;
            int64_t unk10;
            uint64_t unk11;
            uint32_t unk12;
            int unk13;
            uint32_t unk14;
            int unk15;
            int unk16;
            uint32_t unk17;
            uint32_t unk18;
            uint32_t unk19;
            int unk20;
            int unk21;

            Unk4();
        };

        DeviceObjectDX11* deviceObject;
        SParameterBuffer* parameterBuffer;
        uint64_t unk1;
        uint64_t unk2[49];
        uint64_t unk2a[132];
        DeviceObjectDX11* deviceObject2;
        uint64_t unk2b;
        uint64_t unk2c[38];
        Unk4 unk3;
        uint32_t qword7AC;
        uint32_t qword7B0;
        Unk3 qword7B8;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        void* unk8;
        void* unk9;
        uint64_t qword860[10];
        uint64_t qword8B0[24];
        uint32_t qword970;
        uint32_t qword974[32];
        uint32_t qword9F4;

        SDevStatus();

        void Setup();
        void InvalidateStatus();
    };
}
