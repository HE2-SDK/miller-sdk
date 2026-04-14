#pragma once

namespace Cyan{
    class Manager;

    class EmissionGpuBase {
    public:
        Manager* mgr;
        hh::needle::ImplDX11::ShaderMaterialContainerDX11Impl* shaderMatContainer;

        virtual ~EmissionGpuBase();
        virtual int64_t UnkFunc0() {};
        virtual int64_t UnkFunc1() {};
        virtual int64_t UnkFunc2() {};
    };

    class EmissionGpuPrimitive : public EmissionGpuBase {
    public:
        const char* shaderName;

        virtual int64_t UnkFunc0() override;
        virtual int64_t UnkFunc2() override;
        virtual int64_t UnkFunc3() {};

        EmissionGpuPrimitive(Manager* mgr, const char* shaderName);
    };
}
