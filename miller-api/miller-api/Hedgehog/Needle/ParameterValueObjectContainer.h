#pragma once

namespace hh::needle {
    struct ParameterValueObjectContainer {
    public:
        InstanceParameterContainerData ipcd;
        uint32_t unk4;
        void* memorySpan2;
        uint32_t flagsAlways1; // 0x1 does something when parameters are loaded
        uint32_t someMemorySize; // check ctor

        void SetShaderParameterBool(unsigned int index, bool value);
        bool SetShaderParameterBoolByName(CNameIDObject* name, bool value);
        bool SetShaderParameterBoolByName(const char* name, bool value);
        void SetShaderParameterUint(unsigned int index, const unsigned int* value, unsigned int size);
        bool SetShaderParameterUintByName(CNameIDObject* name, const unsigned int* value, unsigned int size);
        bool SetShaderParameterUintByName(const char* name, const unsigned int* value, unsigned int size);
        void SetShaderParameterFloat(unsigned int index, const float* value, unsigned int size);
        bool SetShaderParameterFloatByName(CNameIDObject* name, const float* value, unsigned int size);
        bool SetShaderParameterFloatByName(const char* name, const float* value, unsigned int size);
        void SetShaderParameterFloat(unsigned int index, unsigned int offset, const float* value, unsigned int size);
        bool SetShaderParameterFloatByName(CNameIDObject* name, unsigned int offset, const float* value, unsigned int size);
        bool SetShaderParameterFloatByName(const char* name, unsigned int offset, const float* value, unsigned int size);
        unsigned int GetShaderParameterFloatCount() const;
        unsigned int GetShaderParameterFloatIndex(CNameIDObject* name) const;
        unsigned int GetShaderParameterFloatIndex(const char* name) const;
        void SetTexture(unsigned int index, Texture* texture);
        bool SetTextureByName(CNameIDObject* name, Texture* texture);
        bool SetTextureByName(const char* name, Texture* texture);
        void SetTextureSampler(unsigned int index, Texture* texture, const SamplerStateSetting* samplerStateSetting);
        bool SetTextureSamplerByName(CNameIDObject* name, Texture* texture, const SamplerStateSetting* samplerStateSetting);
        bool SetTextureSamplerByName(const char* name, Texture* texture, const SamplerStateSetting* samplerStateSetting);
        void SetSampler(unsigned int index, const SamplerStateSetting* samplerStateSetting);
        bool SetSamplerByName(CNameIDObject* name, const SamplerStateSetting* samplerStateSetting);
        bool SetSamplerByName(const char* name, const SamplerStateSetting* samplerStateSetting);
        void SetConstantBuffer(unsigned int index, ConstantBuffer* buffer);
        bool SetConstantBufferByName(CNameIDObject* name, ConstantBuffer* buffer);
        bool SetConstantBufferByName(const char* name, ConstantBuffer* buffer);
        static size_t Measure(const InstanceParameterContainerData& instanceParameterContainerData, void* unkParam);
    };
}
