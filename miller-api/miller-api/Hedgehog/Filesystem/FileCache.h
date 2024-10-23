#pragma once

namespace hh::fnd {
    class FileCache : public BaseObject, public csl::fnd::Singleton<FileCache> {
    public:
        void* unkVtbl1;
        void* unkVtbl2;
        csl::fnd::FreeListHeapTemplate<csl::fnd::Mutex> heap;
        uint64_t unk1;
        uint8_t unk2;
        uint8_t unk3;
        uint8_t unk4;
        csl::ut::StringMap<void*> unk5;
        csl::ut::MoveArray<void*> unk6;
        csl::ut::MoveArray<void*> unk7;
        uint8_t unk8;
        uint32_t unk9;
        volatile unsigned int unk10;
        csl::fnd::Mutex unk11;

        static FileCache* Create(csl::fnd::IAllocator* allocator);
        
        FileCache(csl::fnd::IAllocator* allocator);
    };
}
