#pragma once

namespace hh::needle {
    class RenderUnit;
    class RenderProperty;
    class SceneParamContainer : public NeedleRefcountObject {
    public:
        template<typename T>
        class ParamHolder : public NeedleObject {
        public:
            class Listener : public NeedleObject {
                RenderProperty* renderProperty;
            public:
                virtual ~Listener() = default;
                virtual void ParamChangedCallback(const T& previousValue, const T& newValue) = 0;
            };

            Listener* listener;
            bool isSet;
            T data;
        };

        csl::ut::PointerMap<CNameIDObject*, void*> params;
        RenderUnit* renderUnit;
        uint32_t unk1;

        void InitGlobalParams();
        void CreateGlobalParamListeners();

        template<typename T> ParamHolder<T>* GetSceneParam();
        // template<> ParamHolder<FxBloomParameter>* GetSceneParam();
        // template<> ParamHolder<FxDOFParameter>* GetSceneParam();
        // template<> ParamHolder<FxColorContrastParameter>* GetSceneParam();
        // template<> ParamHolder<FxToneMapParameter>* GetSceneParam();
        // template<> ParamHolder<FxCameraControlParameter>* GetSceneParam();
        // template<> ParamHolder<FxShadowMapParameter>* GetSceneParam();
        // template<> ParamHolder<FxShadowHeightMapParameter>* GetSceneParam();
        // template<> ParamHolder<FxVolumetricShadowParameter>* GetSceneParam();
        // template<> ParamHolder<FxScreenBlurParameter>* GetSceneParam();
        // template<> ParamHolder<FxSSAOParameter>* GetSceneParam();
        // template<> ParamHolder<FxSHLightFieldParameter>* GetSceneParam();
        // template<> ParamHolder<FxLightScatteringParameter>* GetSceneParam();
        // template<> ParamHolder<FxRLRParameter>* GetSceneParam();
        // template<> ParamHolder<FxSSGIParameter>* GetSceneParam();
        // template<> ParamHolder<FxPlanarReflectionParameter>* GetSceneParam();
        // template<> ParamHolder<FxOcclusionCapsuleParameter>* GetSceneParam();
        // template<> ParamHolder<FxGodrayParameter>* GetSceneParam();
        // template<> ParamHolder<FxScreenSpaceGodrayParameter>* GetSceneParam();
        // template<> ParamHolder<FxHeatHazeParameter>* GetSceneParam();
        // template<> ParamHolder<FxSceneEnvironmentParameter>* GetSceneParam();
        // template<> ParamHolder<FxRenderOption>* GetSceneParam();
        // template<> ParamHolder<FxSGGIParameter>* GetSceneParam();
        // template<> ParamHolder<FxTAAParameter>* GetSceneParam();
        // template<> ParamHolder<FxEffectParameter>* GetSceneParam();
        // template<> ParamHolder<FxAtmosphereParameter>* GetSceneParam();
        // template<> ParamHolder<FxDensityParameter>* GetSceneParam();
        // template<> ParamHolder<FxWindComputeParameter>* GetSceneParam();
        // template<> ParamHolder<FxGpuEnvironmentParameter>* GetSceneParam();
        // template<> ParamHolder<FxInteractiveWaveParameter>* GetSceneParam();
        // template<> ParamHolder<FxChromaticAberrationParameter>* GetSceneParam();
        // template<> ParamHolder<FxVignetteParameter>* GetSceneParam();
        // template<> ParamHolder<FxTerrainMaterialBlendingParameter>* GetSceneParam();
        // template<> ParamHolder<FxWeatherParameter>* GetSceneParam();
        // template<> ParamHolder<FxColorAccessibilityFilterParameter>* GetSceneParam();
        // template<> ParamHolder<FxCyberNoiseEffectParameter>* GetSceneParam();
        // template<> ParamHolder<FxCyberSpaceStartNoiseParameter>* GetSceneParam();
        // template<> ParamHolder<FxCyberNPCSSEffectRenderParameter>* GetSceneParam();
        // template<> ParamHolder<FxFieldScanEffectRenderParameter>* GetSceneParam();
        // template<> ParamHolder<FxSeparableSSSParameter>* GetSceneParam();
        // template<> ParamHolder<FxAntiAliasing>* GetSceneParam();
        // template<> ParamHolder<gfx::FxDentParameter>* GetSceneParam();
    
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
    };
}
