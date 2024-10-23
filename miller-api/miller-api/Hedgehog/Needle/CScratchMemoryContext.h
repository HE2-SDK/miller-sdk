#pragma once

namespace hh::needle {
    class CScratchMemoryContext {
    public:
        enum class Flag : uint32_t {
            UNKPARAM,
            IS_CHILD,
        };

        void* memory;
        size_t usedSize;
        size_t allocatedSize;
        CScratchMemoryContext* parent;
        void* data; // skipping header
        uint32_t unk4;
        uint32_t flags;

        CScratchMemoryContext(bool empty);
        CScratchMemoryContext(CScratchMemoryContext& other, bool unkParam);
        ~CScratchMemoryContext();
        void PreAllocInside(size_t size);

        // Return value is nr of pages allocated.
        static unsigned int AllocPoolMemoryPage(unsigned int pageCount);
        static unsigned int AllocLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreeLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int GetMaxAllocatablePageSize();
    };
}
