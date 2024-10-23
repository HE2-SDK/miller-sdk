#pragma once

namespace csl::fnd {
    class alignas(8) TlsfHeapBase : public HeapBase {
        struct BlockHead {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            uint32_t unk5;
            uint32_t unk6[25];
            void* unk7[25][32];
        };

        void* bufferBegin;
        void* bufferEnd;
        uint32_t liveAllocations;
        uint32_t totalAllocations;
        uint64_t unk102;
        uint64_t unk103;
        uint32_t blockCount;
        uint64_t block;
        bool initialized;
    public:

        TlsfHeapBase(const char* name);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual const char* GetHeapTypeName() const override;
        virtual bool IsIn(void* ptr) const override;
        virtual size_t GetBlockSize(void* ptr) const override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual void GetStatistics(HeapStatistics& statistics) const override;
        virtual size_t GetBufferTop() const override;
        virtual size_t GetBufferEnd() const override;
        virtual unsigned int GetCurrentAllocateCount() const override;
        virtual unsigned int GetTotalAllocateCount() const override;
        virtual int64_t UnkFunc13() override;
        virtual bool ForEachAllocatedBlock(MemoryBlockFunction& func) override;
        virtual int GetBlockCount() const override;
        virtual int64_t UnkFunc20() override;
    };

    template<typename TLock>
    class alignas(8) TlsfHeapTemplate : public TlsfHeapBase {
        TLock m_Lock{};
    public:
        TlsfHeapTemplate(const char* name) : TlsfHeapBase{ name } {}

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void* Alloc(size_t in_size, size_t in_alignment) override;
		virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
		virtual void Free(void* in_pMemory) override;
        virtual void CollectHeapInformation(HeapInformation& heapInformation) const override;
        virtual int64_t UnkFunc13() override;
        virtual void Lock() override;
        virtual void Unlock() override;
        virtual bool UnkFunc21() override { return true; }
    };
}