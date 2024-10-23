#pragma once

namespace hh::ut {
    struct ResBinaryFileHeader {
        char magic[4];
        char version[3];
        char endianFlag;
        unsigned int fileSize;
        unsigned short nodeCount;
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
