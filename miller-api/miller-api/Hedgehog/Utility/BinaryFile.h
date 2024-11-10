#pragma once

namespace hh::ut {
    struct ResBinaryFileHeader {
        enum class Flag : uint8_t {
            RESOLVED,
            ENDIANNESS_SWAPPED,
        };

        char magic[4];
        char version[3];
        char endianFlag;
        unsigned int fileSize;
        unsigned short nodeCount;
        unsigned short flags;
    };

    struct ResBinaryFileChunkHeader {
        char magic[4];
        unsigned int size;
        unsigned int stringTableOffset;
        unsigned int stringTableSize;
        unsigned int offsetTableSize;
        unsigned short additionalSize;
    };

    class BinaryFile {
        ResBinaryFileHeader* binaryFileHeader;
    public:
        BinaryFile(void* data);
        void* GetDataAddress(int nodeId);
        size_t GetDataSize(int nodeId) const;
        bool IsValid() const;
    };
}
