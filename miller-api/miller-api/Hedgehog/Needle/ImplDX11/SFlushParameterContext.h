#pragma once

namespace hh::needle::ImplDX11 {
    class DeviceObjectDX11;

    struct SFlushParameterContext {
        struct Unk2 {
            enum class ParameterType {
                RESOURCE,
                SAMPLER,
                CONSTANT_BUFFER,
                FLOAT,
                UNKNOWN,
                INT,
                BOOL,
            };

            struct ParameterInfo {
                uint16_t offset;
                uint16_t unk2;
                uint16_t unk3;
                uint8_t slot;
                uint8_t unk5;
            };

            uint16_t typeSegmentStartIndices[9];
            uint16_t parameterInfoStartIndex;
            uint16_t unk1;
            uint16_t hashBucketStartIndices[345];

            union ParameterData {
                CNameIDObject* name;
                ParameterInfo paramInfo;
            };

            /*
             * Contains parameter data that looks like this:
             * - 10 segments of parameter names by type. The indices to these segments are in `
             *   - if there are less than 4 parameters names in this type segment, the segment immediately contains
             *     CNameIDObject* pointers for the parameter names. The segment is thus located in the following slice:
             * 
             *     start: `parameterData[typeSegmentStartIndices[type]]`
             *     end: `parameterData[typeSegmentStartIndices[type + 1]]`
             * 
             *   - if there are more parameters in the segment, then an additional offset is added based on a hash of
             *     the parameter type and parameter name.
             *     The hash is calculated as `type * 38 + namePtr % 37`. This hash is used to index the `hashBucketStartIndices`
             *     map, which is finally used to obtain the additional offset within the type segment,
             *     making the real offsets of the subsegment:
             * 
             *     start: `parameterData[typeSegmentStartIndices[type] + hashBucketStartIndices[type * 38 + namePtr % 37]]`
             *     end: `parameterData[typeSegmentStartIndices[type] + hashBucketStartIndices[type * 38 + namePtr % 37 + 1]]`
             * 
             * - an array of ParameterInfo structs containing the actual information about the parameters.
             * 
             * So you use the lookup table at the start to get the index of the parameter, then use that index to index
             * the ParameterInfo array.
             */    
            ParameterData parameterData[178];

            short GetParameterIndexInTypeSegment(uint8_t type, CNameIDObject* name);
        private:
            static unsigned int GetParameterIndexInBucket(CNameIDObject* name, CNameIDObject** names, unsigned short bucketSize);
        };

        DeviceObjectDX11* deviceObject;
        SResourceContext* resourceContext;
        Unk2* parameterSlots;
        ID3D11Buffer* constantBuffers[14];
        uint64_t unk0a; // possibly padding?
    };
}
