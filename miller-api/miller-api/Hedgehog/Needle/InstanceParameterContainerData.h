#pragma once

namespace hh::needle {
    class InstanceParameterContainerData {
    public:
        template<typename T>
        struct ArrayParamData {
            T* data;
            size_t count;
        };

        struct ParamData {
            unsigned int* boolData;
            ArrayParamData<uint_vector4>* uintData;
            ArrayParamData<float_vector4>* floatData;
            Texture** textureData;
            SamplerStateSetting* samplerData;
            ConstantBuffer** constantBufferData;
            void* unkData;
        };

        struct ParamCounts {
            unsigned int boolCounts;
            unsigned int uintCounts;
            unsigned int floatCounts;
            unsigned int textureCounts;
            unsigned int samplerCounts;
            unsigned int constantBufferCounts;
            unsigned int unkCounts;
        };

        CNameIDObject*** names;
        ParamData* data;
        ParamCounts* counts;
    };
}
