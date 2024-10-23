#pragma once

namespace hh::fnd {
    class MemoryRouterAllocator : public csl::fnd::IAllocator {
    public:
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex>* heap;
        uint64_t unk1;
    };

    class MemoryRouter;

    // csl::fnd::IAllocator* tempAllocator;

    // Temp allocator size is 0x40000 and works on stack.
    void InitializeTempAllocator(MemoryRouter* router, size_t size);
    csl::fnd::IAllocator* GetTempAllocator();

    class MemoryRouter {
    public:
        MemoryRouterAllocator* moduleAllocator;
        MemoryRouterAllocator* debugAllocator;
        static MemoryRouter* instance;
        static MemoryRouter* GetInstance();
        static void SetInstance(MemoryRouter* router);
        inline csl::fnd::IAllocator* GetTemp() { return fnd::GetTempAllocator(); }
        inline csl::fnd::IAllocator* GetModule() { return moduleAllocator; }
        inline csl::fnd::IAllocator* GetDebug() { return debugAllocator; }
        static csl::fnd::IAllocator* GetTempAllocator();
        inline static csl::fnd::IAllocator* GetModuleAllocator() { return GetInstance()->GetModule(); }
        inline static csl::fnd::IAllocator* GetDebugAllocator() { return GetInstance()->GetDebug(); }
    };
}

void* AllocateObjectGlobalMemory(size_t size);
void FreeObjectGlobalMemory(void* ptr);
