#pragma once

namespace hh::gfnd {
    class GraphicsGeometryNeedle : public GraphicsGeometry {
        static GraphicsGeometryNeedle* MyCreate(void* unused, csl::fnd::IAllocator* allocator);
    public:
        GraphicsGeometryNeedle(csl::fnd::IAllocator* allocator);
        virtual bool Initialize(DrawContext* drawContext, const fnd::Geometry& geometry);
        virtual bool InitializeEdge(DrawContext* drawContext, const fnd::Geometry& geometry);
        virtual bool InitializeWire(DrawContext* drawContext, const fnd::WireGeometry& geometry);
        virtual bool InitializeByCopying(DrawContext* drawContext, const GraphicsGeometry* geometry);
        virtual int64_t SetColor(const csl::ut::Color8& color);
        virtual int64_t Render(DrawContext* drawContext, const csl::math::Matrix34& transform);
    };
}
