#pragma once

namespace hh::needle {
    void* NeedleAllocateDefaultMemory(size_t size, unsigned int alignment);
    void NeedleFreeDefaultMemory(void* ptr);

    class NeedleObject {
    public:
        NeedleObject(csl::fnd::IAllocator* allocator);
        static void* AllocateObjectMemory(size_t size, size_t alignment);
        static void FreeObjectMemory(void* ptr);
		void* operator new(size_t count);
		void operator delete(void* ptr) noexcept;
    };
}
