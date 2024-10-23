#pragma once

namespace csl::fnd {
    class FreeListLikeHeapBase : public HeapBase {
        size_t bufferStart;
        size_t bufferEnd;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        size_t unused;
        size_t unallocated;
        unsigned int liveAllocations;
        unsigned int totalAllocations;
        uint32_t unk109;
        uint32_t unk110;

    public:
        FreeListLikeHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool IsIn(void* ptr) const override;
        virtual size_t GetBlockSize(void* ptr) const override;
        virtual void GetStatistics(HeapStatistics& statistics) const override;
        virtual size_t GetBufferTop() const override;
        virtual size_t GetBufferEnd() const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetTotalAllocateCount() const override;
        virtual bool ForEachAllocatedBlock(MemoryBlockFunction& func) override;
        virtual int GetBlockCount() const override;
        virtual int64_t UnkFunc20() override;
    };
}
