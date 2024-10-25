#pragma once

namespace csl::fnd {
    struct HeapBlock {

    };

    struct HeapInformation {
        struct FreeSizeInformation {
            size_t totalFreeSize;
            size_t maxFreeSize;
        };

        unsigned int liveAllocations;
        FreeSizeInformation freeSize;
        size_t bufferSize;
    };

    struct HeapStatistics {
        size_t bufferSize;
        size_t used;
        size_t allocated;
        unsigned int liveAllocations;
        unsigned int totalAllocations;
    };

    class MemoryBlockFunction {
    public:
        virtual void operator()(void* ptr, size_t size) = 0;
    };

    class alignas(8) HeapBase {
        uint64_t unk0a;
        uint64_t unk0b;
        void* unk0;
        csl::ut::LinkList<HeapBase> children;
        
        bool unk1;
        char name[10];
        uint64_t unk2;
        HeapBase* parent;
        uint64_t unk8;
        uint64_t unk9;
        bool initialized;
        uint32_t unk11;
        uint16_t unk12;
        bool debugFillOnAlloc;
        bool debugFillOnFree;
        bool debugUnk;
        uint64_t unk14;
        uint64_t unk15;
        uint32_t unk16;
    public:
        HeapBase(const char* name);
        virtual void* GetRuntimeTypeInfo() const;
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
        virtual void Free(void* in_pMemory) = 0;
        virtual const char* GetHeapTypeName() const = 0;
        virtual bool IsIn(void* ptr) const = 0;
        virtual size_t GetBlockSize(void* ptr) const = 0;
        virtual void GetStatistics(HeapStatistics& statistics) const = 0;
        virtual size_t GetBufferTop() const = 0;
        virtual size_t GetBufferEnd() const = 0;
        virtual unsigned int GetCurrentAllocateCount() const = 0;
        virtual unsigned int GetTotalAllocateCount() const = 0;
        virtual bool UnkFunc11() { return true; }
        virtual void UnkFunc12() {}
        virtual int64_t UnkFunc13() = 0;
        virtual void SetDebugFillOnAlloc(bool enabled);
        virtual void SetDebugFillOnFree(bool enabled);
        virtual void SetDebugUnk(bool enabled);
        virtual void UnkFunc17() {}
        virtual bool ForEachAllocatedBlock(MemoryBlockFunction& func) { return false; }
        virtual int GetBlockCount() const;
        virtual int64_t UnkFunc20();
        virtual bool UnkFunc21() { return false; }
        virtual void Lock() {}
        virtual void Unlock() {}
        virtual bool UnkFunc24() { return false; }
        virtual void UnkFunc25() {}

        void SetName(const char* name);
        inline const char* GetName() {
            return name;
        }
        inline HeapBase* GetParent() {
            return parent;
        }

        inline const csl::ut::LinkList<HeapBase>& GetChildren() {
            return children;
        }
    };
}
