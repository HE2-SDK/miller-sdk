#pragma once

namespace hh::fnd {
    class ResFileCommon {
    public:
        static unsigned int GetReverseBigEndian(unsigned int value);
        static void ChangeEndian16(bool shouldChange, const unsigned short* src, unsigned short* dst);
        static void ChangeEndian32(bool shouldChange, const unsigned int* src, unsigned int* dst);
        static void ReplacePof0(void* data, void* offsetTable, size_t offsetCount, bool byteswap);
        static void ReplaceDic(void* data, void* dic, unsigned int dicCount, bool byteswap);
    };

    struct ResDicPatriciaData {
        struct ResDicNodeData {

        };
    };

    class ResDicPatricia {
    public:
        bool GetName(int, csl::ut::String *);
        void nodeKey(const ResDicPatriciaData::ResDicNodeData* node, int, csl::ut::String *);
    };
}
