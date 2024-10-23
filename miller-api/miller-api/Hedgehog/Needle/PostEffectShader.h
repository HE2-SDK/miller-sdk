#pragma once

namespace hh::needle {
    class PostEffectShader : public NeedleRefcountObject {
    public:
        ShaderObject* shaderObject;
        ParameterValueObject* parameters1;
        ParameterValueObject* parameters2;
        ParameterValueObject* parameters3;
        uint32_t unk5;

        PostEffectShader();
        virtual ~PostEffectShader();

        void Setup(RenderingDevice* renderingDevice, VertexShader* vertexShader, PixelShader* pixelShader, InstanceParameterContainerData parameters1, InstanceParameterContainerData parameters2, InstanceParameterContainerData parameters3);
    };
}
