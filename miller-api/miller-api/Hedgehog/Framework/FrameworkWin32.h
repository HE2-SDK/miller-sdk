#pragma once

namespace hh::fw {
    class FrameworkFrameListener {
    public:
        virtual ~FrameworkFrameListener() = default;
        virtual void FFL_UnkFunc1() {}
        virtual void FFL_UnkFunc2() {}
        virtual void FFL_UnkFunc3() {}
        virtual void FFL_UnkFunc4() {}
    };

    class FrameworkNotificationListener {
    public:
        virtual ~FrameworkNotificationListener() = default;
        virtual void FNL_UnkFunc1() {}
        virtual void FNL_UnkFunc2() {}
        virtual void FNL_UnkFunc3() {}
        virtual void FNL_UnkFunc4() {}
        virtual void FNL_UnkFunc5() {}
        virtual void FNL_UnkFunc6() {}
        virtual void FNL_UnkFunc7() {}
    };

    class FrameworkWin32 : public BaseFramework, public FrameworkFrameListener, FrameworkNotificationListener {
        uint16_t unk101;
        uint64_t unk102;
    public:
        FrameworkWin32(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc2(const FrameworkConfig& config, FrameworkOptions* options) override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4(FrameworkEnvironment& frameworkEnvironment) override;
        virtual uint64_t UnkFunc5() override;
        virtual void FFL_UnkFunc1() override;
        virtual void FNL_UnkFunc3() override;
    };
}
