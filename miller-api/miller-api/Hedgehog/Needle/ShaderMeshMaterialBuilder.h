#pragma once

namespace hh::needle {
    template<typename T>
    class NeedleArray {
    public:
        T* buffer;
        size_t length;
        size_t capacity;
        bool initialized;
    };

    class ShaderMaterialStatusSetting {
    public:
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ComputeShader* computeShader;
        uint16_t* unk2;
        unsigned int someCount;
        unsigned int unk3;
        void* vertexShaderSettings;
        void* pixelShaderSettings;
        void* computeShaderSettings;
    };

    class VertexLayout;
    class ShaderMeshMaterialBuilder {
    public:
        struct SLayoutMaterial {
            VertexLayout* vertexLayouts[32];
            unsigned int vertexLayoutCount;
            ShaderMaterialStatusSetting* statusSetting;
        };

        NeedleArray<SLayoutMaterial> layoutMaterials;
        uint64_t unk2;

        ShaderMeshMaterialBuilder();
        ~ShaderMeshMaterialBuilder();
        void Add(VertexLayout* vertexLayout, const ShaderMaterialStatusSetting& shaderMaterialStatusSetting);
    };
}
