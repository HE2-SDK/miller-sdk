#pragma once

namespace hh::needle::ImplDX11 {
    struct SResourceInfo {
        char unk1[36];
        unsigned int numSamples;
        unsigned int subResource;
        ID3D11Resource* resource;

        SResourceInfo(Texture2DView* texture2DView, unsigned int samples);
        SResourceInfo(RenderTargetView* renderTargetView, unsigned int samples);
        SResourceInfo(DepthStencilView* renderTargetView, unsigned int samples);
    };
}