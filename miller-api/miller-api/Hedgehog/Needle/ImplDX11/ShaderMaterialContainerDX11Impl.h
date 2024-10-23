#pragma once

namespace hh::needle::ImplDX11 {
    struct Unk10 {
        uint8_t itemCount;
        // lower nibble = constant buffer index, upper 16 bits: index into something else
        uint32_t items[1];
    };

    // struct Unk11 {
    //     uint32_t itemCount;

    //     // lower byte = constant buffer index, upper 16 bits: index into something else
    //     uint32_t items[1];
    // };

    struct Unk14 {
        void* unk1[4];
        uint32_t* unk2;
    };

    struct Unk15 {
        uint16_t unk1;
        uint16_t unk2;
        uint16_t unk3;
    };

    struct Unk13 {
        uint16_t flags;
        uint16_t somethingSize;
        uint16_t unk3;
        uint16_t start;
        uint16_t end;
        uint16_t unk6;
        uint16_t unk7;
        uint16_t unk8;
        uint16_t unk9;
        uint16_t unk10;
        Unk15 unk11[1];
    };

    struct Unk12 {
        uint64_t unk1;
        uint64_t unk2;
        Unk13* unk3;
    };

    union ShaderResourcePtr {
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ComputeShader* computeShader;
    };

    struct SShaderConfig {
        ShaderResourcePtr shader;
        uint16_t optionsIncludedInHashBits;
        uint16_t shaderEnabledOptionsBits;
        Unk10* unk1;
        uint16_t* optionsHashToUnk3OffsetMap;
        uint32_t* unk3;

        unsigned short CalculateCacheHash(uint16_t enabledOptionsBits);
    };

    struct SShaderMaterial {
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        SShaderConfig* shaderConfigurations[3];
        csl::ut::Bitset<ShaderStage> enabledShaderStagesFlags;
        uint64_t unk8;
        uint64_t unk9;
    };

    class ShaderMaterialContainerObjectDX11Impl : ShaderMaterialContainerObject {
    public:
        uint64_t unk1[5];
        Unk12* unk3;
        uint64_t unk1a[4];
        SShaderMaterial* materials;
    };

    class DeviceObjectDX11;
    class ShaderMaterialContainerDX11Impl : public ShaderMaterialContainer {
    public:
        ShaderMaterialContainerObjectDX11Impl inlineShaderMaterialContainerObject;
        void* parameterData;
        unsigned int unk201;
        unsigned int additionalCount;
        static ShaderMaterialContainerDX11Impl* Create(DeviceObjectDX11* deviceObject, const ShaderMaterialContainerCreationInfo& creationInfo);
    };
}
