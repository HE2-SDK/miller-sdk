#pragma once

#ifdef AddJob
#undef AddJob
#endif

namespace hh::needle {
    class GlobalParameterBuilder;
    struct GatherRenderingPassContext;
    struct DrawPassIdToIndexMap;
    struct DrawPassInfo {
        DrawPassIdToIndexMap* drawPassIdToIndexMap;
        GatherRenderingPassContext* pGatherRenderingPassContext;
        uint8_t byte268;
    };
    class PipelineInfo : public NeedleObject {
    public:
        uint32_t dword8;
        DrawPassInfo drawPassInfo;
        SupportFX::FxRenderParam renderParam;
        SupportFXAll* supportFX;
        uint64_t qword138;
        GlobalParameterBuilder* globalParameterBuilder;
        RenderTarget* renderTarget;
        RenderingContextManager* renderingContextManager;
        CNameIDObject* renderUnitNameId;
        CNameIDObject* sceneNameId;
        uint32_t cameraId;
        SceneParamContainer* sceneParamContainer;
        uint32_t drawPassCount;
        uint32_t currentPass;
        uint64_t qword180;
        uint32_t dword188;
        RenderUnit* renderUnit;
        uint64_t qword198;
        CScratchMemoryContext* scratchMemoryContext;

        PipelineInfo(CNameIDObject* renderUnitNameId);
        PipelineInfo(const PipelineInfo& other);
        PipelineInfo& operator=(const PipelineInfo& other);

        virtual uint64_t UnkFunc1();

        void SetDrawPassInfo(const DrawPassInfo& drawPassInfo);
        const DrawPassInfo& GetDrawPassInfo() const;

        template<typename T> SceneParamContainer::ParamHolder<T>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxBloomParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxDOFParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxColorContrastParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxToneMapParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxCameraControlParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxShadowMapParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxShadowHeightMapParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxVolumetricShadowParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxScreenBlurParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSSAOParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSHLightFieldParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxLightScatteringParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxRLRParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSSGIParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxPlanarReflectionParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxOcclusionCapsuleParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxGodrayParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxScreenSpaceGodrayParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxHeatHazeParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSceneEnvironmentParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxRenderOption>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSGGIParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxTAAParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxEffectParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxAtmosphereParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxDensityParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxWindComputeParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxGpuEnvironmentParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxInteractiveWaveParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxChromaticAberrationParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxVignetteParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxTerrainMaterialBlendingParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxWeatherParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxColorAccessibilityFilterParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxCyberNoiseEffectParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxCyberSpaceStartNoiseParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxCyberNPCSSEffectRenderParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxFieldScanEffectRenderParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxSeparableSSSParameter>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<FxAntiAliasing>* GetSceneParam();
        // template<> SceneParamContainer::ParamHolder<gfx::FxDentParameter>* GetSceneParam();
    
        template<typename T> bool HasSceneParam() const;
        // template<> bool HasSceneParam<FxBloomParameter>() const;
        // template<> bool HasSceneParam<FxDOFParameter>() const;
        // template<> bool HasSceneParam<FxColorContrastParameter>() const;
        // template<> bool HasSceneParam<FxToneMapParameter>() const;
        // template<> bool HasSceneParam<FxCameraControlParameter>() const;
        // template<> bool HasSceneParam<FxShadowMapParameter>() const;
        // template<> bool HasSceneParam<FxShadowHeightMapParameter>() const;
        // template<> bool HasSceneParam<FxVolumetricShadowParameter>() const;
        // template<> bool HasSceneParam<FxScreenBlurParameter>() const;
        // template<> bool HasSceneParam<FxSSAOParameter>() const;
        // template<> bool HasSceneParam<FxSHLightFieldParameter>() const;
        // template<> bool HasSceneParam<FxLightScatteringParameter>() const;
        // template<> bool HasSceneParam<FxRLRParameter>() const;
        // template<> bool HasSceneParam<FxSSGIParameter>() const;
        // template<> bool HasSceneParam<FxPlanarReflectionParameter>() const;
        // template<> bool HasSceneParam<FxOcclusionCapsuleParameter>() const;
        // template<> bool HasSceneParam<FxGodrayParameter>() const;
        // template<> bool HasSceneParam<FxScreenSpaceGodrayParameter>() const;
        // template<> bool HasSceneParam<FxHeatHazeParameter>() const;
        // template<> bool HasSceneParam<FxSceneEnvironmentParameter>() const;
        // template<> bool HasSceneParam<FxRenderOption>() const;
        // template<> bool HasSceneParam<FxSGGIParameter>() const;
        // template<> bool HasSceneParam<FxTAAParameter>() const;
        // template<> bool HasSceneParam<FxEffectParameter>() const;
        // template<> bool HasSceneParam<FxAtmosphereParameter>() const;
        // template<> bool HasSceneParam<FxDensityParameter>() const;
        // template<> bool HasSceneParam<FxWindComputeParameter>() const;
        // template<> bool HasSceneParam<FxGpuEnvironmentParameter>() const;
        // template<> bool HasSceneParam<FxInteractiveWaveParameter>() const;
        // template<> bool HasSceneParam<FxChromaticAberrationParameter>() const;
        // template<> bool HasSceneParam<FxVignetteParameter>() const;
        // template<> bool HasSceneParam<FxTerrainMaterialBlendingParameter>() const;
        // template<> bool HasSceneParam<FxWeatherParameter>() const;
        // template<> bool HasSceneParam<FxColorAccessibilityFilterParameter>() const;
        // template<> bool HasSceneParam<FxCyberNoiseEffectParameter>() const;
        // template<> bool HasSceneParam<FxCyberSpaceStartNoiseParameter>() const;
        // template<> bool HasSceneParam<FxCyberNPCSSEffectRenderParameter>() const;
        // template<> bool HasSceneParam<FxFieldScanEffectRenderParameter>() const;
        // template<> bool HasSceneParam<FxSeparableSSSParameter>() const;
        // template<> bool HasSceneParam<FxAntiAliasing>() const;
        // template<> bool HasSceneParam<gfx::FxDentParameter>() const;

        SceneContextManager* GetSceneContextManager() const;
    };

    class RenderingPipeline : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<RenderJob*> renderJobs;
        csl::fnd::IAllocator* allocator;
        const char* name;
        bool initialized;
        bool jobsAreRunning;

        RenderingPipeline(csl::fnd::IAllocator* allocator, const char* name);

        virtual uint64_t UnkFunc1();
        virtual void UnkFunc2(PipelineInfo* pipelineInfo);
        virtual void UnkFunc3(PipelineInfo* pipelineInfo) {}
        virtual void RenderMatchingJobs(PipelineInfo* pipelineInfo, uint64_t mask, bool renderNonMatching); // mask bits seem to correspond to render passes, renderNonMatching inverts the mask
        virtual void Initialize();
        virtual void Deinitialize();
        virtual void StartJobs(const RenderJobContext& context);
        virtual void StopJobs();
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual void InitializeJobs() {}
        virtual void DeinitializeJobs() {}

        void AddJob(RenderJob* job);
        void RemoveJob(RenderJob* job);
    };
}
