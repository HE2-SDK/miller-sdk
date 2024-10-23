#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class DevicUniqueObjectContainerDX11 : public NeedleRefcountObject {
        public:
            ID3D11Device* d3dDevice;
        };
    }
}