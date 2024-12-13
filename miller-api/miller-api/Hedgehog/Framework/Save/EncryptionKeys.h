#pragma once

namespace hh::fw::save {
    class EncryptionKeys {
    public:
        const char* key1;
        size_t key1Size;
        const char* key2;
        size_t key2Size;
        unsigned int unk1;
        unsigned int unk2;
        uint8_t unk3;

        EncryptionKeys();
    };
}
