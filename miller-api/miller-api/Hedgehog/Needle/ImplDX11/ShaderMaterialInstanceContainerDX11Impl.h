#pragma once

namespace hh::needle::ImplDX11 {
    class ShaderMaterialInstanceContainerDX11Impl : public ShaderMaterialInstanceContainer {
    public:
    };

    typedef NeedleObjectWithParameterBuffer<ShaderMaterialInstanceContainerDX11Impl> ShaderMaterialInstanceContainer;
}

