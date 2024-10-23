#pragma once

namespace hh::needle::ImplDX11 {
    struct SVSTypeDX11 {};
    struct SPSTypeDX11 {};
    struct SCSTypeDX11 {};
    union ShaderPtr {
        ID3D11VertexShader* vertexShader;
        ID3D11PixelShader* pixelShader;
        ID3D11ComputeShader* computeShader;
    };
}
