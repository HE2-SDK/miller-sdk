#pragma once

namespace hh::needle::ImplDX11 {
    class PerfDiagnostics {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            // char char10;
            // _BYTE gap11[184479];
            // uint64_t qword2D0B0;
            // uint64_t qword2D0B8;
            // uint64_t qword2D0C0;
            // char char2D0C8;
            // _BYTE gap2D0C9[8191];
            // _DWORD dword2F0C8;
            // _BYTE gap2F0CC[4];
            // _DWORD dword2F0D0;
            // uint64_t qword2F0D4;
            // _DWORD dword2F0DC;
            // _BYTE byte2F0E0;
            // _BYTE gap2F0E1[128];
            // _WORD word2F161;
        };

        intrusive_ptr<PerfDiagnostics::Impl> implementation;
        uint64_t unk19;

        void Initialize();
    };
}
