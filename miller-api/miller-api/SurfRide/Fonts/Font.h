#pragma once

namespace SurfRide {
    struct SRS_FONT {
        const char* name;
        int id;
        unsigned int unk1;
        short unk2;
        unsigned short characterCount;
        unsigned short unk3;
        SRS_CHARACTER_MAPPING* characters;
        uint64_t unk4;
        SRS_USERDATA* userData;
    };
}
