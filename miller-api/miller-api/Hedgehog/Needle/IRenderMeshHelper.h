#pragma once

namespace hh::needle {
    class IRenderMeshHelper {
    public:
        virtual void UnkFunc1(RenderingDeviceContext* renderingDeviceContext, void* unkParam2) = 0;
        virtual ~IRenderMeshHelper();
        virtual void SetDrawPassIndex(const DrawPassIdToIndexMap* drawPassIdToIndexMap, unsigned int drawPassId) = 0;
        virtual void UnkFunc3(RenderingDeviceContext* renderingDeviceContext, void* unkParam2) = 0;
    };
}