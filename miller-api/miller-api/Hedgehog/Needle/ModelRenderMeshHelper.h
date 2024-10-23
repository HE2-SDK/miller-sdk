#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class ModelRenderMeshHelper : public IRenderMeshHelper {
    public:
        GatherRenderingPassContext* gatherRenderingPassContext;
        uint32_t unk2;
        uint32_t viewportId;
        uint32_t drawPassIndex;
        int unk3a;
        PBRModelInstanceRenderer* modelInstanceRenderer;
        uint32_t unk5;
        uint32_t unk6;
        uint64_t unk7;

        ModelRenderMeshHelper();

        virtual void UnkFunc1(RenderingDeviceContext* renderingDeviceContext, void* unkParam2) override;
        virtual ~ModelRenderMeshHelper();
        virtual void SetDrawPassIndex(const DrawPassIdToIndexMap* drawPassIdToIndexMap, unsigned int drawPassId) override;
        virtual void UnkFunc3(RenderingDeviceContext* renderingDeviceContext, void* unkParam2) override;
    };
}
