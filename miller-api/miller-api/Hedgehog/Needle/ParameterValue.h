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
        FLOAT,
        BOOL,
        INT,
        SHADER,
        EFFECT,
        TEXTURE,
        SAMPLER,
        RS_FLAG_MASK_2,
        RS_FLAG_MASK,
        SHADER_NAME,
        TEXTURE_NAME ,
        HINT,
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
        intrusive_ptr<CNameIDObject> type;
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