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

    class HeapBase {
        struct Unk1 {
            const char* name;
            uint64_t unk5;
            uint64_t unk6;
            uint64_t unk7;
        };

        class SystemAllocator : public IAllocator {
        public:
            HeapBase* heap;

            virtual void* Alloc(size_t size, size_t alignment) override;
            virtual void Free(void* ptr) override;
        };
    
        csl::ut::StaticLinkListNode linkListNode;
        uint64_t unk0c;
        char name[16];
        HeapBase* parent;
        csl::ut::StaticLinkList<HeapBase, 8> children;
        uint32_t unk0e;
        bool unk1;
        uint64_t unk2;
        int64_t unk3;
        uint32_t unk4;
        Unk1 systemUnk;
        Unk1 defaultUnk;
        SystemAllocator systemAllocator;
        SystemAllocator* pSystemAllocator;
        uint64_t unk5;
        uint64_t unk6;
        csl::ut::MoveArray<Unk1> unk7;
        csl::ut::MoveArray<void*> unk8;
        csl::ut::MoveArray<void*> unk9;

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
        virtual bool UnkFunc13() { return false; }
        virtual void UnkFunc14() {}
        virtual bool ForEachAllocatedBlock(MemoryBlockFunction& func) { return false; }
        virtual bool ForEachUnkBlock(MemoryBlockFunction& func) { return false; }
        virtual int GetBlockCount() const;
        virtual long long UnkFunc18();
        virtual bool UnkFunc19() { return false; }
        virtual void Lock() {}
        virtual void Unlock() {}
        virtual void UnkFunc22() {}
        virtual bool UnkFunc23() { return false; }
        virtual unsigned int UnkFunc24();
        virtual void UnkFunc25();

        void SetName(const char* name);
        inline const char* GetName() {
            return name;
        }
        inline HeapBase* GetParent() {
            return parent;
        }

        inline const csl::ut::StaticLinkList<HeapBase, 8>& GetChildren() {
            return children;
        }
    };
}
