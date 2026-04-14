#pragma once

namespace Cyan {
    class Emitter;
}

namespace Cyan::Graphics {
    struct TextureDecl {
        enum class TextureType : unsigned char {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
        };

        hh::needle::Texture* texture;
        TextureType type;
        char unk0;
        bool unk1;
    };

    struct ParticleDecl {
        struct CPUParticleUVDecl {
            csl::math::Vector2 uvs[4][2];
        };

        struct GPUParticleUVDecl {
            unsigned int matrices[4][2][3];
        };

        union ParticleUVDecl {
            CPUParticleUVDecl cpu;
            GPUParticleUVDecl gpu;
        };

        csl::math::Position position;
        csl::math::Position rotation;
        float unk2;
        float unk4Cbb[4];
        csl::math::Position size;
        unsigned int subParticleIndex;
        ParticleUVDecl uvDeclaration;
        unsigned int colors[2][2];
        float luminance[2][2];
        float uvScale[2];
        float recipunk7[2];
    };

    struct MeshDecl {
        char pad[400];
    };

    struct EmitterDecl {
        struct BlendModeSettings {
            static BlendModeSettings blendModeMap[4];

            hh::needle::BlendMode colorSrcBlendMode;
            hh::needle::BlendMode colorDstBlendMode;
            hh::needle::BlendOp colorBlendOp;
            hh::needle::BlendMode alphaSrcBlendMode;
            hh::needle::BlendMode alphaDstBlendMode;
            hh::needle::BlendOp alphaBlendOp;

            BlendModeSettings(int index);
        };


        enum class UVSubdivisionFlag : unsigned char {
            UNK0,
            ENABLE_VERTICAL_SUBDIVISIONS,
        };

        Emitter* emitter;
        uint64_t pad1;
        csl::math::Matrix44 inheritMatrix;
        csl::math::Vector4 elementScale;
        uint32_t billboardViewportId2;
        float colorSqr[4];
        float mask1[4];
        float mask2[4];
        float mask3[4];
        float mask4[4];
        float mask5[2];
        float mask6[2];
        hh::needle::CullMode cullMode;
        BlendModeSettings blendModeSettings;
        bool enableBlending;
        bool enableDepthTest;
        bool enableDepthWrite;
        float unk454;
        float unk458;
        float unk45C;
        float unk460;
        float unk464;
        float unk468;
        float unk46C;
        float unk470;
        unsigned int textureCount;
        TextureDecl textureDeclarations[4];
        float unk4B8;
        float unk4BC;
        float unk4C0;
        float unk4C4;
        float unk4C8;
        float unk4CC;
        float unk4D0;
        float unk4D4;
        uint32_t unk4D8;
        float unkTexFloat0;
        float unkTexFloat1;
        float unkTexFloat2;
        float unk4E8;
        float unk4EC;
        float unk4F0;
        float unk4F4;
        float unk4F8[4];
        float unk508[4];
        uint64_t gap518; // could be float[4]
        uint32_t unk520;
        float unk524;
        uint32_t unk528[4];
        float unk538;
        float unk53C;
        uint32_t gap540;
        float unk544;
        uint32_t unk548;
        float unkFloatFoo1;
        float unkFloatFoo2;
        float unkFloatFoo0;
        uint32_t unk558[4];
        uint32_t dword230;
        uint32_t dword234;
        uint32_t dword238;
        uint32_t qword240;
        uint32_t qword244;
        uint32_t qword248;
        uint64_t qword570;
        unsigned int particleCount; // tentative
        unsigned int subParticleCount;
        Graphics::MeshInstance* meshInstance;
        int renderLayer;
        float renderPriority;
        uint32_t qword588;
        uint32_t qword58C;
        csl::ut::Bitset<UVSubdivisionFlag> uvSubdivisionFlags;
        uint8_t horizontalUVSubdivisionCount; // tentative
        uint8_t dword592;
        uint8_t dword593;
        uint64_t qword598;

        EmitterDecl& operator=(const EmitterDecl& other);
    };
}
