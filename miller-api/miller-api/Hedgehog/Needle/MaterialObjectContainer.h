#pragma once

namespace hh::needle {
    class MaterialObjectContainer : public NeedleRefcountObject {
    public:
        class MaterialObject : public NeedleRefcountObject {
        public:
            class Unk1 : public NeedleRefcountObject {
            public:
                char unk1[168];
                csl::ut::MoveArray<CNameIDObject*> textureParameterNames;
                csl::ut::MoveArray<CNameIDObject*> samplerParameterNames;
                csl::ut::MoveArray<CNameIDObject*> boolParameterNames;
                csl::ut::MoveArray<CNameIDObject*> uintParameterNames;
                csl::ut::MoveArray<CNameIDObject*> floatParameterNames;

                csl::ut::MoveArray<Texture*> textureParameters;
                csl::ut::MoveArray<SamplerStateSetting*> samplerParameters;
                csl::ut::MoveArray<bool*> boolParameters;
                csl::ut::MoveArray<uint_vector4*> uintParameters;
                csl::ut::MoveArray<float_vector4*> floatParameters;

                Unk1();
            };

            template<typename T>
            struct ParameterContainer {
                bool unk1;
                csl::ut::MoveArray<T> parameters;
                csl::ut::PointerMap<CNameIDObject*, unsigned int> parameterIndicesByName;
            };

            template<typename T>
            struct SingleParameterContainer : ParameterContainer<T> {
                void SetParameter(CNameIDObject* name, T value);
            };

            template<typename T>
            struct ArrayParameterContainer : ParameterContainer<InstanceParameterContainerData::ArrayParamData<T>> {
                void SetParameter(CNameIDObject* name, const T* value);
                void SetParameter(CNameIDObject* name, const T* value, unsigned int count);
            };

            csl::fnd::IAllocator* allocator;
            intrusive_ptr<RenderingDevice> renderingDevice;
            intrusive_ptr<VertexShader> vertexShader;
            intrusive_ptr<PixelShader> pixelShader;
            intrusive_ptr<ComputeShader> computeShader; // tt
            intrusive_ptr<ShaderObject> shaderObject;
            intrusive_ptr<ParameterValueObject> vertexShaderParameters;
            intrusive_ptr<ParameterValueObject> pixelShaderParameters;
            SingleParameterContainer<Texture*> textureParameters;
            SingleParameterContainer<SamplerStateSetting> samplerParameters;
            SingleParameterContainer<bool> boolParameters;
            ArrayParameterContainer<uint_vector4> uintParameters;
            ArrayParameterContainer<float_vector4> floatParameters;
            intrusive_ptr<Unk1> unk7;
            uint64_t unk8;
            uint8_t unk9;
            uint8_t unk10;
            uint8_t unk11a;

            MaterialObject(csl::fnd::IAllocator* allocator, RenderingDevice* renderingDevice);
        };

        struct ShaderInfo {
            void* data;
            unsigned int size;
        };

        intrusive_ptr<MaterialObject> implementation;

        MaterialObjectContainer();
        MaterialObject* LoadVertexPixelShader(SupportFX* supportFX, const ShaderInfo& vertexShader, const ShaderInfo& pixelShader);
        MaterialObject* LoadComputeShader(SupportFX* supportFX, const ShaderInfo& computeShader);
        
        void SetShaderParameterBool(CNameIDObject* name, bool value);
        void SetShaderParameterUint(CNameIDObject* name, const uint_vector4* value);
        void SetShaderParameterUint(CNameIDObject* name, const uint_vector4* value, unsigned int count);
        void SetShaderParameterFloat(CNameIDObject* name, const float_vector4* value);
        void SetShaderParameterFloat(CNameIDObject* name, const float_vector4* value, unsigned int count);
        void SetTexture(CNameIDObject* name, Texture* texture);
        void SetSampler(CNameIDObject* name, const SamplerStateSetting* samplerStateSetting);
    };
}
