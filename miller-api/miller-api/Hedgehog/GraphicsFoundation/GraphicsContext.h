#pragma once

namespace hh::gfnd {
    class GraphicsContext : public fnd::BaseObject {
    public:
        csl::ut::MoveArray<fnd::Reference<RenderableContainer>> renderableContainers;
        csl::ut::MoveArray<ViewportData> viewportDatas;
        csl::fnd::IAllocator* allocator1;
        void* unk4;
        hh::needle::ImplDX11::RenderingDeviceDX11* renderingDevice;
        ViewportData defaultViewportData;
        uint64_t unk7;
        uint64_t unk8;
        int unk9;
        csl::fnd::Mutex mutex;
        int64_t unk10;
        int64_t unk11;
        GraphicsContext(csl::fnd::IAllocator* pAllocator);
        static GraphicsContext* instance;

        inline static GraphicsContext* GetInstance() {
            return RESOLVE_STATIC_VARIABLE(instance);
        }

        void AddRenderable(Renderable* renderable);
        void AddRenderableToViewport(Renderable* renderable, int viewportId);
        ViewportData& GetViewportData(int viewportId);
        static ViewportData& GetViewportData(void* unkParam, int viewportId);
    };
}
