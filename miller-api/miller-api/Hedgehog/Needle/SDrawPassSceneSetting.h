#pragma once

namespace hh::needle {
    struct SDrawPassSceneSetting {
        uint32_t unk1;
        uint32_t unk1a;
        uint64_t unk2;
        CNameIDObject* name;
        uint32_t unk4;
        uint32_t someType; // see 0x1410D4AFF
        void* unk5;
        uint64_t unk6;
    };
}
