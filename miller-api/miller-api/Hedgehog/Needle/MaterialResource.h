#pragma once

#define NEEDLE_RESOURCE_MATERIAL 0x303030303054414Dui64 // '00000TAM'

namespace hh::needle {
    struct TextureData {
        uint32_t texNameOffset;
        uint8_t texCoordIndex;
        TextureWrapMode wrapModeU;
        TextureWrapMode wrapModeV;
        uint8_t padding;
        uint32_t typeOffset;
    };

    template<typename T>
    struct MaterialParamData
    {
        struct Vec4 {
            T x;
            T y;
            T z;
            T w;
        };
        uint8_t flag1;
        uint8_t flag2;
        uint8_t valueCount;
        uint8_t flag3;
        uint32_t nameOffset;
        uint32_t valuesOffset;
    };

    struct MaterialData {
        enum class BlendMode : uint8_t {
            MODE_2_4_0,
            MODE_2_1_0,
            MODE_0_7_0,
            MODE_2_1_2,
        };

        uint32_t shaderNameOffset;
        uint32_t subShaderNameOffset;
        uint32_t textureEntryNamesOffset;
        uint32_t textureEntriesOffset;
        uint8_t alphaThreshold;
        bool noBackfaceCulling;
        BlendMode blendMode;
        uint8_t unknownFlag1;
        uint8_t float4ParamCount;
        uint8_t int4ParamCount;
        uint8_t bool4ParamCount;
        uint8_t textureEntryCount;
        uint32_t float4ParamsOffset;
        uint32_t int4ParamsOffset;
        uint32_t bool4ParamsOffset;
    };

    class MaterialResource;
    struct MaterialChunkBuilder {
        struct ParameterData {
            struct ParamMetadata {
                ParameterType type;
                uint8_t idx;
            };
            ParamMetadata metadatas[256];
            uint16_t dataSizes[256];
            uint16_t parameterValueOffsets[256];
        };

        struct ParameterInfo {
            uint8_t sizeInDwords;
            ParameterType type;
        };

        struct SamplerSetting {
            enum class TextureWrapMode : uint32_t
            {
                REPEAT = 0,
                MIRROR = 1,
                CLAMP = 2,
                MIRROR_ONCE = 3,
                BORDER = 4,
                UNK5 = 5,
                UNK6 = 6,
            };
            TextureWrapMode wrapModeU;
            TextureWrapMode wrapModeV;
            uint32_t texCoordIndex;
        };

        CScratchMemoryContext* memCtx;
        ParameterData parameters;
        intrusive_ptr<MaterialResource> materialResource;
        ParameterInfo* parameterInfos;
        void* parameterValues;
        uint32_t currentParameterIdx;
        uint32_t totalParameters;
        uint64_t currentDataSize;
        uint64_t totalDataSize;
        bool firstTraverse;
        RsFlagMask rsFlagMask;
        uint8_t unk10;
        uint32_t unk11;

        MaterialChunkBuilder(CScratchMemoryContext& memCtx);

        void SetParameterFloat(const char* name, float value);
        void SetParameterAlphaThreshold(float threshold);
        void SetParameterInt(const char* name, int value);
        void SetParameterBool(const char* name, bool value);
        void SetShader(CNameIDObject* name, const ShaderResourceSetting& shaderResourceSetting);
        void SetEffect(CNameIDObject* name, const TechniqueInfo* techniqueInfo);
        void SetTexture(CNameIDObject* type, CNameIDObject* name, Texture* texture);
        void SetSampler(const char* name, const SamplerSetting& samplerSetting);
        void SetRsFlagMask(const RsFlagMask& rsFlagMask);
        void SetShaderName(const char* name);
        void SetTexture(const char* type, const char* name);
        void SetParameterHintValue(const ParameterHintValue* value);
        void SetParameterHintValueUint(const void* nameType, CNameIDObject* name, const uint_vector4& data);

        void AfterTraverseSetupMemory(RenderingDevice* renderingDevice, MaterialResource* elementData);
        MaterialResource* Finish(bool recreate);
        static void Traverse(void* data, MaterialChunkBuilder& chunkBuilder);
        static void RegisterUniqueMaterialResource(MaterialResource** resource);
    };

    class MaterialResource : public TNeedleRefcountUniqueObjectBase<TNeedleRefcountResource<NEEDLE_RESOURCE_MATERIAL, NeedleRefcountResource>> {
    public:
        struct MaterialResourceData {
            void* instanceParameter;
            uint64_t unk2;
            uint32_t instanceParameterCount;
            uint32_t unk3;
            MaterialResource* elementData;

            // Actual data block starts here.
            // Layout is
            // - 0x0 : this small header
            // - 0x8 : parameter infos
            // - 0x8 + ((2 * parameterCount + 7) & 0xFFFFFFFFFFFFFFF8ui64) : parameter values

            uint32_t dataBufferSize;
            uint32_t parameterCount;
        };
        MaterialResourceData* data;
        MaterialResourceData dataBuffer;
        static MaterialResource* Create(unsigned int parameterCount, size_t dataSize);
        void RefreshInstanceParameter();
        void* GetMaterialData() const;
        inline uint32_t GetMaterialDataSize() { return data->dataBufferSize; }
        inline uint32_t GetMaterialParameterCount() { return data->parameterCount; }
        inline MaterialChunkBuilder::ParameterInfo* GetMaterialParameterInfos() {
            return reinterpret_cast<MaterialChunkBuilder::ParameterInfo*>(reinterpret_cast<size_t>(GetMaterialData()) + 8);
        }
        inline void* GetMaterialParameterValues() {
            return reinterpret_cast<void*>(reinterpret_cast<size_t>(GetMaterialData()) + 8 + ((2 * GetMaterialParameterCount() + 7) & 0xFFFFFFFFFFFFFFF8ui64));
        }
        void* GetMaterialInstanceParameter() const;
        uint32_t GetMaterialInstanceParameterCount() const;
        void* GetElementData() const;
        uint32_t GetElementSize() const;
    };

    bool LoadMirageMaterial2(RenderingDevice* renderingDevice, const void* data, MaterialResource** resource);

    //template<typename T>
    void BuildMaterialResourceFromResolvedMemoryImage(RenderingDevice* device, const void* image, MaterialResource** resource, bool unkParam);
    
    // ParameterInfo here is actually just unsigned short, I'm just using a struct for ease of reading
    template<typename E, typename D>
    void ExecuteChunk(E& check, const MaterialChunkBuilder::ParameterInfo* parameterInfos, unsigned int parameterCount, D* data, bool unk);
    
    struct SCheckexec {
        bool unk1;
    };
    void ExecuteChunk(SCheckexec& check, const MaterialChunkBuilder::ParameterInfo* parameterInfos, unsigned int parameterCount, void* data, bool unk);
}
