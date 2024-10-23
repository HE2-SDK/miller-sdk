#pragma once

namespace hh::needle::ImplDX11 {
    class DeviceObjectDX11;
    class RenderingDeviceContextDX11;
    class RenderingDeviceDispatchDX11Impl : public NeedleRefcountObject {
    public:
        struct Unk1 {
            uint64_t unk1;
            int unk2;
            uint32_t unk3;
        };
        struct Unk3 {
            uint64_t unk1[2][7];
            uint32_t count;
        };
        struct Unk5 {
            uint64_t unk1;
            uint64_t unk2;

            Unk5();
        };
        struct Unk4 {
            uint32_t flags;
            char unk2[60];
            RsFlagMask rsFlagMask;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            uint64_t unk7;
            uint32_t unk8;
            uint32_t unk9;
            int64_t unk10;
            uint64_t unk11;
            uint32_t unk12;
            int unk13;
            uint32_t unk14;
            int unk15;
            int unk16;
            uint32_t unk17;
            uint32_t unk18;
            uint32_t unk19;
            int unk20;
            int unk21;

            Unk4();
        };

        struct Unk2 {
            DeviceObjectDX11* deviceObject;
            SParameterBuffer* parameterBuffer;
            ID3D11InputLayout* inputLayout;
            SResourceContext resourceContexts[3];
            SShaderContext shaderContext;
            StatusCacheOneStage flushParameterContexts[3];
            Unk4 unk3;
            uint32_t qword7AC;
            uint32_t qword7B0;
            Unk3 qword7B8;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            InstanceParameterContainerData ipcd;
            RenderTargetsSetting renderTargetsSetting;
            ViewportSetting viewports[8];
            uint32_t viewportCount;
            Rectangle scissors[8];
            uint32_t scissorCount;

            Unk2();

            void Setup();
            void InvalidateStatus();
            void FlushVertexShaderStage(ID3D11DeviceContext* deviceContext);
            void FlushPixelShaderStage(ID3D11DeviceContext* deviceContext);
            void FlushComputeShaderStage(ID3D11DeviceContext* deviceContext);
        };

        ID3D11DeviceContext* deviceContext;
        Unk1 unk1;
        uint64_t* unk28;
        Unk2 unk2;
        uint64_t qword738;
        uint64_t qword740;
        uint64_t qword748;
        uint64_t qword750;
        uint64_t qword758;
        uint64_t qword760;
        uint64_t qword768;
        char gap770[276];
        unsigned int vertexCount; 
        char gap770a[792];
        uint64_t qwordBA0;
        uint32_t dwordBA8;
    };
}
