#pragma once

namespace hh::needle {
    class SupportFX;
    class RenderManager : public NeedleRefcountObject {
    public:
        RenderingDeviceContext* renderingDeviceContext;
        RenderTargetManager* renderTargetManager;
        RenderProperty* renderProperty;
        SupportFX* supportFX;
        intrusive_ptr<NeedleResContainer> resourceContainer;
        float worldScale;

        RenderManager(unsigned int resX, unsigned int resY, unsigned int renderResX, unsigned int renderResY, csl::fnd::IAllocator* allocator);

        void Initialize(RenderingDevice* renderingDevice, RenderingDeviceContext* renderingDeviceContext);
        void InitializeMainRenderTarget(RenderingDevice* renderingDevice, unsigned int resX, unsigned int resY, unsigned int renderResX, unsigned int renderResY);
    };
}
