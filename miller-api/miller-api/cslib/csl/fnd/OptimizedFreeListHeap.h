#pragma once

namespace csl::fnd {
    class OptimizedFreeListHeapBase : public FreeListLikeHeapBase {
        struct Unk1{
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            ut::LinkListNode linkListNode;
        };

        struct Unk2 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            ut::LinkList<Unk1> list1;
            uint64_t unk5;
            ut::LinkList<Unk2> list2;

            Unk2();
        };

        uint64_t unk201;
        Unk2 unk202[6];
        bool initialized;

    public:
        OptimizedFreeListHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual const char* GetHeapTypeName() const override;
        virtual size_t GetBlockSize(void* ptr) const override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual void GetStatistics(HeapStatistics& statistics) const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetTotalAllocateCount() const override;
        virtual int64_t UnkFunc13() override;
    };

    template<typename TLock>
    class alignas(8) OptimizedFreeListHeapTemplate : public OptimizedFreeListHeapBase {
        TLock m_Lock;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual int64_t UnkFunc13() override;
        virtual void Lock() override;
        virtual void Unlock() override;
    };
}
