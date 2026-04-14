#pragma once

namespace Cyan::Graphics {
    class ExternalMeshRenderer : public Renderer {
    public:
        ExternalMeshRenderer(ManagerImpl* managerImpl);
        
        virtual void Initialize(const DeviceContainer& deviceContainer);
        virtual void* UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(void* unkParam1);
        virtual void UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc7(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc8(void* unkParam1, void* unkParam2, void* unkParam3, void* unkParam4);
    };
}