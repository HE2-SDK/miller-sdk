#pragma once

namespace app::fnd {
    struct AppMemoryParam {
        size_t residentHeapSize;
        size_t cyloopHeapSize;
        size_t heightfieldHeapSize;
        size_t needleHeapSize;
    };

    class AppHeapManager : public hh::fnd::BaseObject, public csl::fnd::Singleton<AppHeapManager> {
    public:
        hh::fnd::ThreadSafeTlsfHeapAllocator residentAllocator;
        hh::fnd::ThreadSafeTlsfHeapAllocator cyloopAllocator;
        hh::fnd::ThreadSafeTlsfHeapAllocator heightfieldAllocator;
        hh::fnd::ThreadSafeTlsfHeapAllocator* needleAllocator;

        AppHeapManager(csl::fnd::IAllocator* memoryRouterAllocator, const AppMemoryParam* appMemoryParams);
        static csl::fnd::IAllocator* GetResidentAllocator();
    };
}
