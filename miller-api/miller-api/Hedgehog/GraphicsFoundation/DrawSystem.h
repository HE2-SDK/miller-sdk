#pragma once

namespace hh::gfnd {
    class DrawSystem {
    public:
        static DrawContext* (*CreateDrawContext)(csl::fnd::IAllocator* allocator, hh::gfnd::DrawContext::Unk3* drawCtxConfig);
        static GraphicsGeometry* (*CreateGraphicsGeometry)(void* unused, csl::fnd::IAllocator* allocator);
        static SharedDebugDrawResource* (*CreateSharedDebugDrawResource)(csl::fnd::IAllocator* allocator);
    };
}
