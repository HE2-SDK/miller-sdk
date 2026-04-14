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

    struct ParameterValueFloat {
        intrusive_ptr<CNameIDObject> name;
        float_vector4 values;
    };

    struct ParameterValueBool {
        intrusive_ptr<CNameIDObject> name;
        unsigned int value;
    };

    struct ParameterValueInt {
        intrusive_ptr<CNameIDObject> name;
        uint_vector4 uintVector;
    };

    struct ParameterValueShader {
        intrusive_ptr<CNameIDObject> name;
        ShaderResourceSetting shaderResourceSetting;
    };

    struct ParameterValueEffect {
        TechniqueInfo techniqueInfo;
    };

    class Texture;
    struct ParameterValueTexture {
        intrusive_ptr<CNameIDObject> type;
        intrusive_ptr<CNameIDObject> name;
        Texture* texture;
    };

    struct ParameterValueSampler {
        intrusive_ptr<CNameIDObject> name;
        intrusive_ptr<CNameIDObject> texCoordIndexName;
        intrusive_ptr<CNameIDObject> texCoordMtxName;
        TextureWrapMode wrapModeU;
        TextureWrapMode wrapModeV;
        uint8_t texCoordIndex;
        uint8_t builderUnk10;
        uint32_t builderUnk11;
    };

    struct ParameterValueShaderName {
        intrusive_ptr<CNameIDObject> name;
    };

    struct ParameterValueTextureName {
        intrusive_ptr<CNameIDObject> type;
        intrusive_ptr<CNameIDObject> name;
    };

    struct ParameterValueRsFlagMask {
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
        ParameterValueFloat floatValue;
        ParameterValueBool boolValue;
        ParameterValueInt intValue;
        ParameterValueShader shaderValue;
        ParameterValueEffect effectValue;
        ParameterValueTexture textureValue;
        ParameterValueSampler samplerValue;
        ParameterValueShaderName shaderNameValue;
        ParameterValueTextureName textureNameValue;
        ParameterValueRsFlagMask rsFlagMaskValue;
        ParameterHintValue hintValue;
    };
}