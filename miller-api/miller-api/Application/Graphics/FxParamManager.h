#pragma once

#ifdef AddJob
#undef AddJob
#endif

namespace app::gfx {
    class FxParamManager;
    class FxParamExtension : public hh::fnd::BaseObject {
        FxParamManager* fxParamManager;

    public:
        FxParamExtension(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() = 0;
        virtual void Initialize() = 0;
        virtual void Destroy() = 0;
        virtual void UnkFunc1() {}
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) {}
        virtual void BeforeSetParameter(hh::fnd::SUpdateInfo* updateInfo, hh::needle::NeedleFxParameter* needleFxParameter) {}
        virtual void AfterSetParameter(hh::fnd::SUpdateInfo* updateInfo) {}
        virtual void AfterUpdate(hh::fnd::SUpdateInfo* updateInfo) {}
    };

    class FxParamManager
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public app::game::GameCondition::Listener {
    public:
        class InterpolatorBase : public hh::fnd::ReferencedObject {
        public:
            InterpolatorBase(csl::fnd::IAllocator* allocator);
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) = 0;
            virtual void UpdateJob(uint64_t ownerId, const void* value) = 0;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) = 0;
            virtual void Update(float deltaTime) = 0;
            virtual void SetTweenPosition(uint64_t ownerId, float position) = 0;
            virtual void UnkFunc1() {}
        };

        template<typename T>
        class Interpolator : public InterpolatorBase {
            struct Unk1 {
                T parameters;
                uint64_t ownerId;
                unsigned int interpolationGroupMemberBits;
                unsigned int priority;
                float currentTweenPosition;
                float tweenPositionIncrementPerSecond;
                uint32_t unk6;
            };
        public:
            T* target;
            void (*interpolationFunction)(T* target, T* lower, T* upper, unsigned int flags, float delta);
            csl::ut::InplaceMoveArray<Unk1, 4> interpolationJobs;
            unsigned int interpolationGroupEnabledBits; // bit nr = index of group
            unsigned int interpolationGroupCount;

            Interpolator(csl::fnd::IAllocator* allocator, T* target);
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) override;
            virtual void UpdateJob(uint64_t ownerId, const void* value) override;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) override;
            virtual void Update(float deltaTime) override;
            virtual void SetTweenPosition(uint64_t ownerId, float position) override;
        };

        struct NeedleFXParameterInterpolators {
            Interpolator<hh::needle::FxBloomParameter>* bloomInterpolator;
            Interpolator<hh::needle::FxDOFParameter>* dofInterpolator;
            Interpolator<hh::needle::FxColorContrastParameter>* colorContrastInterpolator;
            Interpolator<hh::needle::FxToneMapParameter>* tonemapInterpolator;
            Interpolator<hh::needle::FxCameraControlParameter>* cameraControlInterpolator;
            Interpolator<hh::needle::FxShadowMapParameter>* shadowmapInterpolator;
            Interpolator<hh::needle::FxShadowHeightMapParameter>* shadowHeightMapInterpolator;
            Interpolator<hh::needle::FxVolumetricShadowParameter>* volShadowInterpolator;
            Interpolator<hh::needle::FxScreenBlurParameter>* blurInterpolator;
            Interpolator<hh::needle::FxSSAOParameter>* ssaoInterpolator;
            Interpolator<hh::needle::FxSHLightFieldParameter>* shlightfieldInterpolator;
            Interpolator<hh::needle::FxLightScatteringParameter>* lightscatteringInterpolator;
            Interpolator<hh::needle::FxFogParameter>* fogInterpolator;
            Interpolator<hh::needle::FxRLRParameter>* rlrInterpolator;
            Interpolator<hh::needle::FxSSGIParameter>* ssgiInterpolator;
            Interpolator<hh::needle::FxPlanarReflectionParameter>* planarReflectionInterpolator;
            Interpolator<hh::needle::FxOcclusionCapsuleParameter>* occlusionCapsuleInterpolator;
            Interpolator<hh::needle::FxGodrayParameter>* godrayInterpolator;
            Interpolator<hh::needle::FxScreenSpaceGodrayParameter>* ssGodrayInterpolator;
            Interpolator<hh::needle::FxHeatHazeParameter>* heatHazeInterpolator;
            Interpolator<hh::needle::FxSceneEnvironmentParameter>* sceneEnvInterpolator;
            Interpolator<hh::needle::FxRenderOption>* renderOptionInterpolator;
            Interpolator<hh::needle::FxSGGIParameter>* sggiInterpolator;
            Interpolator<hh::needle::FxTAAParameter>* taaInterpolator;
            Interpolator<hh::needle::FxEffectParameter>* effectInterpolator;
            Interpolator<hh::needle::FxAtmosphereParameter>* atmosphereInterpolator;
            Interpolator<hh::needle::FxDensityParameter>* densityInterpolator;
            Interpolator<hh::needle::FxWindComputeParameter>* windInterpolator;
            Interpolator<hh::needle::FxGpuEnvironmentParameter>* gpuEnvironmentInterpolator;
            Interpolator<hh::needle::FxInteractiveWaveParameter>* interactiveWaveInterpolator;
            Interpolator<hh::needle::FxChromaticAberrationParameter>* chromaticAberrationInterpolator;
            Interpolator<hh::needle::FxVignetteParameter>* vignetteInterpolator;
            Interpolator<hh::needle::FxTerrainMaterialBlendingParameter>* terrainBlendInterpolator;
            Interpolator<hh::needle::FxWeatherParameter>* weatherInterpolator;
            Interpolator<hh::needle::FxColorAccessibilityFilterParameter>* colorAccessibilityInterpolator;
            Interpolator<hh::needle::FxCyberNoiseEffectParameter>* cyberNoiseInterpolator;
            Interpolator<hh::needle::FxCyberSpaceStartNoiseParameter>* cyberStartNoiseInterpolator;
            Interpolator<hh::needle::FxCyberNPCSSEffectRenderParameter>* cyberNPCSSInterpolator;
            Interpolator<hh::gfx::FxDentParameter>* dentInterpolator;
            Interpolator<hh::needle::FxFieldScanEffectRenderParameter>* fieldScanInterpolator;
            Interpolator<hh::needle::FxSeparableSSSParameter>* ssssInterpolator;
            Interpolator<hh::needle::FxTimeStopParameter>* timeStopInterpolator;
        };

        struct NeedleFXSceneConfigInterpolators {
            Interpolator<hh::gfx::FxRenderTargetSetting>* fxRenderTargetSettingInterpolator;
            Interpolator<hh::needle::FxAntiAliasing>* fxAntiAliasingInterpolator;
            Interpolator<hh::needle::FxLODParameter>* fxLODParameterInterpolator;
            Interpolator<hh::needle::FxDetailParameter>* fxDetailParameterInterpolator;
            Interpolator<hh::needle::FxDynamicResolutionParameter>* fxDynamicResolutionParameterInterpolator;
            Interpolator<hh::gfx::StageCommonTimeProgressParameter>* stageCommonTimeProgressParameterInterpolator;
            Interpolator<hh::needle::FxModelParameter>* fxModelParameterInterpolator;
            Interpolator<hh::gfx::PerformanceSetting>* performanceSettingInterpolator;
        };

        hh::needle::NeedleFxParameter parameters;
        hh::needle::NeedleFxSceneConfig sceneConfig;
        NeedleFXParameterInterpolators paramInterpolators;
        NeedleFXSceneConfigInterpolators sceneConfigInterpolators;
        SceneParameters* sceneParameters[2];
        csl::ut::MoveArray<FxParamExtension*> extensions;
        int currentSceneParameters;
        csl::fnd::Mutex mutex;
        bool paramsDirty;
        bool sceneConfigDirty;
        bool dirty;
    protected:
        bool UpdateNeedleFxSceneConfigInterpolators();
        bool UpdateNeedleFxParameterInterpolators();

    public:
        virtual void* GetRuntimeTypeInfo() override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void SetSceneParameters(SceneParameters* parameters, int idx);

        inline void AddNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, hh::needle::NeedleFxSceneConfig* needleFxSceneConfig, unsigned int priority, float interpolationTime) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->AddJob(ownerId, &needleFxSceneConfig->rendertarget, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->AddJob(ownerId, &needleFxSceneConfig->antialiasing, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->atmosphere, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxLODParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->lod, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxDetailParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->detail, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->dynamicResolution, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->timeProgress, -1, priority, interpolationTime, -1);
            this->mutex.Unlock();
            sceneConfigDirty |= UpdateNeedleFxSceneConfigInterpolators();
        }
        void AddDefaultNeedleFxSceneConfigInterpolationJob(hh::needle::NeedleFxSceneConfig* needleFxParameter, unsigned int priority);
        inline void UpdateNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, hh::needle::NeedleFxSceneConfig* needleFxSceneConfig) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->rendertarget);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->antialiasing);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->atmosphere);
            sceneConfigInterpolators.fxLODParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->lod);
            sceneConfigInterpolators.fxDetailParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->detail);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->dynamicResolution);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->timeProgress);
            this->mutex.Unlock();
            sceneConfigDirty |= UpdateNeedleFxSceneConfigInterpolators();
        }
        void UpdateDefaultNeedleFxSceneConfigInterpolationJob(hh::needle::NeedleFxSceneConfig* needleFxParameter);
        inline void RemoveNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, float interpolationTime) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxLODParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxDetailParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            this->mutex.Unlock();
            // updated |= UpdateNeedleFxSceneConfigInterpolators();
        }
    
        void AddNeedleFxParameterInterpolationJob(uint64_t ownerId, hh::needle::NeedleFxParameter* needleFxParameter, unsigned int priority, float interpolationTime);
        void AddDefaultNeedleFxParameterInterpolationJob(hh::needle::NeedleFxParameter* needleFxParameter, unsigned int priority);
        void UpdateDefaultNeedleFxParameterInterpolationJob(hh::needle::NeedleFxParameter* needleFxParameter);
        void UpdateNeedleFxParameterInterpolationJob(uint64_t ownerId, hh::needle::NeedleFxParameter* needleFxParameter);
        inline void RemoveNeedleFxParameterInterpolationJob(uint64_t ownerId, float interpolationTime) {
            this->mutex.Lock();
            paramInterpolators.bloomInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.dofInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.colorContrastInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.tonemapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cameraControlInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shadowmapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shadowHeightMapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.volShadowInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.blurInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssaoInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shlightfieldInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.lightscatteringInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.rlrInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssgiInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.planarReflectionInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.occlusionCapsuleInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.godrayInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssGodrayInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.heatHazeInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.sceneEnvInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.renderOptionInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.sggiInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.taaInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.effectInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.atmosphereInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.densityInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.windInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.gpuEnvironmentInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.interactiveWaveInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.chromaticAberrationInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.vignetteInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.terrainBlendInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.weatherInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.colorAccessibilityInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberStartNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberNPCSSInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.dentInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.fieldScanInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssssInterpolator->ReverseJob(ownerId, interpolationTime);
            this->mutex.Unlock();
            // updated |= UpdateNeedleFxParameterInterpolators();
        }

        void AddNeedleFxParameterInterpolatorJobById(unsigned int id, uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void UpdateNeedleFxParameterInterpolatorJobById(unsigned int id, uint64_t ownerId, const void* value);
        void RemoveNeedleFxParameterInterpolatorJobById(unsigned int id, size_t ownerId, float interpolationTime);

        void AddNeedleFxSceneConfigInterpolatorJobById(unsigned int id, uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void UpdateNeedleFxSceneConfigInterpolatorJobById(unsigned int id, uint64_t ownerId, const void* value);
        void RemoveNeedleFxSceneConfigInterpolatorJobById(unsigned int id, size_t ownerId, float interpolationTime);

        unsigned int GetBloomParameterId() const;
        unsigned int GetDofParameterId() const;
        unsigned int GetColorContrastParameterId() const;
        unsigned int GetTonemapParameterId() const;
        unsigned int GetCameraControlParameterId() const;
        unsigned int GetShadowmapParameterId() const;
        unsigned int GetShadowHeightMapParameterId() const;
        unsigned int GetVolShadowParameterId() const;
        unsigned int GetBlurParameterId() const;
        unsigned int GetSsaoParameterId() const;
        unsigned int GetShlightfieldParameterId() const;
        unsigned int GetLightscatteringParameterId() const;
        unsigned int GetRlrParameterId() const;
        unsigned int GetSsgiParameterId() const;
        unsigned int GetPlanarReflectionParameterId() const;
        unsigned int GetOcclusionCapsuleParameterId() const;
        unsigned int GetGodrayParameterId() const;
        unsigned int GetSsGodrayParameterId() const;
        unsigned int GetHeatHazeParameterId() const;
        unsigned int GetSceneEnvParameterId() const;
        unsigned int GetRenderOptionParameterId() const;
        unsigned int GetSggiParameterId() const;
        unsigned int GetTaaParameterId() const;
        unsigned int GetEffectParameterId() const;
        unsigned int GetAtmosphereParameterId() const;
        unsigned int GetDensityParameterId() const;
        unsigned int GetWindParameterId() const;
        unsigned int GetGpuEnvironmentParameterId() const;
        unsigned int GetInteractiveWaveParameterId() const;
        unsigned int GetChromaticAberrationParameterId() const;
        unsigned int GetVignetteParameterId() const;
        unsigned int GetTerrainBlendParameterId() const;
        unsigned int GetWeatherParameterId() const;
        unsigned int GetColorAccessibilityParameterId() const;
        unsigned int GetCyberNoiseParameterId() const;
        unsigned int GetCyberStartNoiseParameterId() const;
        unsigned int GetCyberNPCSSParameterId() const;
        unsigned int GetDentParameterId() const;
        unsigned int GetFieldScanParameterId() const;
        unsigned int GetSsssParameterId() const;

        void AddBloomParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxBloomParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddDofParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxDOFParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddColorContrastParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxColorContrastParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddTonemapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxToneMapParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddCameraControlParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCameraControlParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddShadowmapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxShadowMapParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddShadowHeightMapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxShadowHeightMapParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddVolShadowParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxVolumetricShadowParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddBlurParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxScreenBlurParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSsaoParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSSAOParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddShlightfieldParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSHLightFieldParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddLightscatteringParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxLightScatteringParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddRlrParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxRLRParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSsgiParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSSGIParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddPlanarReflectionParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxPlanarReflectionParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddOcclusionCapsuleParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxOcclusionCapsuleParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddGodrayParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxGodrayParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSsGodrayParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxScreenSpaceGodrayParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddHeatHazeParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxHeatHazeParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSceneEnvParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSceneEnvironmentParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddRenderOptionParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxRenderOption* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSggiParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSGGIParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddTaaParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxTAAParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddEffectParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxEffectParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddAtmosphereParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxAtmosphereParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddDensityParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxDensityParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddWindParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxWindComputeParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddGpuEnvironmentParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxGpuEnvironmentParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddInteractiveWaveParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxInteractiveWaveParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddChromaticAberrationParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxChromaticAberrationParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddVignetteParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxVignetteParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddTerrainBlendParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxTerrainMaterialBlendingParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddWeatherParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxWeatherParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddColorAccessibilityParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxColorAccessibilityFilterParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddCyberNoiseParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberNoiseEffectParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddCyberStartNoiseParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberSpaceStartNoiseParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddCyberNPCSSParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberNPCSSEffectRenderParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddDentParameterInterpolatorJob(uint64_t ownerId, const hh::gfx::FxDentParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddFieldScanParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxFieldScanEffectRenderParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddSsssParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSeparableSSSParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);

        void UpdateBloomParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxBloomParameter* value);
        void UpdateDofParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxDOFParameter* value);
        void UpdateColorContrastParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxColorContrastParameter* value);
        void UpdateTonemapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxToneMapParameter* value);
        void UpdateCameraControlParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCameraControlParameter* value);
        void UpdateShadowmapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxShadowMapParameter* value);
        void UpdateShadowHeightMapParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxShadowHeightMapParameter* value);
        void UpdateVolShadowParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxVolumetricShadowParameter* value);
        void UpdateBlurParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxScreenBlurParameter* value);
        void UpdateSsaoParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSSAOParameter* value);
        void UpdateShlightfieldParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSHLightFieldParameter* value);
        void UpdateLightscatteringParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxLightScatteringParameter* value);
        void UpdateRlrParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxRLRParameter* value);
        void UpdateSsgiParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSSGIParameter* value);
        void UpdatePlanarReflectionParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxPlanarReflectionParameter* value);
        void UpdateOcclusionCapsuleParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxOcclusionCapsuleParameter* value);
        void UpdateGodrayParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxGodrayParameter* value);
        void UpdateSsGodrayParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxScreenSpaceGodrayParameter* value);
        void UpdateHeatHazeParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxHeatHazeParameter* value);
        void UpdateSceneEnvParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSceneEnvironmentParameter* value);
        void UpdateRenderOptionParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxRenderOption* value);
        void UpdateSggiParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSGGIParameter* value);
        void UpdateTaaParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxTAAParameter* value);
        void UpdateEffectParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxEffectParameter* value);
        void UpdateAtmosphereParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxAtmosphereParameter* value);
        void UpdateDensityParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxDensityParameter* value);
        void UpdateWindParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxWindComputeParameter* value);
        void UpdateGpuEnvironmentParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxGpuEnvironmentParameter* value);
        void UpdateInteractiveWaveParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxInteractiveWaveParameter* value);
        void UpdateChromaticAberrationParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxChromaticAberrationParameter* value);
        void UpdateVignetteParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxVignetteParameter* value);
        void UpdateTerrainBlendParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxTerrainMaterialBlendingParameter* value);
        void UpdateWeatherParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxWeatherParameter* value);
        void UpdateColorAccessibilityParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxColorAccessibilityFilterParameter* value);
        void UpdateCyberNoiseParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberNoiseEffectParameter* value);
        void UpdateCyberStartNoiseParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberSpaceStartNoiseParameter* value);
        void UpdateCyberNPCSSParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxCyberNPCSSEffectRenderParameter* value);
        void UpdateDentParameterInterpolatorJob(uint64_t ownerId, const hh::gfx::FxDentParameter* value);
        void UpdateFieldScanParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxFieldScanEffectRenderParameter* value);
        void UpdateSsssParameterInterpolatorJob(uint64_t ownerId, const hh::needle::FxSeparableSSSParameter* value);

        void RemoveBloomParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveDofParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveColorContrastParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveTonemapParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveCameraControlParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveShadowmapParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveShadowHeightMapParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveVolShadowParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveBlurParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSsaoParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveShlightfieldParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveLightscatteringParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveRlrParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSsgiParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemovePlanarReflectionParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveOcclusionCapsuleParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveGodrayParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSsGodrayParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveHeatHazeParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSceneEnvParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveRenderOptionParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSggiParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveTaaParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveEffectParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveAtmosphereParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveDensityParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveWindParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveGpuEnvironmentParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveInteractiveWaveParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveChromaticAberrationParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveVignetteParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveTerrainBlendParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveWeatherParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveColorAccessibilityParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveCyberNoiseParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveCyberStartNoiseParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveCyberNPCSSParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveDentParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveFieldScanParameterInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveSsssParameterInterpolatorJob(size_t ownerId, float interpolationTime);

        unsigned int GetFxRenderTargetSettingSceneConfigId() const;
        unsigned int GetFxAntiAliasingSceneConfigId() const;
        unsigned int GetStageCommonAtmosphereParameterSceneConfigId() const;
        unsigned int GetFxLODParameterSceneConfigId() const;
        unsigned int GetFxDetailParameterSceneConfigId() const;
        unsigned int GetFxDynamicResolutionParameterSceneConfigId() const;
        unsigned int GetStageCommonTimeProgressParameterSceneConfigId() const;

        void AddFxRenderTargetSettingSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::FxRenderTargetSetting* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddFxAntiAliasingSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxAntiAliasing* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddStageCommonAtmosphereParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::StageCommonAtmosphereParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddFxLODParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxLODParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddFxDetailParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxDetailParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddFxDynamicResolutionParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxDynamicResolutionParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);
        void AddStageCommonTimeProgressParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::StageCommonTimeProgressParameter* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime);

        void UpdateFxRenderTargetSettingSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::FxRenderTargetSetting* value);
        void UpdateFxAntiAliasingSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxAntiAliasing* value);
        void UpdateStageCommonAtmosphereParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::StageCommonAtmosphereParameter* value);
        void UpdateFxLODParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxLODParameter* value);
        void UpdateFxDetailParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxDetailParameter* value);
        void UpdateFxDynamicResolutionParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::needle::FxDynamicResolutionParameter* value);
        void UpdateStageCommonTimeProgressParameterSceneConfigInterpolatorJob(uint64_t ownerId, const hh::gfx::StageCommonTimeProgressParameter* value);

        void RemoveFxRenderTargetSettingSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveFxAntiAliasingSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveStageCommonAtmosphereParameterSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveFxLODParameterSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveFxDetailParameterSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveFxDynamicResolutionParameterSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);
        void RemoveStageCommonTimeProgressParameterSceneConfigInterpolatorJob(size_t ownerId, float interpolationTime);

		GAMESERVICE_CLASS_DECLARATION(FxParamManager)
    };
}
