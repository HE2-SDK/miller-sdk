#pragma once

namespace hh::needle {

    struct RsFlagMask {
    public:
        // For clarity, a bitfield version of this mask. This is not how the game does it though.
        // The generated code is different, so they must be managing the bitfield themselves.
        //
        // bool unk0 : 1;
        // bool unk1 : 1;
        // bool unk2 : 1;
        // bool unk3 : 1;
        // bool unk4 : 1;
        // uint8_t alphaBlendOp : 3;
        // bool unk8 : 1;
        // uint8_t alphaBlendMode2 : 4;
        // bool unk13 : 1;
        // uint8_t alphaBlendMode1 : 4;
        // bool unk18 : 1;
        // uint8_t blendOp : 3;
        // bool unk22 : 1;
        // uint8_t blendMode2 : 4;
        // bool unk27 : 1;
        // uint8_t blendMode1 : 4;
        // uint32_t unk12;

        enum Flags : uint64_t {
            // When setting blend mode the game also sets 0x806108442100
            // i.e. mostly the bits inbetween the fields and some others.
            // I don't yet know why.
            ALPHA_BLEND_OP_MASK = 0x7ui64 << 5ui64,
            ALPHA_BLEND_MODE_2_MASK = 0xFui64 << 9ui64,
            ALPHA_BLEND_MODE_1_MASK = 0xFui64 << 14ui64,
            BLEND_OP_MASK = 0x7ui64 << 19ui64,
            BLEND_MODE_2_MASK = 0xFui64 << 23ui64,
            BLEND_MODE_1_MASK = 0xFui64 << 28ui64,
            CULL_UNK = 1ui64 << 39ui64,
            CULL_BACK = 1ui64 << 40,
            CULL_FRONT = 1ui64 << 41ui64,
            ENABLE_BLENDING = 1ui64 << 46ui64,
        };

// IDA doesn't understand the uint64_t sized enum?
// #ifdef EXPORTING_TYPES
        uint64_t flags;
// #else
        // Flags flags;
// #endif
        uint64_t unk1;
        void SetBlendMode(unsigned int mode1, unsigned int mode2, unsigned int op);
        void Invalidate();
    };
}