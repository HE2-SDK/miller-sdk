#pragma once

namespace hh::needle::ImplDX11 {
    struct SResourceContext {
        ShaderPtr shader;
        ID3D11Buffer* constantBuffers[14];
        void* shaderResourceViews[14];
        uint64_t data[18];
        uint32_t samplerDirtyBits;
        uint32_t shaderResourceViewsInUseBits;
        uint32_t constantBufferDirtyBits;
    };
}