#pragma once

namespace hh::fw {
    class Application;

    class BaseFramework {
        fnd::Reference<Application> application;
        FrameworkConfig config;
        csl::ut::InplaceMoveArray<void*, 10> unk5;
        csl::ut::InplaceMoveArray<void*, 10> unk6;
        bool (*unk7)(void* unkParam1, int unkParam2, void* unkParam3);
        bool unk8;
    public:
        BaseFramework(csl::fnd::IAllocator* allocator);
        virtual ~BaseFramework() = default;
        virtual void UnkFunc1() {}
        virtual void UnkFunc2(const FrameworkConfig& config, FrameworkOptions* options) {}
        virtual void UnkFunc3() {}
        virtual uint64_t UnkFunc4(FrameworkEnvironment& frameworkEnvironment) = 0;
        virtual uint64_t UnkFunc5() = 0;
        unsigned int Main(const FrameworkConfig& config, FrameworkOptions* options);
    };
}
