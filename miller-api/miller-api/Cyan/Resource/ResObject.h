#pragma once

namespace hh::eff {
    class ResEffect;
}

namespace Cyan::Resource {
    class Effect {
        EffectParam* param;
        hh::eff::ResEffect* resource;
    };

    class Model {
        Graphics::MeshInstance* meshInstance;
        System::IAllocator* allocator;
        EmitterParam::BlendMode blendMode;
        EmitterParam::DepthMode depthMode;
        EmitterParam::CullMode cullMode;
        uint64_t unk4;
    };

    class Shader {
        hh::needle::VertexShader* vertexShader;
        hh::needle::PixelShader* pixelShader;
    };

    class ComputeShader {
        hh::needle::ComputeShader* shader;
    };

    class Texture {
        hh::needle::Texture* texture;
        uint64_t unk1;
    };

    // Currently unused in the engine. No ResourceRequestHandler is registered for them.
    class Skeleton {
        uint64_t unk1;
        uint64_t unk2;
    };

    class NodeAnim {
        uint64_t unk1;
        uint64_t unk2;
    };

    template<typename T>
    class ResObject {
        char name[128];
        T object;

        void CopyName(const char* name);
    };
}
