#pragma once

namespace hh::needle {
    class PrimitiveRenderer : public NeedleRefcountObject {
        // RenderingDeviceContext* renderingDeviceContext;
        ShaderObject* simpleShaderObject;
        ShaderObject* textureShaderObject;
        uint64_t unk1;
        uint64_t unk2;
        Buffer* indexBuffer;
        uint32_t dword30;
        uint32_t dword34;
        uint32_t dword38;
        uint32_t dword3C;
        uint32_t dword40;
        uint32_t dword44;
        uint32_t dword48;
        uint32_t dword4C;
        uint32_t dword50;
        uint32_t dword54;
        uint32_t dword58;
        uint32_t dword5C;
        uint32_t dword60;
        uint32_t dword64;
        uint32_t dword68;
        uint32_t dword6C;
        uint32_t dword70;
        uint32_t dword74;
        uint32_t dword78;
        uint32_t dword7C;
        uint32_t dword80;
        uint32_t dword84;
        uint32_t dword88;
        uint32_t dword8C;
        uint32_t dword90;
        uint32_t dword94;
        uint32_t dword98;
        uint32_t dword9C;
        uint32_t dwordA0;
        uint32_t dwordA4;
        uint32_t dwordA8;
        uint32_t dwordAC;
        uint32_t dwordB0;

    public:
        typedef csl::math::Vector4 Vertex;
    
    public:
        PrimitiveRenderer(RenderingDevice* renderingDevice);
        void Begin(void* unkParam1, const float* unkParam2, const float* unkParam3);
        void DrawVertices(PrimitiveTopology topology, const float* unkParam1, unsigned int indexCount, unsigned int vertexCount, const unsigned short* indices, const Vertex* vertices, unsigned int unkParam5);
        void SetMaterial(int unkParam);
    };
}
