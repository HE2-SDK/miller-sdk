#pragma once

namespace hh::needle {
    struct GatherRenderingPassContext_ModelContainer {
        void* data;
        void* otherData;
        unsigned int otherDataCount; // context unk2
        unsigned int unk1;
    };

    // Maps draw pass ids to sequential indices that skip disabled passes.
    struct DrawPassIdToIndexMap {
        int indicesByPassId[128];
    };

    struct GatherRenderingPassContextImpl {
        class CResourceParseContextHolder {
            struct Unk1 {
                SGlobalParameterSceneSetting globalParameterSceneSetting;
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
            };

            struct Unk2 {
                uint8_t unk1;
                uint8_t unk1a;
                uint16_t unk1b;
                uint32_t unk2;
                uint32_t unk3;
                uint32_t unk4;
            };

            struct Unk3 {
                uint64_t unk1;
                uint32_t unk2;
                uint32_t unk3[32];
                uint64_t unk4[32];
            };

            struct Unk4 {
                uint16_t unk1;
                uint16_t unk2;
                uint16_t unk3;
                uint16_t unk4;
                uint16_t unk5;
                uint16_t unk6;
            };

            struct Unk5 {
                uint8_t pad[480];
            };

            struct Unk6 {
                uint8_t pad[8208];
            };

            struct Unk7 {
                uint8_t pad[96];
                csl::math::Vector4 unk1;
                csl::math::Vector4 unk2;
                uint8_t pad2[112];
                csl::math::Vector4 unk3;
                uint8_t pad3[160];
            };

            struct Unk8 {
                uint8_t unk1[33];
            };

            CScratchMemoryContext memCtx;
            CScratchMemoryContext memCtxs1[32];
            CScratchMemoryContext memCtxs2[32];
            RenderingDevice* renderingDevice;
            Unk1 globalParameterSceneSettings[64];
            uint32_t totalGlobalParameterSize;
            Unk4 unk2a[64];
            SCullGroupSetting cullGroupSettings[32];
            uint8_t unk2b[32];
            uint8_t unk2c[32];
            Unk8 unk2ca[3];
            uint32_t unk2d[32];
            uint8_t unk2e[32];
            uint32_t pad2a;
            uint32_t totalCullingGroupCount;
            uint32_t unk3a;
            uint32_t unk3b;
            float lodLayerRanges[32]; 
            uint32_t unk3c;
            SDrawPassSceneSetting drawPassSettings[64];
            unsigned int drawPassSettingIndices[64];
            uint8_t pad3b[128];
            uint8_t pad3[128];
            uint32_t drawPassCount;
            uint32_t unk4;
            Unk3 unk4a;
            uint32_t unk5;
            Unk2 unk5b[64];
            uint8_t unk5c[64];
            Unk7 unk5f[32];
            Unk5 unk5d[32];
            uint32_t unk10a;
            uint32_t unk10b;
            uint32_t unk10c;
            uint32_t unk10d;
            Unk6 unk5e[32];
            float unk5g[32];
            float unk5h[32];
            uint8_t pad5a[512];
            void** unk5a; // unk5 pointers to memory of size 144 x unk4
            uint8_t pad6[6];
            uint8_t unk6;
            uint32_t unk7;
            uint8_t pad7[36];
            void* unk8; // 256 bytes long
            uint32_t unk9;
            uint32_t unk10;
            rsdx::SJobJoint* modelJoint1;
            rsdx::SJobJoint* modelJoint2;
            ParameterProcessQueueHandle* parameterProcessQueueHandle;
        };
        CResourceParseContextHolder resourceParseContextHolder;
        uint32_t unk2;
        uint32_t unk2a;
        GatherRenderingPassContext_ModelContainer modelContainer;
        uint8_t pad2[1056];
        float unk2b;
        uint8_t unk3;
        bool unk3a;
        float unk4;

        void SetupInitialize(RenderingDevice* renderingDevice, unsigned int totalGlobalParameterSize, unsigned int totalCullingGroupCount, unsigned int drawPassCount, unsigned int unkParam3, unsigned char unkParam4, unsigned int unkParam5);
        void SetCullingGroupSetting(unsigned int index, const SCullGroupSetting& cullingGroupSetting);
        void SetDrawPassGroupSetting(unsigned int index, const SDrawPassSceneSetting& drawPassGroupSetting);
        void SetGlobalParameter(unsigned int index, const SGlobalParameterSceneSetting& globalParameterSceneSetting);
        void SetLODLayerRanges(const float* ranges);
        void* GetParameterBuffer(size_t size);
        float* GetParameterFloatVector(size_t count, const float* vec);
    };

    struct GatherRenderingPassContext {
        GatherRenderingPassContextImpl* implementation;
        CScratchMemoryContext memCtx;
        uint32_t unk2;
        uint16_t unk3;
        DrawPassIdToIndexMap drawPassIdToIndexMap;

        virtual ~GatherRenderingPassContext();

        GatherRenderingPassContext(unsigned int unk2Param);
        void SetupInitialize(RenderingDevice* renderingDevice, unsigned int totalGlobalParameterSize, unsigned int totalCullingGroupCount, unsigned int drawPassCount, unsigned int unkParam3, unsigned char unkParam4, unsigned int unkParam5);
        void SetCullingGroupSetting(unsigned int index, const SCullGroupSetting& cullingGroupSetting);
        void SetDrawPassGroupSetting(unsigned int index, const SDrawPassSceneSetting& drawPassGroupSetting);
        void SetGlobalParameter(unsigned int index, const SGlobalParameterSceneSetting& globalParameterSceneSetting);
        void SetLODLayerRanges(const float* ranges);
        void* GetParameterBuffer(size_t size);
        float* GetParameterFloatVector(size_t count, const float* vec);
    };
}
