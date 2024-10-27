#pragma once

namespace hh::needle::ImplDX11 {
    class PerfDiagnostics {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            struct Unk4 {
                uint64_t unk1;
                uint64_t unk2;
            };
            struct Unk3 {
                Unk4 oword0;
                Unk4 oword10;
                Unk4 oword20;
                Unk4 oword30;
                Unk4 oword40;
                Unk4 oword50;
                Unk4 oword60;
                Unk4 oword70;
                uint64_t qword80;
                uint64_t qword88;
                Unk3();
            };
            struct Unk1 {
                struct Unk2 {
                    uint64_t qword0;
                    uint64_t qword8;
                    Unk3 char10[0x100];
                    volatile int volatile___int329010;
                    uint8_t byte9014;
                    uint32_t dword9018;
                };
                Unk2 unk1;
                Unk2 unk2;
                Unk2 unk3;
                Unk2 unk4;
                Unk2 unk5;

                Unk1();
            };

            struct Unk5 {
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
                uint64_t unk4;
            };

            class Unk9 {
                uint8_t unk1;
                uint8_t unk2[0x200];
            };

            class ProfileElementAccessor : public NeedleObject {
            public:
                Unk9 unk1;
                Unk5 unk2D2D0[256];
                uint32_t dword2F2D0;

                virtual uint64_t UnkFunc1();
                virtual uint64_t UnkFunc2();
                virtual uint64_t UnkFunc3();
                virtual uint64_t UnkFunc4();
                virtual uint64_t UnkFunc5();
                virtual uint64_t UnkFunc6();
                virtual uint64_t UnkFunc7();
                virtual uint64_t UnkFunc8();
                virtual uint64_t UnkFunc9();
                virtual uint64_t UnkFunc10();
            };

            class Unk6 {
            public:
                virtual uint64_t UnkFunc1();
            };

            class Unk7 : public NeedleObject {
            public:
                struct Unk8 {
                    uint64_t pad0[39];
                };

                Unk9 unk1;
                Unk8 unk3[4096];
                uint32_t unk4a;

                Unk7();

                virtual ~Unk7() = default;
                virtual uint64_t UnkFunc1();
                virtual uint64_t UnkFunc2();
                virtual uint64_t UnkFunc3();
                virtual uint64_t UnkFunc4();
                virtual uint64_t UnkFunc5();
                virtual uint64_t UnkFunc6();
                virtual uint64_t UnkFunc7();
                virtual uint64_t UnkFunc8();
                virtual uint64_t UnkFunc9();
                virtual uint64_t UnkFunc10();
            };

            Unk1 unk1;
            uint64_t qword2D0B0;
            uint64_t qword2D0B8;
            ProfileElementAccessor profileElementAccessor;
            Unk6 qword2F2D8;
            Unk7 unk2;
            Unk7 unk3;
            uint32_t dword29F710;
            uint32_t qword29F714;
            uint32_t qword29F718;
            int qword29F71C;
            float gpuTime;
            uint8_t byte29F724;
            char byte29F725[128];
            uint8_t word29F7A5;
            uint8_t word29F7A6;
        };

        intrusive_ptr<PerfDiagnostics::Impl> implementation;
        uint64_t unk19;

        void Initialize();
    };
}
