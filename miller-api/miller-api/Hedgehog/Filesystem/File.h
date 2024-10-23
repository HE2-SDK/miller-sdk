#pragma once

namespace hh::fnd {
    class File : public hh::fnd::ReferencedObject {
    public:
        csl::fnd::IAllocator* fileAllocator;
        csl::ut::VariableString name;
        hh::fnd::Uri uri;
        uint8_t unk1;
        uint32_t maybeFileSize;
        size_t fileSize;
        void* data;
        uint64_t unk2;
        uint64_t unk3;


        File(csl::fnd::IAllocator* allocator);
        static inline File* Create(csl::fnd::IAllocator* allocator);
    };
}