#pragma once

namespace hh::needle {
    class RenderingDevice;


    namespace mirageresourceimage {

        struct MirageNode {
            union Name {
                uint64_t id;
                char name[8];
            };
            enum class Flag : uint32_t {
                IS_LEAF = 29,
                IS_LAST_CHILD = 30,
                IS_ROOT = 31,
            };
            csl::ut::Bitset<Flag> flags;
            Name name;
        };

        struct MirageHeader {
            uint32_t fileSize;
            uint32_t magic;
            uint32_t offsetTableOffset;
            uint32_t offsetCount;
        };

        bool ResolvePointer(void* ptr);
        bool UnResolvePointer(void* ptr);

        void* GetMaterialTextureNameType();
        static void* materialTextureNameType;
    }

    bool ResolveMirageResourceBinary(void* binaryData);
    bool UnResolveMirageResourceBinary(void* binaryData);
}
