#pragma once

namespace Cyan {
    class GPUTextureBuilder {
        struct GPUElementParam {
            struct Table {
                unsigned int color[32];
                unsigned int count;
            };

            unsigned int packedValue[4];
            float emitSpeed0[4];
            float emitSpeed1[4];
            float emitVector[4];
            unsigned int initRotation[4];
            unsigned int angVelocity[4];
            unsigned int particleInfo[4];
            float gravityAccele[4];
            float forceToPosition[4];
            float vortex[4];
            float vectorFieldSize[4];
            float vectorFieldParam[4];
            float fluctuation0[4];
            float fluctuation1[4];
            float depthCollision[4];
            Table tables[4];
        };

        const Resource::ElementParam* elementParam;

        static void BuildTexture1(const Resource::EmitterParam* emitterParam, GPUElementParam* buffer);
        GPUTextureBuilder(const Resource::ElementParam* elementParam);
        unsigned int BuildPart1(GPUElementParam* buffer);
        unsigned int BuildPart2(GPUElementParam* buffer);
        unsigned int BuildPart3(GPUElementParam* buffer);
    public:
        static bool Build(const Graphics::DeviceContainer& deviceContainer, const Resource::EmitterParam* emitterParam, hh::needle::Texture* parameterMap1, hh::needle::Texture* parameterMap2);
    };
}
