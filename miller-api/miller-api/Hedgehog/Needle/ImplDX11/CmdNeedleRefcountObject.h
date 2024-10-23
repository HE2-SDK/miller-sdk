#pragma once

namespace hh::needle::ImplDX11 {
    class CmdNeedleRefcountObject : public RenderingCommandList {
    public:
        ID3D11CommandList* nativeCommandList;
    };
}
