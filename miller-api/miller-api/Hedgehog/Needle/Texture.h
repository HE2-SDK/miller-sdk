#pragma once

#define NEEDLE_RESOURCE_TEXTURE 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    struct TextureCreationInfo {
        enum class Usage {
            DEFAULT,
            IMMUTABLE,
            DYNAMIC,
            STAGING,
            IMMUTABLE2,
            DYNAMIC2,
        };

        enum class BindFlag {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
        };

        enum class MiscFlag {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
            UNK8,
            UNK9,
            UNK10,
            UNK11,
        };

        struct SubresourceData {
            void* sysMem;
            uint32_t memPitch;
        };

        SurfaceType type{}; // goes into surfaceformat unk1
        SurfaceFormat format{};
        unsigned int width{};
        unsigned int height{};
        unsigned int depth{};
        unsigned int mipLevels{};
        unsigned int arraySize{};
        csl::ut::Bitset<BindFlag> bindFlags{};
        csl::ut::Bitset<MiscFlag> miscFlags{};
        uint32_t unk2b{}; // surfaceformat unk5 is true if this is not zero
        Usage usage{};
        int sampleDescIndex{};
        SubresourceData* subresourceDatas{}; // count = arraySize * mipLevels
        void* fileData{}; // Either a DDS or TGA file. Leave as nullptr for custom texture buffer.
        size_t fileSize{};
        uint64_t unk3a{};
        uint64_t unk3b{};
        uint64_t unk3{};
        void* unk4{}; // streaming related i think
        uint64_t unk5{};
    };

    struct TextureViewCreationInfo {
    };

    class Texture : public SurfaceBase {
        uint8_t unk101;
        void* view; // Copied ID3D11TextureView @ 0x155C55D2F
        void* viewSynchronizerVfTable; // streaming, see 0x155E91940
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXTURE;
    };
}
