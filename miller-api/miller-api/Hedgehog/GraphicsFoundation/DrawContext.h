#pragma once

namespace hh::gfnd {
    enum class PrimitiveType {
        POINT_LIST,
        LINE_LIST,
        TRIANGLE_LIST,
        TRIANGLE_STRIP,
    };

    struct DrawVertex {
        float x;
        float y;
        float z;
        uint32_t color;
    };

    class DrawContext {
        uint32_t unk1;
        csl::fnd::IAllocator* allocator;
    public:
        struct Unk2 {
            char unk1[416];
            needle::CScratchMemoryContext* debugDrawMemCtx;
            Unk2(needle::CScratchMemoryContext* memCtx) : debugDrawMemCtx{ memCtx } {}
        };
        struct Unk3 {
            char unk1[152];
            Unk2* unk2;
            Unk3(Unk2* unk2) : unk2{ unk2 } {}
        };

        struct BeginDrawInfo {
            uint32_t unk1;
            float viewMatrix[16];
            float projMatrix[16];
        };

        virtual ~DrawContext() = default;
        virtual int64_t Destroy() = 0;
        virtual void BeginScene(const RenderableParameter* renderableParameter) = 0;
        virtual int64_t EndScene() = 0;
        virtual void BeginDraw(const BeginDrawInfo& beginDrawInfo) = 0;
        virtual int64_t EndDraw() = 0;
        virtual int64_t BeginDraw2d() = 0;
        virtual int64_t EndDraw2d() = 0;
        virtual int64_t UnkFunc8() = 0;
        virtual int64_t DrawPrimitive(PrimitiveType primitiveType, const DrawVertex* vertices, const unsigned short* indices, unsigned int count) = 0;
        virtual int64_t DrawSphere(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawCapsule(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawAABB(const csl::math::Vector3& minPos, const csl::math::Vector3& maxPos, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawOBB(const csl::math::Matrix34& transform, const csl::math::Vector3& halfExtents, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawCylinder(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawCircle(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) = 0;
        virtual int64_t DrawPlane(const csl::math::Matrix34& transform, float width, float height, const csl::ut::Color8& color) = 0;
        virtual void SetWireframeMode() = 0;
        virtual int64_t SetZTestEnable(bool enabled) = 0;
        virtual int64_t SetZWriteEnable(bool enabled) = 0;
        virtual int64_t SetCullingMode(unsigned int idx) = 0;
        virtual int64_t SetUnk2(int a2, int a3, unsigned int* a4) = 0;
    };
}
