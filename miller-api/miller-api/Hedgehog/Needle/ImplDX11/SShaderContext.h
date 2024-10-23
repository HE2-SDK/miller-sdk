#pragma once

namespace hh::needle::ImplDX11 {
    struct SShaderContext {
        ShaderMaterialContainerObjectDX11Impl* materialContainerObject;
        uint64_t unk2a[4];
        InstanceParametersBuildParameter instanceParametersBuildParameter;
        uint64_t unk2b[3];
        uint32_t materialIndex;
    };
}