#pragma once

namespace hh::needle {
    struct ShaderObjectCreationInfo {
        struct ShaderObjectCreationParameterInfo {
            ComputeShader* computeShader;
            InstanceParameterContainerData* vertexShaderParameterValues; // tt
            InstanceParameterContainerData* pixelShaderParameterValues; // tt
            InstanceParameterContainerData* instanceParameterContainers[4];
            unsigned int instanceParameterContainerSizes[4]; //tt, maybe container type
            unsigned int instanceParameterContainerCount;
            // uint32_t unk9; // no reference seen yet, possibly padding.
        };
        VertexLayout* vertexLayout;
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ShaderObjectCreationParameterInfo parameterInfo;
    };

    class ShaderObject : public NeedleRefcountResource {
    public:
    };
}
