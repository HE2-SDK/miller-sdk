#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class RenderTextureHandle;
    class RenderTexturePipeline : public WorldRenderingPipeline {
    public:
        RenderTextureHandle* renderTextureHandle;

        RenderTexturePipeline(csl::fnd::IAllocator* allocator, PBRModelInstanceRenderer* modelRenderer, RenderTextureHandle* renderTextureHandle);

        virtual uint64_t UnkFunc11();
    };
}