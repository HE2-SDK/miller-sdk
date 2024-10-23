#pragma once

namespace hh::needle::ImplDX11 {
    struct SParameterQueue {
        enum class ParameterType : uint8_t {
            BOOL,
            INT,
            FLOAT,
            TEXTURE,
            SAMPLER,
            CONSTANT_BUFFER,
        };

        struct SBoolParameterValue {
            uint32_t value;
        };

        struct SIntParameterValue {
            uint_vector4* pValue;
            uint32_t count;
            uint_vector4 values[1];
        };

        struct SFloatParameterValue {
            float_vector4* pValue;
            uint32_t count;
            float_vector4 values[1];
        };

        struct STextureParameterValue {
            Texture2DView* texture;
        };

        struct SSamplerParameterValue {
            void* sampler;
        };

        struct SConstantBufferParameterValue {
            ConstantBuffer* buffer;
        };

        union SParameterValue {
            SBoolParameterValue boolValue;
            SIntParameterValue intValue;
            SFloatParameterValue floatValue;
            STextureParameterValue textureValue;
            SSamplerParameterValue samplerValue;
            SConstantBufferParameterValue constantBufferValue;
        };

        struct SParameterQueueEntry {
            CNameIDObject* name;
            SParameterValue value;
        };

        // parameter data grows from the bottom starting with SHeader and then the data
        // uint32_t values with metadata data grow from the top, they are laid out as follows:
        // - 3 lower bytes (& 0x00FFFFFF): data size
        // - most significant byte (& 0xFF000000): ParameterType
        uint8_t buffer[0x3800];
        size_t dataSize;
        uint32_t parameterCount;
    };
}
