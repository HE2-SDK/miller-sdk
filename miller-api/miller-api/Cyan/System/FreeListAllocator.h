#pragma once

namespace Cyan::System {
    class FreeListAllocator : public IAllocator {
    public:
        const char* name;
        void* mem;
        size_t size;
        csl::fnd::OptimizedFreeListHeapTemplate<csl::fnd::Mutex> heap;

        FreeListAllocator();

        virtual void* Alloc(size_t size) override;
        virtual void* Alloc(size_t size, const char* name, size_t alignment) override;
        virtual void Free(void* ptr) override;
        virtual void SetupMemory(void* ptr, size_t size) override;
        virtual void SetName(const char* name) override;
        virtual const char* GetName() const override;
        virtual void* AllocBottom(size_t size);
        virtual void* AllocBottom(size_t size, const char* name, size_t alignment);
        virtual ~FreeListAllocator();
    };
}
