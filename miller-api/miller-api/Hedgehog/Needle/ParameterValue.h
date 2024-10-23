#pragma once

namespace hh::needle {
    struct ShaderResourceSetting {
        uint64_t unk1;
        uint_vector4 unk2; // not sure about type
    };

    struct TechniqueInfo {
        char data[864];
    };

    enum class ParameterType : uint8_t {
        FLOAT = 0,
        BOOL = 1,
        INT = 2,
        SHADER = 3,
        EFFECT = 4,
        TEXTURE = 5,
        SAMPLER = 6,
        RS_FLAG_MASK = 7,
        SHADER_NAME = 8,
        TEXTURE_NAME = 9,
        HINT = 10,
    };

    struct ParameterFloatValue {
        intrusive_ptr<CNameIDObject> name;
        float_vector4 values;
    };

    struct ParameterBoolValue {
        intrusive_ptr<CNameIDObject> name;
        unsigned int value;
    };

    struct ParameterIntValue {
        intrusive_ptr<CNameIDObject> name;
        uint_vector4 uintVector;
    };

    struct ParameterShaderValue {
        intrusive_ptr<CNameIDObject> name;
        ShaderResourceSetting shaderResourceSetting;
    };

    struct ParameterEffectValue {
        TechniqueInfo techniqueInfo;
    };

    class Texture;
    struct ParameterTextureValue {
        intrusive_ptr<CNameIDObject> type;
        intrusive_ptr<CNameIDObject> name;
        Texture* texture;
    };

    struct ParameterSamplerValue {
        intrusive_ptr<CNameIDObject> name;
        intrusive_ptr<CNameIDObject> texCoordIndexName;
        intrusive_ptr<CNameIDObject> texCoordMtxName;
        TextureWrapMode wrapModeU;
        TextureWrapMode wrapModeV;
        uint8_t texCoordIndex;
        uint8_t builderUnk10;
        uint32_t builderUnk11;
    };

    struct ParameterShaderNameValue {
        intrusive_ptr<CNameIDObject> name;
    };

    struct ParameterTextureNameValue {
        intrusive_ptr<CNameIDObject> type;
        intrusive_ptr<CNameIDObject> name;
    };

    struct ParameterRsFlagMaskValue {
        uint32_t unk1;
        RsFlagMask rsFlagMask;
    };

    union ParameterHintData {
        intrusive_ptr<CNameIDObject> name;
        uint_vector4 uintVector;
    };

    struct ParameterHintValue {
        void* type;
        intrusive_ptr<CNameIDObject> name;
        ParameterHintData data;
        unsigned int unk1;
    };

    union ParameterValue {
        ParameterFloatValue floatValue;
        ParameterBoolValue boolValue;
        ParameterIntValue intValue;
        ParameterShaderValue shaderValue;
        ParameterEffectValue effectValue;
        ParameterTextureValue textureValue;
        ParameterSamplerValue samplerValue;
        ParameterShaderNameValue shaderNameValue;
        ParameterTextureNameValue textureNameValue;
        ParameterRsFlagMaskValue rsFlagMaskValue;
        ParameterHintValue hintValue;
    };
}