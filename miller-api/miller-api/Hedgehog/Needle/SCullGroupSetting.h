#pragma once

namespace hh::needle {
    struct SCullGroupSetting {
        uint32_t renderParametersUnk107Index;
        uint32_t flags; // 0x8 is on when it's an occlusion culling view i think
        void* unk1;
        float unk2;
        float unk3;
        uint32_t unk4;
        uint32_t unk5;
    };
}
