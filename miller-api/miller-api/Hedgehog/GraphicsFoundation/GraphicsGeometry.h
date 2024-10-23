#pragma once

namespace hh::gfnd {
    class GraphicsGeometry : public fnd::ReferencedObject {
    public:
        enum class PrimitiveType : uint32_t {
            TRIANGLES,
            LINES,
        };
    private:
        csl::ut::MoveArray<csl::math::Vector4> vertices;
        csl::ut::MoveArray<unsigned short> indices;
        csl::ut::MoveArray<csl::math::Vector4> unk3;
        PrimitiveType primitiveType;
    public:
        virtual bool Initialize(DrawContext* drawContext, const fnd::Geometry& geometry) = 0;
        virtual bool InitializeEdge(DrawContext* drawContext, const fnd::Geometry& geometry) = 0;
        virtual bool InitializeWire(DrawContext* drawContext, const fnd::WireGeometry& geometry) = 0;
        virtual bool InitializeByCopying(DrawContext* drawContext, const GraphicsGeometry* geometry) = 0;
        virtual int64_t SetColor(const csl::ut::Color8& color) = 0;
        virtual int64_t Render(DrawContext* drawContext, const csl::math::Matrix34& transform) = 0;
    };
}
