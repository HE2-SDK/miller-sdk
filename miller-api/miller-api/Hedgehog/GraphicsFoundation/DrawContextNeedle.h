#pragma once

namespace hh::gfnd {
    class DrawContextNeedle : public DrawContext {
    public:
        struct Unk1 {
            float unk1;
            float unk2;
            float unk3;
            float unk4;
            float unk5;
            float unk6;
            float unk7;
            float unk8;
            float unk9;
        };
    private:
        needle::PrimitiveRenderer* primitiveRenderer1;
        needle::RenderingDeviceContext* renderingDeviceContext;
        uint16_t unk3;
        Unk1 unk4[1];
        csl::math::Vector4 unk5;
        uint8_t unk6[944];
        needle::PrimitiveRenderer* primitiveRenderer;

        static DrawContextNeedle* MyCreate(csl::fnd::IAllocator* allocator, Unk3* unkParam);
    public:
        DrawContextNeedle(csl::fnd::IAllocator* allocator);
        virtual int64_t Destroy() override;
        virtual void BeginScene(const RenderableParameter* renderableParameter) override;
        virtual int64_t EndScene() override;
        virtual void BeginDraw(const BeginDrawInfo& beginDrawInfo) override;
        virtual int64_t EndDraw() override;
        virtual int64_t BeginDraw2d() override;
        virtual int64_t EndDraw2d() override;
        virtual int64_t UnkFunc8() override;
        virtual int64_t DrawPrimitive(PrimitiveType primitiveType, const DrawVertex* vertices, const unsigned short* indices, unsigned int count) override;
        virtual int64_t DrawSphere(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) override;
        virtual int64_t DrawCapsule(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color) override;
        virtual int64_t DrawAABB(const csl::math::Vector3& minPos, const csl::math::Vector3& maxPos, const csl::ut::Color8& color) override;
        virtual int64_t DrawOBB(const csl::math::Matrix34& transform, const csl::math::Vector3& halfExtents, const csl::ut::Color8& color) override;
        virtual int64_t DrawCylinder(const csl::math::Matrix34& transform, float radius, float halfHeight, const csl::ut::Color8& color) override;
        virtual int64_t DrawCircle(const csl::math::Matrix34& transform, float radius, const csl::ut::Color8& color) override;
        virtual int64_t DrawPlane(const csl::math::Matrix34& transform, float width, float height, const csl::ut::Color8& color) override;
        virtual void SetWireframeMode() override {}
        virtual int64_t SetZTestEnable(bool enabled) override;
        virtual int64_t SetZWriteEnable(bool enabled) override;
        virtual int64_t SetCullingMode(unsigned int idx) override;
        virtual int64_t SetUnk2(int a2, int a3, unsigned int* a4) override;
        void DrawOval(const csl::math::Matrix34& transform, float r1, float r2, const csl::ut::Color8& color);
        void NeedleDrawPrimitive(const csl::math::Matrix34& transform, const csl::ut::Color8& color, int primitiveType);
    };
}
