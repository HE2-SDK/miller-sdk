#pragma once

namespace hh::needle {
    class ParamValueOverrideHelper {
    public:
        struct ParamBuffers {
            void* boolBuffer;
            void* uintBuffer;
            void* floatBuffer;
            void* textureBuffer;
            void* samplerBuffer;
            void* constantBufferBuffer;
            void* unkBuffer;
        };

        InstanceParameterContainerData::ParamData paramData;
        ParamBuffers paramBuffers;
        uint64_t qword70;
        uint64_t qword78;
        uint64_t qword80;
        InstanceParameterContainerData ipcd;
    };
}
