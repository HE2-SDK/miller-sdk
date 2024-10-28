#pragma once

namespace heur::rfl {
    struct GOCSimpleAnimationSpawner {
        csl::ut::VariableString resSkeleton;
        csl::ut::VariableString resAnimation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCSimpleAnimationSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCSimpleAnimationSpawner* pInstance);
        static void Clean(GOCSimpleAnimationSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DecoConfigParam {
        csl::ut::Color8 clientColor;
        uint8_t windowAlpha;
        csl::ut::Color8 startGradationGuideColor;
        csl::ut::Color8 endGradationGuideColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoConfigParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoConfigParam* pInstance);
        static void Clean(DecoConfigParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoBlurParam {
        int32_t radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoBlurParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoBlurParam* pInstance);
        static void Clean(DecoBlurParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoDropShadowParam {
        csl::ut::Color8 color;
        uint8_t size;
        uint8_t spread;
        int8_t distanceX;
        int8_t distanceY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoDropShadowParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoDropShadowParam* pInstance);
        static void Clean(DecoDropShadowParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoGradationParam {
        enum class Orientation : int8_t {
            ORIENTATION_NONE = 0,
            ORIENTATION_HORIZONTAL = 1,
            ORIENTATION_VERTICAL = 2,
            ORIENTATION_DIAGONAL = 3,
        };

        Orientation orientation;
        int8_t srcPosX;
        int8_t srcPosY;
        int8_t dstPosX;
        int8_t dstPosY;
        csl::ut::Color8 srcColor;
        csl::ut::Color8 dstColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoGradationParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoGradationParam* pInstance);
        static void Clean(DecoGradationParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoRimParam {
        csl::ut::Color8 color;
        int32_t thickness;
        int32_t offsetX;
        int32_t offsetY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoRimParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoRimParam* pInstance);
        static void Clean(DecoRimParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoPassParam {
        heur::rfl::DecoDropShadowParam dropShadow;
        heur::rfl::DecoRimParam rim;
        heur::rfl::DecoGradationParam gradation;
        heur::rfl::DecoBlurParam blur;
        bool avoidEdgeArtifact;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoPassParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoPassParam* pInstance);
        static void Clean(DecoPassParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoTechParam {
        enum class DecoLayerBlendOp : int8_t {
            DECO_LAYER_BLEND_OP_BLEND = 0,
            DECO_LAYER_BLEND_OP_SUBTRACT_ALPHA = 1,
        };

        csl::ut::VariableString name;
        csl::ut::Color8 fontColor;
        heur::rfl::DecoGradationParam fontGradParam;
        DecoLayerBlendOp layerBlendOp;
        int32_t numPasses;
        heur::rfl::DecoPassParam passParams[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoTechParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoTechParam* pInstance);
        static void Clean(DecoTechParam* pInstance);
    };
}

namespace heur::rfl {
    struct DecoTechParams {
        heur::rfl::DecoTechParam params[512];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DecoTechParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DecoTechParams* pInstance);
        static void Clean(DecoTechParams* pInstance);
    };
}

namespace heur::rfl {
    struct StatsDataValue {
        enum class StatsType : int32_t {
            TYPE_INVALID = 0,
            TYPE_UINT64 = 1,
            TYPE_UINT32 = 2,
            TYPE_SINT32 = 3,
            TYPE_FLOAT = 4,
        };

        StatsType type;
        uint64_t value;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatsDataValue* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatsDataValue* pInstance);
        static void Clean(StatsDataValue* pInstance);
    };
}

namespace heur::rfl {
    struct StatsDataContainer {
        csl::ut::MoveArray<heur::rfl::StatsDataValue> data;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatsDataContainer* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatsDataContainer* pInstance);
        static void Clean(StatsDataContainer* pInstance);
    };
}

namespace heur::rfl {
    struct GOCActivatorSpawner {
        float m_range;
        float m_distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCActivatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCActivatorSpawner* pInstance);
        static void Clean(GOCActivatorSpawner* pInstance);
    };
}

namespace hh::needle {
    struct FxCullingSettings {
        float rangeDefault;
        float rangeNear;
        float rangeMiddle;
        float rangeFar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCullingSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCullingSettings* pInstance);
        static void Clean(FxCullingSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxDofSettings {
        bool enable;
        bool ignoreSky;
        float focus;
        float znear;
        float zfar;
        float focusRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDofSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDofSettings* pInstance);
        static void Clean(FxDofSettings* pInstance);
    };
}

namespace hh::needle {
    struct FxEffectSettings {
        float lightScale;
        float shadowScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxEffectSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxEffectSettings* pInstance);
        static void Clean(FxEffectSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxGlareSettings {
        bool enable;
        float brightPassThreshold;
        float brightPassInvScale;
        float persistent;
        float bloomScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGlareSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGlareSettings* pInstance);
        static void Clean(FxGlareSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxGrassSettings {
        bool grassIsHide;
        float grassHeightMin;
        float grassHeight;
        float grassWidth;
        float grassFar;
        float grassFarEnd;
        float grassWindAxis;
        float grassWindSpeed;
        float grassWindCycle;
        float grassWindStrength;
        uint32_t grassDupCount;
        float grassDupRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGrassSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGrassSettings* pInstance);
        static void Clean(FxGrassSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxHdrSettings {
        bool enable;
        bool adaptationEnable;
        float adaptationRatio;
        float middleGray;
        float luminanceLow;
        float luminanceHigh;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHdrSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHdrSettings* pInstance);
        static void Clean(FxHdrSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxHourSettings {
        float middleGray;
        csl::math::Vector3 baseColor;
        csl::math::Vector3 light;
        float skyIntensity;
        csl::math::Vector3 sky;
        csl::math::Vector3 ambient;
        csl::math::Vector3 lightScattering;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHourSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHourSettings* pInstance);
        static void Clean(FxHourSettings* pInstance);
    };
}

namespace hh::needle {
    struct FxInShadowShadowScaleSettings {
        float shadowScaleX;
        float shadowScaleY;
        float shadowScaleLightFieldY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxInShadowShadowScaleSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxInShadowShadowScaleSettings* pInstance);
        static void Clean(FxInShadowShadowScaleSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxLightFieldSettings {
        enum class SaturationScalingType : int8_t {
            SATURATION_KEEPING_LUMINANCE = 0,
            SATURATION_KEEPING_BRIGHTNESS = 1,
            SATURATION_NONE = 2,
        };

        bool ignoreData;
        int8_t defaultUpdateInterval;
        csl::math::Vector3 offsetColorUp;
        csl::math::Vector3 offsetColorDown;
        SaturationScalingType saturationScalingType;
        float saturationScalingRate;
        float luminanceScalingRate;
        bool disableFinalAdjustColor;
        float luminanceMin;
        float luminanceMax;
        float luminanceMidium;
        float intensityThreshold;
        float intensityBias;
        float defaultInterruption;
        csl::math::Vector3 defaultColorUp;
        csl::math::Vector3 defaultColorDown;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightFieldSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightFieldSettings* pInstance);
        static void Clean(FxLightFieldSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxLightScatteringSettings {
        bool enable;
        csl::math::Vector3 color;
        float depthScale;
        float inScatteringScale;
        float rayleigh;
        float mie;
        float g;
        float znear;
        float zfar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightScatteringSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightScatteringSettings* pInstance);
        static void Clean(FxLightScatteringSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxLightSettings {
        enum class EyeLightMode : int8_t {
            LIGHTMODE_DIR = 0,
            LIGHTMODE_POINT = 1,
        };

        bool globalLightEnable;
        bool ambLightEnable;
        bool allLocalLightEnable;
        bool eyeLightEnable;
        EyeLightMode eyeLightMode;
        csl::math::Vector3 eyeLightDiffuse;
        csl::math::Vector3 eyeLightSpecular;
        float eyeLightRangeStart;
        float eyeLightRangeEnd;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightSettings* pInstance);
        static void Clean(FxLightSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxOnSceneShadowScaleSettings {
        float shadowScaleZ;
        float shadowScaleW;
        float shadowScaleLightFieldW;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxOnSceneShadowScaleSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxOnSceneShadowScaleSettings* pInstance);
        static void Clean(FxOnSceneShadowScaleSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxSceneSettings {
        enum class PeepingPlayerType : int8_t {
            TYPE_DEFAULT = 0,
            TYPE_EDGE = 1,
        };

        float skyIntensityScale;
        float skyFollowupRatioY;
        bool pseudoFogEnable;
        bool pseudoFogWithoutFar;
        bool pseudoDof;
        bool deepBlurEnable;
        bool noBlurEnable;
        float blurScale;
        bool peepingPlayerEnable;
        float occCheckedPlayerTime;
        PeepingPlayerType peepingPlayerType;
        bool clearFirstSurface;
        bool useManualZPrepass;
        bool useCaptureFramebufferColor;
        bool useCaptureFramebufferDepth;
        bool playerDrawOverlay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneSettings* pInstance);
        static void Clean(FxSceneSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxTimeChangeSettings {
        enum class TimeType : int8_t {
            TIME_NONE = 0,
            TIME_MORNING = 1,
            TIME_DAY = 2,
            TIME_EVENING = 3,
            TIME_NIGHT = 4,
        };

        bool enable;
        bool ignoreSky;
        TimeType timeDebugIndex;
        float morning;
        float day;
        float evening;
        float night;
        heur::rfl::FxHourSettings hourParams[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTimeChangeSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTimeChangeSettings* pInstance);
        static void Clean(FxTimeChangeSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FxShadowScale {
        hh::needle::FxInShadowShadowScaleSettings shadowScaleInShadow;
        heur::rfl::FxOnSceneShadowScaleSettings shadowScaleOnScene;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxShadowScale* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxShadowScale* pInstance);
        static void Clean(FxShadowScale* pInstance);
    };
}

namespace heur::rfl {
    struct FxStageDistortion {
        bool distortionIsUse;
        float distortionSpeed;
        float distortionPower;
        float distortionDensity;
        float distortionDepthDensity;
        float distortionPowerBloom;
        float distortionPowerDepth;
        float distortionPowerFront;
        float distortionDensityFront;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxStageDistortion* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxStageDistortion* pInstance);
        static void Clean(FxStageDistortion* pInstance);
    };
}

namespace heur::rfl {
    struct FxStencilShadow {
        bool enable;
        csl::math::Vector3 shadowColor;
        float shadowAlpha;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxStencilShadow* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxStencilShadow* pInstance);
        static void Clean(FxStencilShadow* pInstance);
    };
}

namespace heur::rfl {
    struct FxSceneCasinoLight {
        bool isUseCasinoLight;
        csl::math::Vector3 casinoLightAABBMin;
        csl::math::Vector3 casinoLightAABBMax;
        float casinoLightMoveRatio;
        float casinoLightStrengthMax;
        float casinoLightRadMin;
        float casinoLightRadMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneCasinoLight* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneCasinoLight* pInstance);
        static void Clean(FxSceneCasinoLight* pInstance);
    };
}

namespace hh::needle {
    struct FxParameter {
        hh::needle::FxCullingSettings culling;
        heur::rfl::FxSceneSettings scene;
        heur::rfl::FxLightSettings light;
        heur::rfl::FxLightFieldSettings lightField;
        heur::rfl::FxLightScatteringSettings olsNear;
        bool separateOlsLayer;
        heur::rfl::FxLightScatteringSettings olsFar;
        heur::rfl::FxHdrSettings hdr;
        heur::rfl::FxGlareSettings glare;
        heur::rfl::FxDofSettings dof;
        heur::rfl::FxTimeChangeSettings timeChange;
        heur::rfl::FxShadowScale shadowScale;
        heur::rfl::FxGrassSettings grassSetting;
        heur::rfl::FxStageDistortion stageDistortion;
        heur::rfl::FxStencilShadow stencilShadow;
        hh::needle::FxEffectSettings effect;
        heur::rfl::FxSceneCasinoLight casinoLight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxParameter* pInstance);
        static void Clean(FxParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FxSceneConfig {
        enum class GIModeTypes : int8_t {
            GIMODE_NORMAL = 0,
            GIMODE_ONLY = 1,
            GIMODE_NONE = 2,
            GIMODE_SHADOW = 3,
            GIMODE_SEPARATED = 4,
        };

        enum class LightFieldModeTypes : int8_t {
            LFMODE_NORMAL = 0,
            LFMODE_ONLY = 1,
            LFMODE_NONE = 2,
        };

        float gammaTVWiiU;
        float gammaDRCWiiU;
        bool fixedLdr;
        GIModeTypes giMode;
        LightFieldModeTypes lightFieldMode;
        bool drawLightFieldSamplingPoints;
        bool updateLightFieldEachFrame;
        bool drawLightFieldRegion;
        int32_t screenshotLargeScale;
        bool drawFxColGeom;
        bool drawFxColName;
        bool drawLocalLightSphere;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneConfig* pInstance);
        static void Clean(FxSceneConfig* pInstance);
    };
}

namespace heur::rfl {
    struct FxSceneData {
        heur::rfl::FxSceneConfig config;
        hh::needle::FxParameter items[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneData* pInstance);
        static void Clean(FxSceneData* pInstance);
    };
}

namespace heur::rfl {
    struct GOCVisualModelSpawner {
        csl::ut::VariableString resModel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCVisualModelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCVisualModelSpawner* pInstance);
        static void Clean(GOCVisualModelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheShader {
        csl::ut::VariableString Name;
        csl::ut::MoveArray<csl::ut::VariableString> Variation;
        uint32_t Hash;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheShader* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheShader* pInstance);
        static void Clean(PSOCacheShader* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheRenderTargetBlend {
        enum class BLEND : uint8_t {
            BLEND_INVALID = 0,
            ZERO = 1,
            ONE = 2,
            SRC_COLOR = 3,
            INV_SRC_COLOR = 4,
            SRC_ALPHA = 5,
            INV_SRC_ALPHA = 6,
            DEST_ALPHA = 7,
            INV_DEST_ALPHA = 8,
            DEST_COLOR = 9,
            INV_DEST_COLOR = 10,
            SRC_ALPHA_SAT = 11,
            BLEND_FACTOR = 12,
            INV_BLEND_FACTOR = 13,
            SRC1_COLOR = 14,
            INV_SRC1_COLOR = 15,
            SRC1_ALPHA = 16,
            INV_SRC1_ALPHA = 17,
        };

        enum class BLEND_OP : uint8_t {
            BLEND_OP_INVALID = 0,
            ADD = 1,
            SUBTRACT = 2,
            REV_SUBTRACT = 3,
            MIN = 4,
            MAX = 5,
        };

        enum class LOGIC_OP : uint8_t {
            LOGIC_OP_CLEAR = 0,
            LOGIC_OP_SET = 1,
            LOGIC_OP_COPY = 2,
            LOGIC_OP_COPY_INVERTED = 3,
            LOGIC_OP_NOOP = 4,
            LOGIC_OP_INVERT = 5,
            LOGIC_OP_AND = 6,
            LOGIC_OP_NAND = 7,
            LOGIC_OP_OR = 8,
            LOGIC_OP_NOR = 9,
            LOGIC_OP_XOR = 10,
            LOGIC_OP_EQUIV = 11,
            LOGIC_OP_AND_REVERSE = 12,
            LOGIC_OP_AND_INVERTED = 13,
            LOGIC_OP_OR_REVERSE = 14,
            LOGIC_OP_OR_INVERTED = 15,
        };

        bool BlendEnable;
        bool LogicOpEnable;
        BLEND SrcBlend;
        BLEND DestBlend;
        BLEND_OP BlendOp;
        BLEND SrcBlendAlpha;
        BLEND DestBlendAlpha;
        BLEND_OP BlendOpAlpha;
        LOGIC_OP LogicOp;
        uint8_t RenderTargetWriteMask;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheRenderTargetBlend* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheRenderTargetBlend* pInstance);
        static void Clean(PSOCacheRenderTargetBlend* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheBlend {
        bool AlphaToCoverageEnable;
        bool IndependentBlendEnable;
        heur::rfl::PSOCacheRenderTargetBlend RenderTarget[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheBlend* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheBlend* pInstance);
        static void Clean(PSOCacheBlend* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheRasterizer {
        enum class FILL_MODE : uint8_t {
            FILL_MODE_INVALID = 0,
            FILL_MODE_INVALID2 = 1,
            FILL_MODE_WIREFRAME = 2,
            FILL_MODE_SOLID = 3,
        };

        enum class CULL_MODE : uint8_t {
            CULL_MODE_INVALID = 0,
            CULL_MODE_NONE = 1,
            CULL_MODE_FRONT = 2,
            CULL_MODE_BACK = 3,
        };

        FILL_MODE FillMode;
        CULL_MODE CullMode;
        bool FrontCounterClockwise;
        int32_t DepthBias;
        float DepthBiasClamp;
        float SlopeScaledDepthBias;
        bool DepthClipEnable;
        bool MultisampleEnable;
        bool AntialiasedLineEnable;
        uint32_t ForcedSampleCount;
        bool ConservativeRaster;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheRasterizer* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheRasterizer* pInstance);
        static void Clean(PSOCacheRasterizer* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheDepthStencilOp {
        enum class STENCIL_OP : uint8_t {
            STENCIL_OP_INVALID = 0,
            STENCIL_OP_KEEP = 1,
            STENCIL_OP_ZERO = 2,
            STENCIL_OP_REPLACE = 3,
            STENCIL_OP_INCR_SAT = 4,
            STENCIL_OP_DECR_SAT = 5,
            STENCIL_OP_INVERT = 6,
            STENCIL_OP_INCR = 7,
            STENCIL_OP_DECR = 8,
        };

        enum class COMPARISON_FUNC : uint8_t {
            COMPARISON_FUNC_INVALID = 0,
            COMPARISON_FUNC_NEVER = 1,
            COMPARISON_FUNC_LESS = 2,
            COMPARISON_FUNC_EQUAL = 3,
            COMPARISON_FUNC_LESS_EQUAL = 4,
            COMPARISON_FUNC_GREATER = 5,
            COMPARISON_FUNC_NOT_EQUAL = 6,
            COMPARISON_FUNC_GREATER_EQUAL = 7,
            COMPARISON_FUNC_ALWAYS = 8,
        };

        STENCIL_OP StencilFailOp;
        STENCIL_OP StencilDepthFailOp;
        STENCIL_OP StencilPassOp;
        COMPARISON_FUNC StencilFunc;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheDepthStencilOp* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheDepthStencilOp* pInstance);
        static void Clean(PSOCacheDepthStencilOp* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheDepthStencil {
        bool DepthEnable;
        bool DepthWriteMask;
        heur::rfl::PSOCacheDepthStencilOp DepthFunc;
        bool StencilEnable;
        uint8_t StencilReadMask;
        uint8_t StencilWriteMask;
        heur::rfl::PSOCacheDepthStencilOp FrontFace;
        heur::rfl::PSOCacheDepthStencilOp BackFace;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheDepthStencil* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheDepthStencil* pInstance);
        static void Clean(PSOCacheDepthStencil* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheInputElement {
        csl::ut::VariableString SemanticName;
        uint32_t SemanticIndex;
        uint32_t Format;
        uint32_t InputSlot;
        uint32_t AlignedByteOffset;
        bool InputSlotClass;
        uint32_t InstanceDataStepRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheInputElement* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheInputElement* pInstance);
        static void Clean(PSOCacheInputElement* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheInputLayout {
        csl::ut::MoveArray<heur::rfl::PSOCacheInputElement> InputElements;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheInputLayout* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheInputLayout* pInstance);
        static void Clean(PSOCacheInputLayout* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheSample {
        uint32_t Count;
        uint32_t Quality;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheSample* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheSample* pInstance);
        static void Clean(PSOCacheSample* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCache {
        enum class TYPE : uint8_t {
            GRAPHICS = 0,
            COMPUTE = 1,
            MESHLET = 2,
        };

        TYPE Type;
        heur::rfl::PSOCacheShader VS;
        heur::rfl::PSOCacheShader PS;
        heur::rfl::PSOCacheShader CS;
        heur::rfl::PSOCacheBlend BlendState;
        uint32_t SampleMask;
        heur::rfl::PSOCacheRasterizer RasterizerState;
        heur::rfl::PSOCacheDepthStencil DepthStencilState;
        heur::rfl::PSOCacheInputLayout InputLayout;
        uint32_t IBStripCutValue;
        uint32_t PrimitiveTopologyType;
        uint32_t NumRenderTargets;
        uint32_t RTVFormats[8];
        uint32_t DSVFormat;
        heur::rfl::PSOCacheSample SampleDesc;
        uint32_t NodeMask;
        uint32_t Flags;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCache* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCache* pInstance);
        static void Clean(PSOCache* pInstance);
    };
}

namespace heur::rfl {
    struct PSOCacheList {
        uint32_t version;
        csl::ut::MoveArray<heur::rfl::PSOCache> caches;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PSOCacheList* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PSOCacheList* pInstance);
        static void Clean(PSOCacheList* pInstance);
    };
}

namespace heur::rfl {
    struct Agent {
        float radius;
        float height;
        float maxClimb;
        float maxSlope;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Agent* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Agent* pInstance);
        static void Clean(Agent* pInstance);
    };
}

namespace heur::rfl {
    struct DetailMesh {
        float sampleDistance;
        float sampleMaxError;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DetailMesh* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DetailMesh* pInstance);
        static void Clean(DetailMesh* pInstance);
    };
}

namespace heur::rfl {
    struct OffMeshLinkElement {
        enum class OffMeshLinkDirection : uint8_t {
            OffMeshLinkUnidirectional = 0,
            OffMeshLinkBidirectional = 1,
        };

        csl::math::Vector3 source;
        csl::math::Vector3 destination;
        float radius;
        uint16_t flags;
        uint8_t area;
        OffMeshLinkDirection direction;
        uint32_t userID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OffMeshLinkElement* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OffMeshLinkElement* pInstance);
        static void Clean(OffMeshLinkElement* pInstance);
    };
}

namespace heur::rfl {
    struct OffMeshLinkParameter {
        csl::ut::MoveArray<heur::rfl::OffMeshLinkElement> elements;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OffMeshLinkParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OffMeshLinkParameter* pInstance);
        static void Clean(OffMeshLinkParameter* pInstance);
    };
}

namespace heur::rfl {
    struct Filtering {
        bool lowHangingObstacles;
        bool ledgeSpans;
        bool walkableLowHeightSpans;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Filtering* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Filtering* pInstance);
        static void Clean(Filtering* pInstance);
    };
}

namespace heur::rfl {
    struct World {
        csl::math::Vector3 aabbMin;
        csl::math::Vector3 aabbMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(World* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(World* pInstance);
        static void Clean(World* pInstance);
    };
}

namespace heur::rfl {
    struct Rasterization {
        float voxelSize;
        float voxelHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Rasterization* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Rasterization* pInstance);
        static void Clean(Rasterization* pInstance);
    };
}

namespace heur::rfl {
    struct Region {
        int32_t minArea;
        int32_t mergeArea;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Region* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Region* pInstance);
        static void Clean(Region* pInstance);
    };
}

namespace heur::rfl {
    struct Partitioning {
        enum class Partition : uint8_t {
            Watershed = 0,
            Monotone = 1,
            Layers = 2,
        };

        Partition type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Partitioning* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Partitioning* pInstance);
        static void Clean(Partitioning* pInstance);
    };
}

namespace heur::rfl {
    struct Polygonization {
        float edgeMaxLength;
        float maxSimplificationError;
        int32_t vertsPerPoly;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Polygonization* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Polygonization* pInstance);
        static void Clean(Polygonization* pInstance);
    };
}

namespace heur::rfl {
    struct Tiling {
        float size;
        int32_t maxTiles;
        bool cache;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Tiling* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Tiling* pInstance);
        static void Clean(Tiling* pInstance);
    };
}

namespace heur::rfl {
    struct NavMeshParameter {
        heur::rfl::World world;
        heur::rfl::Rasterization rasterization;
        heur::rfl::Agent agent;
        heur::rfl::Region region;
        heur::rfl::Partitioning partitioning;
        heur::rfl::Filtering filtering;
        heur::rfl::Polygonization polygonization;
        heur::rfl::DetailMesh detailMesh;
        heur::rfl::Tiling tiling;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NavMeshParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NavMeshParameter* pInstance);
        static void Clean(NavMeshParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxStaticSkyDomeParameter {
        enum class IBLType : int8_t {
            DefaultIBL = 0,
            CreateFromSkyCube = 1,
            None = 2,
        };

        bool showSkyCube;
        IBLType iblType;
        float flatteningY;
        float flatteningXZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxStaticSkyDomeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxStaticSkyDomeParameter* pInstance);
        static void Clean(FxStaticSkyDomeParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSunPosAngle {
        float azimuthAngle;
        float elevationAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSunPosAngle* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSunPosAngle* pInstance);
        static void Clean(FxSunPosAngle* pInstance);
    };
}

namespace hh::needle {
    struct FxSunPosEarth {
        float azimuthAngle;
        float latitude;
        float longitude;
        int32_t month;
        int32_t day;
        float time;
        bool enableAnimation;
        float animationSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSunPosEarth* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSunPosEarth* pInstance);
        static void Clean(FxSunPosEarth* pInstance);
    };
}

namespace hh::needle {
    struct FxSun {
        enum class SunPosType : int8_t {
            SUN_POS_TYPE_NONE = 0,
            SUN_POS_TYPE_ANGLE = 1,
            SUN_POS_TYPE_EARTH = 2,
        };

        float solarRadiusScale;
        SunPosType sunPosType;
        hh::needle::FxSunPosAngle posTypeAngle;
        hh::needle::FxSunPosEarth posTypeEarth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSun* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSun* pInstance);
        static void Clean(FxSun* pInstance);
    };
}

namespace hh::needle {
    struct FxMoon {
        enum class MoonPosType : int8_t {
            MOON_POS_TYPE_NONE = 0,
            MOON_POS_TYPE_INV_SUN = 1,
            MOON_POS_TYPE_EARTH = 2,
        };

        MoonPosType moonPosType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxMoon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxMoon* pInstance);
        static void Clean(FxMoon* pInstance);
    };
}

namespace hh::needle {
    struct FxSkyCommon {
        enum class SkyModel : int8_t {
            BRUNETON = 0,
            SEBASTIEN = 1,
        };

        SkyModel skyModel;
        float illuminanceScale;
        bool enableScattering;
        float scatteringRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSkyCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSkyCommon* pInstance);
        static void Clean(FxSkyCommon* pInstance);
    };
}

namespace hh::needle {
    struct FxBrunetonSkyNight {
        float lunarIntensityInSky;
        float starIntensityInSky;
        float lunarIntensityInCloud;
        float lunarIntensity;
        float skyIntensity;
        csl::ut::Color8 lunarLightColor;
        csl::math::Vector4 lunarLightColorOffset;
        float lunarLightPower;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxBrunetonSkyNight* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxBrunetonSkyNight* pInstance);
        static void Clean(FxBrunetonSkyNight* pInstance);
    };
}

namespace hh::needle {
    struct FxBrunetonSky {
        float illuminanceScale;
        csl::ut::Color8 rayleighColor;
        csl::ut::Color8 lightColorScale;
        float miePhaseFunctionG;
        csl::ut::Color8 mieScatteringColor;
        float mieScatteringScale;
        csl::ut::Color8 mieAbsorptionColor;
        float mieAbsorptionScale;
        csl::ut::Color8 rayleighScatteringColor;
        float rayleighScatteringScale;
        csl::ut::Color8 groundAlbedo;
        csl::ut::Color8 groundIrradianceScale;
        csl::ut::Color8 cubemapColorScale;
        float cubemapColorAngleRatio;
        bool enableScattering;
        float scatteringRatio;
        hh::needle::FxBrunetonSkyNight night;
        bool enableLimitY;
        float debugSkyCubeIntensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxBrunetonSky* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxBrunetonSky* pInstance);
        static void Clean(FxBrunetonSky* pInstance);
    };
}

namespace hh::needle {
    struct FxSebastienSky {
        float miePhaseFunctionG;
        csl::ut::Color8 mieScatteringColor;
        csl::math::Vector4 mieScatteringColorOffset;
        float mieScatteringScale;
        csl::ut::Color8 mieAbsorptionColor;
        csl::math::Vector4 mieAbsorptionColorOffset;
        float mieAbsorptionScale;
        csl::ut::Color8 rayleighScatteringColor;
        csl::math::Vector4 rayleighScatteringColorOffset;
        float rayleighScatteringScale;
        csl::ut::Color8 groundAlbedo;
        csl::math::Vector4 groundAlbedoOffset;
        bool enableGround;
        int32_t numScatteringOrder;
        bool enableScattering;
        bool enableLimitY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSebastienSky* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSebastienSky* pInstance);
        static void Clean(FxSebastienSky* pInstance);
    };
}

namespace hh::needle {
    struct FxCloudProcedural {
        csl::math::Vector3 uvScale;
        csl::math::Vector3 colorGamma;
        csl::math::Vector3 colorScale;
        csl::math::Vector3 colorOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCloudProcedural* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCloudProcedural* pInstance);
        static void Clean(FxCloudProcedural* pInstance);
    };
}

namespace hh::needle {
    struct FxCloudBlendParameter {
        bool enable;
        float probability;
        float cloudiness;
        hh::needle::FxCloudProcedural proceduralCloud;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCloudBlendParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCloudBlendParameter* pInstance);
        static void Clean(FxCloudBlendParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FxCloudParameter {
        bool enable;
        bool enableAnimation;
        float animationFrame;
        float animationSpeed;
        float animationAngle;
        float animationSpeedCirrus;
        float animationAngleCirrus;
        float skyHorizonOffset;
        float cloudStartHeight;
        float cloudCoverageSpeed;
        float cloudTypeSpeed;
        float cloudWetnessSpeed;
        float miePhaseFunctionG;
        float silverIntensity;
        float silverSpread;
        float scale;
        float density;
        float densityThreshold;
        csl::ut::Color8 cloudsExtinctionColor1;
        csl::math::Vector4 cloudsExtinctionColor1Offset;
        csl::ut::Color8 cloudsExtinctionColor2;
        csl::math::Vector4 cloudsExtinctionColor2Offset;
        csl::ut::Color8 cloudsExtinctionColor3;
        csl::math::Vector4 cloudsExtinctionColor3Offset;
        float cloudExtinctionBlend;
        bool enableShadow;
        int32_t shadowCoverage;
        float shadowValueMin;
        hh::needle::FxCloudBlendParameter blendParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCloudParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCloudParameter* pInstance);
        static void Clean(FxCloudParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxCrepuscularRay {
        bool enable;
        float density;
        float decay;
        float weight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCrepuscularRay* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCrepuscularRay* pInstance);
        static void Clean(FxCrepuscularRay* pInstance);
    };
}

namespace hh::needle {
    struct FxManualHeightFog {
        csl::math::Vector3 sunColor;
        csl::math::Vector3 ambColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxManualHeightFog* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxManualHeightFog* pInstance);
        static void Clean(FxManualHeightFog* pInstance);
    };
}

namespace hh::needle {
    struct FxHeightFog {
        bool enable;
        bool enableFogMap;
        float heightScale;
        float distanceOffset;
        float distanceScale;
        csl::math::Vector3 rayleighScale;
        csl::math::Vector3 mieScale;
        float noiseBlend;
        float noiseScale;
        float noiseDistance;
        float animationSpeed;
        float animationAngle;
        bool isAtmospheric;
        hh::needle::FxManualHeightFog manualFog;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHeightFog* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHeightFog* pInstance);
        static void Clean(FxHeightFog* pInstance);
    };
}

namespace hh::needle {
    struct FxAtmosphereParameter {
        bool enable;
        hh::needle::FxStaticSkyDomeParameter staticSkyDome;
        hh::needle::FxSun sunParam;
        hh::needle::FxMoon moonParam;
        hh::needle::FxSkyCommon commonSkyParam;
        hh::needle::FxBrunetonSky brunetonSkyParam;
        hh::needle::FxSebastienSky sebastienSkyParam;
        heur::rfl::FxCloudParameter cloudParam;
        hh::needle::FxCrepuscularRay crepuscularRayParam;
        hh::needle::FxHeightFog heightFogParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxAtmosphereParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxAtmosphereParameter* pInstance);
        static void Clean(FxAtmosphereParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxCloudShadowParameter {
        bool enableShadow;
        int32_t shadowCoverage;
        float shadowValueMin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCloudShadowParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCloudShadowParameter* pInstance);
        static void Clean(FxCloudShadowParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDensityDebugParameter {
        bool underSelect;
        float factor;
        float unit[32];
        int8_t chunk[32];
        float lodAddition;
        int32_t chunkAddition;
        float drawLimitLenght;
        bool drawCallReduction;
        bool enableDither;
        int32_t ditherGrass;
        int32_t ditherOther;
        int32_t ditherPreComputeGrass;
        int32_t ditherPreComputeOther;
        int32_t computeMode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDensityDebugParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDensityDebugParameter* pInstance);
        static void Clean(FxDensityDebugParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDensityLodParameter {
        float lodRatio;
        float lodRise;
        float lodDecrease;
        float lodThreshold;
        bool lodFadeEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDensityLodParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDensityLodParameter* pInstance);
        static void Clean(FxDensityLodParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDensityParameter {
        enum class PlacementType : int8_t {
            CirclePacking = 0,
            RandomPos = 1,
            PT_COUNT = 2,
        };

        enum class ShadowCullingType : int8_t {
            Normal = 0,
            AabbUpScale2 = 1,
            ShadowFrustum = 2,
        };

        bool enable;
        bool precomputeEnable;
        bool cameraUpdate;
        PlacementType placement;
        float placementScale;
        bool alphaEnable;
        float alphaThreshold;
        float alphaScale;
        bool complementEnable;
        bool disableCut;
        ShadowCullingType shadowCulling;
        bool occlusionCulling;
        float occlusionSize;
        float occlusionShadowSize;
        float occlusionBias;
        hh::needle::FxDensityLodParameter lodParam;
        bool angleCulling;
        float angleCullingParam;
        hh::needle::FxDensityDebugParameter debugParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDensityParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDensityParameter* pInstance);
        static void Clean(FxDensityParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDensityWindParameter {
        float windDir;
        float windPower;
        float windLenght;
        float windSpeed;
        float windRalenght;
        float windRaamp;
        float windRalevel;
        float windRtpower;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDensityWindParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDensityWindParameter* pInstance);
        static void Clean(FxDensityWindParameter* pInstance);
    };
}

namespace hh::gfx {
    struct FxDentParameter {
        bool enable;
        float simRadius;
        float dentDepth;
        float normalIntensity;
        float edgeBulge;
        float fade;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDentParameter* pInstance);
        static void Clean(FxDentParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxLightScatteringParameter {
        bool enable;
        csl::math::Vector3 color;
        float inScatteringScale;
        csl::math::Vector3 betaRayleigh;
        float betaMie;
        float g;
        float znear;
        float zfar;
        float depthScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightScatteringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightScatteringParameter* pInstance);
        static void Clean(FxLightScatteringParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxCyberNoiseEffectParameter {
        bool enable;
        float tileX;
        float tileY;
        float tileScrollSpeed;
        float noiseScrollSpeed;
        float thresholdSpeed;
        float thredholdMin;
        float thredholdMax;
        float selectRate;
        float scanLineRSpeed;
        float scanLineRBlend;
        float scanLineGSpeed;
        float scanLineGBlend;
        float rgbLineScale;
        float rgbLineBlend;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCyberNoiseEffectParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCyberNoiseEffectParameter* pInstance);
        static void Clean(FxCyberNoiseEffectParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxCyberNPCSSEffectRenderParameter {
        bool enable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCyberNPCSSEffectRenderParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCyberNPCSSEffectRenderParameter* pInstance);
        static void Clean(FxCyberNPCSSEffectRenderParameter* pInstance);
    };
}

namespace heur::rfl {
    struct HourMinuteData {
        uint8_t hour;
        uint8_t minute;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HourMinuteData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HourMinuteData* pInstance);
        static void Clean(HourMinuteData* pInstance);
    };
}

namespace heur::rfl {
    struct GlobalLightAngleLimit {
        enum class Type : int8_t {
            NONE = 0,
            SHADOW_LIGHT = 1,
            SHADOW_AND_DISTANT_LIGHT = 2,
        };

        Type type;
        float minLightElevationAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GlobalLightAngleLimit* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GlobalLightAngleLimit* pInstance);
        static void Clean(GlobalLightAngleLimit* pInstance);
    };
}

namespace heur::rfl {
    struct GlobalLightParameter {
        bool enable;
        heur::rfl::GlobalLightAngleLimit limit;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GlobalLightParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GlobalLightParameter* pInstance);
        static void Clean(GlobalLightParameter* pInstance);
    };
}

namespace hh::needle {
    struct DebugScreenOption {
        enum class ChannelMode : int8_t {
            CHANNELMODE_RGB = 0,
            CHANNELMODE_RRR = 1,
            CHANNELMODE_GGG = 2,
            CHANNELMODE_BBB = 3,
            CHANNELMODE_AAA = 4,
            CHANNELMODE_RG = 5,
            CHANNELMODE_BA = 6,
        };

        enum class DebugScreenType : int8_t {
            DEBUG_SCREEN_GBUFFER0 = 0,
            DEBUG_SCREEN_GBUFFER1 = 1,
            DEBUG_SCREEN_GBUFFER2 = 2,
            DEBUG_SCREEN_GBUFFER3 = 3,
            DEBUG_SCREEN_GBUFFER4 = 4,
            DEBUG_SCREEN_DEPTHBUFFER = 5,
            DEBUG_SCREEN_CSM0 = 6,
            DEBUG_SCREEN_CSM1 = 7,
            DEBUG_SCREEN_CSM2 = 8,
            DEBUG_SCREEN_CSM3 = 9,
            DEBUG_SCREEN_HDR = 10,
            DEBUG_SCREEN_BLOOM = 11,
            DEBUG_SCREEN_RLR = 12,
            DEBUG_SCREEN_GODRAY = 13,
            DEBUG_SCREEN_SSAO = 14,
            DEBUG_SCREEN_CSM_CACHE0 = 15,
            DEBUG_SCREEN_CSM_CACHE1 = 16,
            DEBUG_SCREEN_CSM_CACHE2 = 17,
            DEBUG_SCREEN_CSM_CACHE3 = 18,
            DEBUG_SCREEN_CSM_CACHE4 = 19,
            DEBUG_SCREEN_CSM_CACHE5 = 20,
            DEBUG_SCREEN_CUSTOM0 = 21,
            DEBUG_SCREEN_CUSTOM1 = 22,
            DEBUG_SCREEN_CUSTOM2 = 23,
            DEBUG_SCREEN_CUSTOM3 = 24,
            DEBUG_SCREEN_TYPE_NUM = 25,
        };

        enum class ErrorCheckType : int8_t {
            ERROR_CHECK_NONE = 0,
            ERROR_CHECK_NAN = 1,
            ERROR_CHECK_ALBEDO = 2,
            ERROR_CHECK_NORMAL = 3,
        };

        enum class VisualizeMode : int8_t {
            DEFAULT = 0,
            HEATMAP_TYPE0 = 1,
            HEATMAP_TYPE1 = 2,
            HEATMAP_TYPE2 = 3,
            VECTOR2D_TYPE0 = 4,
            VECTOR2D_TYPE1 = 5,
            VECTOR2D_TYPE2 = 6,
        };

        bool enable;
        bool fullScreen;
        ChannelMode channelMode;
        float min;
        float max;
        int32_t renderTargetType;
        int32_t depthTargetType;
        DebugScreenType screenType;
        ErrorCheckType errorCheck;
        VisualizeMode visualizeMode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebugScreenOption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebugScreenOption* pInstance);
        static void Clean(DebugScreenOption* pInstance);
    };
}

namespace heur::rfl {
    struct GlobalUserParamOption {
        bool enable;
        csl::math::Vector4 value;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GlobalUserParamOption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GlobalUserParamOption* pInstance);
        static void Clean(GlobalUserParamOption* pInstance);
    };
}

namespace hh::needle {
    struct FxRenderOption {
        enum class DebugViewType : int8_t {
            DEBUG_VIEW_DEFAULT = 0,
            DEBUG_VIEW_DIR_DIFFUSE = 1,
            DEBUG_VIEW_DIR_SPECULAR = 2,
            DEBUG_VIEW_AMB_DIFFUSE = 3,
            DEBUG_VIEW_AMB_SPECULAR = 4,
            DEBUG_VIEW_ONLY_IBL = 5,
            DEBUG_VIEW_ONLY_IBL_SURF_NORMAL = 6,
            DEBUG_VIEW_SHADOW = 7,
            DEBUG_VIEW_WHITE_ALBEDO = 8,
            DEBUG_VIEW_WHITE_ALBEDO_NO_AO = 9,
            DEBUG_VIEW_USER0 = 10,
            DEBUG_VIEW_USER1 = 11,
            DEBUG_VIEW_USER2 = 12,
            DEBUG_VIEW_USER3 = 13,
            DEBUG_VIEW_ALBEDO = 14,
            DEBUG_VIEW_ALBEDO_CHECK_OUTLIER = 15,
            DEBUG_VIEW_OPACITY = 16,
            DEBUG_VIEW_NORMAL = 17,
            DEBUG_VIEW_ROUGHNESS = 18,
            DEBUG_VIEW_AMBIENT = 19,
            DEBUG_VIEW_CAVITY = 20,
            DEBUG_VIEW_REFLECTANCE = 21,
            DEBUG_VIEW_METALLIC = 22,
            DEBUG_VIEW_LOCAL_LIGHT = 23,
            DEBUG_VIEW_SCATTERING_FEX = 24,
            DEBUG_VIEW_SCATTERING_LIN = 25,
            DEBUG_VIEW_SSAO = 26,
            DEBUG_VIEW_RLR = 27,
            DEBUG_VIEW_IBL_DIFFUSE = 28,
            DEBUG_VIEW_IBL_SPECULAR = 29,
            DEBUG_VIEW_ENV_BRDF = 30,
            DEBUG_VIEW_WORLD_POSITION = 31,
            DEBUG_VIEW_SHADING_MODEL_ID = 32,
            DEBUG_VIEW_IBL_CAPTURE = 33,
            DEBUG_VIEW_IBL_SKY_TERRAIN = 34,
            DEBUG_VIEW_WRITE_DEPTH_TO_ALPHA = 35,
            DEBUG_VIEW_SMOOTHNESS = 36,
            DEBUG_VIEW_OCCLUSION_CAPSULE = 37,
            DEBUG_VIEW_PROBE = 38,
            DEBUG_VIEW_CHARACTER_MASK = 39,
            DEBUG_VIEW_DISTANCE = 40,
            DEBUG_VIEW_SHADING_MODEL = 41,
            DEBUG_VIEW_SHADING_KIND = 42,
            DEBUG_VIEW_AMB_DIFFUSE_LF = 43,
            DEBUG_VIEW_SGGI_ONLY = 44,
            DEBUG_VIEW_COUNT = 45,
            DEBUG_VIEW_INVALID = 45,
        };

        enum class LocalLightCullingType : int8_t {
            LOCAL_LIGHT_CULLING_TYPE_NONE = 0,
            LOCAL_LIGHT_CULLING_TYPE_CPU_TILE = 1,
            LOCAL_LIGHT_CULLING_TYPE_GPU_TILE = 2,
            LOCAL_LIGHT_CULLING_TYPE_GPU_CLUSTER = 3,
            LOCAL_LIGHT_CULLING_TYPE_COUNT = 4,
            LOCAL_LIGHT_CULLING_TYPE_DEFAULT = 0,
        };

        enum class TextureViewType : int8_t {
            TEXTURE_VIEW_NONE = 0,
            TEXTURE_VIEW_DEPTH = 1,
            TEXTURE_VIEW_LUMINANCE = 2,
            TEXTURE_VIEW_DOF_BOKEH = 3,
            TEXTURE_VIEW_DOF_BOKEH_NEAR = 4,
            TEXTURE_VIEW_SSAO_SOURCE = 5,
            TEXTURE_VIEW_DOWNSAMPLE = 6,
            TEXTURE_VIEW_COUNT = 7,
        };

        enum class AmbientSpecularType : int8_t {
            AMBIENT_SPECULAR_NONE = 0,
            AMBIENT_SPECULAR_SG = 1,
            AMBIENT_SPECULAR_IBL = 2,
            AMBIENT_SPECULAR_BLEND = 3,
        };

        enum class DebugGITextureDisable : int8_t {
            DEBUG_GI_TEX_DISABLE_NONE = 0,
            DEBUG_GI_TEX_DISABLE_SGGI = 1,
            DEBUG_GI_TEX_DISABLE_AO = 2,
            DEBUG_GI_TEX_DISABLE_ALL = 3,
            DEBUG_GI_TEX_SGGI_ONLY = 4,
            DEBUG_GI_TEX_AOGI_ONLY = 5,
            DEBUG_GI_TEX_AOLF_OCCRATE = 6,
        };

        enum class DebugScreenView : int8_t {
            DEBUG_SCREEN_VIEW_DEFAULT = 0,
            DEBUG_SCREEN_VIEW_ALL_ENABLE = 1,
            DEBUG_SCREEN_VIEW_ALL_DISABLE = 2,
        };

        DebugViewType debugViewType;
        bool clearRenderTarget;
        heur::rfl::GlobalLightParameter globalLight;
        bool enablePointLight;
        int32_t maxLocalShadow;
        float localShadowIntensity;
        bool enableEffectDeformation;
        bool enablePreMergeIBL;
        LocalLightCullingType localLightCullingType;
        float localLightScale;
        float shadowIBLAttenuation;
        int32_t maxCubeProbe;
        bool debugDrawCubeProbe;
        bool debugEnableDrawLocalLight;
        TextureViewType debugTextureViewType;
        bool debugEnableOutputTextureView;
        int32_t debugScreenshotResolutionHeight;
        float debugScreenshotDepthNear;
        float debugScreenshotDepthFar;
        AmbientSpecularType debugAmbientSpecularType;
        DebugGITextureDisable debagGITextureDisableType;
        hh::needle::DebugScreenOption debugScreen[16];
        DebugScreenView debugScreenView;
        bool enableMSAA;
        bool debugEnableDrawFrustumCullFrustum;
        bool debugEnableFixFrustumCullFrustum;
        int32_t debugDrawFrustumCullGroupSettingIndex;
        bool debugEnableOcclusionCullingView;
        int32_t debugOccluderVertThreshold;
        heur::rfl::GlobalUserParamOption globalUserParam[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRenderOption* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRenderOption* pInstance);
        static void Clean(FxRenderOption* pInstance);
    };
}

namespace hh::needle {
    struct FxSGGIParameter {
        float sgStartSmoothness;
        float sgEndSmoothness;
        float doStartSmoothness;
        float doEndSmoothness;
        float doOffset;
        float aoOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSGGIParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSGGIParameter* pInstance);
        static void Clean(FxSGGIParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxRLRParameter {
        bool enable;
        bool traceSky;
        bool useTrans;
        bool usePenet;
        bool useQuat;
        bool useNormal;
        float rayMarchingCount;
        float planeNormalDist;
        float traceThreshold;
        float resolveReproj;
        float overrideRatio;
        float maxRoughness;
        float roughnessLevel;
        float uvOffsetScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRLRParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRLRParameter* pInstance);
        static void Clean(FxRLRParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSSGIDebugParameter {
        bool useDenoise;
        float rayLength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSGIDebugParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSGIDebugParameter* pInstance);
        static void Clean(FxSSGIDebugParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSSGIParameter {
        bool enable;
        float intensity;
        bool useAlbedo;
        bool useParameter;
        hh::needle::FxSSGIDebugParameter debugParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSGIParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSGIParameter* pInstance);
        static void Clean(FxSSGIParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxPlanarReflectionParameter {
        bool enable;
        csl::math::Vector4 plane;
        uint32_t width;
        uint32_t height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxPlanarReflectionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxPlanarReflectionParameter* pInstance);
        static void Clean(FxPlanarReflectionParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxBloomParameter {
        bool enable;
        bool fast;
        float bloomScale;
        float sampleRadiusScale;
        int32_t blurQuality;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxBloomParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxBloomParameter* pInstance);
        static void Clean(FxBloomParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxManualExposureParameter {
        float exposureValue;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxManualExposureParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxManualExposureParameter* pInstance);
        static void Clean(FxManualExposureParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxAutoExposureParameter {
        enum class LUMINANCE_RANGE : int8_t {
            LUMINANCE_RANGE_CLAMP = 0,
            LUMINANCE_RANGE_CUTOFF = 1,
            LUMINANCE_RANGE_CUTOFF_PCT_RATE = 2,
            LUMINANCE_RANGE_CUTOFF_PCT_AREA = 3,
        };

        float middleGray;
        float lumMax;
        float lumMin;
        float cutMax;
        float cutMin;
        float pctMax;
        float pctMin;
        float adaptedRatio;
        LUMINANCE_RANGE luminanceRangeType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxAutoExposureParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxAutoExposureParameter* pInstance);
        static void Clean(FxAutoExposureParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxCameraControlParameter {
        enum class Exposure : int8_t {
            EXPOSURE_MANUAL = 0,
            EXPOSURE_AUTO = 1,
        };

        Exposure exposureType;
        hh::needle::FxManualExposureParameter manualExposure;
        hh::needle::FxAutoExposureParameter autoExposure;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCameraControlParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCameraControlParameter* pInstance);
        static void Clean(FxCameraControlParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxToneMapParameterFilmic {
        float whitePoint;
        float toeStrength;
        float linearAngle;
        float linearStrength;
        float shoulderStrength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxToneMapParameterFilmic* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxToneMapParameterFilmic* pInstance);
        static void Clean(FxToneMapParameterFilmic* pInstance);
    };
}

namespace hh::needle {
    struct FxToneMapParameterGT {
        float maxDisplayBrightness;
        float contrast;
        float linearSectionStart;
        float linearSectionLength;
        float black;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxToneMapParameterGT* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxToneMapParameterGT* pInstance);
        static void Clean(FxToneMapParameterGT* pInstance);
    };
}

namespace hh::needle {
    struct FxToneMapParameter {
        enum class Tonemap : int8_t {
            TONEMAP_DISNEY = 0,
            TONEMAP_FILMIC = 1,
            TONEMAP_ACES = 2,
            TONEMAP_GT = 3,
        };

        Tonemap tonemapType;
        hh::needle::FxToneMapParameterFilmic tonemapParamFilmic;
        hh::needle::FxToneMapParameterGT tonemapParamGT;
        bool updateLuminance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxToneMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxToneMapParameter* pInstance);
        static void Clean(FxToneMapParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxColorContrastParameter {
        enum class LutIndex : int32_t {
            LUT_INDEX_DEFAULT = 0,
            LUT_INDEX_WB = 1,
            LUT_INDEX_USER_0 = 2,
            LUT_INDEX_USER_1 = 3,
            LUT_INDEX_USER_2 = 4,
            LUT_INDEX_USER_3 = 5,
            LUT_INDEX_USER_4 = 6,
            LUT_INDEX_USER_5 = 7,
            LUT_INDEX_COUNT = 8,
        };

        bool enable;
        float contrast;
        float dynamicRange;
        float crushShadows;
        float crushHilights;
        bool useLut;
        LutIndex lutIndex0;
        LutIndex lutIndex1;
        float blendRatio;
        float lutRatio;
        bool useHlsCorrection;
        float hlsHueOffset;
        float hlsLightnessOffset;
        float hlsSaturationOffset;
        int32_t hlsColorOffset[3];
        float hlsColorizeRate;
        float hlsColorizeHue;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxColorContrastParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxColorContrastParameter* pInstance);
        static void Clean(FxColorContrastParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDistanceFogParameter {
        bool enable;
        float nearDist;
        float farDist;
        float influence;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDistanceFogParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDistanceFogParameter* pInstance);
        static void Clean(FxDistanceFogParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxHeightFogParameter {
        bool enable;
        float minHeight;
        float maxHeight;
        float nearDist;
        float farDist;
        float influence;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHeightFogParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHeightFogParameter* pInstance);
        static void Clean(FxHeightFogParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxFogParameter {
        csl::math::Vector3 color;
        float intensity;
        float skyBlend;
        float skyMips;
        hh::needle::FxDistanceFogParameter distanceFogParam;
        hh::needle::FxHeightFogParameter heightFogParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxFogParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxFogParameter* pInstance);
        static void Clean(FxFogParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDOFParameter {
        enum class Quality : int8_t {
            LOW = 0,
            MIDDLE = 1,
            HIGH = 2,
            HIGHEST = 3,
        };

        enum class Mode : int8_t {
            DISTANCE = 0,
            LENS = 1,
        };

        bool enable;
        Quality quality;
        bool useFocusLookAt;
        Mode lensMode;
        float foregroundBokehMaxDepth;
        float foregroundBokehStartDepth;
        float backgroundBokehStartDepth;
        float backgroundBokehMaxDepth;
        float focalLengthInMilliMeters;
        float fnumber;
        float fixedFovy;
        float focusLength;
        float forceFocusRange;
        float cocMaxRadius;
        float foregroundBokehScale;
        float backgroundBokehScale;
        float bladeCount;
        float bladeCurvature;
        float bladeRotation;
        bool drawFocalPlane;
        bool enableCircleDOF;
        float bokehRadiusScale;
        int32_t bokehSampleCount;
        float skyFocusDistance;
        float bokehBias;
        bool enableSWA;
        float swaFocus;
        float swaFocusRange;
        float swaNear;
        float swaFar;
        bool enableEnhancedForeBokeh;
        float foreBokehMaxLuminance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDOFParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDOFParameter* pInstance);
        static void Clean(FxDOFParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxShadowMapParameter {
        enum class ShadowRenderingType : int8_t {
            SHADOW_RENDERING_TYPE_SHADOW_MAP = 0,
            SHADOW_RENDERING_TYPE_PLANAR_PROJECTION = 1,
            SHADOW_RENDERING_TYPE_PLANAR_PROJECTION_SHADOW_MAP = 2,
            SHADOW_RENDERING_TYPE_MULTI_SHADOW_MAP = 3,
            SHADOW_RENDERING_TYPE_COUNT = 4,
        };

        enum class ShadowFilter : int8_t {
            SHADOW_FILTER_POINT = 0,
            SHADOW_FILTER_PCF = 1,
            SHADOW_FILTER_PCSS = 2,
            SHADOW_FILTER_ESM = 3,
            SHADOW_FILTER_MSM = 4,
            SHADOW_FILTER_VSM_POINT = 5,
            SHADOW_FILTER_VSM_LINEAR = 6,
            SHADOW_FILTER_VSM_ANISO_2 = 7,
            SHADOW_FILTER_VSM_ANISO_4 = 8,
            SHADOW_FILTER_VSM_ANISO_8 = 9,
            SHADOW_FILTER_VSM_ANISO_16 = 10,
            SHADOW_FILTER_COUNT = 11,
            SHADOW_FILTER_VSM_FIRST = 5,
            SHADOW_FILTER_VSM_LAST = 10,
        };

        enum class ShadowRangeType : int8_t {
            SHADOW_RANGE_TYPE_CAMERA_LOOKAT = 0,
            SHADOW_RANGE_TYPE_POSITION_MANUAL = 1,
            SHADOW_RANGE_TYPE_FULL_MANUAL = 2,
            SHADOW_RANGE_TYPE_COUNT = 3,
            SHADOW_RANGE_TYPE_DEFAULT = 0,
        };

        enum class FitProjection : int8_t {
            FIT_PROJECTION_TO_CASCADES = 0,
            FIT_PROJECTION_TO_SCENE = 1,
            FIT_PROJECTION_TO_ROTATE_CASCADES = 2,
        };

        enum class FitNearFar : int8_t {
            FIT_NEARFAR_ZERO_ONE = 0,
            FIT_NEARFAR_AABB = 1,
            FIT_NEARFAR_SCENE_AABB = 2,
        };

        enum class PartitionType : int8_t {
            PARTITION_PSSM = 0,
            PARTITION_MANUAL = 1,
        };

        ShadowRenderingType renderingType;
        bool enable;
        ShadowFilter shadowFilter;
        ShadowRangeType shadowRangeType;
        FitProjection fitProjection;
        FitNearFar fitNearFar;
        PartitionType partitionType;
        float sceneRange;
        float sceneCenter[3];
        float manualLightPos[3];
        float pssmLambda;
        float cascadeOffset;
        int32_t cascadeLevel;
        float cascadeSplits[4];
        float cascadeBias[4];
        float bias;
        float offset;
        float normalBias;
        int32_t blurQuality;
        int32_t blurSize;
        float fadeoutDistance;
        float cascadeTransitionfadeDistance;
        bool enableCSMCache;
        float csmCacheMaxHeight;
        float csmCacheMinHeight;
        int32_t csmCacheMaxRenderPass;
        float csmCacheFixedFovy;
        float csmCacheLightDirectionThreshold;
        bool csmCacheParallaxCorrectionEnabled;
        float csmCacheParallaxCorrectionHorizontalBias;
        float csmCacheParallaxCorrectionVerticalBias;
        int32_t csmCacheFramesToRender[3];
        float csmCacheFadeLightElevationAngle;
        float csmCacheMinLightElevationAngle;
        csl::math::Matrix44 shadowCameraViewMatrix;
        csl::math::Matrix44 shadowCameraProjectionMatrix;
        float shadowCameraNearDepth;
        float shadowCameraFarDepth;
        float shadowCameraLookAtDepth;
        bool enableBackFaceShadow;
        bool enableShadowCamera;
        bool enableDrawSceneAABB;
        bool enableDrawShadowFrustum;
        bool enableDrawCascade;
        bool enableDrawCameraFrustum;
        bool enableDrawCSMCache;
        bool enableClearOnCSMCacheIsInvalidated;
        bool enablePauseCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxShadowMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxShadowMapParameter* pInstance);
        static void Clean(FxShadowMapParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxShadowHeightMapParameter {
        bool enable;
        float bias;
        float distanceFalloff;
        float heightFalloffMinHeight;
        float heightFalloffDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxShadowHeightMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxShadowHeightMapParameter* pInstance);
        static void Clean(FxShadowHeightMapParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxVolumetricShadowParameter {
        bool enable;
        bool isForceUseShadowmap;
        bool isUseCloudShadow;
        bool isUseHeightmapShadow;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxVolumetricShadowParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxVolumetricShadowParameter* pInstance);
        static void Clean(FxVolumetricShadowParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSSAO_Parameter {
        float intensity;
        float radius;
        float fadeoutDistance;
        float fadeoutRadius;
        float power;
        float bias;
        float occlusionDistance;
        float directLightingInfluence;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSAO_Parameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSAO_Parameter* pInstance);
        static void Clean(FxSSAO_Parameter* pInstance);
    };
}

namespace hh::needle {
    struct FxHBAO_Parameter {
        float hbaoPower;
        float hbaoBias;
        float hbaoRadius;
        float hbaoFalloff;
        float hbaoSteps;
        float hbaoGitter;
        int8_t hbaoRaycount;
        bool hbaoGiMaskEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHBAO_Parameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHBAO_Parameter* pInstance);
        static void Clean(FxHBAO_Parameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSSS_Parameter {
        float sssRayLength;
        int8_t sssRaycount;
        float sssBias;
        float sssIntensity;
        float sssDepthMin;
        float sssDepthMax;
        float sssLightDistance;
        float sssThickness;
        bool sssGiMaskEnable;
        float sssLimit;
        bool sssDitherEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSS_Parameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSS_Parameter* pInstance);
        static void Clean(FxSSS_Parameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSSAOParameter {
        enum class SSAOType : int8_t {
            SSAO = 0,
            HBAO = 1,
            HBAO_SSS = 2,
            SSS = 3,
            TYPE_COUNT = 4,
        };

        enum class RenderTargetSize : int8_t {
            RTSIZE_SAME_AS_FRAMEBUFFER = 0,
            RTSIZE_ONE_SECOND = 1,
            RTSIZE_ONE_FORTH = 2,
            RTSIZE_COUNT = 3,
        };

        enum class BLURType : int8_t {
            None = 1,
            Gauss2x2 = 2,
            Gauss3x3 = 3,
            Gauss4x4 = 4,
            Gauss5x5 = 5,
            Gauss6x6 = 6,
            Gauss7x7 = 7,
            Gauss8x8 = 8,
            Gauss9x9 = 9,
            Bilateral = 10,
            NoisySample = 11,
            BLUR_COUNT = 12,
        };

        bool enable;
        SSAOType postType;
        RenderTargetSize renderTargetSize;
        BLURType blurStep;
        float bilateralThreshold;
        hh::needle::FxSSAO_Parameter ssaoParam;
        hh::needle::FxHBAO_Parameter hbaoParam;
        hh::needle::FxSSS_Parameter sssParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSSAOParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSSAOParameter* pInstance);
        static void Clean(FxSSAOParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxLightFieldMergeParameter {
        bool enable;
        float blendRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLightFieldMergeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLightFieldMergeParameter* pInstance);
        static void Clean(FxLightFieldMergeParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSHLightFieldParameter {
        enum class DebugDrawType : int8_t {
            DEBUG_DRAW_NONE = 0,
            DEBUG_DRAW_ONLY_ENABLED = 1,
            DEBUG_DRAW_ALL = 2,
        };

        bool enable;
        DebugDrawType debugDrawType;
        bool showSkyVisibility;
        float debugProbeSize;
        csl::math::Vector3 multiplyColorUp;
        csl::math::Vector3 multiplyColorDown;
        float normalBias;
        hh::needle::FxLightFieldMergeParameter lfMerge;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSHLightFieldParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSHLightFieldParameter* pInstance);
        static void Clean(FxSHLightFieldParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxScreenBlurParameter {
        enum class BlurType : int8_t {
            BLURTYPE_PREV_SURFACE = 0,
            BLURTYPE_RADIAL = 1,
            BLURTYPE_CAMERA = 2,
            BLURTYPE_COUNT = 3,
        };

        enum class FocusType : int8_t {
            FOCUSTYPE_CENTER = 0,
            FOCUSTYPE_LOOKAT = 1,
            FOCUSTYPE_USER_SETTING = 2,
            FOCUSTYPE_COUNT = 3,
        };

        bool enable;
        BlurType blurType;
        float blurPower;
        FocusType focusType;
        csl::math::Vector3 focusPosition;
        float focusRange;
        float alphaSlope;
        int32_t sampleNum;
        bool singleDirectionOpt;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxScreenBlurParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxScreenBlurParameter* pInstance);
        static void Clean(FxScreenBlurParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxOcclusionCapsuleParameter {
        bool enable;
        bool enableOcclusion;
        csl::ut::Color8 occlusionColor;
        float occlusionPower;
        bool enableSpecularOcclusion;
        float specularOcclusionAlpha;
        float specularOcclusionPower;
        float specularOcclusionConeAngle;
        bool enableShadow;
        csl::ut::Color8 shadowColor;
        float shadowPower;
        float shadowConeAngle;
        float cullingDistance;
        bool enableManualLight;
        int32_t manualLightCount;
        csl::math::Vector3 manualLightPos[4];
        bool debugDraw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxOcclusionCapsuleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxOcclusionCapsuleParameter* pInstance);
        static void Clean(FxOcclusionCapsuleParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxEffectParameter {
        float lightFieldColorCoefficient;
        float invTonemapCoefficient;
        csl::math::Vector3 shadowColor;
        csl::math::Vector3 directionalLightOverwrite;
        float directionalLightIntensityOverwrite;
        bool overwriteDirectionalLight;
        float localLightIntensityScale;
        float lodDistances[8];
        bool enableVisualizeOverdraw;
        bool renderWireframe;
        bool upsampleBilateral;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxEffectParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxEffectParameter* pInstance);
        static void Clean(FxEffectParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxScreenSpaceGodrayParameter {
        bool enable;
        float rayMarchingCount;
        float density;
        float decay;
        float threshold;
        float lumMax;
        float intensity;
        bool enableDither;
        csl::math::Vector3 lightPos;
        csl::math::Vector3 lightDir;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxScreenSpaceGodrayParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxScreenSpaceGodrayParameter* pInstance);
        static void Clean(FxScreenSpaceGodrayParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxGodrayVolumeTexture {
        bool enableVolumeTexture;
        float uvScale;
        float timeScale;
        float animationAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGodrayVolumeTexture* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGodrayVolumeTexture* pInstance);
        static void Clean(FxGodrayVolumeTexture* pInstance);
    };
}

namespace hh::needle {
    struct FxGodrayParameter {
        bool enable;
        bool isUseShadowmap;
        bool isVariableStep;
        csl::math::Matrix44 shadow;
        csl::math::Matrix34 box;
        csl::math::Vector3 color;
        float density;
        float anisotropy;
        float range;
        float rayMarchingCount;
        float rayMarchingStep;
        float shadowEdge;
        bool isScanFromBack;
        int32_t boxCount;
        bool isNewMode;
        hh::needle::FxGodrayVolumeTexture volumeTexture;
        float transparency;
        bool enable3d;
        float reProject3d;
        float logNear3d;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGodrayParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGodrayParameter* pInstance);
        static void Clean(FxGodrayParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxHeatHazeParameter {
        bool enable;
        float speed;
        float scale;
        float cycle;
        float nearDepth;
        float farDepth;
        float maxHeight;
        float parallaxCorrectFactor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHeatHazeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHeatHazeParameter* pInstance);
        static void Clean(FxHeatHazeParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxPuddleParameter {
        float heightThreshold;
        float slopeThreshold;
        float noiseScaleXZ;
        float noiseScaleY;
        float noiseThreshold;
        float noiseAttenuationRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxPuddleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxPuddleParameter* pInstance);
        static void Clean(FxPuddleParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxRippleParameter {
        float intensity;
        float uvScale;
        float timeScale;
        float normalIntensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRippleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRippleParameter* pInstance);
        static void Clean(FxRippleParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDropParameter {
        float uvScale;
        float timeScale;
        float normalIntensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDropParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDropParameter* pInstance);
        static void Clean(FxDropParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxRainParameter {
        bool enableDrop;
        bool enableFilter;
        bool enableRipple;
        bool enableDropWater;
        float intensity;
        csl::math::Vector4 dropColor;
        bool dropRotTarget;
        bool enableDropOcc;
        float dropCameraLerp;
        float dropCameraRate;
        float dropCameraRotation;
        float dropWidth;
        float dropLength;
        float dropWind;
        float dropRange;
        csl::math::Vector4 filterColor;
        float filterRange;
        float filterEdge;
        float filterAngle;
        hh::needle::FxRippleParameter ripple;
        hh::needle::FxDropParameter drop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRainParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRainParameter* pInstance);
        static void Clean(FxRainParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxWeatherParameter {
        float wetness;
        float char_wetness;
        hh::needle::FxPuddleParameter puddle;
        hh::needle::FxRainParameter rain;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxWeatherParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxWeatherParameter* pInstance);
        static void Clean(FxWeatherParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSceneEnvironmentParameter {
        float windRotationY;
        float windStrength;
        float windNoise;
        float windAmplitude;
        float windFrequencies[4];
        bool enableTreadGrass;
        csl::math::Vector4 grassLodDistance;
        bool enableHighLight;
        float highLightThreshold;
        float highLightObjectAmbientScale;
        float highLightObjectAlbedoHeighten;
        float highLightCharaAmbientScale;
        float highLightCharaAlbedoHeighten;
        float highLightCharaFalloffScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSceneEnvironmentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSceneEnvironmentParameter* pInstance);
        static void Clean(FxSceneEnvironmentParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxTAAParameter {
        bool enableUpscaling;
        float jitterScale;
        float mipBias;
        float sharpnessPower;
        float baseWeight;
        float velocityVarianceBasedWeightBias;
        float colorSpaceClippingScale;
        float colorSpaceClippingScaleForStatic;
        float velocityVarianceMin;
        float velocityVarianceMax;
        bool enableCharaStencilMask;
        bool enableLiteMode;
        bool enablePassThrough;
        bool debugVisualizeVelcotiyVariance;
        csl::math::Vector4 debug;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTAAParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTAAParameter* pInstance);
        static void Clean(FxTAAParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxChromaticAberrationParameter {
        bool enable;
        float offsetR;
        float offsetG;
        float offsetB;
        float curve;
        float scaleX;
        float scaleY;
        float centerX;
        float centerY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxChromaticAberrationParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxChromaticAberrationParameter* pInstance);
        static void Clean(FxChromaticAberrationParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxVfImageCircleParameter {
        float centerX;
        float centerY;
        float scaleX;
        float scaleY;
        float scale;
        float rotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxVfImageCircleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxVfImageCircleParameter* pInstance);
        static void Clean(FxVfImageCircleParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxVfLineParameter {
        float centerX;
        float centerY;
        float directionX;
        float directionY;
        float rotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxVfLineParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxVfLineParameter* pInstance);
        static void Clean(FxVfLineParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxVignetteParameter {
        enum class GradationMode : int8_t {
            GRADATION_MODE_CIRCLE = 0,
            GRADATION_MODE_LINE = 1,
        };

        enum class BlendMode : int8_t {
            BLEND_MODE_ALPHA_BLEND = 0,
            BLEND_MODE_ADD = 1,
            BLEND_MODE_MUL = 2,
            BLEND_MODE_SCREEN = 3,
            BLEND_MODE_OVERLAY = 4,
        };

        bool enable;
        GradationMode gradationType;
        BlendMode blendMode;
        csl::math::Vector3 color;
        float opacity;
        hh::needle::FxVfImageCircleParameter imageCircle;
        hh::needle::FxVfLineParameter line;
        float penumbraScale;
        float intensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxVignetteParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxVignetteParameter* pInstance);
        static void Clean(FxVignetteParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxWindComputeDebugParameter {
        bool debugEnable;
        bool debugSpace;
        bool debugGlobal;
        bool debugGlobalMap;
        bool debugSpaceAll;
        int32_t spaceIndex;
        float spaceThreshold;
        float min;
        float max;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxWindComputeDebugParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxWindComputeDebugParameter* pInstance);
        static void Clean(FxWindComputeDebugParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxWindComputeParameter {
        bool enableAll;
        bool enableDynamicWind;
        bool enableGlobalWind;
        float timeScale;
        float decreaseRate;
        csl::math::Vector3 globalWind;
        float globalWindPower;
        float globalWindSpeed;
        float globalWindOffset;
        csl::math::Vector3 globalSecondWind;
        float globalSecondWindPower;
        float globalSecondWindSpeed;
        float globalSecondWindOffset;
        csl::math::Vector3 globalWindMapSize;
        csl::math::Vector3 globalWindMapCenter;
        csl::math::Vector3 globalWindMapOffset;
        float globalWindMapPower;
        float globalWindMapTimeScale;
        hh::needle::FxWindComputeDebugParameter debugParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxWindComputeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxWindComputeParameter* pInstance);
        static void Clean(FxWindComputeParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxTerrainMaterialBlendingParameter {
        bool enable;
        float blendPower;
        float blendHightPower;
        float cullingDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTerrainMaterialBlendingParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTerrainMaterialBlendingParameter* pInstance);
        static void Clean(FxTerrainMaterialBlendingParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxInteractionDebugParameter {
        bool enable;
        bool collisionEnable;
        float threshold;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxInteractionDebugParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxInteractionDebugParameter* pInstance);
        static void Clean(FxInteractionDebugParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxInteractionParameter {
        bool enable;
        float power;
        float decrease;
        float timeScale;
        hh::needle::FxInteractionDebugParameter debug;
        float tremorPower;
        float tremorSpeed;
        float tremorScaleCriterion;
        float tremorScaleReduce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxInteractionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxInteractionParameter* pInstance);
        static void Clean(FxInteractionParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxGpuEnvironmentParameter {
        float grassDitherStart;
        float grassDitherEnd;
        hh::needle::FxInteractionParameter interaction;
        bool enableZoomBias;
        float zoomBias;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxGpuEnvironmentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxGpuEnvironmentParameter* pInstance);
        static void Clean(FxGpuEnvironmentParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxInteractiveWaveParameter {
        bool enable;
        bool enableDebugDisplay;
        float waveDamping;
        float waveReduceRange;
        float waveSpeed;
        float simurationScale;
        float playerMaxSpeed;
        bool isInWaterDummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxInteractiveWaveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxInteractiveWaveParameter* pInstance);
        static void Clean(FxInteractiveWaveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct UVShift {
        float blockLNoiseSizeX;
        float blockLNoiseSizeY;
        float blockHNoiseSizeX;
        float blockHNoiseSizeY;
        float bNoiseHighRate;
        float intensity;
        float pixelShiftIntensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UVShift* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UVShift* pInstance);
        static void Clean(UVShift* pInstance);
    };
}

namespace hh::needle {
    struct ColorShift {
        float blockLNoiseSize;
        float blockHNoiseSize;
        float bNoiseHighRate;
        float intensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ColorShift* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ColorShift* pInstance);
        static void Clean(ColorShift* pInstance);
    };
}

namespace heur::rfl {
    struct InterlaceNoise {
        float blockLNoiseSize;
        float blockHNoiseSize;
        float bNoiseHighRate;
        float intensity;
        float dropout;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(InterlaceNoise* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(InterlaceNoise* pInstance);
        static void Clean(InterlaceNoise* pInstance);
    };
}

namespace hh::needle {
    struct ColorDropout {
        float blockLNoiseSizeX;
        float blockLNoiseSizeY;
        float blockHNoiseSizeX;
        float blockHNoiseSizeY;
        float bNoiseHighRate;
        float intensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ColorDropout* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ColorDropout* pInstance);
        static void Clean(ColorDropout* pInstance);
    };
}

namespace heur::rfl {
    struct InvertColor {
        float blockLNoiseSizeX;
        float blockLNoiseSizeY;
        float blockHNoiseSizeX;
        float blockHNoiseSizeY;
        float bNoiseHighRate;
        float intensity;
        float invertAllRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(InvertColor* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(InvertColor* pInstance);
        static void Clean(InvertColor* pInstance);
    };
}

namespace heur::rfl {
    struct GlayScaleColor {
        float blockLNoiseSizeX;
        float blockLNoiseSizeY;
        float blockHNoiseSizeX;
        float blockHNoiseSizeY;
        float bNoiseHighRate;
        float intensity;
        float invertAllRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GlayScaleColor* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GlayScaleColor* pInstance);
        static void Clean(GlayScaleColor* pInstance);
    };
}

namespace hh::needle {
    struct FxCyberSpaceStartNoiseParameter {
        bool enable;
        heur::rfl::UVShift uvShift;
        hh::needle::ColorShift colorShift;
        heur::rfl::InterlaceNoise interlaceNoise;
        hh::needle::ColorDropout colorDrop;
        heur::rfl::InvertColor invertColor;
        heur::rfl::GlayScaleColor glayscaleColor;
        float noiseSpeed;
        float noiseBias;
        float noiseWaveAmplitude;
        float noiseWaveCycle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxCyberSpaceStartNoiseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxCyberSpaceStartNoiseParameter* pInstance);
        static void Clean(FxCyberSpaceStartNoiseParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxFieldScanEffectRenderParameter {
        bool enable;
        csl::math::Vector3 centerPos;
        csl::ut::Color8 color;
        float radius1;
        float radius2;
        float radius3;
        float intensity1;
        float intensity2;
        float intensity3;
        float gridIntensity;
        float innerWidth;
        float gridLineWidth;
        float gridLineSpan;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxFieldScanEffectRenderParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxFieldScanEffectRenderParameter* pInstance);
        static void Clean(FxFieldScanEffectRenderParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxColorAccessibilityFilterParameter {
        enum class ColorblinidSimulationType : int8_t {
            COLORBLIND_SIM_NONE = 0,
            COLORBLIND_SIM_PROTANOPIA = 1,
            COLORBLIND_SIM_DEUTERANOPIA = 2,
            COLORBLIND_SIM_TRITANOPIA = 3,
            COLORBLIND_SIM_ALL = 4,
        };

        bool enable;
        float daltonizeFactor;
        float protanopiaFactor;
        float deuteranopiaFactor;
        float tritanopiaFactor;
        float brightness;
        float contrast;
        float maskIntensity[5];
        ColorblinidSimulationType simulationType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxColorAccessibilityFilterParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxColorAccessibilityFilterParameter* pInstance);
        static void Clean(FxColorAccessibilityFilterParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSeparableSSSParameter {
        bool enable;
        csl::math::Vector4 ambientColorBoost;
        bool transmitEnable;
        float width;
        float normalOffset;
        float blurOffsetMax;
        csl::math::Vector4 strength[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSeparableSSSParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSeparableSSSParameter* pInstance);
        static void Clean(FxSeparableSSSParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxTimeStopParameter {
        enum class Mode : int8_t {
            Active = 0,
            End = 1,
        };

        enum class EffectType : int8_t {
            Gray = 0,
            Nega = 1,
            NegaGray = 2,
        };

        bool enable;
        Mode mode;
        float startSpeed;
        EffectType colorType;
        float rimPower;
        float rimThreshold;
        csl::ut::Colorf rimColor[2];
        float highlightPower;
        csl::ut::Colorf highlightColor[2];
        uint32_t highlightCount;
        float highlightDepth;
        float flashSpeed;
        float speedX;
        float speedY;
        csl::ut::Colorf maskColor;
        float distortionPower;
        float framesize;
        float frameDistortion;
        float frameSpeed;
        float rotSpeed;
        bool rotMode;
        float rotDistortionSpeed;
        bool endFade;
        float endSpeed;
        bool overrideParam;
        bool transObjectEnable;
        bool objectTimeStop;
        bool vignette;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTimeStopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTimeStopParameter* pInstance);
        static void Clean(FxTimeStopParameter* pInstance);
    };
}

namespace hh::needle {
    struct NeedleFxParameter {
        hh::needle::FxRenderOption renderOption;
        hh::needle::FxSGGIParameter sggi;
        hh::needle::FxRLRParameter rlr;
        hh::needle::FxSSGIParameter ssgi;
        hh::needle::FxPlanarReflectionParameter planarReflection;
        hh::needle::FxBloomParameter bloom;
        hh::needle::FxCameraControlParameter cameraControl;
        hh::needle::FxToneMapParameter tonemap;
        hh::needle::FxColorContrastParameter colorContrast;
        hh::needle::FxLightScatteringParameter lightscattering;
        hh::needle::FxFogParameter fog;
        hh::needle::FxDOFParameter dof;
        hh::needle::FxShadowMapParameter shadowmap;
        hh::needle::FxShadowHeightMapParameter shadowHeightMap;
        hh::needle::FxVolumetricShadowParameter volShadow;
        hh::needle::FxSSAOParameter ssao;
        hh::needle::FxSHLightFieldParameter shlightfield;
        hh::needle::FxScreenBlurParameter blur;
        hh::needle::FxOcclusionCapsuleParameter occlusionCapsule;
        hh::needle::FxEffectParameter effect;
        hh::needle::FxScreenSpaceGodrayParameter ssGodray;
        hh::needle::FxGodrayParameter godray;
        hh::needle::FxHeatHazeParameter heatHaze;
        hh::needle::FxAtmosphereParameter atmosphere;
        hh::needle::FxWeatherParameter weather;
        hh::needle::FxSceneEnvironmentParameter sceneEnv;
        hh::needle::FxTAAParameter taa;
        hh::needle::FxDensityParameter density;
        hh::needle::FxChromaticAberrationParameter chromaticAberration;
        hh::needle::FxVignetteParameter vignette;
        hh::needle::FxWindComputeParameter wind;
        hh::needle::FxTerrainMaterialBlendingParameter terrainBlend;
        hh::needle::FxGpuEnvironmentParameter gpuEnvironment;
        hh::needle::FxInteractiveWaveParameter interactiveWave;
        hh::needle::FxCyberNoiseEffectParameter cyberNoise;
        hh::needle::FxCyberSpaceStartNoiseParameter cyberStartNoise;
        hh::needle::FxCyberNPCSSEffectRenderParameter cyberNPCSS;
        hh::needle::FxFieldScanEffectRenderParameter fieldScan;
        hh::needle::FxColorAccessibilityFilterParameter colorAccessibility;
        hh::gfx::FxDentParameter dent;
        hh::needle::FxSeparableSSSParameter ssss;
        hh::needle::FxTimeStopParameter timestop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxParameter* pInstance);
        static void Clean(NeedleFxParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxRenderTargetSetting {
        enum class DOFRenderTargetSize : int32_t {
            DOF_RTSIZE_FULL_SCALE = 0,
            DOF_RTSIZE_HALF_SCALE = 1,
            DOF_RTSIZE_QUARTER_SCALE = 2,
            DOF_RTSIZE_COUNT = 3,
            DOF_RTSIZE_INVALID = 3,
        };

        DOFRenderTargetSize dofRenderTargetScale;
        int32_t shadowMapWidth;
        int32_t shadowMapHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxRenderTargetSetting* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxRenderTargetSetting* pInstance);
        static void Clean(FxRenderTargetSetting* pInstance);
    };
}

namespace hh::needle {
    struct FxAntiAliasing {
        enum class AntiAliasingType : int8_t {
            AATYPE_NONE = 0,
            AATYPE_TAA = 1,
            AATYPE_FXAA = 2,
            AATYPE_SMAA = 3,
            AATYPE_LAST = 4,
        };

        enum class UpscaleType : int8_t {
            USTYPE_LINEAR = 0,
            USTYPE_FSR_FAST = 1,
            USTYPE_FSR_EASU = 2,
            USTYPE_FSR_RCAS = 3,
        };

        AntiAliasingType aaType;
        UpscaleType usType;
        float fsrSharpness;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxAntiAliasing* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxAntiAliasing* pInstance);
        static void Clean(FxAntiAliasing* pInstance);
    };
}

namespace hh::needle {
    struct FxLODParameter {
        bool enableDebugDrawLayerRange;
        float layerRange[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxLODParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxLODParameter* pInstance);
        static void Clean(FxLODParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDetailParameter {
        float detailDistance;
        float detailFadeRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDetailParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDetailParameter* pInstance);
        static void Clean(FxDetailParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxDynamicResolutionParameter {
        enum class Mode : int8_t {
            DISABLE = 0,
            ENABLE = 1,
            FIXED_RESOLUTION = 2,
        };

        Mode mode;
        float fixedResolutionRatio;
        float minResolutionRatio;
        float minTargetTimeDifference;
        float maxTargetTimeDifference;
        float increaseRate;
        float decreaseRate;
        float increaseMaxScaleDelta;
        float decreaseMaxScaleDelta;
        bool debugSineFluctuation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDynamicResolutionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDynamicResolutionParameter* pInstance);
        static void Clean(FxDynamicResolutionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct TimeIntervalData {
        heur::rfl::HourMinuteData beginTime;
        heur::rfl::HourMinuteData endTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TimeIntervalData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TimeIntervalData* pInstance);
        static void Clean(TimeIntervalData* pInstance);
    };
}

namespace heur::rfl {
    struct ProgressTimePairData : heur::rfl::TimeIntervalData {
        float hourlyTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ProgressTimePairData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ProgressTimePairData* pInstance);
        static void Clean(ProgressTimePairData* pInstance);
    };
}

namespace hh::gfx {
    struct StageCommonTimeProgressParameter {
        bool enable;
        float solarRadiusScale;
        float azimuthAngle;
        float latitude;
        float longitude;
        int32_t month;
        int32_t day;
        float time;
        float hourlyTime;
        heur::rfl::ProgressTimePairData overrideSpeeds[8];
        heur::rfl::TimeIntervalData night;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCommonTimeProgressParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCommonTimeProgressParameter* pInstance);
        static void Clean(StageCommonTimeProgressParameter* pInstance);
    };
}

namespace hh::gfx {
    struct StageCommonWeatherProgressParameter {
        bool enable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCommonWeatherProgressParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCommonWeatherProgressParameter* pInstance);
        static void Clean(StageCommonWeatherProgressParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxTerrainParameter {
        bool enableDrawGrid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxTerrainParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxTerrainParameter* pInstance);
        static void Clean(FxTerrainParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxModelParameter {
        bool zprepass;
        bool ditherAsBlueNoize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxModelParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxModelParameter* pInstance);
        static void Clean(FxModelParameter* pInstance);
    };
}

namespace hh::gfx {
    struct StageCommonDecalModelParameter {
        float cullingRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCommonDecalModelParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCommonDecalModelParameter* pInstance);
        static void Clean(StageCommonDecalModelParameter* pInstance);
    };
}

namespace hh::gfx {
    struct PerformanceSetting {
        float smallCullingThreshold;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PerformanceSetting* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PerformanceSetting* pInstance);
        static void Clean(PerformanceSetting* pInstance);
    };
}

namespace hh::needle {
    struct NeedleFxSceneConfig {
        hh::needle::FxRenderTargetSetting rendertarget;
        hh::needle::FxAntiAliasing antialiasing;
        hh::needle::FxLODParameter lod;
        hh::needle::FxDetailParameter detail;
        hh::needle::FxDynamicResolutionParameter dynamicResolution;
        hh::gfx::StageCommonTimeProgressParameter timeProgress;
        hh::gfx::StageCommonWeatherProgressParameter weatherProgress;
        hh::needle::FxTerrainParameter terrain;
        hh::needle::FxModelParameter modelParam;
        hh::gfx::StageCommonDecalModelParameter decalModelParam;
        hh::gfx::PerformanceSetting performance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxSceneConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxSceneConfig* pInstance);
        static void Clean(NeedleFxSceneConfig* pInstance);
    };
}

namespace heur::rfl {
    struct TimeProgressAtmosphereParameter {
        hh::needle::FxSkyCommon commonSkyParam;
        hh::needle::FxBrunetonSky brunetonSkyParam;
        hh::needle::FxSebastienSky sebastienSkyParam;
        heur::rfl::FxCloudParameter cloudParam;
        hh::needle::FxCrepuscularRay crepuscularRayParam;
        hh::needle::FxHeightFog heightFogParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TimeProgressAtmosphereParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TimeProgressAtmosphereParameter* pInstance);
        static void Clean(TimeProgressAtmosphereParameter* pInstance);
    };
}

namespace heur::rfl {
    struct TimeProgressNeedleFxParam {
        bool enable;
        float time;
        hh::needle::FxBloomParameter bloom;
        hh::needle::FxCameraControlParameter cameraControl;
        hh::needle::FxCameraControlParameter cameraControlEvent;
        hh::needle::FxToneMapParameter tonemap;
        hh::needle::FxColorContrastParameter colorContrast;
        hh::needle::FxLightScatteringParameter lightscattering;
        hh::needle::FxEffectParameter effect;
        hh::needle::FxScreenSpaceGodrayParameter ssGodray;
        hh::needle::FxGodrayParameter godray;
        hh::needle::FxHeatHazeParameter heatHaze;
        heur::rfl::TimeProgressAtmosphereParameter atmosphere;
        hh::needle::FxWeatherParameter weather;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TimeProgressNeedleFxParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TimeProgressNeedleFxParam* pInstance);
        static void Clean(TimeProgressNeedleFxParam* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherFxParameter {
        bool enable;
        hh::needle::FxBloomParameter bloom;
        hh::needle::FxCameraControlParameter cameraControl;
        hh::needle::FxCameraControlParameter cameraControlEvent;
        hh::needle::FxToneMapParameter tonemap;
        hh::needle::FxColorContrastParameter colorContrast;
        hh::needle::FxLightScatteringParameter lightscattering;
        hh::needle::FxEffectParameter effect;
        hh::needle::FxScreenSpaceGodrayParameter ssGodray;
        hh::needle::FxGodrayParameter godray;
        hh::needle::FxHeatHazeParameter heatHaze;
        heur::rfl::TimeProgressAtmosphereParameter atmosphere;
        hh::needle::FxWeatherParameter weather;
        hh::needle::FxWindComputeParameter wind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherFxParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherFxParameter* pInstance);
        static void Clean(WeatherFxParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageCommonParameter {
        float deadline;
        float oceanSurface;
        float deadFallTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCommonParameter* pInstance);
        static void Clean(StageCommonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageCameraParameter {
        float zNear;
        float zFar;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageCameraParameter* pInstance);
        static void Clean(StageCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageTerrainPrecisionParameter {
        float heightRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageTerrainPrecisionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageTerrainPrecisionParameter* pInstance);
        static void Clean(StageTerrainPrecisionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageTerrainMaterialParameter {
        float uvScaleDetail;
        float uvScaleBase;
        float detailDistance;
        float detailFadeRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageTerrainMaterialParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageTerrainMaterialParameter* pInstance);
        static void Clean(StageTerrainMaterialParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageTerrainParameter {
        bool useHeightMapTerrain;
        bool useHalfPrecision;
        heur::rfl::StageTerrainPrecisionParameter precision;
        int32_t worldSize;
        int32_t heightMapTexelDensity;
        float heightScale;
        float smallestCellSize;
        float slopeClipThrethold;
        csl::math::Vector2 aabbMin;
        csl::math::Vector2 aabbMax;
        heur::rfl::StageTerrainMaterialParameter material;
        bool enableGbufferBlending;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageTerrainParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageTerrainParameter* pInstance);
        static void Clean(StageTerrainParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StageConfig {
        heur::rfl::StageCommonParameter common;
        heur::rfl::StageCameraParameter camera;
        heur::rfl::StageTerrainParameter terrain;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageConfig* pInstance);
        static void Clean(StageConfig* pInstance);
    };
}

namespace hh::needle {
    struct NeedleFxSceneData {
        hh::needle::NeedleFxSceneConfig config;
        hh::needle::NeedleFxParameter items[16];
        heur::rfl::TimeProgressNeedleFxParam timeItems[24];
        heur::rfl::WeatherFxParameter weatherItems[7];
        heur::rfl::StageConfig stageConfig;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NeedleFxSceneData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NeedleFxSceneData* pInstance);
        static void Clean(NeedleFxSceneData* pInstance);
    };
}

namespace heur::rfl {
    struct CapsuleParam {
        enum class VolumeType : int8_t {
            VOLUME_SPHERE = 0,
            VOLUME_CAPSULE = 1,
        };

        enum class LODLevel : int8_t {
            LOD_HIGH = 0,
            LOD_MIDDLE = 1,
            LOD_LOW = 2,
        };

        csl::ut::VariableString type;
        VolumeType volume;
        int32_t priority;
        csl::math::Vector3 translation;
        csl::math::Vector3 rotation;
        csl::math::Vector3 scale;
        csl::math::Vector3 rate;
        float radius;
        LODLevel lod;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CapsuleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CapsuleParam* pInstance);
        static void Clean(CapsuleParam* pInstance);
    };
}

namespace heur::rfl {
    struct OcclusionCapsuleList {
        heur::rfl::CapsuleParam capsules[64];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OcclusionCapsuleList* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OcclusionCapsuleList* pInstance);
        static void Clean(OcclusionCapsuleList* pInstance);
    };
}

namespace hh::needle {
    struct FxDirectionalRadialBlurParameter {
        bool enable;
        csl::math::Vector3 center;
        csl::math::Vector3 direction;
        float blurPowerMax;
        float blurPowerMin;
        float focusRange;
        float alphaSlope;
        int32_t sampleNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxDirectionalRadialBlurParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxDirectionalRadialBlurParameter* pInstance);
        static void Clean(FxDirectionalRadialBlurParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxFXAAParameter {
        enum class QualityType : int8_t {
            QUALITY_LOW = 0,
            QUALITY_MEDIUM = 1,
            QUALITY_HIGH = 2,
            QUALITY_COUNT = 3,
        };

        QualityType qualityType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxFXAAParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxFXAAParameter* pInstance);
        static void Clean(FxFXAAParameter* pInstance);
    };
}

namespace heur::rfl {
    struct FxHDRParameter {
        enum class OutputType : int8_t {
            OUTPUT_TYPE_SDR = 0,
            OUTPUT_TYPE_HDR = 1,
        };

        OutputType outputType;
        float baseNits;
        float maxNitsLevel;
        float minNitsLevel;
        float extendHue;
        float extendSaturation;
        bool autoNitsSetting;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHDRParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHDRParameter* pInstance);
        static void Clean(FxHDRParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxHeightMapParameter {
        bool enable;
        bool enableMultiHeightmap;
        bool debugDrawFrustum;
        bool reprojection;
        uint32_t renderTargetWidth;
        uint32_t renderTargetHeight;
        float referenceValue;
        float heightScale;
        float fadeTime;
        float colorMask;
        csl::math::Matrix44 viewMatrix;
        csl::math::Matrix44 projMatrix;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxHeightMapParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxHeightMapParameter* pInstance);
        static void Clean(FxHeightMapParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxPlanarProjectionShadowParameter {
        bool enable;
        csl::math::Vector4 projectionPlane;
        csl::math::Vector3 lightPosition[4];
        int8_t lightCount;
        float vanishStart;
        float vanishDistance;
        float projectionBias;
        csl::math::Vector3 shadowMapBoxSize;
        csl::math::Vector3 shadowMapBoxOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxPlanarProjectionShadowParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxPlanarProjectionShadowParameter* pInstance);
        static void Clean(FxPlanarProjectionShadowParameter* pInstance);
    };
}

namespace hh::needle {
    struct FxSMAAParameter {
        enum class Preset : int8_t {
            PRESET_SPEED = 0,
            PRESET_QUALITY = 1,
        };

        enum class TestMode : int8_t {
            TEST_MODE_DISABLE = 0,
            TEST_MODE_1 = 1,
            TEST_MODE_2 = 2,
        };

        Preset preset;
        TestMode testMode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FxSMAAParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FxSMAAParameter* pInstance);
        static void Clean(FxSMAAParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ViewSpaceOffsetRflParam {
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 eyeOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ViewSpaceOffsetRflParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ViewSpaceOffsetRflParam* pInstance);
        static void Clean(ViewSpaceOffsetRflParam* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamCollision {
        enum class CollisionType : int8_t {
            SWAY_COLLISTION_TYPE_NONE = 0,
            SWAY_COLLISTION_TYPE_SPHERE = 1,
        };

        CollisionType type;
        csl::math::Vector3 translation;
        csl::math::Vector3 rotation;
        csl::math::Vector3 scale;
        int32_t modelPartId;
        csl::ut::VariableString modelNodeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamCollision* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamCollision* pInstance);
        static void Clean(SwayParamCollision* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamNode {
        bool enable;
        float gravity;
        float resist;
        float resist_decay;
        float recover;
        float recover_decay;
        float spring;
        float radius;
        float transmit;
        float inertia;
        float angle_limit;
        csl::ut::VariableString nodeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamNode* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamNode* pInstance);
        static void Clean(SwayParamNode* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamNodeCollision {
        heur::rfl::SwayParamCollision collisionParam[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamNodeCollision* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamNodeCollision* pInstance);
        static void Clean(SwayParamNodeCollision* pInstance);
    };
}

namespace heur::rfl {
    struct SwayParamIndivisual {
        csl::ut::VariableString idName;
        heur::rfl::SwayParamNode nodeParam[16];
        heur::rfl::SwayParamNodeCollision collisionParam[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwayParamIndivisual* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwayParamIndivisual* pInstance);
        static void Clean(SwayParamIndivisual* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardSpawner {
        bool hardMode;
        hh::game::ObjectId phase2BossLocator;
        hh::game::ObjectId phase2PlayerLocator;
        csl::ut::MoveArray<hh::game::ObjectId> phase2ArmBreakIkuraIds;
        hh::game::ObjectId wallLocator;
        hh::game::ObjectId wallPlayerLocator;
        hh::game::ObjectId phase4IkuraLocator;
        hh::game::ObjectId phase4GiantIkuraLocator;
        hh::game::ObjectId cableALLocator;
        hh::game::ObjectId cableARLocator;
        hh::game::ObjectId cableBLLocator;
        hh::game::ObjectId cableBRLocator;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardSpawner* pInstance);
        static void Clean(BossBiolizardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardEngineSpawner {
        float dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardEngineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardEngineSpawner* pInstance);
        static void Clean(BossBiolizardEngineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardIkuraSpawner {
        bool isHitCollision;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardIkuraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardIkuraSpawner* pInstance);
        static void Clean(BossBiolizardIkuraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesSpawner {
        bool hardMode;
        hh::game::ObjectId bossStageLocator;
        float bossStageLocatorRadius;
        hh::game::ObjectId phase2BossLocator;
        hh::game::ObjectId phase2PlayerLocator;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesSpawner* pInstance);
        static void Clean(BossMephilesSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLBombPillarSpawner {
        int32_t hitDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLBombPillarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLBombPillarSpawner* pInstance);
        static void Clean(ObjMPLBombPillarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLFakerGeneratorSpawner {
        bool isAppear;
        hh::game::ObjectId movePosLocator;
        hh::game::ObjectId movePosLocator2;
        float secondMoveDelay;
        hh::game::ObjectId pillarInitPosition;
        csl::ut::MoveArray<hh::game::ObjectId> pillarLandingPositions;
        float initWaitTime;
        float initMoveDelay;
        float initMoveUpRatio;
        int32_t index;
        bool isAmoebaPillar;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLFakerGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLFakerGeneratorSpawner* pInstance);
        static void Clean(ObjMPLFakerGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLStageSpawner {
        float radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLStageSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLStageSpawner* pInstance);
        static void Clean(ObjMPLStageSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLStageWallSpawner {
        int32_t index;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLStageWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLStageWallSpawner* pInstance);
        static void Clean(ObjMPLStageWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadSpawner {
        bool hardMode;
        hh::game::ObjectId phase2BossLocator;
        csl::ut::VariableString guidePathName;
        csl::ut::VariableString phase2WaterFlowMinPathName;
        csl::ut::VariableString phase2WaterFlowMaxPathName;
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadSpawner* pInstance);
        static void Clean(BossMetaloverloadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossStageVortexSpawner {
        float scale;
        float speedRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossStageVortexSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossStageVortexSpawner* pInstance);
        static void Clean(ObjBossStageVortexSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossStageWaveSpawner {
        float width;
        float length;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossStageWaveSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossStageWaveSpawner* pInstance);
        static void Clean(ObjBossStageWaveSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ActionNotification {
        enum class Type : int8_t {
            Start = 0,
            On = 1,
            Off = 2,
            Finish = 3,
            NumTypes = 4,
            Invalid = -1,
        };

        Type action;
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;
        float delayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ActionNotification* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ActionNotification* pInstance);
        static void Clean(ActionNotification* pInstance);
    };
}

namespace heur::rfl {
    struct PathMovement {
        enum class MoveType : int8_t {
            FIXED = 0,
            PATH = 1,
            TWO_POINT = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
            PATROL_ONEWAY_KILL = 3,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        MoveType moveType;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        csl::math::Vector3 twoPointOffset;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        bool isReverse;
        float waitTime;
        float phase;
        float speed;
        float killWaitTSecOneway;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathMovement* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathMovement* pInstance);
        static void Clean(PathMovement* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLAttackChanceRingSpawner {
        float OutOfControl;
        float KeepVelocity;
        bool TargetToBoss;
        float Speed;
        float UpSpeed;
        float BossMovePosDistance;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        heur::rfl::ActionNotification actions[6];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;
        bool visual;
        float attackChanceTime;
        float moveStopTime;
        float moveStopDelayTime;
        bool HitStop;
        float HitStopDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLAttackChanceRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLAttackChanceRingSpawner* pInstance);
        static void Clean(ObjMOLAttackChanceRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct VolumeTriggerSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_CAPSULE = 3,
            SHAPE_PATH = 4,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
            BASE_X_PLANE = 2,
            BASE_Y_PLANE = 3,
        };

        enum class ColliFilter : int8_t {
            FILTER_DEFAULT = 0,
            FILTER_ONLYENEMY = 1,
            FILTER_HITENEMY = 2,
            FILTER_ALL = 3,
        };

        enum class PathSetDirection : int8_t {
            PATH_TO_START = 0,
            PATH_TO_GOAL = 1,
            PATH_TO_BOTH = 2,
        };

        Shape ShapeType;
        BasePoint basePoint;
        ColliFilter CollisionFilter;
        float CollisionWidth;
        float CollisionHeight;
        float CollisionDepth;
        csl::math::Vector3 CollisionOffset;
        csl::ut::VariableString pathName;
        int32_t pathDivideNum;
        PathSetDirection pathSetDirection;
        float pathSetLength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VolumeTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VolumeTriggerSpawner* pInstance);
        static void Clean(VolumeTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AutoRunParam {
        bool isEnable;
        bool isResetDefult;
        float runSpped;
        float runWidth;
        int32_t lifeCount;
        int32_t hp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AutoRunParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AutoRunParam* pInstance);
        static void Clean(AutoRunParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLAutoRunVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::AutoRunParam params[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLAutoRunVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLAutoRunVolumeSpawner* pInstance);
        static void Clean(ObjMOLAutoRunVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLBurnerSpawner {
        float length;
        bool isRight;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLBurnerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLBurnerSpawner* pInstance);
        static void Clean(ObjMOLBurnerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLEnemySpawner {
        float respawnTime;
        bool isFloatingEffectValid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLEnemySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLEnemySpawner* pInstance);
        static void Clean(ObjMOLEnemySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLMineSpawner {
        enum class InputGuideType : int8_t {
            IG_NONE = 0,
            IG_LEFT_STEP = 1,
            IG_RIGHT_STEP = 2,
        };

        float respawnTime;
        bool isFloatingEffectValid;
        InputGuideType guideType;
        csl::math::Vector3 guideLocalOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLMineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLMineSpawner* pInstance);
        static void Clean(ObjMOLMineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLMotionPlayVolumeSpawner {
        csl::ut::VariableString motionName;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLMotionPlayVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLMotionPlayVolumeSpawner* pInstance);
        static void Clean(ObjMOLMotionPlayVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLPhotonDashRingSpawner {
        float OutOfControl;
        float KeepVelocity;
        float Speed;
        float UpSpeed;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        heur::rfl::ActionNotification actions[6];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;
        float attackChanceTime;
        float moveStopTime;
        float moveStopDelayTime;
        bool HitStop;
        float HitStopDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLPhotonDashRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLPhotonDashRingSpawner* pInstance);
        static void Clean(ObjMOLPhotonDashRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SwitchLayerParam {
        bool isEnable;
        csl::ut::VariableString tag;
        bool isLayerEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwitchLayerParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwitchLayerParam* pInstance);
        static void Clean(SwitchLayerParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLSwitchLayerVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool isOnce;
        heur::rfl::SwitchLayerParam params[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLSwitchLayerVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLSwitchLayerVolumeSpawner* pInstance);
        static void Clean(ObjMOLSwitchLayerVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ActionParam {
        enum class ActionType : int8_t {
            ACT_NONE = 0,
            ACT_MISSILE = 1,
            ACT_TAIL = 2,
            ACT_FLAME = 3,
            ACT_SELF_RECOVER = 4,
            MAX = 5,
        };

        ActionType type;
        int32_t phase1PatternNo;
        float actionTime;
        float actionWaitTime;
        float distanceMin;
        float distanceMax;
        int32_t lifeCount;
        int32_t hp;
        heur::rfl::ActionNotification actions[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ActionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ActionParam* pInstance);
        static void Clean(ActionParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMOLVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionParam actionParams[4];
        bool disableChaosBreakReaction;
        float disableCollisionAddWidth;
        float disableCollisionAddHeight;
        float disableCollisionAddDepth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMOLVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMOLVolumeSpawner* pInstance);
        static void Clean(ObjMOLVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomSpawner {
        bool hardMode;
        csl::ut::VariableString phase1PlayerGuidePathName;
        csl::ut::VariableString phase1BossGuidePathName;
        hh::game::ObjectId phase2BossLocator;
        hh::game::ObjectId phase2PlayerLocator;
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomSpawner* pInstance);
        static void Clean(BossPerfectblackdoomSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSpawner {
        bool hardMode;
        csl::ut::VariableString guidePathName;
        hh::game::ObjectId playerLocator;
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSpawner* pInstance);
        static void Clean(BossPerfectblackdoomFinalSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDAttackChanceRingSpawner {
        float OutOfControl;
        float KeepVelocity;
        bool TargetToBoss;
        float Speed;
        float UpSpeed;
        float BossMovePosDistance;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        heur::rfl::ActionNotification actions[6];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;
        bool visual;
        float attackChanceTime;
        float moveStopTime;
        float moveStopDelayTime;
        bool HitStop;
        float HitStopDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDAttackChanceRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDAttackChanceRingSpawner* pInstance);
        static void Clean(ObjPBDAttackChanceRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AutoRunParams {
        bool isEnable;
        bool isResetDefult;
        float runSpped;
        float runWidth;
        float areaAspectRatio;
        float changeTime;
        bool isbossRelativeDistance;
        float bossRelativeDistance;
        float distanceTransitionTime;
        bool isToPlayer;
        int32_t lifeCount;
        int32_t hp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AutoRunParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AutoRunParams* pInstance);
        static void Clean(AutoRunParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDAutoRunVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::AutoRunParams params[4];
        bool isFinal;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDAutoRunVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDAutoRunVolumeSpawner* pInstance);
        static void Clean(ObjPBDAutoRunVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDBoostChangeDistanceVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool enable;
        int32_t lifeCount;
        int32_t hp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDBoostChangeDistanceVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDBoostChangeDistanceVolumeSpawner* pInstance);
        static void Clean(ObjPBDBoostChangeDistanceVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDDebrisSpawner {
        float respawnTime;
        bool isFloatingEffectValid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDDebrisSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDDebrisSpawner* pInstance);
        static void Clean(ObjPBDDebrisSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFChangeWeakPointVolumeSpawner {
        enum class DamageMode : uint8_t {
            Core = 0,
            EyeFront = 1,
            EyeBack = 2,
        };

        heur::rfl::VolumeTriggerSpawner volume;
        DamageMode changeWeakPoint;
        bool isPlayDoomsEyeAction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFChangeWeakPointVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFChangeWeakPointVolumeSpawner* pInstance);
        static void Clean(ObjPBDFChangeWeakPointVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFDebrisSpawner {
        float respawnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFDebrisSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFDebrisSpawner* pInstance);
        static void Clean(ObjPBDFDebrisSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFDoomsEyeFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            NUM_SIZE_TYPE = 3,
        };

        enum class ModelType : int8_t {
            MODEL_A = 0,
            MODEL_B = 1,
            MODEL_C = 2,
            MODEL_RANDOM = 3,
            NUM_MODEL_TYPE = 4,
        };

        enum class ModelColorType : int8_t {
            COLOR_RED = 0,
            COLOR_BLUE = 1,
            NUM_COLOR_TYPE = 2,
        };

        enum class RandomPosType : int8_t {
            RANDOM_ALL = 0,
            RANDOM_UP = 1,
            RANDOM_DOWN = 2,
            RANDOM_RIGHT = 3,
            RANDOM_LEFT = 4,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        ModelType modelType;
        ModelColorType colorType;
        int8_t modelRotNo;
        bool createEventDriven;
        bool eventDriven;
        bool isAppear;
        float appearTime;
        csl::math::Vector3 appearOffsetPos;
        csl::math::Vector3 appearRadMinPos;
        csl::math::Vector3 appearRadMaxPos;
        RandomPosType appearRadPosType;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        bool isSyncRot;
        float waitTime;
        float phase;
        float speed;
        float rotSpeed;
        float rotSpeedEvent;
        csl::math::Vector3 rotAxis;
        bool se_flag;
        uint32_t randomSeed;
        bool isSetReverseSide;
        bool appearRadPosUsed;
        csl::math::Vector3 appearRadPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFDoomsEyeFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFDoomsEyeFloorSpawner* pInstance);
        static void Clean(ObjPBDFDoomsEyeFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFDoomsEyeFloorGeneratorSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            NUM_SIZE_TYPE = 3,
        };

        enum class ModelType : int8_t {
            MODEL_A = 0,
            MODEL_B = 1,
            MODEL_C = 2,
            MODEL_RANDOM = 3,
            NUM_MODEL_TYPE = 4,
        };

        enum class ModelColorType : int8_t {
            COLOR_RED = 0,
            COLOR_BLUE = 1,
            NUM_COLOR_TYPE = 2,
        };

        enum class ModelRotType : int8_t {
            MODEL_ROT_UP = 0,
            MODEL_ROT_DOWN = 1,
            MODEL_ROT_RIGHT = 2,
            MODEL_ROT_LEFT = 3,
            MODEL_ROT_RANDOM = 4,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        int8_t horizontalNum;
        int8_t verticalNum;
        SizeType sizeType;
        ModelType modelType;
        ModelColorType colorType;
        ModelRotType modelRotType;
        bool createEventDriven;
        bool eventDriven;
        bool isAppear;
        float appearTime;
        csl::math::Vector3 appearRadMinPos;
        csl::math::Vector3 appearRadMaxPos;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        bool isSyncRot;
        float waitTime;
        float phase;
        float speed;
        float rotSpeed;
        float rotSpeedEvent;
        csl::math::Vector3 rotAxis;
        bool se_flag;
        uint32_t randomSeed;
        bool isSetReverseSide;
        bool isPointGeneratorUsed;
        hh::game::ObjectId pointGeneratorObjId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFDoomsEyeFloorGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFDoomsEyeFloorGeneratorSpawner* pInstance);
        static void Clean(ObjPBDFDoomsEyeFloorGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFDoomsEyeRoadSpawner {
        uint32_t modelNo;
        csl::math::Vector3 appearOffsetPos;
        bool se_flag;
        uint32_t randomSeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFDoomsEyeRoadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFDoomsEyeRoadSpawner* pInstance);
        static void Clean(ObjPBDFDoomsEyeRoadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFireBeamTargetSpawner {
        enum class ExecutionType : int8_t {
            TouchOnceExecution = 0,
            TouchRepeatExecution = 1,
            EventOnceExecution = 2,
            EventRepeatExecution = 3,
        };

        csl::math::Vector3 targetPos;
        ExecutionType executionType;
        heur::rfl::VolumeTriggerSpawner volume;
        float repeatTime;
        float beamTime;
        bool isImmediate;
        heur::rfl::ActionNotification startActions[5];
        heur::rfl::ActionNotification endActions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFireBeamTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFireBeamTargetSpawner* pInstance);
        static void Clean(ObjPBDFireBeamTargetSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFireBombTargetSpawner {
        int32_t targetId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFireBombTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFireBombTargetSpawner* pInstance);
        static void Clean(ObjPBDFireBombTargetSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFloorBlockSpawner {
        int32_t blockTypeIndex;
        bool isAmoebaFloor;
        bool isConnect;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFloorBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFloorBlockSpawner* pInstance);
        static void Clean(ObjPBDFloorBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct OffsetPosParam {
        int32_t indexNo;
        csl::math::Vector3 offsetPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OffsetPosParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OffsetPosParam* pInstance);
        static void Clean(OffsetPosParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFPointGeneratorSpawner {
        hh::game::ObjectId startPassPosLocator;
        hh::game::ObjectId endPassPosLocator;
        uint32_t gridXNum;
        uint32_t gridYNum;
        uint32_t gridZNum;
        csl::math::Vector3 gridSize;
        csl::math::Vector2 notCreateArea;
        float notOverlapRadius;
        uint32_t randomSeed;
        heur::rfl::OffsetPosParam offsetPosDataList[30];
        uint32_t useNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFPointGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFPointGeneratorSpawner* pInstance);
        static void Clean(ObjPBDFPointGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFSetWingChaseCameraVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        float distance;
        float hormingDistance;
        float attackingDistance;
        float minDistance;
        float maxDistance;
        float minElevation;
        float maxElevation;
        float targetUpOffset;
        float targetSideOffset;
        float boosTtargetUpOffset;
        float boostTargetSideOffset;
        float maxRollOffset;
        float rollSmoothTime;
        float minRollSpeedThreshold;
        float maxRollSpeedThreshold;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFSetWingChaseCameraVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFSetWingChaseCameraVolumeSpawner* pInstance);
        static void Clean(ObjPBDFSetWingChaseCameraVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDFWarpVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool isFinal;
        bool warpBegin;
        bool transitionBlow;
        uint32_t blowPaternNo;
        bool disableAttackChance;
        int32_t lifeCount;
        int32_t hp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDFWarpVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDFWarpVolumeSpawner* pInstance);
        static void Clean(ObjPBDFWarpVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDMeteoBeamPlaceSpawner {
        enum class BeamDirectionKind : int8_t {
            UP_DIRECTION = 0,
            DOWN_DIRECTION = 1,
            RIGHT_DIRECTION = 2,
            LEFT_DIRECTION = 3,
            UP_DOWN_DIRECTION = 4,
            LEFT_RIGHT_DIRECTION = 5,
            UDLR_DIRECTION = 6,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class InputGuideKind : int8_t {
            INPUT_GUIDE_KIND_NONE = 0,
            INPUT_GUIDE_KIND_LEFT_STEP = 1,
            INPUT_GUIDE_KIND_RIGHT_STEP = 2,
            INPUT_GUIDE_KIND_NUM = 3,
        };

        BeamDirectionKind laserDirKind;
        float rotSpeed;
        float length;
        float colRadius;
        float beamColRadius;
        int32_t blowHitDamagePoint;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        float speed;
        float waitTime;
        float phase;
        bool eventDriven;
        bool eventDrivenBeam;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        bool isReverse;
        bool isCreateDirection;
        bool isColliderEnable;
        InputGuideKind inputGuideKind;
        bool isSE;
        bool isWaterEffect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDMeteoBeamPlaceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDMeteoBeamPlaceSpawner* pInstance);
        static void Clean(ObjPBDMeteoBeamPlaceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDMeteoriteHockeyWallSpawner {
        csl::math::Vector3 wallSize;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDMeteoriteHockeyWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDMeteoriteHockeyWallSpawner* pInstance);
        static void Clean(ObjPBDMeteoriteHockeyWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDMotionPlayVolumeSpawner {
        csl::ut::VariableString startMotionName;
        csl::ut::VariableString loopMotionName;
        float loopMotionTime;
        bool isLoopMotionKeep;
        bool isStartMotionInterpolation;
        csl::ut::VariableString endMotionName;
        float motionSpeed;
        bool isPlayerPosMotionPlay;
        hh::game::ObjectId motionStartPlayerLocator;
        bool isBossStartPotionStop;
        bool isStartWarp;
        bool isStateEndAfter;
        bool isPlayMotionBeforeWarp;
        hh::game::ObjectId startBossLocator;
        csl::math::Vector3 startBossFrontVec;
        bool isEndWarp;
        bool isEndWarpNoEffect;
        bool stopOverride;
        bool isFinal;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDMotionPlayVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDMotionPlayVolumeSpawner* pInstance);
        static void Clean(ObjPBDMotionPlayVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Phase2ActionParams {
        enum class Phase2ActionType : int8_t {
            PHASE2ACT_NONE = 0,
            PHASE2ACT_FIREBOMB = 1,
            PHASE2ACT_FIREEBEAM = 2,
            PHASE2ACT_MAX = 3,
        };

        Phase2ActionType type;
        int32_t patternNo;
        int32_t lifeCount;
        bool isImmediate;
        heur::rfl::ActionNotification startActions[5];
        heur::rfl::ActionNotification endActions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Phase2ActionParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Phase2ActionParams* pInstance);
        static void Clean(Phase2ActionParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDPhase2ActionVolumeSpawner {
        enum class ExecutionType : int8_t {
            TouchExecution = 0,
            EventExecution = 1,
        };

        ExecutionType executionType;
        heur::rfl::VolumeTriggerSpawner volume;
        float actionRepeatTime;
        heur::rfl::Phase2ActionParams actionParams[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDPhase2ActionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDPhase2ActionVolumeSpawner* pInstance);
        static void Clean(ObjPBDPhase2ActionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDPhotonDashRingSpawner {
        float OutOfControl;
        float KeepVelocity;
        float Speed;
        float UpSpeed;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        heur::rfl::ActionNotification actions[6];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;
        float attackChanceTime;
        float moveStopTime;
        float moveStopDelayTime;
        bool HitStop;
        float HitStopDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDPhotonDashRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDPhotonDashRingSpawner* pInstance);
        static void Clean(ObjPBDPhotonDashRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDSafeAreaSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDSafeAreaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDSafeAreaSpawner* pInstance);
        static void Clean(ObjPBDSafeAreaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SetKeepDistanceParams {
        bool isEnable;
        float keepDistance;
        float changeDistanceSpeed;
        int32_t lifeCount;
        int32_t hp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SetKeepDistanceParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SetKeepDistanceParams* pInstance);
        static void Clean(SetKeepDistanceParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDSetKeepDistanceVolumeSpawner {
        bool isFinal;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::SetKeepDistanceParams params[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDSetKeepDistanceVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDSetKeepDistanceVolumeSpawner* pInstance);
        static void Clean(ObjPBDSetKeepDistanceVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDStopVolumeSpawner {
        bool isBossStop;
        bool isFinal;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDStopVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDStopVolumeSpawner* pInstance);
        static void Clean(ObjPBDStopVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SwitchLayerParams {
        bool isEnable;
        csl::ut::VariableString tag;
        bool isLayerEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwitchLayerParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwitchLayerParams* pInstance);
        static void Clean(SwitchLayerParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDSwitchLayerVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool isOnce;
        heur::rfl::SwitchLayerParams params[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDSwitchLayerVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDSwitchLayerVolumeSpawner* pInstance);
        static void Clean(ObjPBDSwitchLayerVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ActionParams {
        enum class ActionType : int8_t {
            ACT_NONE = 0,
            ACT_METEORITEBEAM = 1,
            ACT_METEORITEHOCKEY = 2,
            ACT_AMOEBAMULTIRAIN = 3,
            ACT_WINGTORNADO = 4,
            ACT_SPLASHBLOW = 5,
            MAX = 6,
        };

        ActionType type;
        int32_t phase1PatternNo;
        float actionTime;
        float actionWaitTime;
        float distanceMin;
        float distanceMax;
        int32_t lifeCount;
        int32_t hp;
        bool disableAttackChance;
        heur::rfl::ActionNotification actions[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ActionParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ActionParams* pInstance);
        static void Clean(ActionParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionParams actionParams[4];
        bool disableChaosBreakReaction;
        bool isFinal;
        float disableCollisionAddWidth;
        float disableCollisionAddHeight;
        float disableCollisionAddDepth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDVolumeSpawner* pInstance);
        static void Clean(ObjPBDVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPBDWarpVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool warpBegin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPBDWarpVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPBDWarpVolumeSpawner* pInstance);
        static void Clean(ObjPBDWarpVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossDebugPBDObjectGeneratorSpawner {
        enum class SpawnObjectType : uint8_t {
            METEORITE_BEAM = 0,
            METEORITE_HOCKEY = 1,
            AMOEBA_BLOCK = 2,
            DOOMSEYE = 3,
            MAX = 4,
        };

        enum class LaserDirectionKind : int8_t {
            UP_DIRECTION = 0,
            DOWN_DIRECTION = 1,
            RIGHT_DIRECTION = 2,
            LEFT_DIRECTION = 3,
            UP_DOWN_DIRECTION = 4,
            LEFT_RIGHT_DIRECTION = 5,
            UDLR_DIRECTION = 6,
        };

        SpawnObjectType spawnObjectType;
        float actionTime;
        LaserDirectionKind laserDirectionKind;
        float rotationSpeed;
        float moveSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossDebugPBDObjectGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossDebugPBDObjectGeneratorSpawner* pInstance);
        static void Clean(BossDebugPBDObjectGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlayerAbilityVolumeSpawner {
        enum class PlayerAbilityType : int8_t {
            None = 0,
            Jump = 1,
            Boost = 2,
            BoostAir = 3,
            HomingAttack = 4,
            WallAction = 5,
        };

        PlayerAbilityType abilityType;
        bool enable;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlayerAbilityVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlayerAbilityVolumeSpawner* pInstance);
        static void Clean(ObjPlayerAbilityVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSpawner {
        bool IsCameraView;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSpawner* pInstance);
        static void Clean(ObjCameraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossCameraRailForwardViewSpawner : heur::rfl::ObjCameraSpawner {
        enum class PlayerOffsetType : int8_t {
            PLAYER_OFFSET_NORMAL = 0,
            PLAYER_OFFSET_ABSOLUTE = 1,
        };

        float fovy;
        float zRot;
        float distance;
        csl::ut::VariableString pathName;
        float pathOffset;
        bool reversePathFront;
        bool usePathVerticalComponent;
        bool usePathNormal;
        bool usePosLerp;
        float posSensitivity;
        float posSensitivityBoost;
        float angleSensitivity;
        float angleSensitivityBoost;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        PlayerOffsetType playerOffsetType;
        bool enableCollision;
        float sideMoveDistanceMin;
        float sideMoveDistanceMax;
        csl::math::Vector3 sideMoveLocalOffset;
        float widthMoveDistanceMin;
        float widthMoveDistanceMax;
        csl::math::Vector3 widthMoveLocalOffset;
        bool enableEyePositionLimit;
        float eyePositionLimitMinY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossCameraRailForwardViewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossCameraRailForwardViewSpawner* pInstance);
        static void Clean(ObjBossCameraRailForwardViewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCamera3DSpawner : heur::rfl::ObjCameraSpawner {
        float offsetUp;
        float distanceMin;
        float distanceMax;
        float elevationMin;
        float elevationMax;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCamera3DSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCamera3DSpawner* pInstance);
        static void Clean(ObjCamera3DSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float distance;
        float screenUpLimit;
        float screenDownLimit;
        bool limitViewField;
        float viewFieldBottom;
        float azimuth;
        float elevation;
        csl::math::Vector3 targetOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicSpawner* pInstance);
        static void Clean(ObjCameraClassicSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicChangeParamVolumeSpawner {
        hh::game::ObjectId target;
        int32_t priority;
        float viewFieldBottom;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicChangeParamVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicChangeParamVolumeSpawner* pInstance);
        static void Clean(ObjCameraClassicChangeParamVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraClassicLimitSpawner : heur::rfl::ObjCameraSpawner {
        csl::ut::VariableString pathName;
        hh::game::ObjectId limitPointA;
        hh::game::ObjectId limitPointB;
        float fovy;
        float distance;
        float screenUpLimit;
        float screenDownLimit;
        bool limitViewField;
        float viewFieldBottom;
        float azimuth;
        float elevation;
        csl::math::Vector3 targetOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraClassicLimitSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraClassicLimitSpawner* pInstance);
        static void Clean(ObjCameraClassicLimitSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraCyberStandardSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float zRot;
        float distance;
        csl::ut::VariableString pathName;
        float pathOffset;
        bool reversePathFront;
        float azimuthSensitivity;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float azimuthOffset;
        float elevationOffset;
        float targetUpOffset;
        bool enableCollision;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraCyberStandardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraCyberStandardSpawner* pInstance);
        static void Clean(ObjCameraCyberStandardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraCylindricalInnerSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        csl::ut::VariableString gravityPathName;
        float distance;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float gravityOffset;
        float fixBorderAngleDeg;
        float rollSensitivity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraCylindricalInnerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraCylindricalInnerSpawner* pInstance);
        static void Clean(ObjCameraCylindricalInnerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraCylindricalOuterSpawner : heur::rfl::ObjCameraSpawner {
        csl::ut::VariableString gravityPathName;
        float pitch;
        float dist;
        float offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraCylindricalOuterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraCylindricalOuterSpawner* pInstance);
        static void Clean(ObjCameraCylindricalOuterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraFirstPersonSpawner : heur::rfl::ObjCameraSpawner {
        float Fovy;
        float ZRot;
        float Distance;
        float Yaw;
        float Pitch;
        csl::math::Vector3 targetOffset;
        float posLerpRatio;
        float rotLerpRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraFirstPersonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraFirstPersonSpawner* pInstance);
        static void Clean(ObjCameraFirstPersonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraFixSpawner : heur::rfl::ObjCameraSpawner {
        enum class TargetType : int8_t {
            TARGETTYPE_ABS_COORD = 0,
            TARGETTYPE_LOCATOR = 1,
        };

        float Fovy;
        float ZRot;
        TargetType targetType;
        csl::math::Vector3 TargetPosition;
        hh::game::ObjectId targetID;
        float targetDistance;
        csl::math::Vector3 offsetFromObject;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraFixSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraFixSpawner* pInstance);
        static void Clean(ObjCameraFixSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraFollowSpawner : heur::rfl::ObjCameraSpawner {
        float Fovy;
        float ZRot;
        float Distance;
        float Yaw;
        float Pitch;
        csl::math::Vector3 targetOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        bool enableCollision;
        bool enableCheckCelling;
        bool enableEyePositionLimit;
        float eyePositionLimitMinY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraFollowSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraFollowSpawner* pInstance);
        static void Clean(ObjCameraFollowSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraObjectPanSpawner : heur::rfl::ObjCameraSpawner {
        csl::math::Vector3 target;
        float fovy;
        bool enableLimitAngle;
        float azimuthLimitAngle;
        float elevationLimitAngle;
        csl::math::Vector3 worldOffset;
        float targetDistance;
        float targetFocusDistance;
        bool useDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraObjectPanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraObjectPanSpawner* pInstance);
        static void Clean(ObjCameraObjectPanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPanSpawner : heur::rfl::ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        float roll;
        bool enableLimitAngle;
        float azimuthLimitAngle;
        float elevationLimitAngle;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPanSpawner* pInstance);
        static void Clean(ObjCameraPanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPathMoveFollowSpawner : heur::rfl::ObjCameraSpawner {
        float Fovy;
        float ZRot;
        float Distance;
        float Yaw;
        float Pitch;
        csl::math::Vector3 targetOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        float toPlayerOffset;
        bool isFollowTangent;
        float followTangentOffset;
        csl::ut::VariableString pathName;
        bool enableCollision;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPathMoveFollowSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPathMoveFollowSpawner* pInstance);
        static void Clean(ObjCameraPathMoveFollowSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraPointSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float distance;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraPointSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraPointSpawner* pInstance);
        static void Clean(ObjCameraPointSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        csl::ut::VariableString pathName;
        float pathOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailSpawner* pInstance);
        static void Clean(ObjCameraRailSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailAnimationSpawner : heur::rfl::ObjCameraSpawner {
        enum class UpDirectionType : int8_t {
            UPDIR_Y_UP = 0,
            UPDIR_OBJ_TRANSFORM = 1,
        };

        enum class Type : int8_t {
            TIME_DRIVEN = 0,
            PLAYER_POSITION_DRIVEN = 1,
            EYE_PATH_NEAREST_BASE = 2,
            AT_PATH_NEAREST_BASE = 3,
        };

        float fovy;
        UpDirectionType upDirType;
        float zRot;
        csl::ut::VariableString eyePathName;
        float eyePathOffset;
        csl::ut::VariableString atPathName;
        float atPathOffset;
        Type type;
        float motionLength;
        bool reversePathAdvance;
        bool correctTargetPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailAnimationSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailAnimationSpawner* pInstance);
        static void Clean(ObjCameraRailAnimationSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailDivingSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        csl::ut::VariableString pathName;
        float distance;
        float distanceBoost;
        float horzFollowRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailDivingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailDivingSpawner* pInstance);
        static void Clean(ObjCameraRailDivingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailForwardViewSpawner : heur::rfl::ObjCameraSpawner {
        enum class PlayerOffsetType : int8_t {
            PLAYER_OFFSET_NORMAL = 0,
            PLAYER_OFFSET_ABSOLUTE = 1,
        };

        float fovy;
        float zRot;
        float distance;
        csl::ut::VariableString pathName;
        float pathOffset;
        bool reversePathFront;
        bool usePathVerticalComponent;
        bool usePathNormal;
        bool usePosLerp;
        float posSensitivity;
        float posSensitivityBoost;
        float angleSensitivity;
        float angleSensitivityBoost;
        float azimuthOffsetDeg;
        float elevationOffsetDeg;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        PlayerOffsetType playerOffsetType;
        bool enableCollision;
        bool enableCheckCelling;
        bool enableEyePositionLimit;
        float eyePositionLimitMinY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailForwardViewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailForwardViewSpawner* pInstance);
        static void Clean(ObjCameraRailForwardViewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailLookSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float distance;
        csl::ut::VariableString pathName;
        float pathOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        csl::math::Vector3 worldOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailLookSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailLookSpawner* pInstance);
        static void Clean(ObjCameraRailLookSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraRailSideViewSpawner : heur::rfl::ObjCameraSpawner {
        enum class OrientationMode : int8_t {
            GRAVITY = 0,
            PATH_NORMAL = 1,
        };

        float fovy;
        float distance;
        csl::ut::VariableString pathName;
        float elevation;
        float azimuth;
        float limitLeftRatio;
        float limitRightRatio;
        float upScrollRatio;
        float limitUpScrollDistance;
        float downScrollRatio;
        float limitDownScrollDistance;
        bool isLimitPathDistance;
        float limitPathDistanceMin;
        float limitPathDistanceMax;
        OrientationMode orientationMode;
        bool isSmoothPath;
        bool isDepthPathDependent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraRailSideViewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraRailSideViewSpawner* pInstance);
        static void Clean(ObjCameraRailSideViewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraShakeTriggerSpawner {
        enum class Type : int8_t {
            TYPE_ONESHOT = 0,
            TYPE_CONTINUANCE = 1,
        };

        enum class Shake : int8_t {
            Directional = 0,
            Random = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_EVENT = 3,
        };

        Type type;
        float shakeTime;
        float shakeRange;
        bool oneTimeOnly;
        Shake shakeType;
        float magnitude;
        int32_t freq;
        float zRot;
        float attnRatio;
        bool distanceDecayEnabled;
        ShapeType shape;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraShakeTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraShakeTriggerSpawner* pInstance);
        static void Clean(ObjCameraShakeTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSliderSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float distance;
        float distanceAir;
        float elevationAir;
        float angleSensitive;
        float elevationOffset;
        float pathOffset;
        float targetOffsetY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSliderSpawner* pInstance);
        static void Clean(ObjCameraSliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraStandardCommonParameter {
        float distance;
        float azimuthSensitivity;
        float minElevation;
        float maxElevation;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float elevationOffset;
        float targetUpOffset;
        bool disableRotationControl;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraStandardCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraStandardCommonParameter* pInstance);
        static void Clean(ObjCameraStandardCommonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraStandardDashParameter {
        float minDistance;
        float maxDistance;
        float elevationOffset;
        float azimuthSensitivity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraStandardDashParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraStandardDashParameter* pInstance);
        static void Clean(ObjCameraStandardDashParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraStandardLockonParameter {
        float distance;
        float elevationOffset;
        float targetUpOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraStandardLockonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraStandardLockonParameter* pInstance);
        static void Clean(ObjCameraStandardLockonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraStandardSpawner : heur::rfl::ObjCameraSpawner {
        heur::rfl::ObjCameraStandardCommonParameter common;
        heur::rfl::ObjCameraStandardDashParameter dash;
        heur::rfl::ObjCameraStandardLockonParameter lockon;
        bool bIsActiveOption;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraStandardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraStandardSpawner* pInstance);
        static void Clean(ObjCameraStandardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraSubVolumeSpawner {
        hh::game::ObjectId target;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraSubVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraSubVolumeSpawner* pInstance);
        static void Clean(ObjCameraSubVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraTiltSpawner : heur::rfl::ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        bool enableLimitAngle;
        float azimuthLimitAngle;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        float lineOffset;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraTiltSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraTiltSpawner* pInstance);
        static void Clean(ObjCameraTiltSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVerticalSpawner : heur::rfl::ObjCameraSpawner {
        float fovy;
        float distance;
        float elevationOffsetDeg;
        float gravityOffset;
        csl::math::Vector3 playerOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVerticalSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVerticalSpawner* pInstance);
        static void Clean(ObjCameraVerticalSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVolumeSpawner {
        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
            INTERPOLATE_ABSOLUTE_COORD = 2,
            INTERPOLATE_ABSOLUTE_STABLE = 3,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        hh::game::ObjectId target;
        uint32_t priority;
        bool useHighPriority;
        float easeTimeEnter;
        float easeTimeLeave;
        InterpolateType interpolateTypeEnter;
        InterpolateType interpolateTypeLeave;
        bool enableCollisionEnter;
        bool enableCollisionLeave;
        StateType state;
        ActionType action;
        bool disableFreeMode;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVolumeSpawner* pInstance);
        static void Clean(ObjCameraVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVolumeOnceSpawner {
        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
            INTERPOLATE_ABSOLUTE_COORD = 2,
            INTERPOLATE_ABSOLUTE_STABLE = 3,
        };

        hh::game::ObjectId target;
        uint32_t priority;
        bool useHighPriority;
        float easeTimeEnter;
        float easeTimeLeave;
        InterpolateType interpolateTypeEnter;
        InterpolateType interpolateTypeLeave;
        bool enableCollisionEnter;
        bool enableCollisionLeave;
        bool disableFreeMode;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVolumeOnceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVolumeOnceSpawner* pInstance);
        static void Clean(ObjCameraVolumeOnceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraVolumePlayerActionSpawner {
        enum class PlayerActionType : int8_t {
            GRIND = 0,
            PHOTON_DASH = 1,
            DSURF = 2,
            DAMOEBA = 3,
            DBLOW_AIM = 4,
            DWING = 5,
            DAMOEBA_CATCHED = 6,
            DBLOW_RUSH = 7,
        };

        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
            INTERPOLATE_ABSOLUTE_COORD = 2,
            INTERPOLATE_ABSOLUTE_STABLE = 3,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        PlayerActionType playerActionType;
        hh::game::ObjectId target;
        uint32_t priority;
        bool useHighPriority;
        float easeTimeEnter;
        float easeTimeLeave;
        InterpolateType interpolateTypeEnter;
        InterpolateType interpolateTypeLeave;
        bool enableCollisionEnter;
        bool enableCollisionLeave;
        StateType state;
        ActionType action;
        bool disableFreeMode;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraVolumePlayerActionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraVolumePlayerActionSpawner* pInstance);
        static void Clean(ObjCameraVolumePlayerActionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDefaultCameraSettingSpawner {
        hh::game::ObjectId cameraObjectID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDefaultCameraSettingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDefaultCameraSettingSpawner* pInstance);
        static void Clean(ObjDefaultCameraSettingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFarChangeVolumeSpawner {
        float farDist;
        uint32_t priority;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFarChangeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFarChangeVolumeSpawner* pInstance);
        static void Clean(ObjFarChangeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMotionCameraSpawner : heur::rfl::ObjCameraSpawner {
        csl::ut::VariableString resoueceName;
        bool isEnabledFrameRounding;
        bool isEnabledSequentialPlay;
        bool isEnabledDefaultZClip;
        bool isEnabledDefaultFovy;
        bool isEnabledLoopPlay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMotionCameraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMotionCameraSpawner* pInstance);
        static void Clean(ObjMotionCameraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTimeRecoverSpawner {
        enum class Type : uint8_t {
            Gray = 0,
            Blue = 1,
            Yellow = 2,
            Red = 3,
        };

        Type colorType;
        float collisionRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTimeRecoverSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTimeRecoverSpawner* pInstance);
        static void Clean(ObjTimeRecoverSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAlertSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAlertSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAlertSpawner* pInstance);
        static void Clean(ObjAlertSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaBlockGeneratorSpawner {
        enum class SetType : int8_t {
            ST_NORMAL = 0,
            ST_AFTER_MOVE = 1,
        };

        SetType type;
        int32_t blockTypeIndex;
        bool isBlockSize;
        csl::math::Vector3 blockSize;
        float scale;
        csl::math::Vector3 moveDirection;
        float moveSpeed;
        float activeTime;
        float waitTime;
        float spawnDelay;
        float spawnInterval;
        bool initActive;
        float respawnTime;
        float criticalTime;
        bool isConnect;
        bool isTransparency;
        heur::rfl::ActionNotification breakActions[5];
        heur::rfl::ActionNotification touchActions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaBlockGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaBlockGeneratorSpawner* pInstance);
        static void Clean(ObjAmoebaBlockGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaSwampSpawner {
        float scale;
        bool isInitActve;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaSwampSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaSwampSpawner* pInstance);
        static void Clean(ObjAmoebaSwampSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TouchParam {
        bool overrideSpeed;
        float minSpeed;
        float initSpeed;
        float keepVelocityTime;
        float outOfControlTime;
        bool overrideDirection;
        hh::game::ObjectId target;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TouchParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TouchParam* pInstance);
        static void Clean(TouchParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaTargetSpawner {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        heur::rfl::TouchParam touchParam;
        float initFinishSpeed;
        float horzFinishSpeed;
        float midFinishSpeed;
        float vertFinishSpeed;
        float autoSwingAngle;
        float speedKeepTime;
        float outOfControlTime;
        bool directional;
        hh::game::ObjectId target;
        float radius;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        bool isReverse;
        float moveSpeed;
        float waitTime;
        float phase;
        float lifeTime;
        float respawnTime;
        bool isAfterKill;
        heur::rfl::ActionNotification actions[5];
        bool enableInputGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guidePosOffset;
        bool disableFloorRay;
        float distanceFloor;
        bool fixSwingSpeed;
        float swingSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaTargetSpawner* pInstance);
        static void Clean(ObjAmoebaTargetSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaTargetGeneratorSpawner {
        enum class SetType : int8_t {
            ST_NORMAL = 0,
            ST_AFTER_MOVE = 1,
        };

        SetType type;
        float radius;
        float scale;
        csl::math::Vector3 moveDirection;
        float moveSpeed;
        float activeTime;
        float waitTime;
        float spawnDelay;
        float spawnInterval;
        bool initActive;
        float initFinishSpeed;
        float horzFinishSpeed;
        float midFinishSpeed;
        float vertFinishSpeed;
        float autoSwingAngle;
        float speedKeepTime;
        float outOfControlTime;
        bool directional;
        hh::game::ObjectId target;
        heur::rfl::ActionNotification actions[5];
        float respawnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaTargetGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaTargetGeneratorSpawner* pInstance);
        static void Clean(ObjAmoebaTargetGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaVolumeSpawner* pInstance);
        static void Clean(ObjAmoebaVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PassPlaneTriggerSpawner {
        float width;
        float height;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PassPlaneTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PassPlaneTriggerSpawner* pInstance);
        static void Clean(PassPlaneTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AutorunTriggerSpawner {
        enum class ActionType : int8_t {
            ACT_START = 0,
            ACT_FINISH = 1,
            ACT_DSURF = 2,
            ACT_DSURF_FINISH = 3,
            ACT_DWING = 4,
            ACT_DWING_FINISH = 5,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class JumpMode : int8_t {
            WorldSpace = 0,
            PathSpace = 1,
            NoneJump = 2,
        };

        ActionType action;
        csl::ut::VariableString pathName;
        float speed;
        float speedMin;
        float boostSpeed;
        float boostSpeedMin;
        float initialSpeed;
        float outOfControlTime;
        float glidingMoveRadius;
        float glidingMoveAspectRatio;
        float glidingMoveRadiusChangeTime;
        bool lockBoost;
        float lockBoostTime;
        bool lockTimeStop;
        float lockTimeStopTime;
        float width;
        float adjustSpeed;
        float limitTime;
        StateType state;
        JumpMode jumpMode;
        bool forceFall;
        bool endByAir;
        bool custom;
        float initialSideSpeed;
        float acceleSideForce;
        float deceleSideForce;
        float maxSideSpeed;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AutorunTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AutorunTriggerSpawner* pInstance);
        static void Clean(AutorunTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AutorunVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
            ACTION_DSURF = 2,
            ACTION_DWING = 3,
        };

        enum class JumpMode : int8_t {
            WorldSpace = 0,
            PathSpace = 1,
            NoneJump = 2,
        };

        csl::ut::VariableString pathName;
        float speed;
        float speedMin;
        float boostSpeed;
        float boostSpeedMin;
        float initialSpeed;
        bool shouldSetInitialSpeed;
        float outOfControlTime;
        float glidingMoveRadius;
        float glidingMoveAspectRatio;
        float glidingMoveRadiusChangeTime;
        bool lockBoost;
        float lockBoostTime;
        bool lockTimeStop;
        float lockTimeStopTime;
        float width;
        float adjustSpeed;
        StateType state;
        ActionType action;
        JumpMode jumpMode;
        bool forceFall;
        bool endByAir;
        bool custom;
        float initialSideSpeed;
        float acceleSideForce;
        float deceleSideForce;
        float maxSideSpeed;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AutorunVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AutorunVolumeSpawner* pInstance);
        static void Clean(AutorunVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBallLaunchTriggerSpawner {
        csl::ut::VariableString pathName;
        float minSpeed;
        float maxSpeed;
        bool reverse;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBallLaunchTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBallLaunchTriggerSpawner* pInstance);
        static void Clean(ObjBallLaunchTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBallMoveTriggerSpawner {
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBallMoveTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBallMoveTriggerSpawner* pInstance);
        static void Clean(ObjBallMoveTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBlockageVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBlockageVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBlockageVolumeSpawner* pInstance);
        static void Clean(ObjBlockageVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBlockColliderSpawner {
        enum class Shape : int8_t {
            Box = 0,
            Sphere = 1,
            Capsule = 2,
            NumShapes = 3,
        };

        Shape shape;
        csl::math::Vector3 offset;
        csl::math::Vector3 extents;
        float radius;
        float height;
        bool collidesWithCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBlockColliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBlockColliderSpawner* pInstance);
        static void Clean(ObjBlockColliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBlockObjectSpawner {
        enum class ActionType : int8_t {
            ACT_TERRAIN = 0,
            ACT_LIQUID = 1,
            ACT_RAYBLOCK = 2,
            ACT_EYESIGHTBLOCK = 3,
        };

        enum class ShapeType : int8_t {
            Box = 0,
            TriangularPrism = 1,
        };

        enum class MaterialType : int8_t {
            MAT_NONE = 0,
            MAT_STONE = 1,
            MAT_EARTH = 2,
            MAT_WOOD = 3,
            MAT_GRASS = 4,
            MAT_IRON = 5,
            MAT_SAND = 6,
            MAT_LAVA = 7,
            MAT_GLASS = 8,
            MAT_SNOW = 9,
            MAT_NO_ENTRY = 10,
            MAT_ICE = 11,
            MAT_WATER = 12,
            MAT_SEA = 13,
            MAT_DAMAGE = 14,
            MAT_DEAD = 15,
            MAT_FLOWER0 = 16,
            MAT_FLOWER1 = 17,
            MAT_FLOWER2 = 18,
            MAT_AIR = 19,
            MAT_DEADLEAVES = 20,
            MAT_WIREMESH = 21,
            MAT_DEAD_ANYDIR = 22,
            MAT_DAMAGE_THROUGH = 23,
            MAT_DRY_GRASS = 24,
            MAT_RELIC = 25,
            MAT_GIANT = 26,
            MAT_GRAVEL = 27,
            MAT_MUD_WATER = 28,
            MAT_WET3 = 29,
            MAT_WET4 = 30,
            MAT_WET1 = 31,
            MAT_WET2 = 32,
        };

        csl::math::Vector3 size;
        csl::math::Vector3 collisionOffset;
        bool initial;
        bool unsupported;
        ActionType action;
        ShapeType shapeType;
        MaterialType material;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBlockObjectSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBlockObjectSpawner* pInstance);
        static void Clean(ObjBlockObjectSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBlowAwayRecommendedLocatorSpawner {
        int32_t priority;
        float distance;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBlowAwayRecommendedLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBlowAwayRecommendedLocatorSpawner* pInstance);
        static void Clean(ObjBlowAwayRecommendedLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBombSpawner {
        enum class Visual : int8_t {
            ContactBomb = 0,
            Num = 1,
        };

        Visual visual;
        float explosionColliderDuration;
        float explosionRadius;
        bool isFloatingEffectValid;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBombSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBombSpawner* pInstance);
        static void Clean(ObjBombSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct InterpolateSettings {
        enum class InterpolateType : int8_t {
            INTERPOLATE_RELATIVE = 0,
            INTERPOLATE_ABSOLUTE = 1,
            INTERPOLATE_ABSOLUTE_COORD = 2,
        };

        float easeTimeOn;
        float easeTimeOff;
        InterpolateType interpolateTypeOn;
        InterpolateType interpolateTypeOff;
        bool useReturnCamera;
        hh::game::ObjectId returnCameraTarget;
        float returnCameraHeight;
        float returnCameraInterpolateRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(InterpolateSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(InterpolateSettings* pInstance);
        static void Clean(InterpolateSettings* pInstance);
    };
}

namespace heur::rfl {
    struct FadeSettings {
        float fadeOutTimeOn;
        float fadeStayTimeOn;
        float fadeInTimeOn;
        float fadeOutTimeOff;
        float fadeStayTimeOff;
        float fadeInTimeOff;
        bool stopWhenFade;
        float resumeDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FadeSettings* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FadeSettings* pInstance);
        static void Clean(FadeSettings* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraActivatorSpawner {
        enum class ActivateType : int8_t {
            INTERPOLATE = 0,
            FADE = 1,
        };

        enum class PlayerDisableType : int8_t {
            FROZEN = 0,
            HOLD = 1,
        };

        enum class PurposeOfUseCameraActivator : int8_t {
            Normal = 0,
            Quest = 1,
            NumUses = 2,
        };

        hh::game::ObjectId target;
        ActivateType type;
        uint32_t priority;
        bool useHighPriority;
        float delayTime;
        bool enableLifeTime;
        float lifeTime;
        bool disableControl;
        PlayerDisableType disableType;
        bool isPause;
        heur::rfl::InterpolateSettings interpolate;
        heur::rfl::FadeSettings fade;
        PurposeOfUseCameraActivator purposeOfUse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraActivatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraActivatorSpawner* pInstance);
        static void Clean(ObjCameraActivatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCautionVolumeSpawner {
        enum class CautionType : int8_t {
            CAUTIONTYPE_NONE = -1,
            CAUTIONTYPE_EXCLAMATION = 0,
            CAUTIONTYPE_QUICK_STEP = 1,
            CAUTIONTYPE_DRIFT = 2,
        };

        enum class NaviType : int8_t {
            NAVITYPE_NONE = 0,
            NAVITYPE_JUMP = 1,
            NAVITYPE_SLIDING = 2,
            NAVITYPE_BOOST = 3,
            NAVITYPE_STEP_BOTH = 4,
            NAVITYPE_STEP_L = 5,
            NAVITYPE_STEP_R = 6,
            NAVITYPE_HORMING_ATTACK = 7,
            NAVITYPE_STOMPING = 8,
            NAVITYPE_SPIN_DASH = 9,
            NAVITYPE_GRIND_MOVE = 10,
            NAVITYPE_BADDY_CHANGE = 11,
            NAVITYPE_COUNT = 12,
        };

        bool isHideIfInput;
        CautionType cautionType;
        NaviType naviType;
        bool isSwitch;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCautionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCautionVolumeSpawner* pInstance);
        static void Clean(ObjCautionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionBoxGearSpawner {
        enum class Visual : int8_t {
            Yellow = 0,
            Blue = 1,
            Green = 2,
            Num = 3,
        };

        enum class Event : int8_t {
            EVENT_NONE = 0,
            EVENT_VISIBLE = 1,
            EVENT_INVISIBLE = 2,
        };

        Visual visual;
        int32_t itemID;
        Event eventType;
        heur::rfl::PathMovement pathMovement;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionBoxGearSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionBoxGearSpawner* pInstance);
        static void Clean(ObjCollectionBoxGearSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjConversationVolumeSpawner {
        enum class EndRule : uint8_t {
            AUTOBYTIME = 0,
            AUTOBYVOICE = 1,
            AUTOBYVOICEANDDELAY = 2,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        heur::rfl::VolumeTriggerSpawner volume;
        csl::ut::VariableString labelName;
        EndRule endRule;
        float displayTime;
        float delayTime;
        StateType state;
        ActionType action;
        bool isSondOnly;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjConversationVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjConversationVolumeSpawner* pInstance);
        static void Clean(ObjConversationVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDamageSetVolumeSpawner {
        enum class DamageType : int8_t {
            Normal = 0,
            Laser = 1,
        };

        enum class DebugType : int8_t {
            Surface = 0,
            Wyre = 1,
            None = 2,
        };

        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        DamageType damageType;
        DebugType type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDamageSetVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDamageSetVolumeSpawner* pInstance);
        static void Clean(ObjDamageSetVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDamageTubeVolumeSpawner {
        float width;
        float height;
        float thickness;
        float deg;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDamageTubeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDamageTubeVolumeSpawner* pInstance);
        static void Clean(ObjDamageTubeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DamegeVolumeTarget {
        csl::ut::MoveArray<hh::game::ObjectId> objects;
        int32_t damagePoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DamegeVolumeTarget* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DamegeVolumeTarget* pInstance);
        static void Clean(DamegeVolumeTarget* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDamageVolumeSpawner {
        enum class Type : int8_t {
            TypeOnce = 0,
            TypeReuse = 1,
        };

        Type type;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::DamegeVolumeTarget targets[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDamageVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDamageVolumeSpawner* pInstance);
        static void Clean(ObjDamageVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DashPanelPathAdjustParameter {
        csl::ut::VariableString pathname;
        float adjustSpeed;
        float adjustTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DashPanelPathAdjustParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DashPanelPathAdjustParameter* pInstance);
        static void Clean(DashPanelPathAdjustParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DashPanelChallengeParam {
        bool isChallenge;
        bool isWait;
        bool isOnece;
        csl::ut::MoveArray<hh::game::ObjectId> nextObjects;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DashPanelChallengeParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DashPanelChallengeParam* pInstance);
        static void Clean(DashPanelChallengeParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDashPanelSpawner {
        enum class Visual : int8_t {
            DashPanel = 0,
            WaterDashRing = 1,
            WaterDashRingSV = 2,
            Num = 3,
        };

        enum class Type : int8_t {
            DEFAULT = 0,
            ISL = 1,
        };

        enum class ChangeType : int8_t {
            CHANGE_NONE = 0,
            CHANGE_BOARDING = 1,
            CHANGE_RUN = 2,
        };

        Visual visual;
        Type type;
        float ocTime;
        float speed;
        bool isPosConst;
        bool isOverrideVelocity;
        bool isVisible;
        bool isWaitAppear;
        bool isKeepAutoRunPathSpeed;
        heur::rfl::ActionNotification actions[3];
        heur::rfl::DashPanelPathAdjustParameter adjustPath;
        bool isEndOutControl;
        csl::math::Vector3 collisionScale;
        ChangeType changeType;
        heur::rfl::DashPanelChallengeParam challengeParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDashPanelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDashPanelSpawner* pInstance);
        static void Clean(ObjDashPanelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDashRollerSpawner : heur::rfl::ObjDashPanelSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            GR = 1,
            SV = 2,
            NUM_VISUALS = 3,
        };

        Visual visual;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDashRollerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDashRollerSpawner* pInstance);
        static void Clean(ObjDashRollerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DashRingChallengeParam {
        bool isChallenge;
        bool isWait;
        bool isOnece;
        csl::ut::MoveArray<hh::game::ObjectId> nextObjects;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DashRingChallengeParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DashRingChallengeParam* pInstance);
        static void Clean(DashRingChallengeParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDashRingSpawner {
        enum class Visual : int8_t {
            DashRing = 0,
            RainbowRing = 1,
            WaterDashRing = 2,
            WaterDashRingSV = 3,
            IslDashRing = 4,
            IslRainbowRing = 5,
            None = 6,
            Num = 7,
        };

        Visual visual;
        float OutOfControl;
        float KeepVelocity;
        float Speed;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        bool Railcanyon;
        bool WatterFall;
        bool GlassBreakJump;
        bool CityLastJump;
        bool ChaosLastJump;
        bool isEndOutControl;
        bool isWaitAppear;
        heur::rfl::ActionNotification actions[3];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;
        heur::rfl::DashRingChallengeParam challengeParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDashRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDashRingSpawner* pInstance);
        static void Clean(ObjDashRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjIgnoreDeadlineSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjIgnoreDeadlineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjIgnoreDeadlineSpawner* pInstance);
        static void Clean(ObjIgnoreDeadlineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDebugNoteSpawner {
        enum class ColorType : int8_t {
            TYPE_WHITE = 0,
            TYPE_BLACK = 1,
            TYPE_RED = 2,
            TYPE_GREEN = 3,
            TYPE_BLUE = 4,
            TYPE_YELLOW = 5,
        };

        csl::ut::VariableString memoText;
        ColorType colorType;
        float radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDebugNoteSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDebugNoteSpawner* pInstance);
        static void Clean(ObjDebugNoteSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDiEventStarterSpawner {
        csl::ut::VariableString eventName;
        float interpolationInSec;
        float interpolationOutSec;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDiEventStarterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDiEventStarterSpawner* pInstance);
        static void Clean(ObjDiEventStarterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDimensionTriggerSpawner {
        csl::ut::VariableString pathName;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDimensionTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDimensionTriggerSpawner* pInstance);
        static void Clean(ObjDimensionTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDimensionVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        bool isSideview;
        uint32_t priority;
        csl::ut::VariableString pathName;
        StateType state;
        ActionType action;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDimensionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDimensionVolumeSpawner* pInstance);
        static void Clean(ObjDimensionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDisableSpeedLineVolumeSpawner {
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDisableSpeedLineVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDisableSpeedLineVolumeSpawner* pInstance);
        static void Clean(ObjDisableSpeedLineVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDistSpaceValidationVolumeSpawner {
        enum class VolumeType : int8_t {
            START = 0,
            END = 1,
            START_DS = 2,
            END_DS = 3,
            START_UI = 4,
            END_UI = 5,
        };

        heur::rfl::VolumeTriggerSpawner volume;
        VolumeType type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDistSpaceValidationVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDistSpaceValidationVolumeSpawner* pInstance);
        static void Clean(ObjDistSpaceValidationVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDivingVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        bool limit;
        float easeTimeEnter;
        float easeTimeLeave;
        float outOfControlTime;
        float waitTime;
        bool velocityReset;
        bool cutStartMotion;
        StateType state;
        ActionType action;
        heur::rfl::VolumeTriggerSpawner volume;
        bool isEnableHomingAttack;
        bool updateSpeedParam;
        float maxVertSpeed;
        float acceleVertForce;
        float maxHorzSpeed;
        float acceleHorzForce;
        float deceleVertForce;
        float deceleHorzForce;
        float deceleNeutralForce;
        float maxVertSpeedBoost;
        float acceleVertForceBoost;
        float maxHorzSpeedBoost;
        float acceleHorzForceBoost;
        float deceleVertForceBoost;
        float deceleHorzForceBoost;
        float deceleNeutralForceBoost;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDivingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDivingVolumeSpawner* pInstance);
        static void Clean(ObjDivingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoorSpawner {
        int32_t no;
        float scale;
        float scaleLamp;
        bool isUseLamp;
        csl::ut::MoveArray<hh::game::ObjectId> targetList;
        bool isOpenCollider;
        csl::math::Vector3 openColliderOffsetPos;
        float openColliderHeight;
        float openColliderWidth;
        float openColliderDepth;
        bool bIsWhiteSpaceCollider;
        bool bIsWhiteSpaceBlackColor;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoorSpawner* pInstance);
        static void Clean(ObjDoorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoorSVSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            NUM_SIZE_TYPE = 1,
        };

        SizeType sizeType;
        float openTime;
        bool isOpenUp;
        csl::math::Vector3 openColliderOffsetPos;
        float openColliderWidth;
        float openColliderHeight;
        float openColliderDepth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoorSVSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoorSVSpawner* pInstance);
        static void Clean(ObjDoorSVSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDSurfSetMoveRateVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool isEnable;
        bool isResetDefult;
        float forwardMoveRate;
        float forwardMoveSpinRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDSurfSetMoveRateVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDSurfSetMoveRateVolumeSpawner* pInstance);
        static void Clean(ObjDSurfSetMoveRateVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDSurfSpinBreakSpawner {
        float force;
        float gravity;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDSurfSpinBreakSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDSurfSpinBreakSpawner* pInstance);
        static void Clean(ObjDSurfSpinBreakSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDWingBanVolumeSpawner {
        enum class Condition : int8_t {
            COND_EACHTIME = 0,
            COND_ONCE = 1,
        };

        Condition condition;
        bool eventDriven;
        bool shouldDeactivate;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDWingBanVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDWingBanVolumeSpawner* pInstance);
        static void Clean(ObjDWingBanVolumeSpawner* pInstance);
    };
}

namespace app::player {
    struct PlayerParamGliding {
        float rollSpeed;
        float pitchSpeed;
        float neutralRollSpeed;
        float neutralPitchSpeed;
        float maxRollAngle;
        float maxPitchUpAngle;
        float maxPitchDownAngle;
        float rollingSpeed;
        float rollingDamper;
        float rollingTime;
        float initialSpeed;
        float maxSideSpeed;
        float maxBoostSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamGliding* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamGliding* pInstance);
        static void Clean(PlayerParamGliding* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDWingGlidingVolumeSpawner {
        app::player::PlayerParamGliding param;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDWingGlidingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDWingGlidingVolumeSpawner* pInstance);
        static void Clean(ObjDWingGlidingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct moveData {
        csl::ut::VariableString pathName;
        bool isReverse;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(moveData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(moveData* pInstance);
        static void Clean(moveData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEagleSpawner {
        heur::rfl::moveData start;
        heur::rfl::moveData end;
        bool eventDriven;
        float outOfControlTime;
        float releaseDistance;
        bool isRotateNormal;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEagleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEagleSpawner* pInstance);
        static void Clean(ObjEagleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEffectPhotonDashPathSpawner {
        enum class PathType : int8_t {
            W01_01 = 0,
            W01_02 = 1,
            W01_03 = 2,
            W01_04 = 3,
            TYPE_NUM = 4,
        };

        csl::ut::VariableString pathName;
        float modelMaxLength;
        PathType pathType;
        float camEffectOffset;
        bool isSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEffectPhotonDashPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEffectPhotonDashPathSpawner* pInstance);
        static void Clean(ObjEffectPhotonDashPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEnterDistSpaceVolumeSpawner {
        enum class Kind : int8_t {
            W01_EnterDistSpace1 = 0,
            W01_EndMissileEvent = 1,
            W01_MissMissileEvent = 2,
            W02_EnterDistSpace1 = 3,
            W04_DeathEggRobotEvent = 4,
        };

        Kind kind;
        float cameraInterpolateInSec;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEnterDistSpaceVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEnterDistSpaceVolumeSpawner* pInstance);
        static void Clean(ObjEnterDistSpaceVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EventCameraParam {
        float camInterpolateTimeOnStart;
        float camInterpolateTimeOnFinish;
        bool setCameraLookAt;
        hh::game::ObjectId cameraLookAtTarget;
        csl::math::Vector3 cameraLookAt;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventCameraParam* pInstance);
        static void Clean(EventCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventSpawner {
        int32_t no;
        csl::ut::VariableString eventID;
        csl::ut::VariableString pageName;
        int32_t pageIndex;
        bool useDefaultPath;
        bool showEnemy;
        bool playerAfterIdle;
        bool isSkipDisable;
        bool isFrozen;
        heur::rfl::EventCameraParam camera;
        hh::game::ObjectId playerTrans;
        bool limitFps30;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventSpawner* pInstance);
        static void Clean(ObjEventSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventForcedEndVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventForcedEndVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventForcedEndVolumeSpawner* pInstance);
        static void Clean(ObjEventForcedEndVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EventOrder {
        enum class ConditionType : int8_t {
            CONDITION_ALL = 0,
            CONDITION_OR = 1,
        };

        csl::ut::MoveArray<hh::game::ObjectId> targetList;
        ConditionType condition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventOrder* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventOrder* pInstance);
        static void Clean(EventOrder* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventOrderHubSpawner {
        csl::ut::VariableString puzzleID;
        heur::rfl::EventOrder orders[8];
        csl::ut::VariableString correctLuaName;
        csl::ut::VariableString incorrectLuaName;
        heur::rfl::ActionNotification correctActions[5];
        heur::rfl::ActionNotification incorrectActions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventOrderHubSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventOrderHubSpawner* pInstance);
        static void Clean(ObjEventOrderHubSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventSetterSpawner {
        enum class TriggerType : int8_t {
            TRIGERTYPE_DEAD = 0,
            TRIGGERTYPE_ON = 1,
            TRIGGERTYPE_OFF = 2,
            TRIGGERTYPE_OFF_TO_ON = 3,
            TRIGGERTYPE_ON_TO_OFF = 4,
        };

        enum class ConditionType : int8_t {
            CONDITION_ALL = 0,
            CONDITION_OR = 1,
        };

        enum class Time : int8_t {
            TIMESTYPE_ONCE = 0,
            TIMESTYPE_SEVERAL = 1,
        };

        int32_t no;
        csl::ut::VariableString puzzleID;
        csl::ut::MoveArray<hh::game::ObjectId> TargetList;
        TriggerType Trigger;
        ConditionType Condition;
        Time TimesType;
        csl::ut::VariableString luaName;
        heur::rfl::ActionNotification actions[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventSetterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventSetterSpawner* pInstance);
        static void Clean(ObjEventSetterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventVolumeSpawner {
        int32_t no;
        heur::rfl::VolumeTriggerSpawner volume;
        csl::ut::VariableString enterEvent;
        csl::ut::VariableString leaveEvent;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventVolumeSpawner* pInstance);
        static void Clean(ObjEventVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFallDeadTriggerSpawner {
        enum class DrivenType : int8_t {
            DRIVE_RANGE = 0,
            DRIVE_EVENT = 1,
        };

        DrivenType drive;
        float distance;
        heur::rfl::VolumeTriggerSpawner volume;
        bool setDisableInDSurf;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFallDeadTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFallDeadTriggerSpawner* pInstance);
        static void Clean(ObjFallDeadTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFallLocatorSpawner {
        csl::math::Vector3 fallVelocity;
        float gravity;
        float rotateForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFallLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFallLocatorSpawner* pInstance);
        static void Clean(ObjFallLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFallReturnVolumeSpawner {
        hh::game::ObjectId returnPoint;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFallReturnVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFallReturnVolumeSpawner* pInstance);
        static void Clean(ObjFallReturnVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFanSpawner {
        enum class Model : int8_t {
            NORMAL = 0,
            BIG = 1,
        };

        enum class Visual : int8_t {
            Default = 0,
            ISL = 1,
        };

        enum class Type : int8_t {
            TYPE_ON = 0,
            TYPE_CYCLE = 1,
        };

        enum class Place : int8_t {
            ON_GROUND = 0,
            IN_AIR = 1,
            NUM_PLACES = 2,
        };

        Model model;
        Visual visual;
        Type type;
        Place place;
        float length;
        float velocity;
        float durOn;
        float durOff;
        float phase;
        bool eventDriven;
        bool isBeside;
        bool isWaitAppear;
        float rangeX;
        float rangeZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFanSpawner* pInstance);
        static void Clean(ObjFanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjFlaggedSwitchVolumeSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        int32_t no;
        Condition condition;
        float lifetime;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjFlaggedSwitchVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjFlaggedSwitchVolumeSpawner* pInstance);
        static void Clean(ObjFlaggedSwitchVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjForcedSlidingVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        csl::math::Vector3 rigidBodyCollisionSize;
        csl::math::Vector3 rigidBodyCollisionOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjForcedSlidingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjForcedSlidingVolumeSpawner* pInstance);
        static void Clean(ObjForcedSlidingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGameEndVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        bool isReleaseOnly;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGameEndVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGameEndVolumeSpawner* pInstance);
        static void Clean(ObjGameEndVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGimmickInfoSpawner {
        enum class PlayType : int8_t {
            TYPE_ANYTIME = 0,
            TYPE_NOONONLY = 1,
            TYPE_NIGHTONLY = 2,
            TYPE_WAITTIME = 3,
        };

        int32_t no;
        bool eventDriven;
        csl::ut::VariableString puzzleID;
        csl::ut::MoveArray<hh::game::ObjectId> childInfo;
        csl::ut::MoveArray<hh::game::ObjectId> childLogic;
        csl::ut::MoveArray<hh::game::ObjectId> childEvent;
        csl::ut::VariableString luaName;
        bool isHideMapIcon;
        bool isPuzzle;
        PlayType playType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGimmickInfoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGimmickInfoSpawner* pInstance);
        static void Clean(ObjGimmickInfoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DropItemParam {
        enum class ItemType : int8_t {
            NONE = 0,
            RING = 1,
            SKILL_PIECE = 2,
            POWER_SEED = 3,
            GUARD_SEED = 4,
        };

        ItemType dropItem;
        int32_t dropNum;
        int32_t dropSuperRingNum;
        float velocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DropItemParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DropItemParam* pInstance);
        static void Clean(DropItemParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGismoSpawner {
        int32_t no;
        csl::ut::VariableString name;
        float scale;
        bool enableInstance;
        csl::ut::VariableString giTextureName;
        csl::ut::VariableString giOcclusionTextureName;
        heur::rfl::DropItemParam dropItemParam;
        bool isMovable;
        bool changePhysicsGravity;
        bool zeroGravity;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGismoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGismoSpawner* pInstance);
        static void Clean(ObjGismoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoalRingSpawner {
        enum class PlayrActionType : int8_t {
            DASH = 0,
            STOP = 1,
            BRAKE = 2,
        };

        enum class SEType : int8_t {
            SE_NONE = 0,
            SE_30M = 1,
            SE_60M = 2,
            SE_95M = 3,
            SE_150M = 4,
            SE_190M = 5,
        };

        PlayrActionType actionType;
        csl::math::Vector3 collisionSize;
        bool isReduction;
        SEType seType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoalRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoalRingSpawner* pInstance);
        static void Clean(ObjGoalRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GCBoxSize {
        float x;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GCBoxSize* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GCBoxSize* pInstance);
        static void Clean(GCBoxSize* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGravityCylinderSpawner {
        enum class HeightType : int8_t {
            HEIGHT_12m = 0,
            HEIGHT_24m = 1,
            RADIUS_TYPE_NUM = 2,
        };

        enum class RotationDir : int8_t {
            Right = 0,
            Left = 1,
            None = 2,
        };

        enum class VolumeShape : int8_t {
            Cylinder = 0,
            Box = 1,
            HalfCylinderBox = 2,
        };

        HeightType heightType;
        RotationDir rotationDir;
        float rotationSpeed;
        VolumeShape volumeShape;
        float gravityRadius;
        heur::rfl::GCBoxSize gravityBox;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGravityCylinderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGravityCylinderSpawner* pInstance);
        static void Clean(ObjGravityCylinderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct RatGuardParam {
        enum class RatGuardRadiusType : int8_t {
            RADIUS_2m = 0,
            RADIUS_3m50 = 1,
            RADIUS_TYPE_NUM = 2,
        };

        enum class RatGuardType : uint8_t {
            CIRCLE = 0,
            HALF = 1,
            RATGUARD_TYPE_NUM = 2,
        };

        RatGuardRadiusType radType;
        RatGuardType ratGuardType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RatGuardParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RatGuardParam* pInstance);
        static void Clean(RatGuardParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObstacleParam {
        enum class ObstacleRadiusType : int8_t {
            RADIUS_1m = 0,
            RADIUS_2m = 1,
            RADIUS_TYPE_NUM = 2,
        };

        enum class ObstacleAngleType : uint8_t {
            ANGLE_90 = 0,
            ANGLE_120 = 1,
            ANGLE_180 = 2,
            ANGLE_270 = 3,
            ANGLE_TYPE_NUM = 4,
        };

        ObstacleRadiusType radType;
        ObstacleAngleType angleType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObstacleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObstacleParam* pInstance);
        static void Clean(ObstacleParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGravityCylinderWallSpawner {
        enum class GCylinderWallType : uint8_t {
            RatGuard = 0,
            Obstacle = 1,
            TypeNum = 2,
        };

        GCylinderWallType type;
        heur::rfl::RatGuardParam ratGuardParam;
        heur::rfl::ObstacleParam obstacleParam;
        float yRot;
        bool isStand;
        float collisionScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGravityCylinderWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGravityCylinderWallSpawner* pInstance);
        static void Clean(ObjGravityCylinderWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindBoosterSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        float ocTime;
        float speed;
        float keepVelocityTime;
        csl::math::Vector3 collisionSize;
        bool isOverrideVelocity;
        bool isVisible;
        bool reverse;
        bool isEndOutControl;
        bool isWaitAppear;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindBoosterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindBoosterSpawner* pInstance);
        static void Clean(ObjGrindBoosterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        uint32_t uid;
        float speed;
        float boostSpeed;
        float maxSpeed;
        float acceleForce;
        float gravityForce;
        bool updatePathPosition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindVolumeSpawner* pInstance);
        static void Clean(ObjGrindVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHintRingSpawner {
        enum class Visual : int8_t {
            HintRing = 0,
            Num = 1,
        };

        Visual visual;
        csl::ut::VariableString headerLabel;
        csl::ut::VariableString bodyLabel;
        csl::ut::VariableString textureName;
        csl::ut::VariableString movieName;
        float animSpeed;
        float respawnTime;
        csl::math::Vector3 box;
        csl::math::Vector3 offset;
        bool isDWingHint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHintRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHintRingSpawner* pInstance);
        static void Clean(ObjHintRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHoldPlayerVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        StateType state;
        ActionType action;
        float waitTime;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHoldPlayerVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHoldPlayerVolumeSpawner* pInstance);
        static void Clean(ObjHoldPlayerVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnableFlags {
        bool lightGage;
        bool enableBoost;
        bool enableDWing;
        bool dAmoeba;
        bool timeStop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnableFlags* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnableFlags* pInstance);
        static void Clean(EnableFlags* pInstance);
    };
}

namespace heur::rfl {
    struct ObjInputGuideVolumeSpawner {
        enum class DisplayType : int8_t {
            DISPLAYTYPE_2D = 0,
            DISPLAYTYPE_3D = 1,
            DISPLAYTPYE_NUM = 2,
        };

        enum class GuidePlayerAction : int8_t {
            JUMP = 0,
            TIMESTOP = 1,
            CHAOS_SPEAR = 2,
            BOOST = 3,
            STEP_LEFT = 4,
            STEP_RIGHT = 5,
            HOMING_ATTACK = 6,
            HOMING_ATTACK_AIR = 7,
            STOMP = 8,
            SLIDING = 9,
            SURF_SPIN = 10,
            DWING = 11,
            GUIDE_NUM = 12,
        };

        enum class EndRule : int8_t {
            DISPLAY_TIME = 0,
            LEAVE_VOLUME = 1,
        };

        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        DisplayType displayType;
        heur::rfl::VolumeTriggerSpawner volume;
        GuidePlayerAction guideType;
        EndRule endRule;
        float displayTime;
        csl::math::Vector2 screenPos;
        hh::game::ObjectId locator;
        csl::math::Vector3 locatorOffset;
        heur::rfl::EnableFlags enableFlags;
        StateType state;
        ActionType action;
        bool disableOption;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjInputGuideVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjInputGuideVolumeSpawner* pInstance);
        static void Clean(ObjInputGuideVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjIronBoxSpawner {
        int32_t BoxNumX;
        int32_t BoxNumY;
        int32_t BoxNumZ;
        bool dropShadow;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjIronBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjIronBoxSpawner* pInstance);
        static void Clean(ObjIronBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjItemBoxSpawner {
        enum class Visual : int8_t {
            Normal = 0,
            Sky = 1,
        };

        enum class Item : int8_t {
            Ring_10 = 0,
            Ring_20 = 1,
            LightGaugeMax = 2,
        };

        Visual visual;
        Item item;
        float upSpeed;
        float speedMin;
        float speedMax;
        float respawnTime;
        float outOfControlTime;
        float keepVelocityTime;
        float ignoreSwingingTime;
        float collisionRadius;
        bool isRespawn;
        bool eventDriven;
        bool isHorming;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjItemBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjItemBoxSpawner* pInstance);
        static void Clean(ObjItemBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpBoardPathSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        enum class SizeType : int8_t {
            SIZE_S = 0,
            SIZE_M = 1,
            SIZE_L = 2,
            SIZE_COUNT = 3,
        };

        Visual visual;
        float distance;
        float distanceX;
        float height;
        float outStrength;
        float inStrength;
        float inAngle;
        float impulseSpeedOn;
        float outOfControl;
        float motionTime;
        bool airtrick;
        bool isWaitAppear;
        SizeType size;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpBoardPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpBoardPathSpawner* pInstance);
        static void Clean(ObjJumpBoardPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct LaunchInfo {
        float threathold;
        float firstSpeed;
        float elevation;
        float outOfControl;
        float keepVelocityDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LaunchInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LaunchInfo* pInstance);
        static void Clean(LaunchInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpBoardSurfSpawner {
        heur::rfl::LaunchInfo launchInfos[3];
        heur::rfl::ActionNotification actions[3];
        bool disableLaunch;
        bool enableLeaveJump;
        float leaveJumpSpeedRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpBoardSurfSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpBoardSurfSpawner* pInstance);
        static void Clean(ObjJumpBoardSurfSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLimitEdgeJumpCollisionSpawner {
        enum class Condition : int8_t {
            COND_EACHTIME = 0,
            COND_ONCE = 1,
        };

        csl::math::Vector3 collisionSize;
        float setSpeedNormal;
        float setSpeedBoost;
        float minSpeed;
        float decelerationValue;
        float outOfControlTime;
        Condition condition;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLimitEdgeJumpCollisionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLimitEdgeJumpCollisionSpawner* pInstance);
        static void Clean(ObjLimitEdgeJumpCollisionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLocatorSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLocatorSpawner* pInstance);
        static void Clean(ObjLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLoopAreaVolumeSpawner {
        csl::ut::VariableString pathName;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLoopAreaVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLoopAreaVolumeSpawner* pInstance);
        static void Clean(ObjLoopAreaVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLRInputSwapVolumeSpawner {
        csl::math::Vector3 size;
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLRInputSwapVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLRInputSwapVolumeSpawner* pInstance);
        static void Clean(ObjLRInputSwapVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMagneticVolumeSpawner {
        float radius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMagneticVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMagneticVolumeSpawner* pInstance);
        static void Clean(ObjMagneticVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMissionCollectionSpawner {
        csl::ut::MoveArray<hh::game::ObjectId> itemGeneratorList;
        uint32_t clearItemNum;
        float limitTime;
        float resultTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMissionCollectionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMissionCollectionSpawner* pInstance);
        static void Clean(ObjMissionCollectionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ConnectParameter {
        enum class ConnectType : int8_t {
            CONNECT_SNS = 0,
            CONNECT_STRAIGHT = 1,
        };

        bool isConnect;
        ConnectType connectType;
        float splineTangentLength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ConnectParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ConnectParameter* pInstance);
        static void Clean(ConnectParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PathParameterCommon {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            GR_PATH = 1,
            SV_PATH = 2,
            FV_PATH = 3,
            PH_PATH = 4,
            SL_PATH = 5,
        };

        enum class GrindCapVisible : int8_t {
            Both = 0,
            Head = 1,
            Tail = 2,
            None = 3,
        };

        enum class ParamType : int8_t {
            PARAM_NONE = 0,
            PARAM_LINE = 1,
            PARAM_LOOP = 2,
            PARAM_SPIRAL = 3,
            PARAM_SET_PATH = 4,
            PARAM_POLYGON = 5,
            PARAM_CIRCLE = 6,
        };

        enum class ModelColor : int8_t {
            Blue = 0,
            Red = 1,
            Yellow = 2,
        };

        int32_t pathUID;
        PathType pathType;
        GrindCapVisible capVisible;
        float grindUnitLength;
        ParamType paramType;
        bool isMovable;
        GrindCapVisible homingPoint;
        bool isDistSpaceGrind;
        ModelColor modelColor;
        bool isBrakble;
        bool isNoneModel;
        bool isWaitAppear;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathParameterCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathParameterCommon* pInstance);
        static void Clean(PathParameterCommon* pInstance);
    };
}

namespace heur::rfl {
    struct PathCircleParameter : heur::rfl::PathParameterCommon {
        enum class NormalType : int8_t {
            NOR_DEFAULT = 0,
            NOR_OUTSIDE = 1,
            NOR_INSIDE = 2,
        };

        NormalType normalType;
        float radius;
        float divideRate;
        bool isReverse;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathCircleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathCircleParameter* pInstance);
        static void Clean(PathCircleParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMissionCollectionItemGeneratorSpawner {
        enum class PathType : int8_t {
            SetNode = 0,
            Circle = 1,
        };

        PathType pathType;
        csl::ut::VariableString pathName;
        uint32_t ringNum;
        heur::rfl::PathCircleParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMissionCollectionItemGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMissionCollectionItemGeneratorSpawner* pInstance);
        static void Clean(ObjMissionCollectionItemGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMissionClockSpawner {
        enum class ResourceType : int8_t {
            Blue = 0,
            Green = 1,
            Yellow = 2,
            RESOURCE_MAX = 3,
        };

        int32_t no;
        float defaultTimeLimitNormal;
        float defaultTimeLimitHard;
        csl::ut::MoveArray<hh::game::ObjectId> normalClocks;
        csl::ut::MoveArray<hh::game::ObjectId> hardClocks;
        hh::game::ObjectId targetNormalCamera;
        hh::game::ObjectId targetHardCamera;
        float cameraEaseTime;
        float cameraStayClockTime;
        float greatClearTimeNormal;
        float greatClearTimeHard;
        ResourceType CollectionItemBoxTypeNormal;
        int32_t CollectionItemBoxIDNormal;
        ResourceType CollectionItemBoxTypeHard;
        int32_t CollectionItemBoxIDHard;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMissionClockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMissionClockSpawner* pInstance);
        static void Clean(ObjMissionClockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMissionRingSpawner {
        enum class ResourceType : int8_t {
            Blue = 0,
            Green = 1,
            Yellow = 2,
            RESOURCE_MAX = 3,
        };

        int32_t no;
        int32_t challengeID;
        float defaultTimeLimitNormal;
        float defaultTimeLimitHard;
        int32_t ringNormaNormal;
        int32_t ringNormaHard;
        hh::game::ObjectId targetNormalCamera;
        hh::game::ObjectId targetHardCamera;
        float cameraEaseTime;
        float cameraStayTime;
        float greatClearTimeNormal;
        float greatClearTimeHard;
        ResourceType CollectionItemBoxTypeNormal;
        int32_t CollectionItemBoxIDNormal;
        ResourceType CollectionItemBoxTypeHard;
        int32_t CollectionItemBoxIDHard;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMissionRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMissionRingSpawner* pInstance);
        static void Clean(ObjMissionRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWSMissionBaseSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWSMissionBaseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWSMissionBaseSpawner* pInstance);
        static void Clean(ObjWSMissionBaseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNoEntryColliderSpawner {
        enum class Shape : int8_t {
            Box = 0,
            Sphere = 1,
            Capsule = 2,
            Donut = 3,
            NumShapes = 4,
        };

        int32_t no;
        Shape shape;
        csl::math::Vector3 offset;
        csl::math::Vector3 extents;
        float radius;
        float height;
        bool collidesWithCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNoEntryColliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNoEntryColliderSpawner* pInstance);
        static void Clean(ObjNoEntryColliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjObjectLayerTriggerSpawner {
        csl::ut::VariableString layerName;
        bool enabled;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjObjectLayerTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjObjectLayerTriggerSpawner* pInstance);
        static void Clean(ObjObjectLayerTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOutOfControlTriggerSpawner {
        float outOfControlTime;
        bool releaseByGround;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOutOfControlTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOutOfControlTriggerSpawner* pInstance);
        static void Clean(ObjOutOfControlTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOutOfControlVolumeSpawner {
        bool releaseByGround;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOutOfControlVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOutOfControlVolumeSpawner* pInstance);
        static void Clean(ObjOutOfControlVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleBaseSoundParam {
        csl::ut::VariableString name;
        bool is3D;
        float volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleBaseSoundParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleBaseSoundParam* pInstance);
        static void Clean(ObjParticleBaseSoundParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleBaseRumbleParam {
        csl::ut::VariableString name;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleBaseRumbleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleBaseRumbleParam* pInstance);
        static void Clean(ObjParticleBaseRumbleParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleBaseSpawner {
        csl::ut::VariableString effectName;
        float scale;
        uint8_t colorR;
        uint8_t colorG;
        uint8_t colorB;
        uint8_t colorA;
        heur::rfl::ObjParticleBaseSoundParam sound;
        heur::rfl::ObjParticleBaseRumbleParam rumble;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleBaseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleBaseSpawner* pInstance);
        static void Clean(ObjParticleBaseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleSpawner : heur::rfl::ObjParticleBaseSpawner {
        enum class TriggerType : int8_t {
            RANGE = 0,
            MESSAGE = 1,
        };

        enum class Emit : int8_t {
            EMIT_OBJECT = 0,
            EMIT_PLAYER = 1,
            EMIT_CAMERA = 2,
            EMIT_ORIGIN = 3,
        };

        TriggerType trigger;
        int32_t sectorId;
        bool bIsTimeStop;
        Emit emitPointType;
        float zOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleSpawner* pInstance);
        static void Clean(ObjParticleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleExtentSpawner {
        enum class Shape : int8_t {
            SHAPE_SPHERE = 0,
            SHAPE_BOX = 1,
        };

        enum class Emit : int8_t {
            EMIT_VOLUME = 0,
            EMIT_FACE = 1,
            EMIT_ORIGIN = 2,
        };

        enum class Direction : int8_t {
            DIRECTION_Y_UP = 0,
            DIRECTION_NORMAL = 1,
            DIRECTION_RANDOM = 2,
        };

        enum class ActiveType : int8_t {
            TYPE_ACTIVE = 0,
            TYPE_NONACTIVE = 1,
        };

        csl::ut::VariableString effectName;
        float scale;
        uint8_t colorR;
        uint8_t colorG;
        uint8_t colorB;
        uint8_t colorA;
        Shape shapeType;
        csl::math::Vector3 extents;
        Emit emitPointType;
        Direction directionType;
        float interval;
        float loopTime;
        bool bottomExclusion;
        bool upperHalfOnly;
        ActiveType active;
        int32_t sectorId;
        bool bIsTimeStop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleExtentSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleExtentSpawner* pInstance);
        static void Clean(ObjParticleExtentSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjParticleVolumeSpawner : heur::rfl::ObjParticleBaseSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
        };

        enum class Emit : int8_t {
            EMIT_OBJECT = 0,
            EMIT_PLAYER = 1,
            EMIT_CONTACT = 2,
            EMIT_CAMERA = 3,
            EMIT_ORIGIN = 4,
        };

        enum class Gravity : int8_t {
            GRAVITY_OBJECT = 0,
            GRAVITY_EMIT = 1,
        };

        Shape shapeType;
        float width;
        float height;
        float depth;
        float zOffset;
        bool isStay;
        Emit emitPointType;
        Gravity gravityPointType;
        bool bIsTimeStop;
        bool bIsEventPlay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjParticleVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjParticleVolumeSpawner* pInstance);
        static void Clean(ObjParticleVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPhotonDashRingSpawner {
        float OutOfControl;
        float KeepVelocity;
        float Speed;
        bool PosConst;
        bool VeloConst;
        bool Spin;
        bool AirTrick;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];
        heur::rfl::PathMovement pathMovement;
        csl::math::Vector3 collisionScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPhotonDashRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPhotonDashRingSpawner* pInstance);
        static void Clean(ObjPhotonDashRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPipeMoveTriggerSpawner {
        enum class SpeedType : int8_t {
            SPEED_FIX = 0,
            SPEED_MIN = 1,
        };

        csl::ut::VariableString pathName;
        SpeedType speedType;
        float speed;
        float outOfControlTime;
        float launchSpeed;
        float attackTime;
        bool isPoseToReverseGravity;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPipeMoveTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPipeMoveTriggerSpawner* pInstance);
        static void Clean(ObjPipeMoveTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlayerInputVolumeSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
        };

        enum class InvalidInputType : int8_t {
            POSTURE_INPUT = 0,
            PLAYER_INPUT = 1,
        };

        Condition condition;
        float time;
        InvalidInputType inputType;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlayerInputVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlayerInputVolumeSpawner* pInstance);
        static void Clean(ObjPlayerInputVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPlayerNavigateInfoSpawner {
        float moveSpeed;
        float maxMoveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPlayerNavigateInfoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPlayerNavigateInfoSpawner* pInstance);
        static void Clean(ObjPlayerNavigateInfoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MoveParameter {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_CONSTANT = 1,
            MOVE_ROTATE = 2,
        };

        MoveType type;
        float distance;
        float cycle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MoveParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MoveParameter* pInstance);
        static void Clean(MoveParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointLightSpawner {
        float colorR;
        float colorG;
        float colorB;
        float sourceRadius;
        float halfLength;
        float attenuationRadius;
        bool enableShadow;
        heur::rfl::MoveParameter move;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointLightSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointLightSpawner* pInstance);
        static void Clean(ObjPointLightSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointMarkerSpawner {
        enum class ViewType : int8_t {
            FORWARDVIEW = 0,
            SIDEVIEW = 1,
            SIDEVIEW_REV = 2,
        };

        enum class ModelType : int8_t {
            Normal = 0,
            Isl = 1,
        };

        enum class RestartType : int8_t {
            Standard = 0,
            Boarding = 1,
            DWing = 2,
        };

        float Width;
        ViewType StageType;
        ModelType modelType;
        heur::rfl::PassPlaneTriggerSpawner passPlane;
        RestartType restartType;
        hh::game::ObjectId camera;
        float cameraLimit;
        bool isDistSpace;
        bool isReset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointMarkerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointMarkerSpawner* pInstance);
        static void Clean(ObjPointMarkerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPopupSpringSpawner {
        float FirstSpeed;
        float OutOfControl;
        float KeepVelocityDistance;
        float VisibleTime;
        bool isEndOutControl;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPopupSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPopupSpringSpawner* pInstance);
        static void Clean(ObjPopupSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PICameraParameter {
        float azimuth;
        float elevation;
        float distance;
        float zRoll;
        float fovy;
        csl::math::Vector3 frameOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PICameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PICameraParameter* pInstance);
        static void Clean(PICameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPositionIndicatorSpawner {
        enum class PurposeOfUse : uint8_t {
            QuestFiledCenterLinePoint = 0,
            NumPurposes = 1,
        };

        PurposeOfUse purposeOfUse;
        bool useCamera;
        heur::rfl::PICameraParameter cameraParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPositionIndicatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPositionIndicatorSpawner* pInstance);
        static void Clean(ObjPositionIndicatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPressParamVolumeSpawner {
        float distance;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPressParamVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPressParamVolumeSpawner* pInstance);
        static void Clean(ObjPressParamVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPropellerSpringSpawner {
        float firstSpeedHA;
        float outOfControlHA;
        float keepVelocityDistanceHA;
        float firstSpeed;
        float outOfControl;
        float keepVelocityDistance;
        bool isEventOn;
        bool airtrick;
        float riseSpeed;
        float riseHeight;
        float maxHeight;
        float fallSpeed;
        float fallWaitTime;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPropellerSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPropellerSpringSpawner* pInstance);
        static void Clean(ObjPropellerSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulleySpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        csl::ut::VariableString pathName;
        float startPosition1D;
        float endPosition1D;
        bool isJumpCancel;
        csl::math::Vector3 offset;
        float minSpeed;
        float maxSpeed;
        float waitToReturnSec;
        float returnSpeed;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulleySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulleySpawner* pInstance);
        static void Clean(ObjPulleySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPulleyColumnSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        uint32_t height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPulleyColumnSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPulleyColumnSpawner* pInstance);
        static void Clean(ObjPulleyColumnSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepSpawner {
        enum class LineType : int8_t {
            LINE2_LEFT = 0,
            LINE2_RIGHT = 1,
            LINE3 = 2,
            LINE5 = 3,
        };

        enum class JumpMode : int8_t {
            WorldSpace = 0,
            PathSpace = 1,
            NoneJump = 2,
        };

        LineType line;
        csl::ut::VariableString pathName;
        float speed;
        float speedMin;
        float boostSpeed;
        float boostSpeedMin;
        float boostLvMaxSpeed;
        float boostLvMaxSpeedMin;
        float initialSpeed;
        float stepWidth;
        JumpMode jumpMode;
        bool endByAir;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepSpawner* pInstance);
        static void Clean(ObjQuickStepSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepTriggerSpawner : heur::rfl::ObjQuickStepSpawner {
        enum class ActionType : int8_t {
            ACT_START = 0,
            ACT_END = 1,
        };

        ActionType type;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepTriggerSpawner* pInstance);
        static void Clean(ObjQuickStepTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjQuickStepVolumeSpawner : heur::rfl::ObjQuickStepSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjQuickStepVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjQuickStepVolumeSpawner* pInstance);
        static void Clean(ObjQuickStepVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRailSwitchSpawner {
        int32_t switchId;
        float collisionTime;
        bool enableSpearTrigger;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRailSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRailSwitchSpawner* pInstance);
        static void Clean(ObjRailSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRailSwitchPathControllerSpawner {
        enum class PathType : int8_t {
            Blue = 0,
            Red = 1,
        };

        enum class HomingType : int8_t {
            Both = 0,
            Head = 1,
            Tail = 2,
            None = 3,
        };

        int32_t switchId;
        PathType defaultPathType;
        csl::ut::VariableString bluePathName1;
        csl::ut::VariableString bluePathName2;
        csl::ut::VariableString bluePathName3;
        csl::ut::VariableString bluePathName4;
        csl::ut::VariableString bluePathName5;
        HomingType blueHomingType;
        csl::ut::VariableString redPathName1;
        csl::ut::VariableString redPathName2;
        csl::ut::VariableString redPathName3;
        csl::ut::VariableString redPathName4;
        csl::ut::VariableString redPathName5;
        HomingType redHomingType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRailSwitchPathControllerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRailSwitchPathControllerSpawner* pInstance);
        static void Clean(ObjRailSwitchPathControllerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRailSwitchSignSpawner {
        enum class SignDirection : int32_t {
            Up = 0,
            Right = 1,
            Down = 2,
            Left = 3,
        };

        int32_t switchId;
        SignDirection signDirBlue;
        SignDirection signDirRed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRailSwitchSignSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRailSwitchSignSpawner* pInstance);
        static void Clean(ObjRailSwitchSignSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRainVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRainVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRainVolumeSpawner* pInstance);
        static void Clean(ObjRainVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct RequestChangeMotionVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RequestChangeMotionVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RequestChangeMotionVolumeSpawner* pInstance);
        static void Clean(RequestChangeMotionVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjResultPositionSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjResultPositionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjResultPositionSpawner* pInstance);
        static void Clean(ObjResultPositionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRingSpawner {
        enum class Visibility : int8_t {
            Visible = 0,
            Invisible = 1,
        };

        Visibility visibility;
        float respawnTime;
        bool isEventDrivenEffect;
        heur::rfl::PathMovement pathMovement;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRingSpawner* pInstance);
        static void Clean(ObjRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSuperRingSpawner : heur::rfl::ObjRingSpawner {
        enum class RotateAxis : int8_t {
            WorldAxisY = 0,
            LocalAxisY = 1,
        };

        RotateAxis axis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSuperRingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSuperRingSpawner* pInstance);
        static void Clean(ObjSuperRingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SaveDenyVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SaveDenyVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SaveDenyVolumeSpawner* pInstance);
        static void Clean(SaveDenyVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SelectCannonLaunch {
        csl::math::Vector3 direction;
        float firstSpeed;
        float keepVelocityDistance;
        float outOfControl;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SelectCannonLaunch* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SelectCannonLaunch* pInstance);
        static void Clean(SelectCannonLaunch* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSelectCannonSpawner {
        bool isLimitOn;
        float limitTime;
        int32_t selectNum;
        heur::rfl::SelectCannonLaunch launchParam[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSelectCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSelectCannonSpawner* pInstance);
        static void Clean(ObjSelectCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathNodeSpawner {
        enum class LineType : int8_t {
            LINETYPE_SNS = 0,
            LINETYPE_STRAIGHT = 1,
            NUM = 2,
        };

        uint32_t nodeId;
        LineType lineType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathNodeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathNodeSpawner* pInstance);
        static void Clean(ObjSetPathNodeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PathSetPathParameter : heur::rfl::PathParameterCommon {
        enum class LineType : int8_t {
            LINETYPE_SNS = 0,
            LINETYPE_STRAIGHT = 1,
        };

        csl::ut::MoveArray<hh::game::ObjectId> nodeList;
        bool isLoopPath;
        LineType startLineType;
        float divideLength;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathSetPathParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathSetPathParameter* pInstance);
        static void Clean(PathSetPathParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathSpawner {
        heur::rfl::PathSetPathParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathSpawner* pInstance);
        static void Clean(ObjSetPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PathLoopParameter : heur::rfl::PathParameterCommon {
        enum class EasingPoint : int8_t {
            BothPoint = 0,
            BeginPoint = 1,
            EndPonit = 2,
        };

        float inRadius;
        float outRadius;
        float angle;
        float shiftDistance;
        float inDistance;
        float outDistance;
        float easingForce;
        EasingPoint easingPoint;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathLoopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathLoopParameter* pInstance);
        static void Clean(PathLoopParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathLoopSpawner {
        heur::rfl::PathLoopParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathLoopSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathLoopSpawner* pInstance);
        static void Clean(ObjSetPathLoopSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PathSpiralParameter : heur::rfl::PathParameterCommon {
        enum class RotDir : int8_t {
            ROT_DIR_LEFT = 0,
            ROT_DIR_RIGHT = 1,
        };

        enum class EasingPoint : int8_t {
            BothPoint = 0,
            BeginPoint = 1,
            EndPonit = 2,
        };

        RotDir rotDir;
        float inRadius;
        float outRadius;
        float angle;
        float shiftDistance;
        float inDistance;
        float outDistance;
        float easingForce;
        EasingPoint easingPoint;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathSpiralParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathSpiralParameter* pInstance);
        static void Clean(PathSpiralParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathSpiralSpawner {
        heur::rfl::PathSpiralParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathSpiralSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathSpiralSpawner* pInstance);
        static void Clean(ObjSetPathSpiralSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PathLineParameter : heur::rfl::PathParameterCommon {
        float distance;
        float twistAngle;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathLineParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathLineParameter* pInstance);
        static void Clean(PathLineParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathLineSpawner {
        heur::rfl::PathLineParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathLineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathLineSpawner* pInstance);
        static void Clean(ObjSetPathLineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathCircleSpawner {
        heur::rfl::PathCircleParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathCircleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathCircleSpawner* pInstance);
        static void Clean(ObjSetPathCircleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct PathPolygonParameter : heur::rfl::PathParameterCommon {
        enum class PolygonType : int8_t {
            TRIANGLE_PATH = 0,
            SQUARE_PATH = 1,
        };

        enum class NormalType : int8_t {
            NOR_DEFAULT = 0,
            NOR_OUTSIDE = 1,
            NOR_INSIDE = 2,
        };

        PolygonType polygonType;
        NormalType normalType;
        float width;
        float height;
        float offsetHeight;
        heur::rfl::ConnectParameter connectParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathPolygonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathPolygonParameter* pInstance);
        static void Clean(PathPolygonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathPolygonSpawner {
        heur::rfl::PathPolygonParameter setParameter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathPolygonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathPolygonSpawner* pInstance);
        static void Clean(ObjSetPathPolygonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSetPathConnectorSpawner {
        enum class PathType : int8_t {
            OBJ_PATH = 0,
            GR_PATH = 1,
            SV_PATH = 2,
            FV_PATH = 3,
            PH_PATH = 4,
            SL_PATH = 5,
        };

        enum class HomingAttackPoint : int8_t {
            Both = 0,
            Head = 1,
            Tail = 2,
            None = 3,
        };

        int32_t pathUID;
        PathType pathType;
        csl::ut::MoveArray<hh::game::ObjectId> pathList;
        bool isLoopPath;
        float divideLength;
        bool isMovable;
        HomingAttackPoint homingPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSetPathConnectorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSetPathConnectorSpawner* pInstance);
        static void Clean(ObjSetPathConnectorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSkatingVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSkatingVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSkatingVolumeSpawner* pInstance);
        static void Clean(ObjSkatingVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderPathVolumeSpawner {
        csl::ut::VariableString pathName;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderPathVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderPathVolumeSpawner* pInstance);
        static void Clean(ObjSliderPathVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderParamTriggerSpawner {
        float speed;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderParamTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderParamTriggerSpawner* pInstance);
        static void Clean(ObjSliderParamTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSliderTriggerSpawner {
        enum class ActionType : int8_t {
            ACT_BEGIN = 0,
            ACT_END = 1,
        };

        ActionType action;
        float speed;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSliderTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSliderTriggerSpawner* pInstance);
        static void Clean(ObjSliderTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpearSwitchSpawner {
        float scale;
        float switchOffRadius;
        float switchOffHeight;
        float switchOnRadius;
        float switchOnHeight;
        heur::rfl::ActionNotification actions[5];
        bool needOpenAllSwitch;
        bool enableSolid;
        bool enableInputGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guidePosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpearSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpearSwitchSpawner* pInstance);
        static void Clean(ObjSpearSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpearTargetSpawner {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        float radius;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        bool isReverse;
        float moveSpeed;
        float waitTime;
        float phase;
        bool isSV;
        bool bIsGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guideViewOffset;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpearTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpearTargetSpawner* pInstance);
        static void Clean(ObjSpearTargetSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringSpawner {
        enum class Visual : int8_t {
            Normal = 0,
            Sky = 1,
            Water = 2,
        };

        enum class Type : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        Type type;
        float firstSpeed;
        float outOfControl;
        float keepVelocityDistance;
        float colliRadius;
        float colliRadiusSolid;
        csl::math::Vector3 colliPositionOffset;
        csl::math::Vector3 colliPositionOffsetSolid;
        bool isHorming;
        bool isEventOn;
        bool isWaitAppear;
        bool isHorizon;
        bool airtrick;
        bool isVisible;
        bool isSmooth;
        bool isDisposable;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringSpawner* pInstance);
        static void Clean(ObjSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringPoleSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        float speedMin;
        float speedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringPoleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringPoleSpawner* pInstance);
        static void Clean(ObjSpringPoleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjStartPositionSpawner {
        enum class StartType : int8_t {
            STAND = 0,
            RUNNING = 1,
            FALL = 2,
            DOWN = 3,
            BOARDING = 4,
        };

        StartType m_startType;
        float m_speed;
        float m_time;
        float m_outOfControlTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjStartPositionSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjStartPositionSpawner* pInstance);
        static void Clean(ObjStartPositionSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SteeringAssistTriggerSpawner {
        csl::ut::VariableString pathName;
        float speed;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SteeringAssistTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SteeringAssistTriggerSpawner* pInstance);
        static void Clean(SteeringAssistTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SteeringAssistVolumeSpawner {
        csl::ut::VariableString pathName;
        float speed;
        uint8_t priority;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SteeringAssistVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SteeringAssistVolumeSpawner* pInstance);
        static void Clean(SteeringAssistVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwitchableMotionObjectSpawner {
        enum class BuildingType : int8_t {
            DS_BUILDING_A = 0,
            DS_BUILDING_D = 1,
            DS_BUILDING_E = 2,
            DS_GATE = 3,
            DS_GROUND_BUILDING_A = 4,
            DS_JUMP_RAMP = 5,
            DS_SHAKE_FLOOR_A = 6,
            DS_SHAKE_FLOOR_B = 7,
            DS_TUBE_TERRAIN_01 = 8,
            DS_TUBE_TERRAIN_02 = 9,
            DS_TUBE_TERRAIN_03 = 10,
            DS_TUBE_DAMAGE = 11,
            DS_CLASH_A = 12,
            DS_CLASH_B = 13,
            DS_CLASH_C = 14,
            TYPE_NUM = 15,
        };

        BuildingType modelType;
        float scale;
        bool isLoop;
        int32_t initFrame;
        int32_t endFrame;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwitchableMotionObjectSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwitchableMotionObjectSpawner* pInstance);
        static void Clean(ObjSwitchableMotionObjectSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwitchVolumeSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        Condition condition;
        float lifetime;
        bool eventDriven;
        bool supportedTimeStop;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwitchVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwitchVolumeSpawner* pInstance);
        static void Clean(ObjSwitchVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainBlockSpawner {
        enum class Block : int8_t {
            BLOCK_BOX = 0,
            BLOCK_ARCH_CURVE_UP = 1,
            BLOCK_ARCH_CURVE_DOWN = 2,
            BLOCK_ARCH_CURVE_RIGHT = 3,
            BLOCK_ARCH_CURVE_LEFT = 4,
        };

        enum class Layer : int8_t {
            LAYER_LAND = 0,
            LAYER_MOVELAND = 1,
        };

        enum class MaterialType : int8_t {
            MAT_NONE = 0,
            MAT_STONE = 1,
            MAT_EARTH = 2,
            MAT_WOOD = 3,
            MAT_GRASS = 4,
            MAT_IRON = 5,
            MAT_SAND = 6,
            MAT_LAVA = 7,
            MAT_GLASS = 8,
            MAT_SNOW = 9,
            MAT_NO_ENTRY = 10,
            MAT_ICE = 11,
            MAT_WATER = 12,
            MAT_SEA = 13,
            MAT_DAMAGE = 14,
            MAT_DEAD = 15,
            MAT_FLOWER0 = 16,
            MAT_FLOWER1 = 17,
            MAT_FLOWER2 = 18,
            MAT_AIR = 19,
            MAT_DEADLEAVES = 20,
            MAT_WIREMESH = 21,
            MAT_DEAD_ANYDIR = 22,
            MAT_DAMAGE_THROUGH = 23,
            MAT_DRY_GRASS = 24,
            MAT_RELIC = 25,
            MAT_GIANT = 26,
            MAT_GRAVEL = 27,
            MAT_MUD_WATER = 28,
            MAT_WET3 = 29,
            MAT_WET4 = 30,
            MAT_WET1 = 31,
            MAT_WET2 = 32,
        };

        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class Color : int8_t {
            COLOR_GREEN = 0,
            COLOR_BROWN = 1,
            COLOR_BLUE = 2,
            COLOR_WHITE = 3,
            COLOR_RED = 4,
            COLOR_YELLOW = 5,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class BreakableDamageType : int8_t {
            BDT_None = 0,
            BDT_DestroyTerrain = 1,
        };

        Block BlockType;
        float BlockWidth;
        float BlockWidthEnd;
        float BlockHeight;
        float BlockDepth;
        float BlockDepthOffset;
        float ArchRadius;
        float ArchDegree;
        uint32_t ArchDivNum;
        float SlopeHeight;
        bool EnableDamage;
        bool EnableSolid;
        Layer LayerGroup;
        bool AttrParkour;
        bool AttrBreakable;
        bool AttrSlope;
        bool AttrWall;
        bool AttrLoop;
        bool AttrSlide;
        bool AttrSlider;
        bool AttrUnsupported;
        bool AttrAmoeba;
        bool AttrWater;
        MaterialType material;
        WallType WallLeft;
        WallType WallRight;
        WallType WallFront;
        WallType WallBack;
        float WallHeight;
        Color ColorType;
        float Interval;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        BreakableDamageType damageType;
        bool eventDriven;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        bool isReverse;
        float moveSpeed;
        float waitTime;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainBlockSpawner* pInstance);
        static void Clean(ObjTerrainBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Point {
        float z;
        float y;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Point* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Point* pInstance);
        static void Clean(Point* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainBlocksSpawner {
        enum class Layer : int8_t {
            LAYER_LAND = 0,
            LAYER_MOVELAND = 1,
        };

        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class Color : int8_t {
            COLOR_GREEN = 0,
            COLOR_BROWN = 1,
            COLOR_BLUE = 2,
            COLOR_WHITE = 3,
            COLOR_RED = 4,
            COLOR_YELLOW = 5,
        };

        float Width;
        float Height;
        heur::rfl::Point Blocks[30];
        Layer LayerGroup;
        bool AttrEnableParkour;
        WallType WallLeft;
        WallType WallRight;
        WallType WallFront;
        WallType WallBack;
        float WallHeight;
        Color ColorType;
        float Interval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainBlocksSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainBlocksSpawner* pInstance);
        static void Clean(ObjTerrainBlocksSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainPathSpawner {
        enum class Color : int8_t {
            COLOR_GREEN = 0,
            COLOR_BROWN = 1,
            COLOR_BLUE = 2,
            COLOR_WHITE = 3,
            COLOR_RED = 4,
            COLOR_YELLOW = 5,
        };

        enum class MaterialType : int8_t {
            MAT_NONE = 0,
            MAT_STONE = 1,
            MAT_EARTH = 2,
            MAT_WOOD = 3,
            MAT_GRASS = 4,
            MAT_IRON = 5,
            MAT_SAND = 6,
            MAT_LAVA = 7,
            MAT_GLASS = 8,
            MAT_SNOW = 9,
            MAT_NO_ENTRY = 10,
            MAT_ICE = 11,
            MAT_WATER = 12,
            MAT_SEA = 13,
            MAT_DAMAGE = 14,
            MAT_DEAD = 15,
            MAT_FLOWER0 = 16,
            MAT_FLOWER1 = 17,
            MAT_FLOWER2 = 18,
            MAT_AIR = 19,
            MAT_DEADLEAVES = 20,
            MAT_WIREMESH = 21,
            MAT_DEAD_ANYDIR = 22,
            MAT_DAMAGE_THROUGH = 23,
            MAT_DRY_GRASS = 24,
            MAT_RELIC = 25,
            MAT_GIANT = 26,
            MAT_GRAVEL = 27,
            MAT_MUD_WATER = 28,
            MAT_WET3 = 29,
            MAT_WET4 = 30,
            MAT_WET1 = 31,
            MAT_WET2 = 32,
        };

        enum class WallType : int8_t {
            WALL_NONE = 0,
            WALL_EXIST = 1,
            WALL_COLLISION = 2,
        };

        enum class NormalType : int8_t {
            NORMAL_BY_YUP = 0,
            NORMAL_BY_PATH = 1,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        csl::ut::VariableString pathName;
        float widthStart;
        float widthEnd;
        float height;
        float wallHeight;
        int32_t split;
        Color ColorType;
        bool EnableDamage;
        bool EnableSolid;
        bool AttrParkour;
        bool AttrBreakable;
        bool AttrSlope;
        bool AttrWall;
        bool AttrLoop;
        bool AttrSlide;
        bool AttrSlider;
        bool AttrAmoeba;
        bool AttrWater;
        MaterialType material;
        WallType rightWallType;
        WallType leftWallType;
        WallType frontWallType;
        WallType backWallType;
        NormalType normalType;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString movePathName;
        bool isReverse;
        float moveSpeed;
        float waitTime;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainPathSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainPathSpawner* pInstance);
        static void Clean(ObjTerrainPathSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainPathCylinderSpawner {
        csl::ut::VariableString pathName;
        float radius;
        int32_t numPlain;
        float splitDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainPathCylinderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainPathCylinderSpawner* pInstance);
        static void Clean(ObjTerrainPathCylinderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornSpawner {
        enum class MoveType : int8_t {
            TYPE_APPEAR = 0,
            TYPE_DISAPPEAR = 1,
            TYPE_MOVE = 2,
        };

        csl::math::Vector2 size;
        csl::math::Vector2 interval;
        float offTime;
        float onTime;
        float phase;
        MoveType type;
        bool eventDriven;
        bool hasRigidbody;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornSpawner* pInstance);
        static void Clean(ObjThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallMoveParam {
        enum class Direction : int8_t {
            DIR_HORIZONTAL = 0,
            DIR_VERTICAL = 1,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        float time;
        float distance;
        float phase;
        Direction direction;
        TimeType timeType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallMoveParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallMoveParam* pInstance);
        static void Clean(ObjThornBallMoveParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallRollingParam {
        enum class Direction : int8_t {
            DIR_HORIZONTAL = 0,
            DIR_VERTICAL = 1,
        };

        float time;
        float radius;
        float phase;
        Direction direction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallRollingParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallRollingParam* pInstance);
        static void Clean(ObjThornBallRollingParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornBallSpawner {
        enum class Type : int8_t {
            TYPE_NORMAL = 0,
            TYPE_MOVE = 1,
            TYPE_ROLLING = 2,
        };

        Type type;
        bool hitEnemy;
        heur::rfl::ObjThornBallMoveParam moveParam;
        heur::rfl::ObjThornBallRollingParam rollingParam;
        bool eventDriven;
        float collisionRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornBallSpawner* pInstance);
        static void Clean(ObjThornBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThornCylinderSpawner {
        enum class Type : int8_t {
            TYPE_SHORT = 0,
            TYPE_LONG = 1,
            NUM_TYPES = 2,
        };

        Type type;
        bool rigidbody;
        bool isMoveFloorEntry;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThornCylinderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThornCylinderSpawner* pInstance);
        static void Clean(ObjThornCylinderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTimeStopBanVolumeSpawner {
        enum class Condition : int8_t {
            COND_EACHTIME = 0,
            COND_ONCE = 1,
        };

        enum class TimeStopType : int8_t {
            TimeStopReset = 0,
            TimeStopBan = 1,
        };

        Condition condition;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        TimeStopType timeStopType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTimeStopBanVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTimeStopBanVolumeSpawner* pInstance);
        static void Clean(ObjTimeStopBanVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTrapSpringSpawner {
        enum class Visual : int8_t {
            TrapSpring = 0,
            WaterTrapSpring = 1,
            Num = 2,
        };

        Visual visual;
        float CloseTime;
        float AnimSpeed;
        float firstSpeed;
        float keepVelocityDistance;
        float outOfControl;
        float dir;
        float dirY;
        bool bIsDsurf;
        bool bIsSmoothing;
        bool bIsSV;
        bool bIsClose;
        bool isEndOutControl;
        bool isVerticalJump;
        bool bIsGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guideViewOffset;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTrapSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTrapSpringSpawner* pInstance);
        static void Clean(ObjTrapSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVATParameterVolumeSpawner {
        enum class EnumObjVATParameterRefObjectPattern : int8_t {
            NOP = 0,
            PLAYER_TR = 1,
            PLAYER_T = 2,
            PLAYER_T_CAMERA_R = 3,
            OBJECT_TR = 4,
            OBJECT_T = 5,
        };

        enum class EnumObjVATParameterInterpolationType : int8_t {
            LINEAR = 0,
            SINE = 1,
        };

        float move_speed;
        float move_speed_amplitude;
        float move_speed_amplspeed;
        float radius;
        float radius_speed;
        float radius_speed_amplitude;
        float radius_speed_amplspeed;
        float falloff;
        float falloff_speed;
        float falloff_speed_amplitude;
        float falloff_speed_amplspeed;
        float intensity;
        float intensity_speed;
        float intensity_speed_amplitude;
        float intensity_speed_amplspeed;
        bool reverse;
        EnumObjVATParameterRefObjectPattern refObjectPattern;
        csl::ut::VariableString refObjectName;
        csl::math::Vector3 refObjectPositionOffset;
        EnumObjVATParameterInterpolationType interpolation_type;
        float interpolation_time;
        float distance_affected_by_player;
        float radius_affected_by_player;
        float falloff_affected_by_player;
        bool enable_lod_optimize;
        float lod_optimize_distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVATParameterVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVATParameterVolumeSpawner* pInstance);
        static void Clean(ObjVATParameterVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjVibrationVolumeSpawner {
        csl::ut::VariableString name;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjVibrationVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjVibrationVolumeSpawner* pInstance);
        static void Clean(ObjVibrationVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct WallBreakawayVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WallBreakawayVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WallBreakawayVolumeSpawner* pInstance);
        static void Clean(WallBreakawayVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWarpObjVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        hh::game::ObjectId target;
        hh::game::ObjectId transformLocator;
        bool is_use_disp;
        bool is_disp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWarpObjVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWarpObjVolumeSpawner* pInstance);
        static void Clean(ObjWarpObjVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWarpTriggerSpawner {
        enum class StatusType : int8_t {
            RESET = 0,
            CONTINUANCE = 1,
        };

        hh::game::ObjectId warpPoint;
        StatusType status;
        bool disableCameraReset;
        heur::rfl::PassPlaneTriggerSpawner passPlane;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWarpTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWarpTriggerSpawner* pInstance);
        static void Clean(ObjWarpTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct WaterFallVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WaterFallVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WaterFallVolumeSpawner* pInstance);
        static void Clean(WaterFallVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct WaterFlowVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        float rotateSpeed;
        float intakeSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WaterFlowVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WaterFlowVolumeSpawner* pInstance);
        static void Clean(WaterFlowVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWaterVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWaterVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWaterVolumeSpawner* pInstance);
        static void Clean(ObjWaterVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWideSpringSpawner {
        enum class Visual : int8_t {
            Normal = 0,
            Island = 1,
        };

        Visual visual;
        float firstSpeed;
        float outOfControl;
        float keepVelocityDistance;
        bool isEndOutControl;
        bool isWaitAppear;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWideSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWideSpringSpawner* pInstance);
        static void Clean(ObjWideSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBalloonSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        enum class Color : int8_t {
            COLOR_W9 = 0,
            COLOR_RED = 1,
            COLOR_BLUE = 2,
            COLOR_YELLOW = 3,
            COLOR_GREEN = 4,
            NUM_COLORS = 5,
        };

        enum class Dimension : int8_t {
            DIM_SV = 0,
            DIM_FV = 1,
        };

        Visual visual;
        Color balloonColor;
        Dimension dimension;
        float upSpeed;
        float speedMin;
        float speedMax;
        float respawnTime;
        float outOfControlTime;
        float keepVelocityTime;
        float ignoreSwingingTime;
        bool isDefaultPositionRespawn;
        bool eventDriven;
        bool isHorming;
        bool isWaitAppear;
        bool castShadow;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBalloonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBalloonSpawner* pInstance);
        static void Clean(ObjBalloonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCannonSpawner {
        enum class ModelType : int8_t {
            FV = 0,
            FV_BASELESS = 1,
            SV = 2,
            SV_BASELESS = 3,
            MODEL_NUM = 4,
        };

        enum class TargetType : int8_t {
            OBJECT = 0,
            COORDINATE = 1,
        };

        ModelType modelType;
        TargetType targetType;
        hh::game::ObjectId target;
        csl::math::Vector3 targetPos;
        float speed;
        float velocityRatio;
        float keepVelocity;
        bool isAutoShot;
        bool isMovableBarrel;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCannonSpawner* pInstance);
        static void Clean(ObjCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeSwitchSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        Condition condition;
        float lifetime;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeSwitchSpawner* pInstance);
        static void Clean(ObjChangeSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisData {
        float gravity;
        float lifeTime;
        float mass;
        float friction;
        float explosionScale;
        float impulseScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisData* pInstance);
        static void Clean(DebrisData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDestructibleWallSpawner {
        float Height;
        float Width;
        float Depth;
        csl::math::Vector3 scale;
        int32_t maxHp;
        int32_t spearAttackDamageValue;
        int32_t spinAttackDamageValue;
        int32_t enemyBlowAwayAttackDamageValue;
        int32_t dWingAttackDamageValue;
        heur::rfl::DebrisData debrisData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDestructibleWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDestructibleWallSpawner* pInstance);
        static void Clean(ObjDestructibleWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDownReelSpawner {
        uint32_t standLegNum;
        uint32_t standStickNum;
        float maxLength;
        float shotLength;
        float downSpeedMax;
        float upSpeedMax;
        float firstSpeed;
        float shotAngle;
        float outOfControl;
        bool isExtendOver;
        bool isOneTimeUp;
        bool eventDriven;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDownReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDownReelSpawner* pInstance);
        static void Clean(ObjDownReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDriftEndVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDriftEndVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDriftEndVolumeSpawner* pInstance);
        static void Clean(ObjDriftEndVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGoalTriggerSpawner {
        enum class GoalActionType : int8_t {
            GOALACTIONTYPE_STOP = 0,
            GOALACTIONTYPE_BRAKE = 1,
            GOALACTIONTYPE_DASH = 2,
        };

        float goalTime;
        GoalActionType actionType;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGoalTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGoalTriggerSpawner* pInstance);
        static void Clean(ObjGoalTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindThornSpawner {
        bool reverse;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindThornSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindThornSpawner* pInstance);
        static void Clean(ObjGrindThornSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGuideLaserFenceSpawner {
        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ONCE = 1,
            ACT_KEEP = 2,
            NUM_ACT_TYPE = 3,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        ActionType actionType;
        TimeType timeType;
        int8_t laserNum;
        float laserOffsetY;
        float laserLength;
        float laserHeight;
        float waitTime;
        float activeTime;
        float phase;
        bool isDamageFence;
        bool isEnablePoleCollision;
        bool isEventDriven;
        bool isSE;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGuideLaserFenceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGuideLaserFenceSpawner* pInstance);
        static void Clean(ObjGuideLaserFenceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjHanggliderSpawner {
        enum class MoveType : int8_t {
            MOVE_POINT = 0,
            MOVE_PATH = 1,
        };

        MoveType moveType;
        csl::math::Vector3 moveVector;
        float waitTime;
        float lifeTime;
        csl::ut::VariableString pathName;
        float finishDist;
        float moveSpeed;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjHanggliderSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjHanggliderSpawner* pInstance);
        static void Clean(ObjHanggliderSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct JumpSelectorLaunch {
        float firstSpeed;
        float outOfControl;
        float keepVelocityDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(JumpSelectorLaunch* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(JumpSelectorLaunch* pInstance);
        static void Clean(JumpSelectorLaunch* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpSelectorSpawner {
        enum class JumpSelectorType : uint8_t {
            JUMP = 0,
            ATTACK = 1,
            SELECT = 2,
        };

        JumpSelectorType type;
        float inputTime;
        heur::rfl::JumpSelectorLaunch launchJump;
        heur::rfl::JumpSelectorLaunch launchAttack;
        float outOfControlMiss;
        float collisionRadius;
        bool reusable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpSelectorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpSelectorSpawner* pInstance);
        static void Clean(ObjJumpSelectorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLaserFenceSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
            NUM_VIS_TYPE = 2,
        };

        enum class ActionType : int8_t {
            ACT_LOOP = 0,
            ACT_ONCE = 1,
            ACT_KEEP = 2,
            NUM_ACT_TYPE = 3,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        Visual visual;
        ActionType actionType;
        TimeType timeType;
        float laserLength;
        float waitTime;
        float activeTime;
        float phase;
        bool isEventDriven;
        bool isDedicatedCollisionDetection;
        bool isSE2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLaserFenceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLaserFenceSpawner* pInstance);
        static void Clean(ObjLaserFenceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMeteoriteSpawner {
        enum class SizeType : int8_t {
            SMALL = 0,
            MIDDLE = 1,
            LARGE = 2,
            SIZETYPE_NUM = 3,
        };

        enum class ShotDirType : int8_t {
            AUTO = 0,
            MANUAL = 1,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        ShotDirType shotDirType;
        float upSpeed;
        float speedMin;
        float speedMax;
        float respawnTime;
        float outOfControlTime;
        float keepVelocityTime;
        float ignoreSwingingTime;
        bool isHorming;
        bool isRespawn;
        heur::rfl::DebrisData debrisData;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool isSmoothMove;
        bool isReverse;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        float waitTime;
        float phase;
        float speed;
        uint8_t fragmentMin;
        uint8_t fragmentMax;
        float fragmentdeleteTime;
        float fragmentspeedMin;
        float fragmentspeedMax;
        float fragmentScaleMin;
        float fragmentScaleMax;
        bool isFragmentMovePlayerVelocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMeteoriteSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMeteoriteSpawner* pInstance);
        static void Clean(ObjMeteoriteSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNormalFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            SIZE_D = 3,
            SIZE_E = 4,
            SIZE_F = 5,
            SIZE_G = 6,
            SIZE_H = 7,
            SIZE_I = 8,
            SIZE_J = 9,
            NUM_SIZE_TYPE = 10,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        bool isFall;
        float waitFallTime;
        bool isSyncRot;
        bool isSmoothMove;
        bool isReverse;
        bool isPressDead;
        bool isWallLeft;
        bool isWallRight;
        bool isWallFront;
        bool isWallBack;
        float WallHeight;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        float waitTime;
        float phase;
        float speed;
        bool isTransparency;
        bool isCameraTransparency;
        bool isHideUntilEvent;
        bool playMoveSE;
        bool playStopSE;
        bool useChaosAppearAnim;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNormalFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNormalFloorSpawner* pInstance);
        static void Clean(ObjNormalFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjThroughFloorSpawner : heur::rfl::ObjNormalFloorSpawner {
        enum class Visual : int8_t {
            Floor2m = 0,
            Floor3m = 1,
            Floor5m = 2,
            NumVisuals = 3,
        };

        Visual visual;
        bool canGoThrough;
        bool doesRespawn;
        float respawnTime;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjThroughFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjThroughFloorSpawner* pInstance);
        static void Clean(ObjThroughFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGravityFloorSpawner : heur::rfl::ObjNormalFloorSpawner {
        enum class Visual : int8_t {
            Floor5m = 0,
            Floor10m = 1,
            Floor15m = 2,
            NumVisuals = 3,
        };

        Visual visual;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGravityFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGravityFloorSpawner* pInstance);
        static void Clean(ObjGravityFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceNormalFloorSpawner : heur::rfl::ObjNormalFloorSpawner {
        enum class ModelType : int8_t {
            WhiteSpace = 0,
            SpaceColonyARK = 1,
            RailCanyon = 2,
            KingdomValley = 3,
            City = 4,
            ChaosIsland = 5,
            RadicalHighway = 6,
            Eclipse1 = 7,
            Eclipse2 = 8,
            Eclipse3 = 9,
            WhiteSpaceStage2 = 10,
            Num = 11,
            Invalid = -1,
        };

        ModelType modelType;
        bool isWaitAppear;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceNormalFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceNormalFloorSpawner* pInstance);
        static void Clean(ObjWhiteSpaceNormalFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDistortionNormalFloorSpawner : heur::rfl::ObjNormalFloorSpawner {
        enum class Visual : int8_t {
            Floor5x5x2m = 0,
            Floor10x10x2m = 1,
            Floor5x5x5m = 2,
            NumVisuals = 3,
        };

        Visual visual;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDistortionNormalFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDistortionNormalFloorSpawner* pInstance);
        static void Clean(ObjDistortionNormalFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaFloorSpawner : heur::rfl::ObjNormalFloorSpawner {
        bool isAmoebaFront;
        bool isFrontWall;
        bool isFrontWallLeft;
        bool isFrontWallRight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaFloorSpawner* pInstance);
        static void Clean(ObjAmoebaFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOperationGuideVolumeSpawner {
        enum class GuideType : int32_t {
            SideStep = 0,
            Boarding = 1,
            Diving = 2,
            Drift = 3,
        };

        float lifetime;
        heur::rfl::VolumeTriggerSpawner volume;
        GuideType guideType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOperationGuideVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOperationGuideVolumeSpawner* pInstance);
        static void Clean(ObjOperationGuideVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPoleSpawner {
        enum class Type : int8_t {
            FV = 0,
            SV = 1,
        };

        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Type type;
        Visual visual;
        bool isHorming;
        bool usedPillar;
        uint32_t sideBarNum;
        uint32_t pillarNum;
        float distanceOffset;
        csl::math::Vector3 colloffset;
        csl::math::Vector3 collisionSize;
        csl::math::Vector3 successShotVelocity;
        csl::math::Vector3 failShotVelocity;
        float outOfControlTime;
        heur::rfl::ActionNotification actions[3];
        bool isFixedInjection;
        bool isEndOutControl;
        bool isWaitAppear;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPoleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPoleSpawner* pInstance);
        static void Clean(ObjPoleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRingGeneratorSpawner {
        float interval;
        heur::rfl::PathMovement pathMovement;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRingGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRingGeneratorSpawner* pInstance);
        static void Clean(ObjRingGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRotateThornBallAxisParam {
        float radius;
        uint32_t ballNum;
        float ballInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRotateThornBallAxisParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRotateThornBallAxisParam* pInstance);
        static void Clean(ObjRotateThornBallAxisParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRotateThornBallSpawner {
        enum class RotateType : int8_t {
            TYPE_RIGHT = 0,
            TYPE_LEFT = 1,
        };

        enum class StartType : int8_t {
            START_WAIT = 0,
            START_ROTATE = 1,
        };

        enum class PlaceType : int8_t {
            ON_GROUND = 0,
            IN_AIR = 1,
            NUM_PLACES = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        RotateType rotateType;
        float angularVelocity;
        StartType startType;
        PlaceType placeType;
        TimeType timeType;
        bool eventDriven;
        bool showCenterObj;
        uint32_t axisNum;
        heur::rfl::ObjRotateThornBallAxisParam axisParam[4];
        bool disableSolidCollision;
        bool playHeadSE;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRotateThornBallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRotateThornBallSpawner* pInstance);
        static void Clean(ObjRotateThornBallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSideReelSpawner {
        bool visiableLegModel;
        uint32_t standLegNum;
        float length;
        float upSpeedMax;
        float firstSpeed;
        float shotAngle;
        float outOfControl;
        bool isOneTimeUp;
        bool eventDriven;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSideReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSideReelSpawner* pInstance);
        static void Clean(ObjSideReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSideViewPathVolumeSpawner {
        csl::ut::VariableString pathName;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSideViewPathVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSideViewPathVolumeSpawner* pInstance);
        static void Clean(ObjSideViewPathVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSpringBoardSpawner {
        enum class Visual : int8_t {
            Normal = 0,
            Sky = 1,
        };

        Visual visual;
        float firstSpeed;
        float outOfControl;
        float keepVelocityDistance;
        bool isEventOn;
        bool isHorizon;
        bool isVisible;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSpringBoardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSpringBoardSpawner* pInstance);
        static void Clean(ObjSpringBoardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct SwingReelImpulse {
        float addSpeed;
        float outOfControl;
        float motionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwingReelImpulse* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwingReelImpulse* pInstance);
        static void Clean(SwingReelImpulse* pInstance);
    };
}

namespace heur::rfl {
    struct SwingReelPath {
        hh::game::ObjectId targetObj;
        csl::math::Vector3 targetOffset;
        float outStrength;
        float inStrength;
        float outUpPower;
        float inElev;
        float pathRoll;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwingReelPath* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwingReelPath* pInstance);
        static void Clean(SwingReelPath* pInstance);
    };
}

namespace heur::rfl {
    struct SwingReelVertical {
        float moveRange;
        float launchAngleSum;
        float period;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwingReelVertical* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwingReelVertical* pInstance);
        static void Clean(SwingReelVertical* pInstance);
    };
}

namespace heur::rfl {
    struct SwingReelHorizontal {
        enum class RotateDirection : int8_t {
            Left = 0,
            Right = 1,
        };

        RotateDirection rotateDirection;
        float ropeTiltMax;
        float ropeTiltTime;
        float launchAngleSum;
        float period;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SwingReelHorizontal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SwingReelHorizontal* pInstance);
        static void Clean(SwingReelHorizontal* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwingReelSpawner {
        enum class SwingReelType : int8_t {
            TypeVertical = 0,
            TypeHorizontal = 1,
        };

        SwingReelType type;
        float ropeLength;
        bool eventDriven;
        float handleDownTime;
        heur::rfl::SwingReelImpulse impulseParam;
        heur::rfl::SwingReelPath pathParam;
        heur::rfl::SwingReelVertical vertParam;
        heur::rfl::SwingReelHorizontal horzParam;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwingReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwingReelSpawner* pInstance);
        static void Clean(ObjSwingReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwitchUsualSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_TIMER = 1,
            COND_ON_STAY = 2,
        };

        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Condition condition;
        Visual visual;
        float lifetime;
        bool usedRigidCol;
        bool eventDriven;
        bool leaveProofRemoved;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwitchUsualSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwitchUsualSpawner* pInstance);
        static void Clean(ObjSwitchUsualSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTimeStartVolumeSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        Condition condition;
        float lifetime;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTimeStartVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTimeStartVolumeSpawner* pInstance);
        static void Clean(ObjTimeStartVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTimeStopWatchVolumeSpawner {
        enum class Condition : int8_t {
            COND_ON_TRIGGER = 0,
            COND_PULSE = 1,
            COND_TIMER_ONCE = 2,
            COND_TIMER = 3,
            COND_ON_STAY = 4,
        };

        Condition condition;
        float lifetime;
        bool eventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTimeStopWatchVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTimeStopWatchVolumeSpawner* pInstance);
        static void Clean(ObjTimeStopWatchVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUpReelSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        float radius;
        float solidRadius;
        float length;
        float upSpeedMax;
        float firstSpeed;
        float outOfControl;
        bool isOneTimeUp;
        bool eventDriven;
        bool isEndOutControl;
        bool isWaitAppear;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUpReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUpReelSpawner* pInstance);
        static void Clean(ObjUpReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceUpReelSpawner : heur::rfl::ObjUpReelSpawner {
        int32_t no;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceUpReelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceUpReelSpawner* pInstance);
        static void Clean(ObjWhiteSpaceUpReelSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWallJumpBlockSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        float width;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWallJumpBlockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWallJumpBlockSpawner* pInstance);
        static void Clean(ObjWallJumpBlockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeesGeneratorSpawner {
        enum class EventDrivenType : uint8_t {
            WaitAll = 0,
            Wait = 1,
            NoWait = 2,
        };

        enum class HomingDirection : uint8_t {
            Forward = 0,
            Reverse = 1,
        };

        EventDrivenType eventType;
        csl::ut::VariableString pathName;
        uint32_t numBees;
        uint32_t numFirstBees;
        float appearSpan;
        float moveSpeed;
        hh::game::ObjectId startPosObj;
        hh::game::ObjectId endPosObj;
        bool repat;
        uint8_t pad1[3];
        float repeatSpanTime;
        bool homingReBound;
        HomingDirection homingDir;
        uint8_t pad2[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeesGeneratorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeesGeneratorSpawner* pInstance);
        static void Clean(EnemyBeesGeneratorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BeetleAttackParam {
        float searchDistance;
        float searchViewAngle;
        float bulletSpeed;
        float prepareTime;
        float attackInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeetleAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeetleAttackParam* pInstance);
        static void Clean(BeetleAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct BeetleBarrierParam {
        enum class BarrierDeploymentType : int8_t {
            Always = 0,
            Interval = 1,
        };

        float barrierInterval;
        float barrierTime;
        float firstWaitTime;
        float brakeTime;
        BarrierDeploymentType deploymentType;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeetleBarrierParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeetleBarrierParam* pInstance);
        static void Clean(BeetleBarrierParam* pInstance);
    };
}

namespace heur::rfl {
    struct BeetleMoveParam {
        enum class BeetleMoveType : int8_t {
            FIXED = 0,
            TWO_POINT = 1,
            PATH = 2,
        };

        BeetleMoveType moveType;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        float moveSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeetleMoveParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeetleMoveParam* pInstance);
        static void Clean(BeetleMoveParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetleSpawner {
        enum class BeetleType : int8_t {
            MONOBEETLE = 0,
            GUNBEETLE = 1,
            SPARKBEETLE = 2,
        };

        enum class FixedDirType : int8_t {
            DIR_SET = 0,
            DIR_PLAYER = 1,
        };

        enum class BeetleSpawnType : int8_t {
            Normal = 0,
            DistSpace = 1,
        };

        BeetleType beetleType;
        bool isRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        bool eventDriven;
        bool playAppearEffectOnRangeIn;
        bool isTransparency;
        heur::rfl::BeetleAttackParam attackParam;
        heur::rfl::BeetleBarrierParam barrierParam;
        heur::rfl::BeetleMoveParam moveParam;
        FixedDirType dirType;
        bool fixWarpAngle;
        float warpAngle;
        BeetleSpawnType spawnType;
        bool enableBlock;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetleSpawner* pInstance);
        static void Clean(EnemyBeetleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ShapeCone {
        float SearchDistance;
        float SearchAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ShapeCone* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ShapeCone* pInstance);
        static void Clean(ShapeCone* pInstance);
    };
}

namespace heur::rfl {
    struct ShapeCuboid {
        csl::math::Vector3 size;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ShapeCuboid* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ShapeCuboid* pInstance);
        static void Clean(ShapeCuboid* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonFCSpawner {
        enum class ViewShape : uint32_t {
            CONE = 0,
            CUBOID = 1,
        };

        float SerchLength;
        float SerchMoveSpeed;
        ViewShape viewShape;
        heur::rfl::ShapeCone cone;
        heur::rfl::ShapeCuboid cuboid;
        bool IsMove;
        bool CheckShielding;
        bool AttackConst;
        float AttackConstAngle;
        float StraightDistance;
        float RespawnTime;
        csl::math::Vector3 RespawnOffsetPos;
        csl::ut::VariableString RespawnPathName;
        bool isFV;
        bool isEscape;
        bool eventDriven;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonFCSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonFCSpawner* pInstance);
        static void Clean(EnemyBeetonFCSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflyCommonConfig {
        float searchDistance;
        float rotateSpeed;
        float foundAttackStartTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflyCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflyCommonConfig* pInstance);
        static void Clean(EnemyChaosflyCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct TentacleAttackParam {
        float attackMaxDistance;
        float attackMinDistance;
        float rotateSpeed;
        float rotateChaseSpeed;
        float attackMaxDegree;
        float waitTime;
        float speed;
        float intervalTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TentacleAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TentacleAttackParam* pInstance);
        static void Clean(TentacleAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct BeamAttackParam {
        float attackMaxDistance;
        float attackMinDistance;
        float rotateSpeed;
        float waitTime;
        float intervalTime;
        float maxDegree;
        float speed;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BeamAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BeamAttackParam* pInstance);
        static void Clean(BeamAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflyNormalConfig {
        heur::rfl::TentacleAttackParam tentacleParam;
        heur::rfl::BeamAttackParam beamParam;
        int32_t tentacleAttackRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflyNormalConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflyNormalConfig* pInstance);
        static void Clean(EnemyChaosflyNormalConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBlockCollisionParam {
        float collisionRadius;
        float collisionHeight;
        csl::math::Vector3 collisionPosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBlockCollisionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBlockCollisionParam* pInstance);
        static void Clean(EnemyBlockCollisionParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCollisionParam {
        heur::rfl::EnemyBlockCollisionParam blockCollisionParam;
        float damageCollisionRadiusOffset;
        float damageCollisionHeightOffset;
        csl::math::Vector3 damageCollisionPosOffset;
        float touchCollisionRadiusOffset;
        float touchCollisionHeightOffset;
        csl::math::Vector3 touchCollisionPosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCollisionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCollisionParam* pInstance);
        static void Clean(EnemyCollisionParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyComboParam {
        float warpRadius;
        float warpHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyComboParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyComboParam* pInstance);
        static void Clean(EnemyComboParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflycellCommonConfig {
        int32_t addLightGaugeNum;
        float spawnSpeed;
        float moveSpeed;
        float jumpAttackSpeed;
        float jumpAttackheight;
        float attackStartTime;
        float attackDistance;
        float attackMaxDegree;
        float rotSpeed;
        float moveRotSpeed;
        float rotateSpeedMin;
        float rotateSpeedMax;
        float rotateSpeedMaxSpeedMin;
        float rotateSpeedMinSpeedMax;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflycellCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflycellCommonConfig* pInstance);
        static void Clean(EnemyChaosflycellCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflyDivisionConfig {
        float distance;
        float DivisionMax;
        heur::rfl::EnemyChaosflycellCommonConfig cellParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflyDivisionConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflyDivisionConfig* pInstance);
        static void Clean(EnemyChaosflyDivisionConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflySpawner {
        enum class ChaosflyType : int8_t {
            Normal = 0,
            Division = 1,
            NumMaxType = 2,
        };

        enum class ChaosflyNormalAttackType : int8_t {
            All = 0,
            TentacleOnly = 1,
            BeamOnly = 2,
            NumMaxType = 3,
        };

        ChaosflyType chaosflyType;
        ChaosflyNormalAttackType chaosflyNormalAttackType;
        bool isRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        heur::rfl::EnemyChaosflyCommonConfig commonParam;
        heur::rfl::EnemyChaosflyNormalConfig normalParam;
        heur::rfl::EnemyChaosflyDivisionConfig divisionParam;
        bool fixWarpAngle;
        float warpAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflySpawner* pInstance);
        static void Clean(EnemyChaosflySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflycellSpawner {
        heur::rfl::EnemyChaosflycellCommonConfig commonParam;
        bool fixWarpAngle;
        float warpAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflycellSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflycellSpawner* pInstance);
        static void Clean(EnemyChaosflycellSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarCommonConfig {
        float searchDistance;
        float rotateSpeed;
        float foundAttackStartTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarCommonConfig* pInstance);
        static void Clean(EnemyChaospillarCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarNormalConfig {
        heur::rfl::TentacleAttackParam tentacleParam;
        heur::rfl::BeamAttackParam beamParam;
        int32_t tentacleAttackRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarNormalConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarNormalConfig* pInstance);
        static void Clean(EnemyChaospillarNormalConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarGuardConfig {
        float distance;
        heur::rfl::TentacleAttackParam tentacleParam;
        float stunTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarGuardConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarGuardConfig* pInstance);
        static void Clean(EnemyChaospillarGuardConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarSpawner {
        enum class ChaospillarType : int8_t {
            Normal = 0,
            Guard = 1,
            NumMaxType = 2,
        };

        enum class ChaospillarNormalAttackType : int8_t {
            All = 0,
            TentacleOnly = 1,
            BeamOnly = 2,
            NumMaxType = 3,
        };

        ChaospillarType chaospillarType;
        ChaospillarNormalAttackType chaospillarNormalAttackType;
        bool isRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        heur::rfl::EnemyChaospillarCommonConfig commonParam;
        heur::rfl::EnemyChaospillarNormalConfig normalParam;
        heur::rfl::EnemyChaospillarGuardConfig guardParam;
        bool fixWarpAngle;
        float warpAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarSpawner* pInstance);
        static void Clean(EnemyChaospillarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ReflectorIndividualParam {
        enum class ReflectorMoveType : int8_t {
            Straight = 0,
            LeanLeft = 1,
            LeanRight = 2,
            ThreeWay = 3,
        };

        ReflectorMoveType moveType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ReflectorIndividualParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ReflectorIndividualParam* pInstance);
        static void Clean(ReflectorIndividualParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCometSpawner {
        enum class WarpAttackOffsetType : int8_t {
            None = 0,
            Global = 1,
            Local = 2,
            Camera = 3,
        };

        int32_t no;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        float rotateSpeed;
        float barrierStartDistance;
        csl::math::Vector3 barrierGuideRange;
        float startReflectorWaitTime;
        float shootReflectorLifeTime;
        float shootReflectorInterval;
        uint32_t shootReflectorIndividualParamNum;
        heur::rfl::ReflectorIndividualParam shootReflectorIndividualParams[9];
        float dBlowAttackAimAngleLimitH;
        float dBlowAttackAimAngleLimitV;
        float damageVelocityScaleRush;
        float damageVelocityScaleSlamDownward;
        float damageKnockbackLimitDistance;
        float killBelowPositionY;
        float respawnTime;
        int32_t addLightGaugeNum;
        WarpAttackOffsetType warpAttackOffsetType;
        bool sideView;
        bool isTransparency;
        bool eventDriven;
        bool eventDrivenAfterRespawn;
        bool performUniqueActions;
        bool disableCharacterControlWhenNotBattle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCometSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCometSpawner* pInstance);
        static void Clean(EnemyCometSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoSpawner {
        enum class WarpAttackOffsetType : int8_t {
            None = 0,
            Global = 1,
            Local = 2,
            Camera = 3,
        };

        int32_t no;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        csl::ut::VariableString pathName;
        float endMoveRestDistance;
        float damageVelocityScaleRush;
        float damageVelocityScaleSlamDownward;
        float projectileStartDistance;
        float killBelowPositionY;
        float respawnTime;
        int32_t addLightGaugeNum;
        WarpAttackOffsetType warpAttackOffsetType;
        WarpAttackOffsetType warpAttackOffsetTypeVehicle;
        bool isTransparency;
        bool eventDriven;
        csl::ut::MoveArray<hh::game::ObjectId> tornadoes;
        csl::ut::MoveArray<hh::game::ObjectId> objectsWhenVehicleDead;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoSpawner* pInstance);
        static void Clean(EnemyCoreMachoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoTornadoSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            NUM_SIZE_TYPE = 1,
        };

        enum class VisualType : int8_t {
            VISUAL_A = 0,
            VISUAL_B = 1,
            NUM_VISUAL_TYPE = 2,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        VisualType visualType;
        float windRadiusOffset;
        float windSpeedMin;
        float windSpeedMax;
        float windDistanceMin;
        float windDistanceMax;
        float blowingPower;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        bool isSyncRot;
        float waitTime;
        float phase;
        float speed;
        bool isVisibleOmen;
        float visibleStartRange;
        csl::ut::MoveArray<hh::game::ObjectId> floors;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoTornadoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoTornadoSpawner* pInstance);
        static void Clean(EnemyCoreMachoTornadoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoTornadoVolumeSpawner {
        csl::math::Vector3 windPositionOffset;
        float windSpeedMin;
        float windSpeedMax;
        float windDistanceMin;
        float windDistanceMax;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoTornadoVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoTornadoVolumeSpawner* pInstance);
        static void Clean(EnemyCoreMachoTornadoVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        StateType state;
        ActionType action;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        float projectileStartDistance;
        bool isEventDriven;
        heur::rfl::VolumeTriggerSpawner volume;
        hh::game::ObjectId subject;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoVolumeSpawner* pInstance);
        static void Clean(EnemyCoreMachoVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ConversationInfo {
        csl::ut::VariableString labelName;
        float displayTime;
        float delayTime;
        bool isSondOnly;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ConversationInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ConversationInfo* pInstance);
        static void Clean(ConversationInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDoomsEyeSpawner {
        enum class StartStateType : int8_t {
            MOVE = 0,
            MOVE_RC = 1,
            MOVE_CT = 2,
            COMBAT = 3,
            StartStateType_Num = 4,
        };

        csl::ut::VariableString pathName;
        bool isKillEndMove;
        bool isEventDriven;
        bool isHomingAttack;
        bool isAuraEffect;
        float homingAttackDistanceOffset;
        float speed;
        int32_t maxHp;
        int32_t barrierHp;
        int32_t damageHA;
        float stunTime;
        bool useDebugSpeed;
        float modelScale;
        StartStateType startStateType;
        float keepDistanceMinWhileMoving;
        float keepDistanceMaxWhileMoving;
        float movementRestartDistance;
        int32_t ditem_no;
        heur::rfl::ActionNotification actions[5];
        heur::rfl::ConversationInfo conversations[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDoomsEyeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDoomsEyeSpawner* pInstance);
        static void Clean(EnemyDoomsEyeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDoomsEyeFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            SIZE_D = 3,
            SIZE_E = 4,
            SIZE_F = 5,
            SIZE_G = 6,
            SIZE_H = 7,
            SIZE_I = 8,
            SIZE_J = 9,
            SIZE_K = 10,
            SIZE_L = 11,
            SIZE_M = 12,
            NUM_SIZE_TYPE = 13,
        };

        enum class ConditionType : int8_t {
            CONDITION_NORMAL = 0,
            CONDITION_DAMAGE = 1,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        ConditionType initialCondition;
        ConditionType eventCondition;
        bool enableSolid;
        bool eventDriven;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        csl::ut::VariableString pathChangeName;
        float pathChangeSpeed;
        hh::game::ObjectId pathChangeEffect;
        bool isSyncRot;
        bool isMovable;
        float waitTime;
        float phase;
        float speed;
        float rotSpeed;
        float rotSpeedEvent;
        csl::math::Vector3 rotAxis;
        csl::math::Vector3 attackColliderScale;
        bool se_flags[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDoomsEyeFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDoomsEyeFloorSpawner* pInstance);
        static void Clean(EnemyDoomsEyeFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDoomsEyeFloorEffectObjectSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDoomsEyeFloorEffectObjectSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDoomsEyeFloorEffectObjectSpawner* pInstance);
        static void Clean(EnemyDoomsEyeFloorEffectObjectSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDoomsEyeRoadSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            SIZE_D = 3,
            SIZE_E = 4,
            SIZE_F = 5,
            SIZE_G = 6,
            NUM_SIZE_TYPE = 7,
        };

        enum class ConditionType : int8_t {
            CONDITION_NORMAL = 0,
            CONDITION_DAMAGE = 1,
        };

        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType sizeType;
        ConditionType initialCondition;
        ConditionType eventCondition;
        bool enableSolid;
        bool usePhysicsMeshForSolid;
        bool eventDriven;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        bool isSyncRot;
        float waitTime;
        float phase;
        float speed;
        csl::math::Vector3 attackColliderScale;
        bool se_flags[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDoomsEyeRoadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDoomsEyeRoadSpawner* pInstance);
        static void Clean(EnemyDoomsEyeRoadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDoomsEyeVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        enum class AnimationType : int8_t {
            ANIMATION_NONE = -1,
            ANIMATION_REACTION_01 = 0,
            ANIMATION_REACTION_02 = 1,
            ANIMATION_REACTION_03 = 2,
            ANIMATION_REACTION_04 = 3,
            ANIMATION_REACTION_05 = 4,
            ANIMATION_NUM = 5,
        };

        enum class TentacleType : int8_t {
            TT_None = -1,
            TT_Two = 0,
            TT_Four = 1,
            TT_Six = 2,
            TT_Num = 3,
        };

        StateType state;
        ActionType action;
        AnimationType animation;
        TentacleType requestDamageObject;
        float damageObjectLength;
        float damageObjectRotateSpeed;
        float damageObjectStunTime;
        float maxSpeed;
        float accelSpeed;
        csl::math::Vector3 damageObjectGuideRange;
        csl::math::Vector3 damageObjectGuidePositionOffset;
        bool damageObjectGuideAction;
        bool suspendMovement;
        bool useHomingAttack;
        bool isEventDriven;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDoomsEyeVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDoomsEyeVolumeSpawner* pInstance);
        static void Clean(EnemyDoomsEyeVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlapperSpawner {
        enum class ActionType : int8_t {
            Normal = 0,
            Needle = 1,
            Thunder = 2,
            Cannon = 3,
            AT_Num = 4,
        };

        enum class MoveType : int8_t {
            Fixed = 0,
            Offset = 1,
            Path = 2,
        };

        enum class OrientationForMoveTypeFix : int8_t {
            Set = 0,
            Player = 1,
        };

        enum class UpdateTimeTypeForActionTypeNeedle : int8_t {
            Global = 0,
            Local = 1,
        };

        int32_t no;
        ActionType actionType;
        MoveType moveType;
        OrientationForMoveTypeFix orientationForMoveTypeFix;
        UpdateTimeTypeForActionTypeNeedle updateTimeType;
        csl::math::Vector3 moveOffset;
        csl::ut::VariableString pathName;
        float moveSpeed;
        float searchDistance;
        float searchAngle;
        float attackCannonSpeed;
        float attackCannonReadyTime;
        float attackCannonCycleTime;
        float attackCannonLifeTime;
        float attackCannonRadius;
        float attackCannonHeight;
        float attackNeedleOffTime;
        float attackNeedleOnTime;
        float attackNeedlePhaseTime;
        float respawnTime;
        int32_t addLightGaugeNum;
        bool fixWarpAngle;
        float warpAngle;
        bool appearEffect;
        bool eventDriven;
        bool isTransparency;
        bool forceThunderToBeTreatedAsGrounded;
        bool bIsGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guideViewOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlapperSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlapperSpawner* pInstance);
        static void Clean(EnemyEggFlapperSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlyerSpawner {
        bool doesRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        float searchDistance;
        float searchAngle;
        float rotationSpeed;
        float bulletSpeed;
        int32_t bulletCount;
        float bulletInterval;
        float bulletLimitDistance;
        float prepareTime;
        float rechargeTime;
        float lostSightTime;
        bool fixWarpAngle;
        float warpAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlyerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlyerSpawner* pInstance);
        static void Clean(EnemyEggFlyerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGuardianSpawner {
        enum class AppearType : int8_t {
            Stand = 0,
            Fall = 1,
        };

        int32_t no;
        float eyesightDistance;
        float eyesightLostDelayTime;
        float respawnTime;
        int32_t addLightGaugeNum;
        bool isTransparency;
        bool fixWarpAngle;
        float warpAngle;
        AppearType appearType;
        float fallHeight;
        float fallSpeed;
        bool appearEffect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGuardianSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGuardianSpawner* pInstance);
        static void Clean(EnemyEggGuardianSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EggGunnerAppearParam {
        enum class AppearType : int8_t {
            APPEARTYPE_IDLE = 0,
            APPEARTYPE_FALL = 1,
            APPEARTYPE_POINT = 2,
            APPEARTYPE_PATH = 3,
        };

        bool eventDriven;
        bool playAppearEffect;
        AppearType appearType;
        bool appearAir;
        float fallHeight;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        float moveSpeed;
        bool globalUpdateTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EggGunnerAppearParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EggGunnerAppearParam* pInstance);
        static void Clean(EggGunnerAppearParam* pInstance);
    };
}

namespace heur::rfl {
    struct EggGunnerRocketAttackParam {
        enum class RocketGuideStrength : int8_t {
            LOW = 0,
            MIDDLE = 1,
            HIGH = 2,
        };

        float attackMaxDistance;
        float attackMinDistance;
        float waitTime;
        float intervalTime;
        float maxDegree;
        float rapidFireIntervalTime;
        float num;
        RocketGuideStrength guideStrength;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EggGunnerRocketAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EggGunnerRocketAttackParam* pInstance);
        static void Clean(EggGunnerRocketAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct EggGunnerVulcanAttackParam {
        float attackMaxDistance;
        float attackMinDistance;
        float waitTime;
        float intervalTime;
        float maxDegree;
        float speed;
        float rapidFireIntervalTime;
        float num;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EggGunnerVulcanAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EggGunnerVulcanAttackParam* pInstance);
        static void Clean(EggGunnerVulcanAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGunnerSpawner {
        enum class ModelType : int8_t {
            GUNNER = 0,
            STINGER = 1,
            MT_Num = 2,
        };

        ModelType modelType;
        bool isRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        heur::rfl::EggGunnerAppearParam appearParam;
        heur::rfl::PathMovement moveParam;
        float searchDistance;
        float searchDegree;
        heur::rfl::EggGunnerRocketAttackParam rocketParam;
        heur::rfl::EggGunnerVulcanAttackParam vulcanParam;
        bool fixWarpAngle;
        float warpAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGunnerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGunnerSpawner* pInstance);
        static void Clean(EnemyEggGunnerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MeleeAttackParam {
        float attackSpeed;
        float attackTime;
        float attackInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MeleeAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MeleeAttackParam* pInstance);
        static void Clean(MeleeAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct MovementParams {
        enum class MovementType : int8_t {
            FIXED = 0,
            TWOPOINT = 1,
            PATH = 2,
        };

        MovementType moveType;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        float moveSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MovementParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MovementParams* pInstance);
        static void Clean(MovementParams* pInstance);
    };
}

namespace heur::rfl {
    struct CannonAttackParam {
        float bulletSpeed;
        float prepareTime;
        float attackInterval;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CannonAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CannonAttackParam* pInstance);
        static void Clean(CannonAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggPawnSpawner {
        enum class EggPawnType : int8_t {
            NORMAL = 0,
            LANCE = 1,
            CANNON = 2,
            TYPE_NUM = 3,
        };

        enum class AppearType : int8_t {
            STAND = 0,
            FALL = 1,
        };

        enum class SearchRangeShape : int8_t {
            Sphere = 0,
            HalfSphere_Y_UP = 1,
        };

        EggPawnType pawnType;
        bool eventDriven;
        AppearType appearType;
        float fallHeight;
        float fallSpeed;
        bool eventAttack;
        bool shouldKeepAttack;
        heur::rfl::MeleeAttackParam eventAttackParam;
        bool doesSleep;
        bool doesRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        float searchDistance;
        float searchAngle;
        SearchRangeShape searchRangeShape;
        heur::rfl::MovementParams movementParams;
        heur::rfl::MeleeAttackParam meleeAttackParam;
        heur::rfl::CannonAttackParam canonAttackParam;
        bool fixWarpAngle;
        float warpAngle;
        float rotationSpeed;
        float prepareAttackTime;
        float lostSightTime;
        bool noSearchOnReturnPos;
        bool isTransparency;
        bool isSV;
        bool enableSafeWallKnockback;
        bool isGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guideViewOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggPawnSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggPawnSpawner* pInstance);
        static void Clean(EnemyEggPawnSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnFcSpawner {
        enum class ShotType : int8_t {
            SHOT_BOTH_HANDS = 0,
            SHOT_ONE_HAND = 1,
        };

        ShotType shotType;
        float approachLimit;
        float serachDistance;
        float serachAngle;
        float moveDistance;
        bool shotCoolDown;
        bool attackConst;
        float attackConstAngle;
        bool isFV;
        bool eventDriven;
        bool isGravity;
        bool isFallStart;
        bool isTreadGrass;
        bool updateMaterial;
        bool isStatic;
        float toSVPathDistance;
        bool isRespawn;
        bool fixWarpAngle;
        float warpAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnFcSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnFcSpawner* pInstance);
        static void Clean(EnemyEggpawnFcSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggTankSpawner {
        enum class MoveType : int32_t {
            MOVE_NONE = 0,
            MOVE_FORWARD = 1,
            MOVE_BACK = 2,
        };

        float serachDistance;
        MoveType moveType;
        float moveDistance;
        float moveSpeed;
        bool isRespawn;
        bool eventDriven;
        bool isFV;
        float bulletSpeed;
        float bulletMaxFlyingDistance;
        uint32_t bulletContinuousShellingNum;
        float bulletShellingInterval;
        float bulletCoolDownTime;
        float bulletFiringAngle;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggTankSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggTankSpawner* pInstance);
        static void Clean(EnemyEggTankSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ClonesInfo {
        csl::ut::MoveArray<hh::game::ObjectId> cloneLocators;
        hh::game::ObjectId warpLocator;
        bool hide;
        bool downWhenClonesAreBroken;
        bool dieWhenBlowUpCloning;
        bool inputGuide;
        float inputGuideHAPosYOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ClonesInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ClonesInfo* pInstance);
        static void Clean(ClonesInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyFlashSpawner {
        enum class WarpAttackOffsetType : int8_t {
            None = 0,
            Global = 1,
            Local = 2,
            Camera = 3,
        };

        int32_t no;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        float readyCloneWaitTime;
        heur::rfl::ClonesInfo clonesInfo[4];
        float cloneLifeTimeFromBody;
        float damageVelocityScaleRush;
        float damageVelocityScaleSlamDownward;
        float killBelowPositionY;
        float respawnTime;
        int32_t addLightGaugeNum;
        WarpAttackOffsetType warpAttackOffsetType;
        bool isTransparency;
        csl::math::Vector3 warpOffsetForFV;
        csl::math::Vector3 warpOffsetForFVWhileBlownUp;
        csl::math::Vector3 warpOffsetForFVWhileBlownAway;
        float warpAngleForFV;
        float warpAngleForFVWhileBlownUp;
        float warpAngleForFVWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        bool dieWhenBlowUpBeforeCloning;
        bool inputGuideHA;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyFlashSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyFlashSpawner* pInstance);
        static void Clean(EnemyFlashSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyFlashCloneLocatorSpawner {
        enum class MotionPattern : int32_t {
            MT_AppearAttack = 0,
            MT_AppearAttackAir = 1,
            MT_AppearAttackAir2 = 2,
            MT_QuickAttack = 3,
        };

        hh::game::ObjectId targetLocator;
        float speed;
        float appearDelayTime;
        float appearTime;
        float limitDirAngle;
        float lifeTime;
        MotionPattern motionPattern;
        bool appearOnly1stTime;
        bool repeat;
        bool gravityAndGrounded;
        bool disappearWhenHitLand;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyFlashCloneLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyFlashCloneLocatorSpawner* pInstance);
        static void Clean(EnemyFlashCloneLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GunHunterAttackParam {
        float searchDistance;
        float attackDistance;
        float bulletSpeed;
        float attackChargeTime;
        float attackInterval;
        bool playSeekAnimation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GunHunterAttackParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GunHunterAttackParam* pInstance);
        static void Clean(GunHunterAttackParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyGunHunterSpawner {
        enum class AppearType : int8_t {
            APPEARTYPE_STAND = 0,
            APPEARTYPE_CROUCH = 1,
            APPEARTYPE_FALL = 2,
            APPEARTYPE_DOOMEYE = 3,
        };

        bool eventDriven;
        bool playAppearEffect;
        bool playAppearEffectOnRangeIn;
        AppearType appearType;
        float fallHeight;
        float fallSpeed;
        float upHeight;
        float upSpeed;
        float doomeyeAnimePlaySpeed;
        bool doesRespawn;
        float respawnTime;
        int32_t addLightGaugeNum;
        bool fixWarpAngle;
        float warpAngle;
        heur::rfl::GunHunterAttackParam attackParam;
        bool isTransparency;
        bool isGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guideViewOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyGunHunterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyGunHunterSpawner* pInstance);
        static void Clean(EnemyGunHunterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManSpawner {
        enum class Type : int8_t {
            Normal = 0,
            Red = 1,
        };

        enum class SearchShape : int8_t {
            Sphere = 0,
            Box = 1,
        };

        enum class RespawnType : int8_t {
            Egg = 0,
            Stand = 1,
            Fall = 2,
        };

        Type type;
        csl::ut::MoveArray<hh::game::ObjectId> territories;
        bool enableEffect;
        bool isEgg;
        SearchShape searchShape;
        csl::math::Vector3 searchRange;
        bool isSonicSet;
        csl::math::Vector3 moveOffset;
        float moveWaitTime;
        float actionRate[6];
        float actionCoolTime[6];
        float straightWaveDistance;
        bool eventDriven;
        int32_t addLightGaugeNum;
        bool isRespawn;
        RespawnType respawnType;
        float respawnTime;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManSpawner* pInstance);
        static void Clean(EnemyManSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyMotoraSpawner {
        float SerachDistance;
        float Speed;
        float MaxMoveDistance;
        bool IsEventOn;
        bool IsFV;
        bool IsFallStart;
        bool isTreadGrass;
        bool updateMaterial;
        bool isRespawn;
        bool isTransparency;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyMotoraSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyMotoraSpawner* pInstance);
        static void Clean(EnemyMotoraSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRhinolinerActionTriggerSpawner {
        bool eventDriven;
        csl::math::Vector3 size;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRhinolinerActionTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRhinolinerActionTriggerSpawner* pInstance);
        static void Clean(ObjRhinolinerActionTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AccelerationParametor {
        float speed;
        float accel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AccelerationParametor* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AccelerationParametor* pInstance);
        static void Clean(AccelerationParametor* pInstance);
    };
}

namespace heur::rfl {
    struct PathCreateParametor {
        enum class TargetType : int8_t {
            ToOffset = 0,
            ToObject = 1,
        };

        TargetType targetType;
        csl::math::Vector3 distPosition;
        hh::game::ObjectId toObjectID;
        float upPower;
        float speed;
        float jumpSpeedAccel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathCreateParametor* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathCreateParametor* pInstance);
        static void Clean(PathCreateParametor* pInstance);
    };
}

namespace heur::rfl {
    struct ActionParametor {
        enum class ActionType : int8_t {
            None = 0,
            ChangeSpeed = 1,
            Jump = 2,
            Attack = 3,
        };

        ActionType actionType;
        heur::rfl::AccelerationParametor accelerationParam;
        heur::rfl::PathCreateParametor pathParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ActionParametor* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ActionParametor* pInstance);
        static void Clean(ActionParametor* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyRhinolinerSpawner {
        bool isWaitStart;
        bool eventDriven;
        bool isTransparency;
        bool isUTurn;
        bool isInterruptionJumpMotion;
        int32_t addLightGaugeNum;
        float initializedSpeed;
        float initializedMaxSpeed;
        float initializedAccleration;
        heur::rfl::ActionParametor actionParametors[8];
        csl::ut::MoveArray<hh::game::ObjectId> cameraVolumeIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyRhinolinerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyRhinolinerSpawner* pInstance);
        static void Clean(EnemyRhinolinerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoHomingLaserSalvoInfo {
        csl::math::Vector3 launch_position_offset;
        csl::math::Vector3 launch_direction;
        csl::math::Vector3 target_position_offset;
        float speedAtStart;
        float speed;
        float speedMin;
        float speedMax;
        float speedAcceleration;
        float relativeSpeedToDecelerate;
        float decelerateAtOverRelativeSpeed;
        float radius;
        float length;
        float damage_collider_scale;
        float lifeTime;
        float angularSpeed;
        float startDistance;
        float endDistance;
        float onTimeAtStart;
        float onTime;
        float offTime;
        float directionError;
        float targetPositionEstimatedTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoHomingLaserSalvoInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoHomingLaserSalvoInfo* pInstance);
        static void Clean(EnemySalvoHomingLaserSalvoInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoSpawner {
        enum class WarpAttackOffsetType : int8_t {
            None = 0,
            Global = 1,
            Local = 2,
            Camera = 3,
        };

        int32_t no;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        csl::ut::VariableString pathName;
        float keepDistanceMin;
        float keepDistanceMax;
        float keepDistanceMinWhileAttacking;
        float keepDistanceMaxWhileAttacking;
        uint32_t shootHomingLaserRapidFireNum;
        heur::rfl::EnemySalvoHomingLaserSalvoInfo homingLaserSalvo[5];
        float escapeTime;
        float damageVelocityScaleRush;
        float damageVelocityScaleSlamDownward;
        float killBelowPositionY;
        float respawnTime;
        int32_t addLightGaugeNum;
        WarpAttackOffsetType warpAttackOffsetType;
        bool sideView;
        bool isTransparency;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoSpawner* pInstance);
        static void Clean(EnemySalvoSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoVolumeSpawner {
        enum class StateType : int8_t {
            DEFAULTSTATE_ON = 0,
            DEFAULTSTATE_OFF = 1,
        };

        enum class ActionType : int8_t {
            ACTION_EACHTIME = 0,
            ACTION_ONCE = 1,
        };

        enum class AnimationType : int8_t {
            ANIMATION_NONE = -1,
            ANIMATION_APPEAR_TURN = 0,
            ANIMATION_NUM = 1,
        };

        StateType state;
        ActionType action;
        AnimationType animation;
        float moveSpeed;
        float keepDistanceMin;
        float keepDistanceMinWhileAttacking;
        float escapeTime;
        bool isEventDriven;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoVolumeSpawner* pInstance);
        static void Clean(EnemySalvoVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySoldierSpawner {
        enum class WarpAttackOffsetType : int8_t {
            None = 0,
            Global = 1,
            Local = 2,
            Camera = 3,
        };

        int32_t no;
        float eyesightHeightUpperLimit;
        float eyesightHeightLowerLimit;
        float eyesightDistance;
        float eyesightDistanceOnBattle;
        float damageVelocityScaleRush;
        float damageVelocityScaleSlamDownward;
        float killBelowPositionY;
        float respawnTime;
        int32_t addLightGaugeNum;
        WarpAttackOffsetType warpAttackOffsetType;
        bool sideView;
        bool isTransparency;
        float movableDistance;
        float attackableDistance;
        float moveSpeed;
        float frontDistanceForCheckTerrain;
        float topYOffsetForCheckTerrain;
        float btmYOffsetForCheckTerrain;
        float heightCannotBeClimbed;
        csl::math::Vector3 warpOffsetForFV;
        csl::math::Vector3 warpOffsetForSV;
        csl::math::Vector3 warpOffsetForFVWhileBlownUp;
        csl::math::Vector3 warpOffsetForSVWhileBlownUp;
        csl::math::Vector3 warpOffsetForFVWhileBlownAway;
        csl::math::Vector3 warpOffsetForSVWhileBlownAway;
        float warpAngleForFV;
        float warpAngleForSV;
        float warpAngleForFVWhileBlownUp;
        float warpAngleForSVWhileBlownUp;
        float warpAngleForFVWhileBlownAway;
        float warpAngleForSVWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        bool useTutorial;
        bool disableCharacterControlWhenNotBattle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySoldierSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySoldierSpawner* pInstance);
        static void Clean(EnemySoldierSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyTwisterSpawner {
        enum class MoveType : int8_t {
            Fix = 0,
            Path = 1,
            TwoPoint = 2,
        };

        enum class RotateType : int8_t {
            ChangeByTime = 0,
            OnlyNormal = 1,
            OnlyHighSpeed = 2,
        };

        MoveType moveType;
        csl::ut::VariableString pathName;
        csl::math::Vector3 twoPointOffset;
        float offsetPhase;
        float moveSpeed;
        RotateType rotateType;
        float highSpeedTime;
        float waitTime;
        bool isRespawn;
        float respawnTime;
        bool isSv;
        bool isTransparency;
        bool eventDriven;
        bool enableBlock;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyTwisterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyTwisterSpawner* pInstance);
        static void Clean(EnemyTwisterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerritorySpawner {
        enum class Shape : int8_t {
            SHAPE_CYLINDER = 0,
            SHAPE_BOX = 1,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Y_PLANE = 1,
            BASE_X_PLANE = 2,
            BASE_Z_PLANE = 3,
        };

        Shape shape;
        BasePoint basePoint;
        csl::ut::VariableString pathName;
        csl::math::Vector3 patrolSize;
        csl::math::Vector3 fightSize;
        csl::math::Vector3 patrolOffset;
        csl::math::Vector3 fightOffset;
        bool isFallReturnArea;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerritorySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerritorySpawner* pInstance);
        static void Clean(ObjTerritorySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldSetupParameter {
        int8_t prio;
        bool defaultON;
        bool fixed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldSetupParameter* pInstance);
        static void Clean(GravityFieldSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldBoxSetupParameter : heur::rfl::GravityFieldSetupParameter {
        float x;
        float y;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldBoxSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldBoxSetupParameter* pInstance);
        static void Clean(GravityFieldBoxSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldBoxSpawner : heur::rfl::GravityFieldBoxSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldBoxSpawner* pInstance);
        static void Clean(ObjGFieldBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldConcaveBoxSetupParameter : heur::rfl::GravityFieldSetupParameter {
        csl::ut::VariableString pathName;
        float widthStart;
        float widthEnd;
        float height;
        int32_t split;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldConcaveBoxSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldConcaveBoxSetupParameter* pInstance);
        static void Clean(GravityFieldConcaveBoxSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldConcaveBoxSpawner : heur::rfl::GravityFieldConcaveBoxSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldConcaveBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldConcaveBoxSpawner* pInstance);
        static void Clean(ObjGFieldConcaveBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldConstantSetupParameter : heur::rfl::GravityFieldSetupParameter {
        float x;
        float y;
        float z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldConstantSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldConstantSetupParameter* pInstance);
        static void Clean(GravityFieldConstantSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldConstantSpawner : heur::rfl::GravityFieldConstantSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldConstantSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldConstantSpawner* pInstance);
        static void Clean(ObjGFieldConstantSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldCylinderSplineSetupParameter : heur::rfl::GravityFieldSetupParameter {
        float radius;
        csl::ut::VariableString pathName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldCylinderSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldCylinderSplineSetupParameter* pInstance);
        static void Clean(GravityFieldCylinderSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldFaceSplineSetupParameter : heur::rfl::GravityFieldCylinderSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldFaceSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldFaceSplineSetupParameter* pInstance);
        static void Clean(GravityFieldFaceSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldFaceSplineSpawner : heur::rfl::GravityFieldFaceSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldFaceSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldFaceSplineSpawner* pInstance);
        static void Clean(ObjGFieldFaceSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldHemisphereSetupParameter : heur::rfl::GravityFieldSetupParameter {
        enum class Type : int8_t {
            TYPE_OUTER = 0,
            TYPE_INNER = 1,
        };

        float radius;
        float innerRadius;
        Type type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldHemisphereSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldHemisphereSetupParameter* pInstance);
        static void Clean(GravityFieldHemisphereSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldHemisphereSpawner : heur::rfl::GravityFieldHemisphereSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldHemisphereSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldHemisphereSpawner* pInstance);
        static void Clean(ObjGFieldHemisphereSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldInsideCylinderSplineSetupParameter : heur::rfl::GravityFieldCylinderSplineSetupParameter {
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldInsideCylinderSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldInsideCylinderSplineSetupParameter* pInstance);
        static void Clean(GravityFieldInsideCylinderSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldInsideCylinderSplineSpawner : heur::rfl::GravityFieldInsideCylinderSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldInsideCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldInsideCylinderSplineSpawner* pInstance);
        static void Clean(ObjGFieldInsideCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldInsidePrismSplineSetupParameter : heur::rfl::GravityFieldCylinderSplineSetupParameter {
        float innerRadius;
        int8_t divide;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldInsidePrismSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldInsidePrismSplineSetupParameter* pInstance);
        static void Clean(GravityFieldInsidePrismSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldInsidePrismSplineSpawner : heur::rfl::GravityFieldInsidePrismSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldInsidePrismSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldInsidePrismSplineSpawner* pInstance);
        static void Clean(ObjGFieldInsidePrismSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldOutsideCylinderSplineSetupParameter : heur::rfl::GravityFieldCylinderSplineSetupParameter {
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldOutsideCylinderSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldOutsideCylinderSplineSetupParameter* pInstance);
        static void Clean(GravityFieldOutsideCylinderSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldOutsideCylinderSplineSpawner : heur::rfl::GravityFieldOutsideCylinderSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldOutsideCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldOutsideCylinderSplineSpawner* pInstance);
        static void Clean(ObjGFieldOutsideCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldOutsidePrismSplineSetupParameter : heur::rfl::GravityFieldCylinderSplineSetupParameter {
        float innerRadius;
        int8_t divide;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldOutsidePrismSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldOutsidePrismSplineSetupParameter* pInstance);
        static void Clean(GravityFieldOutsidePrismSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldOutsidePrismSplineSpawner : heur::rfl::GravityFieldOutsidePrismSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldOutsidePrismSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldOutsidePrismSplineSpawner* pInstance);
        static void Clean(ObjGFieldOutsidePrismSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldSphereSetupParameter : heur::rfl::GravityFieldSetupParameter {
        float radius;
        float innerRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldSphereSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldSphereSetupParameter* pInstance);
        static void Clean(GravityFieldSphereSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldSphereSpawner : heur::rfl::GravityFieldSphereSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldSphereSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldSphereSpawner* pInstance);
        static void Clean(ObjGFieldSphereSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldSvSplineSetupParameter : heur::rfl::GravityFieldSetupParameter {
        csl::ut::VariableString pathName;
        float x;
        float y;
        float z;
        float tolerance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldSvSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldSvSplineSetupParameter* pInstance);
        static void Clean(GravityFieldSvSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldSvSplineSpawner : heur::rfl::GravityFieldSvSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldSvSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldSvSplineSpawner* pInstance);
        static void Clean(ObjGFieldSvSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNpcBaseSpawner {
        float minIdleReactionInterval;
        float maxIdleReactionInterval;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNpcBaseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNpcBaseSpawner* pInstance);
        static void Clean(ObjNpcBaseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigSpawner : heur::rfl::ObjNpcBaseSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigSpawner* pInstance);
        static void Clean(ObjBigSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGeraldSpawner : heur::rfl::ObjNpcBaseSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGeraldSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGeraldSpawner* pInstance);
        static void Clean(ObjGeraldSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMariaSpawner : heur::rfl::ObjNpcBaseSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMariaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMariaSpawner* pInstance);
        static void Clean(ObjMariaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOmegaSpawner : heur::rfl::ObjNpcBaseSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOmegaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOmegaSpawner* pInstance);
        static void Clean(ObjOmegaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionInfo {
        enum class CollectionMode : int8_t {
            Art = 0,
            Movie = 1,
            Sound = 2,
            Character = 3,
            History = 4,
            GeraldNote = 5,
            Num = 6,
            None = -1,
        };

        CollectionMode itemMode;
        int32_t itemID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionInfo* pInstance);
        static void Clean(CollectionInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOrbotCubotSpawner {
        heur::rfl::CollectionInfo itemInfos[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOrbotCubotSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOrbotCubotSpawner* pInstance);
        static void Clean(ObjOrbotCubotSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRougeSpawner : heur::rfl::ObjNpcBaseSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRougeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRougeSpawner* pInstance);
        static void Clean(ObjRougeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmbSoundVolumeSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_CAPSULE = 3,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        int32_t id;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmbSoundVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmbSoundVolumeSpawner* pInstance);
        static void Clean(ObjAmbSoundVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeBGMAisacVolumeSpawner {
        csl::ut::VariableString aisacName;
        float targetAisacValue;
        float fadeInTime;
        float fadeOutTime;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeBGMAisacVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeBGMAisacVolumeSpawner* pInstance);
        static void Clean(ObjChangeBGMAisacVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ChangeBGMData {
        enum class InterruptType : int8_t {
            INTERRUPT_TYPE_STOP = 0,
            INTERRUPT_TYPE_PAUSE = 1,
            INTERRUPT_TYPE_OVERLAP = 2,
            NUM_INTERRUPT_TYPE = 3,
        };

        csl::ut::VariableString cueName;
        float fadeOutTime;
        float playDelayTime;
        float fadeInTime;
        InterruptType interruptType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ChangeBGMData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ChangeBGMData* pInstance);
        static void Clean(ChangeBGMData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeBGMTriggerSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        heur::rfl::ChangeBGMData enterChangeBGMData;
        heur::rfl::ChangeBGMData leaveChangeBGMData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeBGMTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeBGMTriggerSpawner* pInstance);
        static void Clean(ObjChangeBGMTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChangeSEAisacVolumeSpawner {
        csl::ut::VariableString aisacName;
        float targetAisacValue;
        float fadeInTime;
        float fadeOutTime;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChangeSEAisacVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChangeSEAisacVolumeSpawner* pInstance);
        static void Clean(ObjChangeSEAisacVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjExtentSoundSourceSpawner {
        enum class PlayMode : int8_t {
            PLAYMODE_LOOP = 0,
            PLAYMODE_ONE_SHOT = 1,
            PLAYMODE_PERIODIC = 2,
        };

        enum class Shape : int8_t {
            SHAPE_SPHERE = 0,
        };

        csl::ut::VariableString cueName;
        PlayMode playMode;
        float timeOffset;
        float playInterval;
        float volume;
        Shape shape;
        csl::math::Vector3 hearingRange;
        csl::math::Vector3 undampedRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjExtentSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjExtentSoundSourceSpawner* pInstance);
        static void Clean(ObjExtentSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOneShotBGMTriggerSpawner {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        csl::ut::VariableString cueName;
        float fadeTime;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOneShotBGMTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOneShotBGMTriggerSpawner* pInstance);
        static void Clean(ObjOneShotBGMTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOneShotSoundTriggerSpawner {
        enum class SoundPositionType : int8_t {
            SOUND_POS_CENTER = 0,
            SOUND_POS_MANUAL = 1,
        };

        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
        };

        csl::ut::VariableString cueName;
        float volume;
        bool isPlay3D;
        SoundPositionType soundPositionType;
        csl::math::Vector3 soundPosition;
        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;
        bool isStopWhenDestroy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOneShotSoundTriggerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOneShotSoundTriggerSpawner* pInstance);
        static void Clean(ObjOneShotSoundTriggerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSoundSourceSpawner {
        enum class PlayMode : int8_t {
            PLAYMODE_LOOP = 0,
            PLAYMODE_ONE_SHOT = 1,
            PLAYMODE_PERIODIC = 2,
        };

        csl::ut::VariableString cueName;
        PlayMode playMode;
        float timeOffset;
        float playInterval;
        float volume;
        float hearingRange;
        float undampedRange;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSoundSourceSpawner* pInstance);
        static void Clean(ObjSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPathSoundSourceSpawner : heur::rfl::ObjSoundSourceSpawner {
        csl::ut::VariableString pathName;
        int32_t searchDivideNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPathSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPathSoundSourceSpawner* pInstance);
        static void Clean(ObjPathSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjPointSoundSourceSpawner : heur::rfl::ObjSoundSourceSpawner {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjPointSoundSourceSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjPointSoundSourceSpawner* pInstance);
        static void Clean(ObjPointSoundSourceSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSoundSourcePlaneSpawner {
        csl::ut::VariableString cueName;
        float volume;
        bool is3D;
        csl::math::Vector3 pos3D;
        heur::rfl::PassPlaneTriggerSpawner planeTrigger;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSoundSourcePlaneSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSoundSourcePlaneSpawner* pInstance);
        static void Clean(ObjSoundSourcePlaneSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSoundSourceVolumeSpawner : heur::rfl::ObjSoundSourceSpawner {
        heur::rfl::VolumeTriggerSpawner volumeTrigger;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSoundSourceVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSoundSourceVolumeSpawner* pInstance);
        static void Clean(ObjSoundSourceVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigBatterySpawner {
        float visual_scale;
        float big_missile_visual_scale;
        float big_missile_diameter;
        float big_missile_height;
        float big_missile_speed;
        float big_missile_acceleration;
        float big_missile_speed_max;
        float big_missile_wait_time_ready;
        float big_missile_wait_time_shot;
        float big_missile_rotate_speed;
        float big_missile_life_time;
        float big_missile_qte_start_distance;
        csl::math::Vector3 big_missile_launch_position_offset;
        csl::math::Vector3 big_missile_qte_root_position;
        csl::math::Quaternion big_missile_qte_root_rotation;
        csl::math::Vector3 big_missile_qte_success_position;
        csl::math::Quaternion big_missile_qte_success_rotation;
        csl::math::Vector3 big_missile_qte_fail_position;
        csl::math::Quaternion big_missile_qte_fail_rotation;
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigBatterySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigBatterySpawner* pInstance);
        static void Clean(ObjBigBatterySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBrokenBatterySpawner {
        bool isEventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBrokenBatterySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBrokenBatterySpawner* pInstance);
        static void Clean(ObjBrokenBatterySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDistSpaceExitSoundPlayerSpawner {
        bool dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDistSpaceExitSoundPlayerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDistSpaceExitSoundPlayerSpawner* pInstance);
        static void Clean(ObjDistSpaceExitSoundPlayerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCameraLimitedPanSpawner : heur::rfl::ObjCameraSpawner {
        enum class PositionMode : int8_t {
            POS_MODE_FIX = 0,
            POS_MODE_MAINTAIN_DISTANCE = 1,
        };

        float fovy;
        csl::math::Vector3 atBase;
        float atRadius;
        float playerRadius;
        float atOffsetY;
        PositionMode positionMode;
        float distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCameraLimitedPanSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCameraLimitedPanSpawner* pInstance);
        static void Clean(ObjCameraLimitedPanSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSmallBatterySpawner {
        enum class CollisionSizeType : int8_t {
            Diameter_x_Diameter = 0,
            Diameter_x_Width = 1,
            Num_CollisionSizeType = 2,
        };

        enum class OmenType : int8_t {
            OT_NONE = 0,
            OT_A = 1,
            OT_B = 2,
            OT_C = 3,
            Num_OmenType = 4,
        };

        enum class RotateForwardType : int8_t {
            RFT_HALFX = 0,
            RFT_HALFZ = 1,
        };

        float visual_scale;
        float respawnTime;
        float small_missile_visual_scale;
        CollisionSizeType small_missile_collision_size_type;
        float small_missile_diameter;
        float small_missile_height;
        float small_missile_width;
        float small_missile_speed;
        float small_missile_acceleration;
        float small_missile_speed_max;
        float small_missile_wait_time_ready;
        float small_missile_wait_time_shot;
        float small_missile_life_time;
        csl::math::Vector3 small_missile_launch_position_offset;
        csl::math::Vector3 small_missile_blown_velocity;
        OmenType small_missile_omen_type;
        bool small_missile_omen_skip_1st_time;
        RotateForwardType small_missile_rotate_forward_type;
        bool small_missile_se_flags[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSmallBatterySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSmallBatterySpawner* pInstance);
        static void Clean(ObjSmallBatterySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSubBatterySpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSubBatterySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSubBatterySpawner* pInstance);
        static void Clean(ObjSubBatterySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigCannonSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigCannonSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigCannonSpawner* pInstance);
        static void Clean(ObjBigCannonSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBigDoorSpawner {
        enum class Visual : int8_t {
            BIGDOOR01 = 0,
            BIGDOOR02 = 1,
            TYPEMAX = 2,
        };

        Visual modelType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBigDoorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBigDoorSpawner* pInstance);
        static void Clean(ObjBigDoorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDestructibleBridgeSpawner {
        enum class Type : int8_t {
            RAIL = 0,
            FLOOR = 1,
            ALL = 2,
            ALL_20M = 3,
            ALL_30M = 4,
        };

        Type type;
        heur::rfl::ActionNotification actions[4];
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDestructibleBridgeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDestructibleBridgeSpawner* pInstance);
        static void Clean(ObjDestructibleBridgeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct Associative {
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;
        float delayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Associative* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Associative* pInstance);
        static void Clean(Associative* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDestructibleFloorWithPillerSpawner {
        enum class Height : int8_t {
            HEIGHT_3M = 0,
            HEIGHT_5M = 1,
            HEIGHT_10M = 2,
            HEIGHT_NUM = 3,
        };

        enum class Type : int8_t {
            NORMAL = 0,
            RAIL = 1,
        };

        enum class DestructibleFlag : int8_t {
            TOUCH_ENEMY = 0,
            RIDE_PLAYER = 1,
            ALL = 2,
            NOT = 3,
        };

        Height height;
        Type type;
        DestructibleFlag destFlag;
        float waitlTimeEvent;
        float waitTimeRidePlayer;
        bool isDestroyableStomping;
        bool isEnablePillerCollision;
        bool enableInputGuide;
        csl::math::Vector3 guideSize;
        csl::math::Vector3 guideColOffset;
        csl::math::Vector3 guidePosOffset;
        heur::rfl::Associative associativeObjects[4];
        heur::rfl::ActionNotification actions[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDestructibleFloorWithPillerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDestructibleFloorWithPillerSpawner* pInstance);
        static void Clean(ObjDestructibleFloorWithPillerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGrindFloorSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGrindFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGrindFloorSpawner* pInstance);
        static void Clean(ObjGrindFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct JumpRopeSpringInfo {
        float firstSpeed;
        float outOfControl;
        float keepVelocityTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(JumpRopeSpringInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(JumpRopeSpringInfo* pInstance);
        static void Clean(JumpRopeSpringInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpRopeSpawner {
        float ropeDistance;
        float playerAngle;
        heur::rfl::JumpRopeSpringInfo spring[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpRopeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpRopeSpawner* pInstance);
        static void Clean(ObjJumpRopeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpRopePoleSpawner {
        int32_t pillerNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpRopePoleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpRopePoleSpawner* pInstance);
        static void Clean(ObjJumpRopePoleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOgreTrainSpawner {
        bool eventDriven;
        bool isReverse;
        bool isReturn;
        bool isJump;
        bool isHuge;
        bool isAutorun;
        float firstSpeed;
        float accelPower;
        float targetSpeed;
        float findPathDelayTime;
        int32_t typeCModelNum;
        csl::ut::VariableString centerPath;
        csl::ut::VariableString centerPath2;
        csl::ut::VariableString centerPath3;
        csl::ut::VariableString landingPath;
        csl::ut::VariableString landingPath2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOgreTrainSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOgreTrainSpawner* pInstance);
        static void Clean(ObjOgreTrainSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOgreTrainGoalSpawner {
        bool dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOgreTrainGoalSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOgreTrainGoalSpawner* pInstance);
        static void Clean(ObjOgreTrainGoalSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOgreTrainVolumeSpawner {
        bool eventDriven;
        csl::math::Vector3 size;
        float firstSpeed;
        float maxSpeed;
        float accelSpped;
        bool breakBridge;
        bool isKill;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOgreTrainVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOgreTrainVolumeSpawner* pInstance);
        static void Clean(ObjOgreTrainVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSmallDoorSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSmallDoorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSmallDoorSpawner* pInstance);
        static void Clean(ObjSmallDoorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCircuitBreakerSpawner {
        float force;
        float gravity;
        float lifeTime;
        bool isOpen;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCircuitBreakerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCircuitBreakerSpawner* pInstance);
        static void Clean(ObjCircuitBreakerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjKdvPillarSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjKdvPillarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjKdvPillarSpawner* pInstance);
        static void Clean(ObjKdvPillarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMovingPillarSpawner {
        enum class InitState : int8_t {
            OUTWARD = 0,
            BACKWARD = 1,
            NUM_INIT_STATE = 2,
        };

        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            SIZE_D = 3,
            SIZE_E = 4,
            SIZE_F = 5,
            NUM_SIZE_TYPE = 6,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        bool eventDriven;
        InitState initState;
        SizeType sizeType;
        TimeType timeType;
        csl::math::Vector3 moveVector;
        float moveTime;
        float waitTime;
        float moveTimeBackward;
        float waitTimeBackward;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMovingPillarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMovingPillarSpawner* pInstance);
        static void Clean(ObjMovingPillarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjOldCastleDoorSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjOldCastleDoorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjOldCastleDoorSpawner* pInstance);
        static void Clean(ObjOldCastleDoorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjStainedGlassSpawner {
        bool debrisPhysicsMoving;
        float debrisGravity;
        float debrisLifeTime;
        float debrisMass;
        float debrisFriction;
        float debrisRestitution;
        float debrisCullingRadius;
        float debrisRotationForce;
        int32_t debrisMaxPieces;
        float debrisImpluseScale;
        float debrisExplosionScale;
        bool debrisRotationRandom;
        float debrisSleepDownRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjStainedGlassSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjStainedGlassSpawner* pInstance);
        static void Clean(ObjStainedGlassSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWindRoadSpawner {
        enum class Point : int32_t {
            Start = 0,
            End = 1,
            Both = 2,
        };

        csl::ut::VariableString pathName;
        Point haPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWindRoadSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWindRoadSpawner* pInstance);
        static void Clean(ObjWindRoadSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWindRoadSwitchSpawner {
        enum class AnimRoll : uint8_t {
            Left = 0,
            Right = 1,
            Num = 2,
        };

        csl::ut::MoveArray<hh::game::ObjectId> windRoadList;
        AnimRoll animRoll;
        float upSpeed;
        float speedMin;
        float speedMax;
        float outOfControlTime;
        float keepVelocityTime;
        float ignoreSwingingTime;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWindRoadSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWindRoadSwitchSpawner* pInstance);
        static void Clean(ObjWindRoadSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBombEventSpawner {
        enum class Scene : int8_t {
            SCENE_ALL = 0,
            SCENE_SOUND = 1,
            SCENE_BALLISTIC = 2,
        };

        enum class EffectLodType : int8_t {
            EFFECT_LOW = 0,
            EFFECT_HIGH = 1,
        };

        enum class CameraShakeType : int32_t {
            NONE = 0,
            PARAM_NAME = 1,
            NUMBER_INPUT = 2,
        };

        enum class ShakeType : int32_t {
            SHAKE_DIRECTIONAL = 0,
            SHAKE_RANDOM = 1,
        };

        csl::ut::VariableString pathid;
        float speed;
        bool once;
        Scene scene;
        EffectLodType effectLod;
        float effectScale;
        heur::rfl::ActionNotification actions[3];
        csl::ut::MoveArray<hh::game::ObjectId> gismoTargets;
        CameraShakeType camraShakeType;
        csl::ut::VariableString parameterName;
        float shakeTime;
        float shakeRange;
        ShakeType shakeType;
        float magnitude;
        int32_t freq;
        float zRot;
        float attnRatio;
        bool enableDistAttn;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBombEventSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBombEventSpawner* pInstance);
        static void Clean(ObjBombEventSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct TargetPointInfo {
        float actionInterval;
        int32_t actionPattern;
        csl::ut::MoveArray<hh::game::ObjectId> targetLocators;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TargetPointInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TargetPointInfo* pInstance);
        static void Clean(TargetPointInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRobotSpawner {
        enum class ActionType : int8_t {
            Beam = 0,
            Punch = 1,
            Rubble = 2,
        };

        int32_t no;
        ActionType actionType;
        float afterActionWaitTime;
        float actionRadius;
        float actionLength;
        float actionSpeed;
        float actionInterval;
        float actionLifeTime;
        heur::rfl::TargetPointInfo targets[10];
        csl::ut::MoveArray<hh::game::ObjectId> targetLocatorsAfterAction;
        float omenDelayTime;
        float warpRadius;
        float warpHeight;
        csl::math::Vector3 warpOffset;
        csl::math::Vector3 warpOffsetWhileBlownUp;
        csl::math::Vector3 warpOffsetWhileBlownAway;
        float warpAngle;
        float warpAngleWhileBlownUp;
        float warpAngleWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        bool attackColliderHitPlayer;
        bool repeatAction;
        csl::ut::VariableString eventName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRobotSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRobotSpawner* pInstance);
        static void Clean(ObjDeathEggRobotSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRobotFloorSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            SIZE_D = 3,
            SIZE_E = 4,
            SIZE_F = 5,
            NUM_SIZE_TYPE = 6,
        };

        enum class BreakableType : int8_t {
            NONE = 0,
            ALWAYS = 1,
            AFTEROMEN = 2,
        };

        SizeType sizeType;
        BreakableType breakableType;
        bool canGoThrough;
        bool reverseDirOmen;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRobotFloorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRobotFloorSpawner* pInstance);
        static void Clean(ObjDeathEggRobotFloorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRobotRubbleSpawner {
        enum class ModelType : int8_t {
            MT_Rock = 0,
            MT_Rubble = 1,
            MT_NUM = 2,
        };

        csl::ut::VariableString pathName;
        float radius;
        float speed;
        float lifeTime;
        float ignoreLandTime;
        csl::math::Vector3 rotateOffsetRandom;
        ModelType modelType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRobotRubbleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRobotRubbleSpawner* pInstance);
        static void Clean(ObjDeathEggRobotRubbleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDeathEggRobotFarSpawner {
        float modelScail;
        float startTime;
        bool eventDriven;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDeathEggRobotFarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDeathEggRobotFarSpawner* pInstance);
        static void Clean(ObjDeathEggRobotFarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGeyserSpawner {
        enum class SizeType : int32_t {
            SIZE_S = 0,
            SIZE_M = 1,
            SIZE_L = 2,
        };

        enum class TimeType : int32_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        SizeType size;
        bool eventDriven;
        TimeType timeType;
        bool keepRise;
        float disableTime;
        float enableTime;
        float firstWaitTime;
        float riseSpeed;
        float jumpSpeed;
        float outOfControl;
        float keepVelocityTime;
        hh::game::ObjectId enemy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGeyserSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGeyserSpawner* pInstance);
        static void Clean(ObjGeyserSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSewagePipeSpawner {
        enum class Type : int32_t {
            WAIT_TIME = 0,
            WAIT_EVENT = 1,
            WAIT_EVENT_AND_TIME = 2,
        };

        enum class AnimationType : int32_t {
            ANIM_3M = 0,
            ANIM_8M = 1,
            ANIM_13M = 2,
        };

        Type type;
        AnimationType animType;
        float waitTime;
        float signTime;
        float drainTime;
        float drainDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSewagePipeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSewagePipeSpawner* pInstance);
        static void Clean(ObjSewagePipeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAirWallSpawner {
        enum class Size : int8_t {
            SMALL = 0,
            MEDIUM = 1,
        };

        enum class Genre : int8_t {
            NORMAL = 0,
            FRONTSIDE = 1,
            FRONT = 2,
        };

        enum class Move : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class Patrol : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class Time : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        enum class Event : int8_t {
            EVENT_NONE = 0,
            EVENT_HIDE = 1,
            EVENT_NO_MOVE = 2,
        };

        Size sizeType;
        Genre genreType;
        Move moveType;
        Patrol patrolType;
        Time timeType;
        Event eventDriven;
        bool isSyncRot;
        bool isSmoothMove;
        bool isReverse;
        bool isPressDead;
        csl::math::Vector3 moveVector;
        csl::ut::VariableString pathName;
        csl::ut::MoveArray<hh::game::ObjectId> locaterList;
        float waitTime;
        float phase;
        float speed;
        bool isWaitAppear;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAirWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAirWallSpawner* pInstance);
        static void Clean(ObjAirWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ConeCollisionData {
        float angle;
        float nearClip;
        float farClip;
        float offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ConeCollisionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ConeCollisionData* pInstance);
        static void Clean(ConeCollisionData* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaPipeSpawner {
        enum class Model : int8_t {
            StraightLine = 0,
            RightAngle = 1,
        };

        enum class Size : int8_t {
            Small = 0,
            Normal = 1,
            Big = 2,
        };

        Model model;
        Size size;
        float length;
        float radius;
        heur::rfl::ConeCollisionData cone;
        float rotX;
        float rotY;
        float rotZ;
        float shotSpeed;
        float outOfControl;
        float keepVelocityTime;
        float shotOffset;
        bool noPlayPipeAnim;
        bool isPlayerHide;
        float playerHideToTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaPipeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaPipeSpawner* pInstance);
        static void Clean(ObjAmoebaPipeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAppearGimmickMessangerSpawner {
        csl::ut::MoveArray<hh::game::ObjectId> objectIds;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAppearGimmickMessangerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAppearGimmickMessangerSpawner* pInstance);
        static void Clean(ObjAppearGimmickMessangerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBioMetalBoxSpawner {
        enum class SizeType : int32_t {
            Large = 0,
            Small = 1,
            Max = 2,
        };

        SizeType sizeType;
        int32_t numBoxesX;
        int32_t numBoxesY;
        int32_t numBoxesZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBioMetalBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBioMetalBoxSpawner* pInstance);
        static void Clean(ObjBioMetalBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCrushingWallSpawner {
        enum class SizePattern : int32_t {
            Pattern1 = 0,
            Pattern2 = 1,
            Pattern3 = 2,
            Pattern4 = 3,
            Pattern5 = 4,
            Pattern6 = 5,
            Max = 6,
        };

        enum class TimeType : int32_t {
            Global = 0,
            Local = 1,
        };

        enum class BasePointType : int32_t {
            Center = 0,
            Bottom = 1,
            MoveDirectionSurface = 2,
            ReverseMoveDirectionSurface = 3,
        };

        SizePattern sizePattern;
        TimeType timeType;
        BasePointType basePointType;
        csl::math::Vector3 destOffset;
        float pushingTime;
        float pushingWaitTime;
        float pullingTime;
        float pullingWaitTime;
        float phase;
        float movableCollisionHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCrushingWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCrushingWallSpawner* pInstance);
        static void Clean(ObjCrushingWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCrushingWallFrameSpawner {
        enum class ModelType : int32_t {
            FrameA = 0,
            FrameB = 1,
            FrameD = 2,
            FrameDDbl = 3,
            FrameE = 4,
            FrameF = 5,
            Max = 6,
        };

        ModelType modelType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCrushingWallFrameSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCrushingWallFrameSpawner* pInstance);
        static void Clean(ObjCrushingWallFrameSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGratingSpawner {
        enum class Type : uint8_t {
            Small = 0,
            Normal = 1,
            Big = 2,
        };

        Type type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGratingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGratingSpawner* pInstance);
        static void Clean(ObjGratingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct MoveSimulationParam {
        float restitution;
        float accel;
        float gravity;
        float rotCoefficient;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MoveSimulationParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MoveSimulationParam* pInstance);
        static void Clean(MoveSimulationParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRollingRockGeneraterSpawner {
        enum class MoveType : uint8_t {
            Physics = 0,
            PathAndPhysics = 1,
            Path = 2,
            ProgramSimulation = 3,
        };

        float minSpeed;
        float maxSpeed;
        float shotAngleTheta;
        float shotAnglePhi;
        float shotSpeed;
        float linearDamping;
        float setWaitTime;
        float premonitionWaitTime;
        float shotWaitTime;
        float size;
        float life;
        int32_t shotNum;
        MoveType moveType;
        heur::rfl::MoveSimulationParam simulationParam;
        csl::ut::VariableString pathName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRollingRockGeneraterSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRollingRockGeneraterSpawner* pInstance);
        static void Clean(ObjRollingRockGeneraterSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUpDownGondolaSpawner {
        enum class SizeType : int8_t {
            SIZE_A = 0,
            SIZE_B = 1,
            SIZE_C = 2,
            NUM_SIZE_TYPE = 3,
        };

        csl::math::Vector3 moveVector;
        float horizontalMovementSpeed;
        float upwardMovementSpeed;
        float waitTimeToRise;
        float downwardMovementSpeed;
        float downwardMovementRange;
        SizeType sizeType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUpDownGondolaSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUpDownGondolaSpawner* pInstance);
        static void Clean(ObjUpDownGondolaSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct LaunchInfoW6 {
        float threathold;
        float firstSpeed;
        float elevation;
        float outOfControl;
        float keepVelocityDistance;
        float motionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LaunchInfoW6* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LaunchInfoW6* pInstance);
        static void Clean(LaunchInfoW6* pInstance);
    };
}

namespace heur::rfl {
    struct ObjJumpBoardW6Spawner {
        heur::rfl::LaunchInfoW6 launchInfos[1];
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjJumpBoardW6Spawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjJumpBoardW6Spawner* pInstance);
        static void Clean(ObjJumpBoardW6Spawner* pInstance);
    };
}

namespace heur::rfl {
    struct LPSignParam {
        enum class SingType : int32_t {
            SIGN_NONE = -1,
            SIGN_A = 0,
            SIGN_B = 1,
            SIGN_TYPE_NUM = 2,
        };

        SingType type;
        float offsetX;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LPSignParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LPSignParam* pInstance);
        static void Clean(LPSignParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLargePoleSpawner {
        bool isHorming;
        bool usedPillar;
        uint32_t sideBarNum;
        uint32_t pillarNum;
        float distanceOffset;
        float guideOffsetX;
        csl::math::Vector3 collisionSizeOffset;
        csl::math::Vector3 successShotVelocity;
        csl::math::Vector3 failShotVelocity;
        float outOfControlTime;
        heur::rfl::LPSignParam signParam[5];
        heur::rfl::ActionNotification actions[3];
        bool isFixedInjection;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLargePoleSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLargePoleSpawner* pInstance);
        static void Clean(ObjLargePoleSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjRocketRadiSpawner {
        enum class MoveType : int8_t {
            MOVE_POINT = 0,
            MOVE_PATH = 1,
        };

        MoveType moveType;
        csl::math::Vector3 moveVector;
        float waitTime;
        float lifeTime;
        csl::ut::VariableString pathName;
        float finishDist;
        float moveSpeed;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjRocketRadiSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjRocketRadiSpawner* pInstance);
        static void Clean(ObjRocketRadiSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSignBoardSpawner {
        bool isLighting;
        bool isLeft;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSignBoardSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSignBoardSpawner* pInstance);
        static void Clean(ObjSignBoardSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjUpReelRadiSpawner {
        float length;
        float upSpeedMax;
        float firstSpeed;
        float outOfControl;
        bool isOneTimeUp;
        bool eventDriven;
        bool isEndOutControl;
        heur::rfl::ActionNotification actions[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjUpReelRadiSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjUpReelRadiSpawner* pInstance);
        static void Clean(ObjUpReelRadiSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjColliderTestSpawner {
        enum class ShapeType : int8_t {
            SPHERE = 0,
            CAPSULE = 1,
            CYLINDER = 2,
            BOX = 3,
        };

        enum class LayerType : int8_t {
            NONE = 0,
            SOLID = 1,
            LIQUID = 2,
            THROUGH = 3,
            CAMERA = 4,
            SOLID_ONEWAY = 5,
            SOLID_THROUGH = 6,
            SOLID_TINY = 7,
            SOLID_DETAIL = 8,
            SOLID_MESH = 9,
            LAND = 10,
            RAYBLOCK = 11,
            EVENT = 12,
            RAYBLOCK_ENEMY = 13,
            ENEMY_BODY = 14,
            PLAYER = 15,
            ENEMY = 16,
            OBJECT_BODY = 17,
            GIMMICK = 18,
            DYNAMICS = 19,
            RING = 20,
            CHARACTER_CONTROL = 21,
            PLAYER_ONLY = 22,
            DYNAMICS_THROUGH = 23,
            ENEMY_ONLY = 24,
            SENSOR_PLAYER = 25,
            SENSOR_RING = 26,
            SENSOR_GIMMICK = 27,
            SENSOR_LAND = 28,
            SENSOR_ALL = 29,
            SENSOR_PLAYER_ENEMY = 30,
            RESERVED31 = 31,
        };

        ShapeType shape;
        float width;
        float height;
        float depth;
        LayerType layer;
        bool hitbits[32];
        bool triggers[3];
        bool outputLog;
        bool outputScreen;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjColliderTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjColliderTestSpawner* pInstance);
        static void Clean(ObjColliderTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDSurfSpinTestSpawner {
        enum class MoveType : int8_t {
            MOVE_NONE = 0,
            MOVE_POINT = 1,
            MOVE_PATH = 2,
        };

        enum class PatrolType : int8_t {
            PATROL_RETURN = 0,
            PATROL_LOOP = 1,
            PATROL_ONEWAY = 2,
        };

        enum class TimeType : int8_t {
            TIME_LOCAL = 0,
            TIME_GLOBAL = 1,
        };

        csl::math::Vector3 size;
        MoveType moveType;
        PatrolType patrolType;
        TimeType timeType;
        bool eventDriven;
        csl::math::Vector3 destOffset;
        csl::ut::VariableString pathName;
        bool isReverse;
        float moveSpeed;
        float waitTime;
        float phase;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDSurfSpinTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDSurfSpinTestSpawner* pInstance);
        static void Clean(ObjDSurfSpinTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct EventPlayTestParam {
        enum class StartType : uint8_t {
            Stand = 0,
            Fixed = 1,
            Frozen = 2,
        };

        csl::ut::VariableString eventName;
        bool setRootMatrix;
        bool noUnload;
        StartType playerStartType;
        float cameraInterpolateTime;
        bool setCameraLookAt;
        csl::math::Vector3 cameraLookAt;
        bool playSeamless;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventPlayTestParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventPlayTestParam* pInstance);
        static void Clean(EventPlayTestParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventPlayTestSpawner {
        bool eventDriven;
        bool preload;
        heur::rfl::EventPlayTestParam param;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventPlayTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventPlayTestSpawner* pInstance);
        static void Clean(ObjEventPlayTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMockSpawner {
        enum class Kind : int8_t {
            Gate = 0,
            DEnemy = 1,
            Boss = 2,
            Num = 3,
        };

        Kind m_kind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMockSpawner* pInstance);
        static void Clean(ObjMockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossModelPreviewSpawner {
        enum class ModelType : uint8_t {
            BioLizard = 0,
            MOL = 1,
            Mephiles = 2,
            PBD = 3,
            PBD_Final = 4,
        };

        ModelType modelType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossModelPreviewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossModelPreviewSpawner* pInstance);
        static void Clean(ObjBossModelPreviewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCharacterModelPreviewSpawner {
        enum class ModelType : uint8_t {
            Terios = 0,
            Sonic = 1,
            BlackDoom = 2,
            TimeEater = 3,
            Big = 4,
            Omega = 5,
            Rouge = 6,
            Cubot = 7,
            Orbot = 8,
            Maria = 9,
            Gerald = 10,
        };

        ModelType modelType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCharacterModelPreviewSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCharacterModelPreviewSpawner* pInstance);
        static void Clean(ObjCharacterModelPreviewSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSampleShapeSpawner {
        enum class Shape : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_CYLINDER_MIDAIR = 3,
            SHAPE_FanCYLINDER_MIDAIR = 4,
        };

        enum class LayerType : int8_t {
            NONE = 0,
            SOLID = 1,
            LIQUID = 2,
            THROUGH = 3,
            CAMERA = 4,
            SOLID_ONEWAY = 5,
            SOLID_THROUGH = 6,
            SOLID_TINY = 7,
            SOLID_DETAIL = 8,
            SOLID_MESH = 9,
            LAND = 10,
            RAYBLOCK = 11,
            EVENT = 12,
            RAYBLOCK_ENEMY = 13,
            ENEMY_BODY = 14,
            PLAYER = 15,
            ENEMY = 16,
            OBJECT_BODY = 17,
            GIMMICK = 18,
            DYNAMICS = 19,
            RING = 20,
            CHARACTER_CONTROL = 21,
            PLAYER_ONLY = 22,
            DYNAMICS_THROUGH = 23,
            ENEMY_ONLY = 24,
            SENSOR_PLAYER = 25,
            SENSOR_RING = 26,
            SENSOR_GIMMICK = 27,
            SENSOR_LAND = 28,
            SENSOR_ALL = 29,
            SENSOR_PLAYER_ENEMY = 30,
            RESERVED31 = 31,
        };

        enum class MaterialType : int8_t {
            MAT_NONE = 0,
            MAT_STONE = 1,
            MAT_EARTH = 2,
            MAT_WOOD = 3,
            MAT_GRASS = 4,
            MAT_IRON = 5,
            MAT_SAND = 6,
            MAT_LAVA = 7,
            MAT_GLASS = 8,
            MAT_SNOW = 9,
            MAT_NO_ENTRY = 10,
            MAT_ICE = 11,
            MAT_WATER = 12,
            MAT_SEA = 13,
            MAT_DAMAGE = 14,
            MAT_DEAD = 15,
            MAT_FLOWER0 = 16,
            MAT_FLOWER1 = 17,
            MAT_FLOWER2 = 18,
            MAT_AIR = 19,
            MAT_DEADLEAVES = 20,
            MAT_WIREMESH = 21,
            MAT_DEAD_ANYDIR = 22,
            MAT_DAMAGE_THROUGH = 23,
            MAT_DRY_GRASS = 24,
            MAT_RELIC = 25,
            MAT_GIANT = 26,
            MAT_GRAVEL = 27,
            MAT_MUD_WATER = 28,
            MAT_WET3 = 29,
            MAT_WET4 = 30,
            MAT_WET1 = 31,
            MAT_WET2 = 32,
        };

        Shape ShapeType;
        float Width;
        float Height;
        float Depth;
        uint8_t Red;
        uint8_t Green;
        uint8_t Blue;
        uint8_t Alpha;
        bool IsEnableModel;
        bool IsEnableRigidbody;
        LayerType layer;
        MaterialType material;
        bool attributes[24];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSampleShapeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSampleShapeSpawner* pInstance);
        static void Clean(ObjSampleShapeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceTalkTestSpawner {
        int32_t no;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceTalkTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceTalkTestSpawner* pInstance);
        static void Clean(ObjWhiteSpaceTalkTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct DrivenCollision {
        uint32_t visibleSectorID;
        uint32_t hideSectorID;
        bool use;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DrivenCollision* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DrivenCollision* pInstance);
        static void Clean(DrivenCollision* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceSectorTestSpawner {
        heur::rfl::DrivenCollision redCollision;
        heur::rfl::DrivenCollision blueCollision;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceSectorTestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceSectorTestSpawner* pInstance);
        static void Clean(ObjWhiteSpaceSectorTestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAppearGimmickVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;
        csl::ut::VariableString disableLayer;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAppearGimmickVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAppearGimmickVolumeSpawner* pInstance);
        static void Clean(ObjAppearGimmickVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBoltSpawner {
        int32_t type;
        int32_t boltID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBoltSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBoltSpawner* pInstance);
        static void Clean(ObjBoltSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct AppearGateParams {
        csl::ut::MoveArray<hh::game::ObjectId> challengeGates;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AppearGateParams* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AppearGateParams* pInstance);
        static void Clean(AppearGateParams* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossGateSpawner {
        enum class Value : int8_t {
            SpaceColonyARK = 0,
            RailCanyon = 1,
            KingdomValley = 2,
            City = 3,
            ChaosIsland = 4,
            RadicalHighway = 5,
            Num = 6,
            Invalid = -1,
            WhiteSpace = 8,
        };

        Value stageID;
        Value zoneID;
        heur::rfl::AppearGateParams gateParams[5];
        hh::game::ObjectId navShortcutCam;
        float navShortcutCamTime;
        csl::math::Vector3 navShortcuthalfExtents;
        csl::math::Vector3 navShortcutColliderOffset;
        csl::math::Vector3 halfExtents;
        csl::math::Vector3 colliderOffset;
        float scale;
        int8_t maxKeyCount;
        hh::game::ObjectId dGear;
        csl::ut::MoveArray<hh::game::ObjectId> naviEventColl;
        hh::game::ObjectId middleNavigationLocator;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossGateSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossGateSpawner* pInstance);
        static void Clean(ObjBossGateSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjBossGateKeySpawner {
        enum class Value : int8_t {
            SpaceColonyARK_ACT1 = 0,
            SpaceColonyARK_ACT2 = 1,
            BossBiolizard = 2,
            RailCanyon_ACT1 = 3,
            RailCanyon_ACT2 = 4,
            KingdomValley_ACT1 = 5,
            KingdomValley_ACT2 = 6,
            BossMetalOverload = 7,
            City_ACT1 = 8,
            City_ACT2 = 9,
            ChaosIsland_ACT1 = 10,
            ChaosIsland_ACT2 = 11,
            BossMephiles = 12,
            RadicalHighway_ACT1 = 13,
            RadicalHighway_ACT2 = 14,
            BossPerfectBlackDoom = 15,
            Num = 16,
            Invalid = -1,
        };

        Value stageID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjBossGateKeySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjBossGateKeySpawner* pInstance);
        static void Clean(ObjBossGateKeySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCaveVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCaveVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCaveVolumeSpawner* pInstance);
        static void Clean(ObjCaveVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChallengeGateMissionNotesSpawner {
        enum class NotesColor : int8_t {
            Blue = 0,
            Yellow = 1,
        };

        enum class ResourceType : int8_t {
            Blue = 0,
            Green = 1,
            Yellow = 2,
            RESOURCE_MAX = 3,
        };

        csl::ut::VariableString pathName;
        float pathMoveSpeed;
        float speedToPath;
        float time;
        NotesColor notesColor;
        bool isWating;
        float waitRange;
        hh::game::ObjectId targetCam;
        float preMoveTime;
        float preMoveWaitCamTime;
        bool eventDriven;
        csl::math::Vector3 normalGoalPos;
        bool isEclipse;
        ResourceType CollectionItemBoxType;
        int32_t CollectionItemBoxID;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChallengeGateMissionNotesSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChallengeGateMissionNotesSpawner* pInstance);
        static void Clean(ObjChallengeGateMissionNotesSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChallengeGateSpawner {
        enum class Value : int8_t {
            Ring1 = 0,
            Rings = 1,
            DashRing = 2,
            Enemy = 3,
            TimeStop = 4,
            Gimmick = 5,
            ChaosSpear = 6,
            DSurf = 7,
            DAmoeba = 8,
            Num = 9,
            Invalid = -1,
        };

        Value stageID;
        Value challengeID;
        hh::game::ObjectId targetNotes;
        float scale;
        csl::math::Vector3 halfExtents;
        csl::math::Vector3 colliderOffset;
        Value iconKind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChallengeGateSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChallengeGateSpawner* pInstance);
        static void Clean(ObjChallengeGateSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjChallengeGateEclipseSpawner {
        enum class Value : int8_t {
            Ring1 = 0,
            Rings = 1,
            DashRing = 2,
            Enemy = 3,
            TimeStop = 4,
            Gimmick = 5,
            ChaosSpear = 6,
            DSurf = 7,
            DAmoeba = 8,
            Num = 9,
            Invalid = -1,
        };

        Value stageID;
        Value iconKind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjChallengeGateEclipseSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjChallengeGateEclipseSpawner* pInstance);
        static void Clean(ObjChallengeGateEclipseSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceClockSpawner {
        enum class ClockType : int8_t {
            Black = 0,
            Blue = 1,
            Yellow = 2,
            Red = 3,
            TYPE_MAX = 4,
        };

        ClockType type;
        bool skyBeamOn;
        bool getEffectOn;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceClockSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceClockSpawner* pInstance);
        static void Clean(ObjWhiteSpaceClockSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionBalloonVolumeSpawner {
        enum class CollectionMode : int8_t {
            Art = 0,
            Movie = 1,
            Sound = 2,
            Character = 3,
            History = 4,
            GeraldNote = 5,
            Num = 6,
            None = -1,
        };

        CollectionMode collectionMode;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionBalloonVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionBalloonVolumeSpawner* pInstance);
        static void Clean(ObjCollectionBalloonVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionBikeSpawner {
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionBikeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionBikeSpawner* pInstance);
        static void Clean(ObjCollectionBikeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionFlickySpawner {
        float scale;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionFlickySpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionFlickySpawner* pInstance);
        static void Clean(ObjCollectionFlickySpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionRoomLocatorSpawner {
        enum class CollectionMode : int8_t {
            Art = 0,
            Movie = 1,
            Sound = 2,
            Character = 3,
            History = 4,
            GeraldNote = 5,
            Num = 6,
            None = -1,
        };

        CollectionMode collectionMode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionRoomLocatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionRoomLocatorSpawner* pInstance);
        static void Clean(ObjCollectionRoomLocatorSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjCollectionItemBoxSpawner {
        enum class ResourceType : int8_t {
            Blue = 0,
            Green = 1,
            Yellow = 2,
            RESOURCE_MAX = 3,
        };

        enum class Value : int8_t {
            Random = 0,
            TypeA = 1,
            TypeB = 2,
            TypeC = 3,
            TypeD = 4,
            Num = 5,
            Default = 0,
            Invalid = -1,
        };

        ResourceType type;
        int32_t boxID;
        Value itemPointType;
        int32_t gearCount;
        bool inCave;
        bool isEclipse;
        bool isEventDriven;
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjCollectionItemBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjCollectionItemBoxSpawner* pInstance);
        static void Clean(ObjCollectionItemBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDGearSpawner {
        enum class Value : int8_t {
            Invalid = -1,
            MultiSpear = 0,
            Blow = 1,
            Surf = 2,
            Amoeba = 3,
            Wing = 4,
            Num = 5,
        };

        Value type;
        hh::game::ObjectId targetCam;
        float easeTime;
        bool bIsSave;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDGearSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDGearSpawner* pInstance);
        static void Clean(ObjDGearSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDoomZoneSwitchSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDoomZoneSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDoomZoneSwitchSpawner* pInstance);
        static void Clean(ObjDoomZoneSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjDPowerSealedStandSpawner {
        enum class Value : int8_t {
            Invalid = -1,
            MultiSpear = 0,
            Blow = 1,
            Surf = 2,
            Amoeba = 3,
            Wing = 4,
            Num = 5,
        };

        Value actionType;
        hh::game::ObjectId targetCam;
        hh::game::ObjectId warpLocator;
        float dsurfCollisionYOffset;
        csl::ut::VariableString guidePathName;
        hh::game::ObjectId clearWarpLocator;
        hh::game::ObjectId ditemCam;
        hh::game::ObjectId cameraActivator;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjDPowerSealedStandSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjDPowerSealedStandSpawner* pInstance);
        static void Clean(ObjDPowerSealedStandSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEventFinishCameraApplierSpawner {
        int8_t cutScene;
        hh::game::ObjectId targetCamera;
        float waitTime;
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEventFinishCameraApplierSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEventFinishCameraApplierSpawner* pInstance);
        static void Clean(ObjEventFinishCameraApplierSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjLargeCrestSpawner {
        float angularVelocityLimit;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjLargeCrestSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjLargeCrestSpawner* pInstance);
        static void Clean(ObjLargeCrestSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceNavigationPillarSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceNavigationPillarSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceNavigationPillarSpawner* pInstance);
        static void Clean(ObjWhiteSpaceNavigationPillarSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjStageGateSpawner {
        enum class Value : int8_t {
            SpaceColonyARK = 0,
            RailCanyon = 1,
            KingdomValley = 2,
            City = 3,
            ChaosIsland = 4,
            RadicalHighway = 5,
            Num = 6,
            Invalid = -1,
            WhiteSpace = 8,
        };

        Value stageID;
        Value zoneID;
        float scale;
        csl::math::Vector3 halfExtents;
        csl::math::Vector3 colliderOffset;
        hh::game::ObjectId dGear;
        hh::game::ObjectId camera;
        hh::game::ObjectId stageUICamera;
        hh::game::ObjectId productionCamera;
        float viewTime;
        hh::game::ObjectId dPowerSealedStand;
        hh::game::ObjectId bigId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjStageGateSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjStageGateSpawner* pInstance);
        static void Clean(ObjStageGateSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjSwitchSetLayerSpawner {
        enum class Visual : int8_t {
            NORMAL = 0,
            ISL = 1,
        };

        Visual visual;
        bool usedRigidCol;
        bool eventDriven;
        csl::ut::VariableString activeLayerName[5];
        csl::ut::VariableString nonActiveLayerName[5];
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjSwitchSetLayerSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjSwitchSetLayerSpawner* pInstance);
        static void Clean(ObjSwitchSetLayerSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjTerrainPartsSpawner {
        float scale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjTerrainPartsSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjTerrainPartsSpawner* pInstance);
        static void Clean(ObjTerrainPartsSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjAmoebaPassBoxSpawner {
        enum class Type : int8_t {
            NORMAL = 0,
            TOPGRATING = 1,
        };

        Type m_type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjAmoebaPassBoxSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjAmoebaPassBoxSpawner* pInstance);
        static void Clean(ObjAmoebaPassBoxSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceDestructibleWallSpawner : heur::rfl::ObjDestructibleWallSpawner {
        int32_t no;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceDestructibleWallSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceDestructibleWallSpawner* pInstance);
        static void Clean(ObjWhiteSpaceDestructibleWallSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceGeraldNoteSpawner {
        int32_t m_objNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceGeraldNoteSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceGeraldNoteSpawner* pInstance);
        static void Clean(ObjWhiteSpaceGeraldNoteSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceGratingSpawner {
        enum class GratingType : int8_t {
            Arch = 0,
            Square = 1,
            BetweenPillar = 2,
            MAX_GRATINGTYPE = 3,
        };

        GratingType type;
        bool useNavigation;
        bool isShortcut;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceGratingSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceGratingSpawner* pInstance);
        static void Clean(ObjWhiteSpaceGratingSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceSpearSwitchSpawner {
        float scale;
        float radius;
        csl::math::Vector3 offset;
        bool enableInTutorial;
        heur::rfl::ActionNotification actions[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceSpearSwitchSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceSpearSwitchSpawner* pInstance);
        static void Clean(ObjWhiteSpaceSpearSwitchSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceSpringSpawner : heur::rfl::ObjSpringSpawner {
        int32_t no;
        bool reverseSaveState;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceSpringSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceSpringSpawner* pInstance);
        static void Clean(ObjWhiteSpaceSpringSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceSwitchUsualSpawner : heur::rfl::ObjSwitchUsualSpawner {
        int32_t no;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceSwitchUsualSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceSwitchUsualSpawner* pInstance);
        static void Clean(ObjWhiteSpaceSwitchUsualSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWingTutorialFailedVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWingTutorialFailedVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWingTutorialFailedVolumeSpawner* pInstance);
        static void Clean(ObjWingTutorialFailedVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWingTutorialGoalVolumeSpawner {
        heur::rfl::VolumeTriggerSpawner volume;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWingTutorialGoalVolumeSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWingTutorialGoalVolumeSpawner* pInstance);
        static void Clean(ObjWingTutorialGoalVolumeSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraBattleParameter {
        float distance;
        float distanceSuspensionK;
        float elevationOffset;
        float azimuthMinOffset;
        float azimuthMaxOffset;
        float azimuthMinOffsetDistance;
        float azimuthMaxOffsetDistance;
        float azimuthSensitivity;
        float targetOffsetSuspensionK;
        float targetMinUpOffset;
        float targetMaxUpOffset;
        float targetFrontOffset;
        float delayAllowDistance;
        float delayLimitDistance;
        float delaySuspensionK;
        float manualControlTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraBattleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraBattleParameter* pInstance);
        static void Clean(StandardCameraBattleParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraCommonParameter {
        float distance;
        float distanceSuspensionK;
        float minElevation;
        float maxElevation;
        float azimuthSensitivity;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float elevationOffset;
        float targetUpOffset;
        float targetMinUpOffsetLimit;
        float targetMaxUpOffsetLimit;
        float targetMinUpOffsetLimitDistance;
        float targetMaxUpOffsetLimitDistance;
        float targetOffsetSuspensionK;
        float delayAllowDistance;
        float delayLimitDistance;
        float delaySuspensionK;
        float autocontrolDisabledTime;
        float chaseSegmentSuspensionK;
        float chaseSegmentShortenSpeed;
        int32_t chaseSegmentMaxCount;
        float inertiaMinDecel;
        float inertiaOvershootAngle;
        float resetSuspensionK;
        float downDirectionDotThreshold;
        float baseUpLeanRate;
        bool disableRotationControl;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraCommonParameter* pInstance);
        static void Clean(StandardCameraCommonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraDashParameter {
        float minDistance;
        float maxDistance;
        float minDistanceAccel;
        float maxDistanceAccel;
        float distanceSuspensionK;
        float elevationOffset;
        float azimuthSensitivity;
        float targetOffsetSuspensionK;
        float targetUpOffset;
        float delayAllowDistance;
        float delayLimitDistance;
        float delaySuspensionK;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraDashParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraDashParameter* pInstance);
        static void Clean(StandardCameraDashParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraCyloopParameter {
        float minDistance;
        float maxDistance;
        float elevationOffset;
        float azimuthSensitivity;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float targetUpOffset;
        float minDelayLimitDistance;
        float maxDelayLimitDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraCyloopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraCyloopParameter* pInstance);
        static void Clean(StandardCameraCyloopParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraLockonParameter {
        float distance;
        float minElevation;
        float maxElevation;
        float elevationOffset;
        float minElevationCyloop;
        float maxElevationCyloop;
        float elevationOffsetCyloop;
        float targetUpOffset;
        float delayAllowDistance;
        float delayLimitDistance;
        float delaySuspensionK;
        float panningSuspensionK;
        float interiorPanningDistance;
        float interiorPanningSuspensionK;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraLockonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraLockonParameter* pInstance);
        static void Clean(StandardCameraLockonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraWallParameter {
        float distance;
        float targetUpOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraWallParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraWallParameter* pInstance);
        static void Clean(StandardCameraWallParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraLoopParameter {
        float azimuthSensitivity;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float targetUpOffset;
        float baseUpLeanRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraLoopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraLoopParameter* pInstance);
        static void Clean(StandardCameraLoopParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraSurfParameter {
        float azimuthSensitivity;
        float elevationUpSensitivity;
        float elevationDownSensitivity;
        float targetUpOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraSurfParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraSurfParameter* pInstance);
        static void Clean(StandardCameraSurfParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraOptionParameter {
        float minManualRotationSpeed;
        float maxManualRotationSpeed;
        float minMouseRotationRate;
        float maxMouseRotationRate;
        float minDistanceScale;
        float maxDistanceScale;
        float maxElevationAddOffset;
        float minTargetUpOffsetScale;
        float maxTargetUpOffsetScale;
        float minFovyRate;
        float minLimitFovy;
        float minFovyScale;
        float maxFovyScale;
        bool bIsActiveOption;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraOptionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraOptionParameter* pInstance);
        static void Clean(StandardCameraOptionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct StandardCameraConfig {
        heur::rfl::StandardCameraCommonParameter common;
        heur::rfl::StandardCameraDashParameter dash;
        heur::rfl::StandardCameraCyloopParameter cyloop;
        heur::rfl::StandardCameraCyloopParameter cyloopSnipe;
        heur::rfl::StandardCameraLockonParameter lockon;
        heur::rfl::StandardCameraWallParameter wall;
        heur::rfl::StandardCameraLoopParameter loop;
        heur::rfl::StandardCameraBattleParameter battle;
        heur::rfl::StandardCameraSurfParameter surf;
        heur::rfl::StandardCameraOptionParameter option;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StandardCameraConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StandardCameraConfig* pInstance);
        static void Clean(StandardCameraConfig* pInstance);
    };
}

namespace heur::rfl {
    struct CameraShakeRecord {
        enum class ShakeType : uint8_t {
            Directional = 0,
            WorldY = 1,
            Random = 2,
        };

        csl::ut::VariableString name;
        ShakeType type;
        float zRot;
        float duration;
        float frequency;
        float amplitude;
        float timeAttenuationRate;
        bool enableDistanceAttenuation;
        float attenuationDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CameraShakeRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CameraShakeRecord* pInstance);
        static void Clean(CameraShakeRecord* pInstance);
    };
}

namespace heur::rfl {
    struct EventCameraShakeRecord {
        enum class ShakeType : uint8_t {
            LocalX = 0,
            LocalY = 1,
            LocalZ = 2,
        };

        csl::ut::VariableString name;
        ShakeType type;
        float duration;
        float scale;
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EventCameraShakeRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EventCameraShakeRecord* pInstance);
        static void Clean(EventCameraShakeRecord* pInstance);
    };
}

namespace heur::rfl {
    struct CameraShakeTable {
        heur::rfl::CameraShakeRecord records[74];
        heur::rfl::EventCameraShakeRecord eventRecords[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CameraShakeTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CameraShakeTable* pInstance);
        static void Clean(CameraShakeTable* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionItemInfo {
        enum class OpenState : int32_t {
            Locked = 0,
            LockedCollectionBox = 1,
            Opened = 2,
            DLC_DDX = 3,
        };

        bool isEnable;
        OpenState openState;
        int32_t textLabelNumber;
        int32_t textureNumber;
        int32_t objNumber;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionItemInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionItemInfo* pInstance);
        static void Clean(CollectionItemInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionArtInfo {
        heur::rfl::CollectionItemInfo info;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionArtInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionArtInfo* pInstance);
        static void Clean(CollectionArtInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionCharacterInfo {
        enum class CollectionCharaKind : int32_t {
            CollectionCharaKindShadow = 0,
            CollectionCharaKindOmega = 1,
            CollectionCharaKindBig = 2,
            CollectionCharaKindMaria = 3,
            CollectionCharaKindGerald = 4,
            CollectionCharaKindOrbot = 5,
            CollectionCharaKindCubot = 6,
            CollectionCharaKindNum = 7,
            CollectionCharaKindNone = -1,
        };

        heur::rfl::CollectionItemInfo info;
        CollectionCharaKind charaKind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionCharacterInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionCharacterInfo* pInstance);
        static void Clean(CollectionCharacterInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionCharacterModelParam {
        csl::math::Vector3 modelPos;
        csl::math::Vector3 cameraPos;
        csl::math::Vector3 cameraTarget;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionCharacterModelParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionCharacterModelParam* pInstance);
        static void Clean(CollectionCharacterModelParam* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionCharacterMenuParam {
        float turnSpeed;
        heur::rfl::CollectionCharacterModelParam charaModelParams[7];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionCharacterMenuParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionCharacterMenuParam* pInstance);
        static void Clean(CollectionCharacterMenuParam* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionGeraldNoteInfo {
        heur::rfl::CollectionItemInfo info;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionGeraldNoteInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionGeraldNoteInfo* pInstance);
        static void Clean(CollectionGeraldNoteInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionGeraldNotePlayer {
        float moveSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionGeraldNotePlayer* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionGeraldNotePlayer* pInstance);
        static void Clean(CollectionGeraldNotePlayer* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionHistoryInfo {
        heur::rfl::CollectionItemInfo info;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionHistoryInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionHistoryInfo* pInstance);
        static void Clean(CollectionHistoryInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionMovieInfo {
        heur::rfl::CollectionItemInfo info;
        csl::ut::VariableString assetName;
        bool isEclipseMode;
        int32_t wsLevel;
        int32_t eyeCount;
        bool fps30;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionMovieInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionMovieInfo* pInstance);
        static void Clean(CollectionMovieInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionSoundInfo {
        heur::rfl::CollectionItemInfo info;
        csl::ut::VariableString assetName;
        int32_t playTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionSoundInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionSoundInfo* pInstance);
        static void Clean(CollectionSoundInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionRoomPlayerAction {
        float moveSpeed;
        float tolerance;
        float chairTolerance;
        float chairStartWaitTime;
        float chairStartMoveTime;
        float chairStartPosOffsetY;
        float chairEndWaitTime;
        float chairEndMoveTime;
        float chairEndMoveDistance;
        float bikeTolerance;
        float bikeStartWaitTime;
        float bikeStartMoveTime;
        float bikeStartMenuOpenWait;
        float bikeStartPosOffsetY;
        float bikeEndWaitTime;
        float bikeEndMoveTime;
        float bikeEndMoveDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionRoomPlayerAction* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionRoomPlayerAction* pInstance);
        static void Clean(CollectionRoomPlayerAction* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionRoomCamera {
        float beginInterpolateTime;
        float endInterpolateTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionRoomCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionRoomCamera* pInstance);
        static void Clean(CollectionRoomCamera* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionSoundMenuParam {
        float endFadeTime;
        float endWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionSoundMenuParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionSoundMenuParam* pInstance);
        static void Clean(CollectionSoundMenuParam* pInstance);
    };
}

namespace heur::rfl {
    struct CollectionParamter {
        heur::rfl::CollectionArtInfo artInfos[121];
        heur::rfl::CollectionSoundInfo soundInfos[100];
        heur::rfl::CollectionMovieInfo movieInfos[30];
        heur::rfl::CollectionCharacterInfo charaInfos[7];
        heur::rfl::CollectionHistoryInfo historyInfos[11];
        heur::rfl::CollectionGeraldNoteInfo noteInfos[28];
        heur::rfl::CollectionCharacterMenuParam charaMenuParam;
        heur::rfl::CollectionRoomPlayerAction roomActionParam;
        heur::rfl::CollectionGeraldNotePlayer notePlayerParam;
        heur::rfl::CollectionRoomCamera artCamera;
        heur::rfl::CollectionRoomCamera soundCamera;
        heur::rfl::CollectionRoomCamera movieCamera;
        heur::rfl::CollectionRoomCamera charaCamera;
        heur::rfl::CollectionRoomCamera historyCamera;
        heur::rfl::CollectionRoomCamera noteCamera;
        heur::rfl::CollectionSoundMenuParam soundMenuParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionParamter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionParamter* pInstance);
        static void Clean(CollectionParamter* pInstance);
    };
}

namespace heur::rfl {
    struct AddDatabaseInfo {
        uint8_t recordNo;
        uint8_t numRecords;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AddDatabaseInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AddDatabaseInfo* pInstance);
        static void Clean(AddDatabaseInfo* pInstance);
    };
}

namespace heur::rfl {
    struct ContentParameter {
        heur::rfl::AddDatabaseInfo databases[2];
        csl::ut::VariableString stagedata;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ContentParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ContentParameter* pInstance);
        static void Clean(ContentParameter* pInstance);
    };
}

namespace heur::rfl {
    struct CreditBGInfo {
        csl::ut::VariableString bgName;
        float displayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CreditBGInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CreditBGInfo* pInstance);
        static void Clean(CreditBGInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CreditItemInfo {
        enum class CreditItemKind : int8_t {
            Empty = 0,
            Category = 1,
            Post = 2,
            Name = 3,
            Logo = 4,
            Num = 5,
        };

        CreditItemKind creditItemKind;
        uint8_t numItems;
        bool isLastItem;
        csl::ut::VariableString str[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CreditItemInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CreditItemInfo* pInstance);
        static void Clean(CreditItemInfo* pInstance);
    };
}

namespace heur::rfl {
    struct CreditParamter {
        float blackBGTime;
        float emptySize;
        float creditTime;
        float finishInterval;
        float guideDisplayTime;
        float lastItemStopHeight;
        float bgmDelay;
        float bgmFadeOutTime;
        csl::ut::VariableString unclearBGMName;
        csl::ut::VariableString bgmName;
        heur::rfl::CreditItemInfo itemInfos[2048];
        heur::rfl::CreditBGInfo bgInfos[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CreditParamter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CreditParamter* pInstance);
        static void Clean(CreditParamter* pInstance);
    };
}

namespace heur::rfl {
    struct Record {
        uint8_t no;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Record* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Record* pInstance);
        static void Clean(Record* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyAttackRecord : heur::rfl::Record {
        csl::ut::VariableString name;
        int32_t damage;
        float velocityX;
        float velocityY;
        csl::ut::VariableString hitStopName;
        csl::ut::VariableString cameraShakeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyAttackRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyAttackRecord* pInstance);
        static void Clean(EnemyAttackRecord* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyAttackRecordBaseTable {
        heur::rfl::EnemyAttackRecord data[192];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyAttackRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyAttackRecordBaseTable* pInstance);
        static void Clean(EnemyAttackRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyAttackRecordTable {
        heur::rfl::EnemyAttackRecord data[192];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyAttackRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyAttackRecordTable* pInstance);
        static void Clean(EnemyAttackRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDefenceRecord : heur::rfl::Record {
        csl::ut::VariableString name;
        float baseRate;
        float stunRate;
        float staggerRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDefenceRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDefenceRecord* pInstance);
        static void Clean(EnemyDefenceRecord* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDefenceRecordBaseTable {
        heur::rfl::EnemyDefenceRecord data[64];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDefenceRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDefenceRecordBaseTable* pInstance);
        static void Clean(EnemyDefenceRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyDefenceRecordTable {
        heur::rfl::EnemyDefenceRecord data[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyDefenceRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyDefenceRecordTable* pInstance);
        static void Clean(EnemyDefenceRecordTable* pInstance);
    };
}

namespace heur::rfl {
    struct DLCParameter {
        uint8_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DLCParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DLCParameter* pInstance);
        static void Clean(DLCParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisParameter {
        int32_t m_maxNumPieces;
        float gravity;
        float lifeTime;
        float force;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisParameter* pInstance);
        static void Clean(DebrisParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldOutsideBoxSplineSetupParameter : heur::rfl::GravityFieldOutsideCylinderSplineSetupParameter {
        csl::math::Vector3 extents;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldOutsideBoxSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldOutsideBoxSplineSetupParameter* pInstance);
        static void Clean(GravityFieldOutsideBoxSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GravityFieldOutsideHalfCylinderBoxSplineSetupParameter : heur::rfl::GravityFieldOutsideCylinderSplineSetupParameter {
        csl::math::Vector3 extents;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GravityFieldOutsideHalfCylinderBoxSplineSetupParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GravityFieldOutsideHalfCylinderBoxSplineSetupParameter* pInstance);
        static void Clean(GravityFieldOutsideHalfCylinderBoxSplineSetupParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DevConfigParameters {
        enum class ReplayMode : int8_t {
            REPLAY_MODE_OFF = 0,
            REPLAY_MODE_RECORD = 1,
            REPLAY_MODE_PLAY = 2,
            REPLAY_MODE_GHOST = 3,
        };

        bool autoSaveEnabled;
        bool gismoEnabled;
        bool reportEnabled;
        bool creditsEnabled;
        ReplayMode replayMode;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DevConfigParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DevConfigParameters* pInstance);
        static void Clean(DevConfigParameters* pInstance);
    };
}

namespace heur::rfl {
    struct HeightFieldConfigData {
        enum class LayerType : int8_t {
            LAYER_NONE = 0,
            LAYER_SOLID = 1,
            LAYER_LIQUID = 2,
            LAYER_THROUGH = 3,
            LAYER_CAMERA = 4,
            LAYER_SOLID_ONEWAY = 5,
            LAYER_SOLID_THROUGH = 6,
            LAYER_SOLID_TINY = 7,
            LAYER_SOLID_DETAIL = 8,
            LAYER_SOLID_MESH = 9,
            LAYER_LAND = 10,
            LAYER_RAYBLOCK = 11,
            LAYER_EVENT = 12,
            LAYER_RAYBLOCK_ENEMY = 13,
            LAYER_ENEMY_BODY = 14,
            LAYER_PLAYER = 15,
            LAYER_ENEMY = 16,
            LAYER_OBJECT_BODY = 17,
            LAYER_GIMMICK = 18,
            LAYER_DYNAMICS = 19,
            LAYER_RING = 20,
            LAYER_CHARACTER_CONTROL = 21,
            LAYER_PLAYER_ONLY = 22,
            LAYER_DYNAMICS_THROUGH = 23,
            LAYER_ENEMY_ONLY = 24,
            LAYER_SENSOR_PLAYER = 25,
            LAYER_SENSOR_RING = 26,
            LAYER_SENSOR_GIMMICK = 27,
            LAYER_SENSOR_LAND = 28,
            LAYER_SENSOR_ALL = 29,
            LAYER_SENSOR_PLAYER_ENEMY = 30,
            LAYER_RESERVED31 = 31,
        };

        enum class MaterialType : int8_t {
            MAT_NONE = 0,
            MAT_STONE = 1,
            MAT_EARTH = 2,
            MAT_WOOD = 3,
            MAT_GRASS = 4,
            MAT_IRON = 5,
            MAT_SAND = 6,
            MAT_LAVA = 7,
            MAT_GLASS = 8,
            MAT_SNOW = 9,
            MAT_NO_ENTRY = 10,
            MAT_ICE = 11,
            MAT_WATER = 12,
            MAT_SEA = 13,
            MAT_DAMAGE = 14,
            MAT_DEAD = 15,
            MAT_FLOWER0 = 16,
            MAT_FLOWER1 = 17,
            MAT_FLOWER2 = 18,
            MAT_AIR = 19,
            MAT_DEADLEAVES = 20,
            MAT_WIREMESH = 21,
            MAT_DEAD_ANYDIR = 22,
            MAT_DAMAGE_THROUGH = 23,
            MAT_DRY_GRASS = 24,
            MAT_RELIC = 25,
            MAT_GIANT = 26,
            MAT_GRAVEL = 27,
            MAT_MUD_WATER = 28,
            MAT_WET3 = 29,
            MAT_WET4 = 30,
            MAT_WET1 = 31,
            MAT_WET2 = 32,
        };

        LayerType layer;
        MaterialType material;
        bool notStand;
        bool wall;
        bool parkour;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HeightFieldConfigData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HeightFieldConfigData* pInstance);
        static void Clean(HeightFieldConfigData* pInstance);
    };
}

namespace heur::rfl {
    struct HeightFieldConfig {
        heur::rfl::HeightFieldConfigData data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HeightFieldConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HeightFieldConfig* pInstance);
        static void Clean(HeightFieldConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BakeBoxParameter {
        csl::ut::VariableString name;
        csl::math::Vector3 center;
        csl::math::Vector3 halfExtents;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BakeBoxParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BakeBoxParameter* pInstance);
        static void Clean(BakeBoxParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BakeCameraParameter {
        csl::ut::VariableString name;
        csl::ut::MoveArray<heur::rfl::BakeCameraParameter> data;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BakeCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BakeCameraParameter* pInstance);
        static void Clean(BakeCameraParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BakeCameraParameterData {
        csl::math::Vector3 target;
        csl::math::Vector3 eye;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BakeCameraParameterData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BakeCameraParameterData* pInstance);
        static void Clean(BakeCameraParameterData* pInstance);
    };
}

namespace heur::rfl {
    struct FixedNoteData {
        csl::ut::VariableString pathName;
        int32_t id;
        float moveSpeed;
        float respawnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FixedNoteData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FixedNoteData* pInstance);
        static void Clean(FixedNoteData* pInstance);
    };
}

namespace heur::rfl {
    struct GameChallengeAnnihilationData {
        csl::ut::VariableString targetIDs[8];
        int32_t clearAnnihilationNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameChallengeAnnihilationData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameChallengeAnnihilationData* pInstance);
        static void Clean(GameChallengeAnnihilationData* pInstance);
    };
}

namespace heur::rfl {
    struct GameChallengeCollectionData {
        int32_t clearCollectionNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameChallengeCollectionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameChallengeCollectionData* pInstance);
        static void Clean(GameChallengeCollectionData* pInstance);
    };
}

namespace heur::rfl {
    struct ResultChallengeParam {
        float timeRankS;
        float timeRankA;
        float timeRankB;
        float timeRankC;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ResultChallengeParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ResultChallengeParam* pInstance);
        static void Clean(ResultChallengeParam* pInstance);
    };
}

namespace heur::rfl {
    struct GameChallengeTouchData {
        csl::ut::VariableString targetIDs[8];
        int32_t clearTouchNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameChallengeTouchData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameChallengeTouchData* pInstance);
        static void Clean(GameChallengeTouchData* pInstance);
    };
}

namespace heur::rfl {
    struct GameChallengeData {
        enum class ChallengeType : uint8_t {
            Ring = 0,
            OneRing = 1,
            TargetAnnihilation = 2,
            ChaosControllMaster = 3,
            CleaningSea = 4,
            DashRing = 5,
            ArcEscape = 6,
            BilliardBlow = 7,
            SpearRunner = 8,
            HighSpeedRailCanyon = 9,
            StoneLabyrinth = 10,
            DeathEggRobotPanic = 11,
            GondolaSurveyTeam = 12,
            Num = 13,
        };

        enum class IconType : int8_t {
            RING = 0,
            CLOCK = 1,
            ENEMYCHAOS = 2,
            ENEMYBEETLE = 3,
            OBJCHAOSSPEAR = 4,
            OBJDASHRING = 5,
            OBJSURFSPIN = 6,
            ENEMYEGGSTINGER = 7,
            ENEMYTWISTER = 8,
            None = 9,
            NUM = 10,
        };

        csl::ut::VariableString stageCode;
        ChallengeType challenge;
        IconType iconType;
        float limitTime;
        csl::ut::VariableString titleLabel;
        csl::ut::VariableString explainLabel;
        heur::rfl::ResultChallengeParam resultData;
        heur::rfl::GameChallengeCollectionData chalengeRingData;
        heur::rfl::GameChallengeAnnihilationData challengeAnnihilationData;
        heur::rfl::GameChallengeTouchData challengeTouchData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameChallengeData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameChallengeData* pInstance);
        static void Clean(GameChallengeData* pInstance);
    };
}

namespace heur::rfl {
    struct GameChallengeParameter {
        heur::rfl::GameChallengeData datas[32];
        heur::rfl::GameChallengeData hardChallenges[11];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameChallengeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameChallengeParameter* pInstance);
        static void Clean(GameChallengeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameCollectionGearData {
        enum class Color : int32_t {
            NotEarned = -1,
            Yellow = 0,
            Blue = 1,
            Green = 2,
            None = 3,
        };

        csl::ut::VariableString stageID;
        Color color[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameCollectionGearData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameCollectionGearData* pInstance);
        static void Clean(GameCollectionGearData* pInstance);
    };
}

namespace heur::rfl {
    struct GameCollectionGearParameter {
        heur::rfl::GameCollectionGearData Datas[64];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameCollectionGearParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameCollectionGearParameter* pInstance);
        static void Clean(GameCollectionGearParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameGrassInteractionParameterData {
        csl::ut::VariableString name;
        float radius;
        float height;
        float power;
        bool moveHitEnabled;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameGrassInteractionParameterData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameGrassInteractionParameterData* pInstance);
        static void Clean(GameGrassInteractionParameterData* pInstance);
    };
}

namespace heur::rfl {
    struct GameGrassInteractionParameter {
        heur::rfl::GameGrassInteractionParameterData data[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameGrassInteractionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameGrassInteractionParameter* pInstance);
        static void Clean(GameGrassInteractionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameGrindLodParameter {
        float distances[4];
        float cullingDistances[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameGrindLodParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameGrindLodParameter* pInstance);
        static void Clean(GameGrindLodParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameHitStopParameterData {
        csl::ut::VariableString name;
        float scale;
        float time;
        float easeOutTime;
        float delayTime;
        bool layerPlayer;
        bool layerEnemy;
        bool layerDamagedEnemy;
        bool layerGimmick;
        bool layerCamera;
        bool layerOthers;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameHitStopParameterData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameHitStopParameterData* pInstance);
        static void Clean(GameHitStopParameterData* pInstance);
    };
}

namespace heur::rfl {
    struct GameHitStopParameter {
        heur::rfl::GameHitStopParameterData data[64];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameHitStopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameHitStopParameter* pInstance);
        static void Clean(GameHitStopParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameLightGaugeParameterData {
        csl::ut::VariableString name;
        int32_t value;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameLightGaugeParameterData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameLightGaugeParameterData* pInstance);
        static void Clean(GameLightGaugeParameterData* pInstance);
    };
}

namespace heur::rfl {
    struct GameLightGaugeParameter {
        heur::rfl::GameLightGaugeParameterData data[80];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameLightGaugeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameLightGaugeParameter* pInstance);
        static void Clean(GameLightGaugeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ResultViewParam {
        float waitTimeStart;
        float waitTimeRing;
        float waitTimeRank;
        float waitTimeRankAS;
        float waitTimeNextRank;
        float waitTimeObj;
        float scoreChangeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ResultViewParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ResultViewParam* pInstance);
        static void Clean(ResultViewParam* pInstance);
    };
}

namespace heur::rfl {
    struct ResultScoreParam {
        csl::ut::VariableString stageCode;
        int32_t baseScore;
        int32_t coefTime;
        int32_t coefRing;
        int32_t ringScoreMax;
        int32_t scoreRankS;
        int32_t scoreRankA;
        int32_t scoreRankB;
        int32_t scoreRankC;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ResultScoreParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ResultScoreParam* pInstance);
        static void Clean(ResultScoreParam* pInstance);
    };
}

namespace heur::rfl {
    struct GameResultParameter {
        heur::rfl::ResultViewParam viewParam;
        heur::rfl::ResultScoreParam defaultScore;
        heur::rfl::ResultScoreParam stageScore[20];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameResultParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameResultParameter* pInstance);
        static void Clean(GameResultParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameVignetteCircleParameter {
        float centerX;
        float centerY;
        float scaleX;
        float scaleY;
        float scale;
        float rotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameVignetteCircleParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameVignetteCircleParameter* pInstance);
        static void Clean(GameVignetteCircleParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameVignetteLineParameter {
        float centerX;
        float centerY;
        float directionX;
        float directionY;
        float rotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameVignetteLineParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameVignetteLineParameter* pInstance);
        static void Clean(GameVignetteLineParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameVignetteParameter {
        enum class GradationMode : int8_t {
            GRADATION_MODE_CIRCLE = 0,
            GRADATION_MODE_LINE = 1,
        };

        enum class BlendMode : int8_t {
            BLEND_MODE_ALPHA_BLEND = 0,
            BLEND_MODE_ADD = 1,
            BLEND_MODE_MUL = 2,
            BLEND_MODE_SCREEN = 3,
            BLEND_MODE_OVERLAY = 4,
        };

        GradationMode gradationType;
        BlendMode blendMode;
        csl::math::Vector3 color;
        float opacity;
        heur::rfl::GameVignetteCircleParameter imageCircle;
        heur::rfl::GameVignetteLineParameter line;
        float penumbraScale;
        float intensity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameVignetteParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameVignetteParameter* pInstance);
        static void Clean(GameVignetteParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameTimeStopParameter {
        float scale;
        float physicsTimeScale;
        float shaderTimeScale;
        float grayColorScale;
        float easeOutTime;
        heur::rfl::GameVignetteParameter vignette;
        float vignetteTime;
        float vignetteEaseTimeMin;
        float vignetteEaseTimeMax;
        heur::rfl::GameVignetteParameter vignetteEnd1;
        heur::rfl::GameVignetteParameter vignetteEnd2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameTimeStopParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameTimeStopParameter* pInstance);
        static void Clean(GameTimeStopParameter* pInstance);
    };
}

namespace heur::rfl {
    struct GameUIBoostParam {
        float lossAnimRatio;
        float useAnimRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameUIBoostParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameUIBoostParam* pInstance);
        static void Clean(GameUIBoostParam* pInstance);
    };
}

namespace heur::rfl {
    struct GameUICursorParam {
        float targetCursorOffsetY;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameUICursorParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameUICursorParam* pInstance);
        static void Clean(GameUICursorParam* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceStageUIModelParam {
        csl::math::Vector3 modelPos;
        csl::math::Vector3 cameraPos;
        csl::math::Vector3 cameraTarget;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceStageUIModelParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceStageUIModelParam* pInstance);
        static void Clean(WhiteSpaceStageUIModelParam* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceStageUI {
        heur::rfl::WhiteSpaceStageUIModelParam modelParam;
        heur::rfl::WhiteSpaceStageUIModelParam dwingModelParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceStageUI* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceStageUI* pInstance);
        static void Clean(WhiteSpaceStageUI* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceQAPage {
        csl::ut::VariableString headerLabel;
        csl::ut::VariableString textLabel;
        csl::ut::VariableString movieName;
        csl::ut::VariableString textureName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceQAPage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceQAPage* pInstance);
        static void Clean(WhiteSpaceQAPage* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceQAInfo {
        enum class OpenState : int32_t {
            Locked = 0,
            Opened = 1,
        };

        bool enable;
        OpenState openState;
        heur::rfl::WhiteSpaceQAPage pages[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceQAInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceQAInfo* pInstance);
        static void Clean(WhiteSpaceQAInfo* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceQAParamter {
        heur::rfl::WhiteSpaceQAInfo infos[40];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceQAParamter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceQAParamter* pInstance);
        static void Clean(WhiteSpaceQAParamter* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceMapUI {
        float mapZoomScale;
        float mapUnderGroundZoomScale;
        float mapScale;
        float mapZoomAnimRatio;
        float mapZoomRangeX;
        float mapZoomRangeY;
        csl::math::Vector3 mapUnderGroundPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceMapUI* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceMapUI* pInstance);
        static void Clean(WhiteSpaceMapUI* pInstance);
    };
}

namespace heur::rfl {
    struct GameUIWhiteSpaceParam {
        float itemInfoTimer;
        heur::rfl::WhiteSpaceStageUI stageUIParam;
        heur::rfl::WhiteSpaceQAParamter qaParam;
        heur::rfl::WhiteSpaceMapUI mapParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameUIWhiteSpaceParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameUIWhiteSpaceParam* pInstance);
        static void Clean(GameUIWhiteSpaceParam* pInstance);
    };
}

namespace heur::rfl {
    struct GameUIParameter {
        heur::rfl::GameUIBoostParam boostParam;
        heur::rfl::GameUICursorParam cursorParam;
        heur::rfl::GameUIWhiteSpaceParam whiteSpaceParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameUIParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameUIParameter* pInstance);
        static void Clean(GameUIParameter* pInstance);
    };
}

namespace heur::rfl {
    struct PathData {
        csl::ut::VariableString pathName;
        float moveSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PathData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PathData* pInstance);
        static void Clean(PathData* pInstance);
    };
}

namespace heur::rfl {
    struct GeraldNoteRflParam {
        heur::rfl::PathData pathList[3];
        int32_t idlist[8];
        float respawnTime;
        heur::rfl::FixedNoteData fixedData[3];
        heur::rfl::FixedNoteData eclipsFixedData[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GeraldNoteRflParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GeraldNoteRflParam* pInstance);
        static void Clean(GeraldNoteRflParam* pInstance);
    };
}

namespace heur::rfl {
    struct RankingKindParam {
        enum class RankingId : int32_t {
            ShadowRankingTest = 0,
            SSpaceColonyArkAct1 = 1,
            SSpaceColonyArkAct1DWing = 2,
            SSpaceColonyArkAct2 = 3,
            SSpaceColonyArkAct2DWing = 4,
            SRailCanyonAct1 = 5,
            SRailCanyonAct1DWing = 6,
            SRailCanyonAct2 = 7,
            SRailCanyonAct2DWing = 8,
            SKingdomValleyAct1 = 9,
            SKingdomValleyAct1DWing = 10,
            SKingdomValleyAct2 = 11,
            SKingdomValleyAct2DWing = 12,
            SCityAct1 = 13,
            SCityAct1DWing = 14,
            SCityAct2 = 15,
            SCityAct2DWing = 16,
            SChaosIslandAct1 = 17,
            SChaosIslandAct1DWing = 18,
            SChaosIslandAct2 = 19,
            SChaosIslandAct2DWing = 20,
            SRadicalHighwayAct1 = 21,
            SRadicalHighwayAct1DWing = 22,
            SRadicalHighwayAct2 = 23,
            SRadicalHighwayAct2DWing = 24,
            RANKINGID_END = 25,
            RANKINGID_START = 1,
            RANKINGID_ACT_NUM = 25,
        };

        RankingId rankingId;
        bool valid;
        uint32_t minTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RankingKindParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RankingKindParam* pInstance);
        static void Clean(RankingKindParam* pInstance);
    };
}

namespace heur::rfl {
    struct RankingRflParam {
        heur::rfl::RankingKindParam rankingKindInfos[25];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RankingRflParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RankingRflParam* pInstance);
        static void Clean(RankingRflParam* pInstance);
    };
}

namespace heur::rfl {
    struct TimeServiceParam {
        float speed;
        float timeMagnification;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TimeServiceParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TimeServiceParam* pInstance);
        static void Clean(TimeServiceParam* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherBlockParameter {
        uint8_t blockWeights[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherBlockParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherBlockParameter* pInstance);
        static void Clean(WeatherBlockParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherTypeParameter {
        uint8_t transitWeights[5];
        heur::rfl::WeatherBlockParameter blockParams[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherTypeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherTypeParameter* pInstance);
        static void Clean(WeatherTypeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherTimeParameter {
        uint8_t hour;
        uint8_t minute;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherTimeParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherTimeParameter* pInstance);
        static void Clean(WeatherTimeParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherTimeControlParameter {
        heur::rfl::WeatherTimeParameter sunriseBeginTime;
        heur::rfl::WeatherTimeParameter dayBeginTime;
        heur::rfl::WeatherTimeParameter sunsetBeginTime;
        heur::rfl::WeatherTimeParameter nightBeginTime;
        heur::rfl::WeatherTimeParameter blockTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherTimeControlParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherTimeControlParameter* pInstance);
        static void Clean(WeatherTimeControlParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WeatherParameters {
        heur::rfl::WeatherTypeParameter type[5];
        heur::rfl::WeatherTimeControlParameter timeControl;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WeatherParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WeatherParameters* pInstance);
        static void Clean(WeatherParameters* pInstance);
    };
}

namespace heur::rfl {
    struct EffectParameters {
        float localLightIntensityScale;
        bool dropPriorityEnabled;
        int8_t dropPriority;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectParameters* pInstance);
        static void Clean(EffectParameters* pInstance);
    };
}

namespace heur::rfl {
    struct AuraEffectLerpNode {
        float distance;
        float noiseTextureScrollSpeed;
        float blurScale;
        float colorGain;
        float noiseGain;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AuraEffectLerpNode* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AuraEffectLerpNode* pInstance);
        static void Clean(AuraEffectLerpNode* pInstance);
    };
}

namespace heur::rfl {
    struct AuraEffectLerpParameter {
        csl::ut::VariableString name;
        heur::rfl::AuraEffectLerpNode node[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AuraEffectLerpParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AuraEffectLerpParameter* pInstance);
        static void Clean(AuraEffectLerpParameter* pInstance);
    };
}

namespace heur::rfl {
    struct AuraEffectParameters {
        heur::rfl::AuraEffectLerpParameter params[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AuraEffectParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AuraEffectParameters* pInstance);
        static void Clean(AuraEffectParameters* pInstance);
    };
}

namespace heur::rfl {
    struct GraphicsParameters {
        heur::rfl::AuraEffectParameters aura;
        heur::rfl::EffectParameters effect;
        heur::rfl::WeatherParameters weather;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GraphicsParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GraphicsParameters* pInstance);
        static void Clean(GraphicsParameters* pInstance);
    };
}

namespace heur::rfl {
    struct NoisePresetParameters {
        hh::needle::FxCyberSpaceStartNoiseParameter presets[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NoisePresetParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NoisePresetParameters* pInstance);
        static void Clean(NoisePresetParameters* pInstance);
    };
}

namespace heur::rfl {
    struct LicenseItemInfo {
        int8_t pageIndex;
        csl::ut::VariableString label;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LicenseItemInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LicenseItemInfo* pInstance);
        static void Clean(LicenseItemInfo* pInstance);
    };
}

namespace heur::rfl {
    struct LicenseInfo {
        bool isEnable;
        float fontScale;
        heur::rfl::LicenseItemInfo infos[40];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LicenseInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LicenseInfo* pInstance);
        static void Clean(LicenseInfo* pInstance);
    };
}

namespace heur::rfl {
    struct LicenseParamter {
        heur::rfl::LicenseInfo ps4_Infos;
        heur::rfl::LicenseInfo ps5_Infos;
        heur::rfl::LicenseInfo xbox_Infos;
        heur::rfl::LicenseInfo scarlett_Infos;
        heur::rfl::LicenseInfo nx_Infos;
        heur::rfl::LicenseInfo steam_Infos;
        heur::rfl::LicenseInfo epic_Infos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LicenseParamter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LicenseParamter* pInstance);
        static void Clean(LicenseParamter* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardActionData {
        enum class ActionType : int32_t {
            INVALID_ACTION = 0,
            PHASE1_IDLE = 1,
            PHASE1_Y_ROT_HEAD = 2,
            PHASE1_Y_ROT_TAIL = 3,
            PHASE1_ENERGY_BALL = 4,
            PHASE1_DOWN = 5,
            PHASE2_IDLE = 6,
            PHASE2_HAND_NORMAL = 7,
            PHASE2_HAND_WAVE = 8,
            PHASE2_HAND_IKURA = 9,
            PHASE2_HAND_TRIPLE_0 = 10,
            PHASE2_HAND_TRIPLE_1 = 11,
            PHASE2_HAND_TRIPLE_2 = 12,
            PHASE2_HAND_TRIPLE_3 = 13,
            PHASE2_JUMP = 14,
            PHASE3_IDLE = 15,
            PHASE3_HOMING_IKURA_0 = 16,
            PHASE3_HOMING_IKURA_1 = 17,
            PHASE3_HOMING_IKURA_2 = 18,
            PHASE3_HOMING_IKURA_3 = 19,
            PHASE3_GIANT_IKURA = 20,
            ACTION_TYPE_NUM = 21,
        };

        ActionType actionType;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardActionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardActionData* pInstance);
        static void Clean(BossBiolizardActionData* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardArmBreakCamera {
        float fovy;
        float distance;
        float elevation;
        float rotation;
        float gravityOffset;
        csl::math::Vector3 worldOffset;
        float keepTime;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardArmBreakCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardArmBreakCamera* pInstance);
        static void Clean(BossBiolizardArmBreakCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardAttackImpactWave {
        float time;
        float damageByHand;
        float damageByBody;
        float delay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardAttackImpactWave* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardAttackImpactWave* pInstance);
        static void Clean(BossBiolizardAttackImpactWave* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardLockonCameraParam {
        bool enable;
        float fovy;
        float distance;
        float offsetHeight;
        float offsetHeightAdded;
        float minElevation;
        float maxElevation;
        float panningSuspensionK;
        float interiorPanningSuspensionK;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardLockonCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardLockonCameraParam* pInstance);
        static void Clean(BossBiolizardLockonCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardBodyPressParam {
        float pressBodyCollisionRadius;
        float pressBodyCollisionHeight;
        csl::math::Vector3 pressNeckCollisionSize;
        float pressBodySensorRadius;
        float pressBodySensorHeight;
        csl::math::Vector3 pressNeckSensorSize;
        csl::math::Vector3 pressNeckSideSensorSize;
        csl::math::Vector3 pressNeckSideSensorOffset;
        float pressStartTime;
        heur::rfl::BossBiolizardLockonCameraParam lockonCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardBodyPressParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardBodyPressParam* pInstance);
        static void Clean(BossBiolizardBodyPressParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardCommonParam {
        float damageColliderRadius;
        float damageColliderHeight;
        csl::math::Vector3 damageColliderOffset;
        float shockwaveColliderRadius;
        float shockwaveColliderHeight;
        csl::math::Vector3 shockwaveColliderOffset;
        int32_t coreDropRingNum;
        csl::math::Vector3 coreDropRingOffset;
        float waterFlowRotateSpeed;
        float waterFlowIntakeSpeed;
        heur::rfl::BossBiolizardBodyPressParam bodyPress;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardCommonParam* pInstance);
        static void Clean(BossBiolizardCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhaseParam {
        int32_t lifeCount;
        int32_t healthPoint;
        heur::rfl::BossBiolizardActionData actionTable[16];
        heur::rfl::BossBiolizardActionData actionTable2[16];
        heur::rfl::BossBiolizardActionData actionTable3[16];
        heur::rfl::BossBiolizardActionData actionTableByHard[16];
        heur::rfl::BossBiolizardActionData actionTable2ByHard[16];
        heur::rfl::BossBiolizardActionData actionTable3ByHard[16];
        int32_t useActTblHealthPoint2;
        int32_t useActTblHealthPoint3;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhaseParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhaseParam* pInstance);
        static void Clean(BossBiolizardPhaseParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardYRotParam {
        float motionSpeed;
        csl::math::Vector3 headCollisionSize;
        csl::math::Vector3 tailCollisionSize;
        csl::math::Vector3 headBlockSize;
        csl::math::Vector3 tailBlockSize;
        float footCollisionRadius;
        float footCollisionHeight;
        float blendMotionDistanceMin;
        float blendMotionDistanceMax;
        heur::rfl::BossBiolizardLockonCameraParam lockonCamera;
        float waitTime;
        float changeDelayTime;
        float neckMoveDelayTime;
        float hitWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardYRotParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardYRotParam* pInstance);
        static void Clean(BossBiolizardYRotParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardEnergyBallParam {
        float chargeTime;
        float chargeTimeByHard;
        int32_t shotNum;
        int32_t shotNumByHard;
        float shotDelayTime;
        float shotDelayTimeByHard;
        float frontSpeed;
        float frontSpeedByHard;
        float sideSpeed;
        float sideSpeedByHard;
        float startSize;
        float startSizeByHard;
        float maxSize;
        float maxSizeByHard;
        float endSize;
        float endSizeByHard;
        float startHeight;
        float startHeightByHard;
        float maxHeight;
        float maxHeightByHard;
        float endHeight;
        float endHeightByHard;
        float sizeUpDist;
        float sizeUpDistByHard;
        float keepMaxDist;
        float keepMaxDistByHard;
        float sizeDownDist;
        float sizeDownDistByHard;
        float endDist;
        float endDistByHard;
        float explodeSize;
        float explodeSizeByHard;
        float explodeTime;
        float explodeTimeByHard;
        float hitWaitTime;
        float hitWaitTimeByHard;
        heur::rfl::BossBiolizardLockonCameraParam lockonCamera;
        csl::math::Vector3 spawnOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardEnergyBallParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardEnergyBallParam* pInstance);
        static void Clean(BossBiolizardEnergyBallParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase1CameraExtensionInfo {
        float addDistance;
        float addElevationOffset;
        float addTargetUpOffset;
        float addLookatUpOffset;
        float addLookatWorldUpOffset;
        bool isDisableAvoidance;
        float easeIn;
        float easeOut;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase1CameraExtensionInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase1CameraExtensionInfo* pInstance);
        static void Clean(BossBiolizardPhase1CameraExtensionInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase1CameraExtensionParam {
        float nearCameraRange;
        float nearCameraMargin;
        heur::rfl::BossBiolizardPhase1CameraExtensionInfo nearCameraInfo;
        float outrangeCameraAngle;
        float outrangeCameraAngleOffset;
        float outrangeCameraAngleMargin;
        heur::rfl::BossBiolizardPhase1CameraExtensionInfo outrangeCameraInfo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase1CameraExtensionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase1CameraExtensionParam* pInstance);
        static void Clean(BossBiolizardPhase1CameraExtensionParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase1Param {
        heur::rfl::BossBiolizardYRotParam yRotParam;
        heur::rfl::BossBiolizardEnergyBallParam energyBall;
        heur::rfl::BossBiolizardLockonCameraParam waterLockonCamera;
        heur::rfl::BossBiolizardLockonCameraParam downLockonCamera;
        heur::rfl::BossBiolizardPhase1CameraExtensionParam extensionCamera;
        heur::rfl::BossBiolizardPhase1CameraExtensionParam extensionCameraEB;
        float downPanCameraRatio;
        csl::math::Vector3 downPanCameraOffset;
        csl::math::Vector3 downPanCameraOffsetPlayer;
        float downPanCameraFadeTime;
        float downRailCameraDistance;
        csl::math::Vector3 downRailCameraOffsetPlayer;
        float downRailCameraAzimuth;
        float downRailCameraElavation;
        float downRailCameraAnglePerSec;
        float downRailCameraFadeTime;
        float downRailGrindBoosterSpeed;
        heur::rfl::BossBiolizardLockonCameraParam downSpringLockonCamera;
        csl::math::Vector3 downSpringVelocity;
        heur::rfl::BossBiolizardLockonCameraParam downEndHitCamera;
        heur::rfl::BossBiolizardLockonCameraParam downEndMissCamera;
        float downEndHitMoveSpeed;
        float downEndMissMoveSpeed;
        float downEndHitSlideDistance;
        float downEndMissSlideDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase1Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase1Param* pInstance);
        static void Clean(BossBiolizardPhase1Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardRoeArmTripleAttackInfo {
        bool isWave[3];
        bool isDebris[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardRoeArmTripleAttackInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardRoeArmTripleAttackInfo* pInstance);
        static void Clean(BossBiolizardRoeArmTripleAttackInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardRoeArm {
        int32_t roeHandHp;
        int32_t roeHandHpByHard[4];
        float roeHandSwingWaitTime;
        float roeHandBreakDamageTime;
        float roeHandBreakDamageTimeByHard;
        float rangeDistanceMin;
        float rangeDistanceMax;
        float rangeAngel;
        float rangeAngelOffset;
        float targetDelay;
        float breakPlayerHoldTime;
        heur::rfl::BossBiolizardRoeArmTripleAttackInfo tripleAttacks[4];
        heur::rfl::BossBiolizardRoeArmTripleAttackInfo tripleAttacksByHard[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardRoeArm* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardRoeArm* pInstance);
        static void Clean(BossBiolizardRoeArm* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardDropIkura {
        int32_t roeHandAttackDropIkuraNum;
        int32_t boundNum;
        float boundDecRatio;
        float moveSpeed;
        float moveSpeedRandomRange;
        float shotAngleRandomRange;
        float downSpeed;
        int32_t chaosSpearBreakRingNum;
        int32_t chaosSpearBreakRingNumByHard;
        float dBlownPowerRatioY;
        float dBlownPowerRatioXZ;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardDropIkura* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardDropIkura* pInstance);
        static void Clean(BossBiolizardDropIkura* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPointCamera {
        float fovy;
        float toPointDistanceMin;
        float toPointDistanceMax;
        float distanceMin;
        float distanceMax;
        float gravityOffsetMin;
        float gravityOffsetMax;
        csl::math::Vector3 playerOffsetMin;
        csl::math::Vector3 playerOffsetMax;
        csl::math::Vector3 worldOffsetMin;
        csl::math::Vector3 worldOffsetMax;
        csl::math::Vector3 pointLocalOffsetMin;
        csl::math::Vector3 pointLocalOffsetMax;
        csl::ut::VariableString nodeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPointCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPointCamera* pInstance);
        static void Clean(BossBiolizardPointCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardDamageCamera {
        float fovy;
        float distance;
        float elevation;
        float gravityOffset;
        csl::math::Vector3 worldOffset;
        float keepTime;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardDamageCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardDamageCamera* pInstance);
        static void Clean(BossBiolizardDamageCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardStuckCollisionData {
        float radius;
        float height;
        csl::math::Vector3 position;
        csl::math::Vector3 rotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardStuckCollisionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardStuckCollisionData* pInstance);
        static void Clean(BossBiolizardStuckCollisionData* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase2Param {
        float roeArmBreakIkuraTime;
        float battleAreaMoveDistance;
        float defaultCameraDistanceScale;
        float ikuraCameraDistanceScale;
        float ikuraCameraDistanceKeepTime;
        float handAttackSuccessAddWaitTime;
        int32_t breakRingNum;
        int32_t timeStopBreakRingNum;
        int32_t breakRingNumByHard;
        int32_t timeStopBreakRingNumByHard;
        heur::rfl::BossBiolizardRoeArm roeArm;
        heur::rfl::BossBiolizardAttackImpactWave wave;
        heur::rfl::BossBiolizardAttackImpactWave waveTriple;
        heur::rfl::BossBiolizardAttackImpactWave waveTripleByHard[4];
        heur::rfl::BossBiolizardDropIkura dropIkura;
        heur::rfl::BossBiolizardPointCamera camera;
        heur::rfl::BossBiolizardDamageCamera damageCamera;
        heur::rfl::BossBiolizardArmBreakCamera armBreakCamera;
        heur::rfl::BossBiolizardArmBreakCamera armBreakCameraTS;
        heur::rfl::BossBiolizardPhase1CameraExtensionInfo armBreakedDownCameraInfo;
        heur::rfl::BossBiolizardStuckCollisionData stuckCollisions[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase2Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase2Param* pInstance);
        static void Clean(BossBiolizardPhase2Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase3Param {
        int32_t roeHandAttackDropIkuraNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase3Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase3Param* pInstance);
        static void Clean(BossBiolizardPhase3Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardHomingIkuraTableDataParam {
        enum class ShotType : int32_t {
            NONE = 0,
            ONE_SHOT = 1,
            ONE_SHOT_PLAYER = 2,
            ONE_SHOT_HOMING = 3,
            MULTI_SHOT = 4,
            MULTI_SHOT_HOMING = 5,
        };

        ShotType type;
        int32_t num;
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardHomingIkuraTableDataParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardHomingIkuraTableDataParam* pInstance);
        static void Clean(BossBiolizardHomingIkuraTableDataParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardHomingIkuraTableParam {
        heur::rfl::BossBiolizardHomingIkuraTableDataParam tableData[24];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardHomingIkuraTableParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardHomingIkuraTableParam* pInstance);
        static void Clean(BossBiolizardHomingIkuraTableParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardHomingIkuraParam {
        float radius;
        float hitRadius;
        float bodyRadius;
        float speed;
        float minSpeed;
        float decelePower;
        float speedRandom;
        float minSpeedRandom;
        float decelePowerRandom;
        bool enableChaosSpearRandom;
        float lifeTime;
        float homingAngularSpeed;
        float homingEndDistance;
        float homingEndHeight;
        int32_t firstSpawnNum;
        csl::math::Vector3 spawnAreaSize;
        csl::math::Vector3 spawnAreaOffset;
        csl::math::Vector3 spawnNumMax;
        float appearWaitTime;
        float startWaitTime;
        float endWaitTime;
        float endWaitTimeByGaugeMax;
        float floatSEDelay;
        int32_t ringNum;
        csl::math::Vector3 attackCenter;
        float attackRadius;
        heur::rfl::BossBiolizardLockonCameraParam nearDistLockonCamera;
        csl::math::Vector3 nearDistCameraOffset;
        heur::rfl::BossBiolizardHomingIkuraTableParam numTable[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardHomingIkuraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardHomingIkuraParam* pInstance);
        static void Clean(BossBiolizardHomingIkuraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardGiantIkuraStartCamera {
        float fovy;
        float roll;
        csl::math::Vector3 target;
        csl::math::Vector3 position;
        csl::math::Vector3 up;
        float delay;
        float keepTime;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardGiantIkuraStartCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardGiantIkuraStartCamera* pInstance);
        static void Clean(BossBiolizardGiantIkuraStartCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardFixedCamera {
        csl::math::Vector3 eyeLocalOffset;
        csl::math::Vector3 lookAtLocalOffset;
        float fov;
        float roll;
        float easeInTime;
        float easeOutTime;
        float keepTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardFixedCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardFixedCamera* pInstance);
        static void Clean(BossBiolizardFixedCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardGiantIkuraParam {
        float radius;
        float speed;
        int32_t health;
        int32_t childNum;
        float childSpawnTime;
        float childSpeedMin;
        float childSpeedMax;
        float childLifeTime;
        float timeStopGaugeStopTime;
        heur::rfl::BossBiolizardGiantIkuraStartCamera startCamera;
        heur::rfl::BossBiolizardFixedCamera fixedCamera;
        float fixedCameraStartDelay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardGiantIkuraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardGiantIkuraParam* pInstance);
        static void Clean(BossBiolizardGiantIkuraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardPhase4Param {
        heur::rfl::BossBiolizardHomingIkuraParam homingIkura;
        heur::rfl::BossBiolizardHomingIkuraParam homingIkuraByHard;
        heur::rfl::BossBiolizardGiantIkuraParam giantIkura;
        float downTime;
        float cameraDistanceScale;
        heur::rfl::BossBiolizardLockonCameraParam waterLockonCamera;
        csl::math::Vector3 waterCameraOffset;
        heur::rfl::BossBiolizardLockonCameraParam lockonCamera;
        float chaosSpearInputGuideDelayTime;
        int8_t chaosSpearGuideDispInputCount;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardPhase4Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardPhase4Param* pInstance);
        static void Clean(BossBiolizardPhase4Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossBiolizardConfig {
        heur::rfl::BossBiolizardCommonParam commonParam;
        heur::rfl::BossBiolizardPhaseParam phaseParam[4];
        heur::rfl::BossBiolizardPhase1Param phase1;
        heur::rfl::BossBiolizardPhase2Param phase2;
        heur::rfl::BossBiolizardPhase3Param phase3;
        heur::rfl::BossBiolizardPhase4Param phase4;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBiolizardConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBiolizardConfig* pInstance);
        static void Clean(BossBiolizardConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesActionData {
        enum class ActionType : int8_t {
            INVALID_ACTION = 0,
            PHASE1_IDLE = 1,
            PHASE1_MINION = 2,
            PHASE1_BLADE = 3,
            PHASE1_DEMON = 4,
            PHASE2_IDLE = 5,
            ACTION_TYPE_NUM = 6,
        };

        ActionType actionType;
        float time;
        int32_t attackIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesActionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesActionData* pInstance);
        static void Clean(BossMephilesActionData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesBladeTable {
        int32_t num;
        int32_t attackNum;
        int32_t amoebaSpawnIdx1;
        int32_t amoebaSpawnIdx2;
        int32_t amoebaSpawnIdx3;
        float aimSpeed;
        float aimTime;
        float assaultSpeed;
        float time;
        float amoebaTargetActiveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesBladeTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesBladeTable* pInstance);
        static void Clean(BossMephilesBladeTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesCameraExtensionParam {
        float addDistance;
        float addElevationOffset;
        float addTargetUpOffset;
        float addTargetFrontOffset;
        float addLookatUpOffset;
        float addLookatWorldUpOffset;
        float addAzimuthOffset;
        bool isDisableAvoidance;
        float time;
        float easeIn;
        float easeOut;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesCameraExtensionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesCameraExtensionParam* pInstance);
        static void Clean(BossMephilesCameraExtensionParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesAttackBlade {
        heur::rfl::BossMephilesBladeTable bladeTable[4];
        heur::rfl::BossMephilesBladeTable bladeTableByHard[4];
        heur::rfl::BossMephilesCameraExtensionParam exCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesAttackBlade* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesAttackBlade* pInstance);
        static void Clean(BossMephilesAttackBlade* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesDemonHandAttack {
        float reactionTime;
        float range;
        float rangeOffset;
        float wavePointOffset;
        float waveRadus;
        float waveDelay;
        float waveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesDemonHandAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesDemonHandAttack* pInstance);
        static void Clean(BossMephilesDemonHandAttack* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesLockonCameraParam {
        bool enable;
        float distance;
        float minElevation;
        float maxElevation;
        float panningSuspensionK;
        float interiorPanningSuspensionK;
        float time;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesLockonCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesLockonCameraParam* pInstance);
        static void Clean(BossMephilesLockonCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesAttackDemon {
        int32_t lifeCountMax;
        int32_t lifeCountMaxByHard;
        int32_t hp;
        int32_t hpByHard;
        int32_t shieldHp[4];
        float rotAnimSpeedRatios[4];
        float hideMoveSpeed;
        float rotSpeedNormal;
        float rotSpeedAttack;
        float rotSpeedHide;
        float waitTimeInit;
        float waitTimes[4];
        float waitTimesByHard[4];
        float hideTime;
        float hideAttackRangeMin;
        float hideAttackRange;
        float hideAttackColRadius;
        float hideAttackDelay;
        float hideMoveMarginDistance;
        float hideEndDistance;
        float laserTimes[4];
        float laserAimSpeeds[4];
        int32_t amoebaTargetNum;
        float amoebaTargetActiveTime;
        float amoebaTargetSpawnDistanceCycle;
        int32_t dropRingNum;
        int32_t dropRingNumByHard;
        float dropRingTime;
        float finishLaunchPower;
        float finishCameraLookAtHeight;
        float finishBreakFakerCreateTime;
        float finishBreakedMessageDelayTime;
        float fakerAppearMoveTime;
        float fakerAppearMoveUpRatio;
        heur::rfl::BossMephilesDemonHandAttack handAttack;
        heur::rfl::BossMephilesDemonHandAttack handAttackByHard;
        heur::rfl::BossMephilesLockonCameraParam lockonCamera;
        heur::rfl::BossMephilesCameraExtensionParam exHideAttack;
        heur::rfl::BossMephilesCameraExtensionParam exHideMove;
        heur::rfl::BossMephilesCameraExtensionParam exLaser;
        heur::rfl::BossMephilesCameraExtensionParam exDamage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesAttackDemon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesAttackDemon* pInstance);
        static void Clean(BossMephilesAttackDemon* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesFixedCamera {
        csl::math::Vector3 eyeLocalOffset;
        csl::math::Vector3 lookAtLocalOffset;
        float fov;
        float roll;
        float easeInTime;
        float easeOutTime;
        float keepTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesFixedCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesFixedCamera* pInstance);
        static void Clean(BossMephilesFixedCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesAttackFaker {
        int32_t num;
        int32_t numByHard;
        int32_t spBreakNum;
        int32_t spBreakActiveNum;
        int32_t spBreakNumByHard;
        int32_t spBreakActiveNumByHard;
        float floatingHeight;
        float initSpawnRaidus;
        float initDelay;
        float delay;
        int32_t breakCountrNum;
        float attackPosRaidus;
        float straightAttackHitColRaidus;
        float straightAttackSpeed;
        float straightDelay;
        float straightAddDelay;
        int32_t straightNum;
        float straightDelayByHard;
        float straightAddDelayByHard;
        int32_t straightNumByHard;
        heur::rfl::BossMephilesFixedCamera attackCamera;
        float soulSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesAttackFaker* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesAttackFaker* pInstance);
        static void Clean(BossMephilesAttackFaker* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesMinionTable {
        int32_t num;
        int32_t amoebaMinionNum;
        int32_t attackNum;
        int32_t attackCycle;
        float attackInitDelayNormal;
        float attackInitDelayAmoeba;
        float attackDelayNormal;
        float attackDelayAmoeba;
        float time;
        int32_t amoebaLotCycle;
        int32_t amoebaLotValue;
        int32_t ringNum;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesMinionTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesMinionTable* pInstance);
        static void Clean(BossMephilesMinionTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesAttackMinion {
        float spawnRadiusMin;
        float spawnRadiusMax;
        float moveRadiusMin;
        float moveRadiusMax;
        float moveDegree;
        float shakeDegree;
        float shakeSpeed;
        float heightRatio;
        float attackSpeedNormal;
        float attackSpeedAmoeba;
        float attackSpeedNormalByHard;
        float attackSpeedAmoebaByHard;
        float amoebaTargetActiveTime;
        heur::rfl::BossMephilesMinionTable minionTable[4];
        heur::rfl::BossMephilesMinionTable minionTableByHard[4];
        heur::rfl::BossMephilesCameraExtensionParam exCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesAttackMinion* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesAttackMinion* pInstance);
        static void Clean(BossMephilesAttackMinion* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesAttackPillar {
        float initStartDelay;
        float startDelay;
        float startDelayByHard;
        float addStartDelay;
        float readyTime;
        float fallTime;
        float waitTime;
        float waitTimeByHard;
        float riseTime;
        float launchSpeed;
        float launchSpeedByHard;
        float launchSpeedKeepTime;
        float launchOutOfControlTime;
        float leanAngle;
        float leanTime;
        int32_t amoebaTargetNum;
        float amoebaTargetDelay;
        float amoebaTargetDistance;
        float waveRadius;
        float waveDelay;
        float waveTime;
        float waveTimeByHard;
        float cameraHeightMin;
        float cameraHeightMax;
        float cameraLookUpDelay;
        float cameraLookUpEaseTime;
        float cameraLookUpKeepTime;
        float cameraReturnTime;
        csl::ut::VariableString layerName;
        csl::ut::VariableString endOffLayerName;
        heur::rfl::BossMephilesFixedCamera fixedCamera;
        float fixedCameraStartDelay;
        float firstReactionStartDelay;
        float firstReactionEndDelay;
        float firstMoveTime;
        float firstUpRatio;
        float pillarCreateDelay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesAttackPillar* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesAttackPillar* pInstance);
        static void Clean(BossMephilesAttackPillar* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesDBlowHitParam {
        float VerticalPowerRatio;
        float VerticalSpeedKeepTime;
        float VerticalSpeedDecelTime;
        float HorizontalPowerRatio;
        float HorizontalSpeedKeepTime;
        float HorizontalSpeedDecelTime;
        int32_t wallHitDamage;
        float waitTime;
        heur::rfl::BossMephilesFixedCamera bombHitCamera;
        heur::rfl::BossMephilesFixedCamera blowDownCamera;
        float blowDownCameraDelay;
        float blowDownWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesDBlowHitParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesDBlowHitParam* pInstance);
        static void Clean(BossMephilesDBlowHitParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesWarpStatusData {
        bool isEnable;
        float damageTime;
        float counterAtkWaitTime;
        float warpedWaitTime;
        bool isDBlow;
        bool isCounter;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesWarpStatusData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesWarpStatusData* pInstance);
        static void Clean(BossMephilesWarpStatusData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesWarpStatusTable {
        heur::rfl::BossMephilesWarpStatusData warpDatas[20];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesWarpStatusTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesWarpStatusTable* pInstance);
        static void Clean(BossMephilesWarpStatusTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesWarpCameraAndPosition {
        heur::rfl::BossMephilesFixedCamera warpCamera;
        csl::math::Vector3 warpPositions[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesWarpCameraAndPosition* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesWarpCameraAndPosition* pInstance);
        static void Clean(BossMephilesWarpCameraAndPosition* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesWarpParam {
        heur::rfl::BossMephilesWarpStatusTable warpTable[4];
        heur::rfl::BossMephilesWarpStatusTable warpTableByHard[4];
        float warpDistanceByNormal;
        float warpDistanceByCounter;
        int32_t useTableIndexMax;
        heur::rfl::BossMephilesFixedCamera counterCamera;
        heur::rfl::BossMephilesWarpCameraAndPosition warpPattern[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesWarpParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesWarpParam* pInstance);
        static void Clean(BossMephilesWarpParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesCommonParam {
        heur::rfl::BossMephilesDBlowHitParam dBlow;
        heur::rfl::BossMephilesWarpParam warp;
        float battleAwayTime;
        int32_t cumulativeDamageLimits[4];
        int32_t cumulativeDamageLimitsByHard[4];
        float spearDamageWaitTimes[4];
        heur::rfl::BossMephilesFixedCamera spearDamageCamera;
        heur::rfl::BossMephilesCameraExtensionParam exStageOutSideCamera;
        float stageOutSideDistance;
        float stageOutSideMargin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesCommonParam* pInstance);
        static void Clean(BossMephilesCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhaseParam {
        int32_t lifeCount;
        int32_t healthPoint;
        int32_t healthPointByHard;
        int32_t useTableIndexMax;
        heur::rfl::BossMephilesActionData actionTable1[24];
        heur::rfl::BossMephilesActionData actionTable2[24];
        heur::rfl::BossMephilesActionData actionTable3[24];
        heur::rfl::BossMephilesActionData actionTable4[24];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhaseParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhaseParam* pInstance);
        static void Clean(BossMephilesPhaseParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhase1StatusTable {
        float amoebaMoveSpeed;
        float amoebaMoveAccel;
        float amoebaMoveAngle;
        float amoebaEscapeDistance;
        float amoebaPatrolSpeed;
        float amoebaPatrolDistance;
        float hideEndWait;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhase1StatusTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhase1StatusTable* pInstance);
        static void Clean(BossMephilesPhase1StatusTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhase1Status {
        float floatingHeight;
        float initIdleTime;
        float idleTime;
        float amoebaHitRadius;
        heur::rfl::BossMephilesPhase1StatusTable statusTable[4];
        heur::rfl::BossMephilesPhase1StatusTable statusTableByHard[4];
        heur::rfl::BossMephilesFixedCamera hideEndCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhase1Status* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhase1Status* pInstance);
        static void Clean(BossMephilesPhase1Status* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhase1Param {
        heur::rfl::BossMephilesPhase1Status status;
        heur::rfl::BossMephilesAttackMinion minion;
        heur::rfl::BossMephilesAttackBlade blade;
        heur::rfl::BossMephilesCameraExtensionParam exCameraInit;
        heur::rfl::BossMephilesCameraExtensionParam exCameraDamage;
        heur::rfl::BossMephilesCameraExtensionParam exCameraHideChase;
        heur::rfl::BossMephilesLockonCameraParam lockonCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhase1Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhase1Param* pInstance);
        static void Clean(BossMephilesPhase1Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhase2StageLayerParam {
        csl::ut::VariableString layerName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhase2StageLayerParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhase2StageLayerParam* pInstance);
        static void Clean(BossMephilesPhase2StageLayerParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesPhase2Param {
        heur::rfl::BossMephilesPhase2StageLayerParam startActiveLayers[4];
        heur::rfl::BossMephilesAttackDemon demon;
        heur::rfl::BossMephilesAttackPillar pillar;
        heur::rfl::BossMephilesAttackFaker faker;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesPhase2Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesPhase2Param* pInstance);
        static void Clean(BossMephilesPhase2Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossMephilesConfig {
        heur::rfl::BossMephilesCommonParam commonParam;
        heur::rfl::BossMephilesPhaseParam phaseParam[2];
        heur::rfl::BossMephilesPhase1Param phase1;
        heur::rfl::BossMephilesPhase2Param phase2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMephilesConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMephilesConfig* pInstance);
        static void Clean(BossMephilesConfig* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLSoulSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLSoulSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLSoulSpawner* pInstance);
        static void Clean(ObjMPLSoulSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjMPLWaveSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjMPLWaveSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjMPLWaveSpawner* pInstance);
        static void Clean(ObjMPLWaveSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct BossBattleLockOnCameraParam {
        csl::ut::VariableString nodeName;
        csl::math::Vector3 offset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBattleLockOnCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBattleLockOnCameraParam* pInstance);
        static void Clean(BossBattleLockOnCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadActionData {
        enum class ActionType : int8_t {
            INVALID_ACTION = 0,
            PHASE2_IDLE = 1,
            PHASE2_ATTACK_MISSILE = 2,
            PHASE2_ATTACK_SHOT = 3,
            PHASE2_ATTACK_NORMAL_THROWING = 4,
            PHASE2_ATTACK_SP_THROWING = 5,
            PHASE2_RING_POP = 6,
            PHASE2_RING_POP_1 = 7,
            PHASE2_ATTACK_MINE = 8,
            PHASE2_ATTACK_MINE_1 = 9,
            PHASE2_ATTACK_MINE_2 = 10,
            PHASE2_ATTACK_MINE_3 = 11,
            PHASE2_ATTACK_MINE_4 = 12,
            PHASE2_ATTACK_THORNBALL = 13,
            ACTION_TYPE_NUM = 14,
        };

        ActionType actionType;
        float time;
        int32_t successSkip;
        int32_t patternIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadActionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadActionData* pInstance);
        static void Clean(BossMetaloverloadActionData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadSwitchLayerData {
        csl::ut::VariableString layerName;
        int32_t phase;
        int32_t lifeMin;
        int32_t lifeMax;
        csl::ut::VariableString tag;
        bool isChangePhaseEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadSwitchLayerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadSwitchLayerData* pInstance);
        static void Clean(BossMetaloverloadSwitchLayerData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadCommonParam {
        float floatHeight;
        float upperRotSpeed;
        float upperResetRotSpeed;
        heur::rfl::BossMetaloverloadSwitchLayerData switchLayers[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadCommonParam* pInstance);
        static void Clean(BossMetaloverloadCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhaseParam {
        int32_t lifeCount;
        int32_t healthPoint;
        int32_t healthPointByHard;
        heur::rfl::BossMetaloverloadActionData actionTable1[34];
        heur::rfl::BossMetaloverloadActionData actionTable2[34];
        heur::rfl::BossMetaloverloadActionData actionTable3[34];
        heur::rfl::BossMetaloverloadActionData actionTable4[34];
        heur::rfl::BossMetaloverloadActionData actionTable1ByHard[34];
        heur::rfl::BossMetaloverloadActionData actionTable2ByHard[34];
        heur::rfl::BossMetaloverloadActionData actionTable3ByHard[34];
        heur::rfl::BossMetaloverloadActionData actionTable4ByHard[34];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhaseParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhaseParam* pInstance);
        static void Clean(BossMetaloverloadPhaseParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1AutorunParam {
        float speed;
        float width;
        float bossSpeedMax;
        float bossSpeedMin;
        float bossAccelSpeed;
        float bossDecelSpeed;
        float bossKeepDistanceDefault;
        float bossKeepDistanceLimit;
        float bossStanLostDistance;
        float bossDefalutDistanceReturnTime;
        float bossDefalutDistanceReturnSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1AutorunParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1AutorunParam* pInstance);
        static void Clean(BossMetaloverloadPhase1AutorunParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPointCameraParam {
        float fovy;
        float toPointDistanceMin;
        float toPointDistanceMax;
        float distanceMin;
        float distanceMax;
        float gravityOffsetMin;
        float gravityOffsetMax;
        csl::math::Vector3 playerOffsetMin;
        csl::math::Vector3 playerOffsetMax;
        csl::math::Vector3 worldOffsetMin;
        csl::math::Vector3 worldOffsetMax;
        csl::math::Vector3 pointLocalOffsetMin;
        csl::math::Vector3 pointLocalOffsetMax;
        csl::ut::VariableString nodeName;
        float roll;
        float easeInTime;
        float easeOutTime;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPointCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPointCameraParam* pInstance);
        static void Clean(BossPointCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadLockonCameraParam {
        bool enable;
        float distance;
        float minElevation;
        float maxElevation;
        float panningSuspensionK;
        float interiorPanningSuspensionK;
        float time;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadLockonCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadLockonCameraParam* pInstance);
        static void Clean(BossMetaloverloadLockonCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1MissileInfo {
        enum class InputGuideKind : int8_t {
            INPUT_GUIDE_KIND_NONE = 0,
            INPUT_GUIDE_KIND_LEFT_STEP = 1,
            INPUT_GUIDE_KIND_RIGHT_STEP = 2,
            INPUT_GUIDE_KIND_JUMP = 3,
            INPUT_GUIDE_KIND_NUM = 4,
        };

        int8_t laneNumber;
        bool missileStepsEneble[4];
        bool enebleBounce;
        float shotTime;
        InputGuideKind inputGuideKind;
        bool isScreenInputGuide;
        float screenInputGuideDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1MissileInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1MissileInfo* pInstance);
        static void Clean(BossMetaloverloadPhase1MissileInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1MissilePatternData {
        heur::rfl::BossMetaloverloadPhase1MissileInfo missileInfoTabel[40];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1MissilePatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1MissilePatternData* pInstance);
        static void Clean(BossMetaloverloadPhase1MissilePatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1MissileParam {
        float backwardMoveTime;
        float backwardMoveDistance;
        float originalPosMoveTime;
        float startWaitTime;
        float endWaitTime;
        float straightSpeed;
        float straightSpeedByHard;
        float curveTime;
        float curveTimeByHard;
        float blowSpeed;
        float laneHeight;
        float lifeTime;
        float leaveDistance;
        int32_t blowHitDamagePoint;
        float blowCurvedTime;
        float blowCurvedYMax;
        float floatHeight;
        float missileScale;
        float stepHeight;
        float colRadius;
        float colHeight;
        csl::math::Vector3 colOffset;
        heur::rfl::BossMetaloverloadPhase1MissilePatternData missilePatterns[4];
        heur::rfl::BossMetaloverloadPhase1MissilePatternData missilePatternsByHard[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1MissileParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1MissileParam* pInstance);
        static void Clean(BossMetaloverloadPhase1MissileParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhaseTailInfo {
        enum class Phase1TailAttackType : int8_t {
            TAIL_ACT_NONE = 0,
            TAIL_ACT_1 = 1,
            TAIL_ACT_2 = 2,
            TAIL_ACT_3 = 3,
            TAIL_ACT_4 = 4,
            TAIL_ACT_NUM = 5,
        };

        Phase1TailAttackType type;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhaseTailInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhaseTailInfo* pInstance);
        static void Clean(BossMetaloverloadPhaseTailInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1TailPatternData {
        float attackInterval;
        heur::rfl::BossMetaloverloadPhaseTailInfo tailTypeTabel[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1TailPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1TailPatternData* pInstance);
        static void Clean(BossMetaloverloadPhase1TailPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1TailParam {
        float frontMoveDistance;
        float frontMoveUpPos;
        float riseAndFallMotionSpeed;
        float attackMotionSpeed;
        float attackIntervalMotionSpeed;
        float colliderOffsetHeight;
        float floatHeight;
        heur::rfl::BossMetaloverloadPhase1TailPatternData tailPatterns[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1TailParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1TailParam* pInstance);
        static void Clean(BossMetaloverloadPhase1TailParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1FlameParam {
        float backwardMoveTime;
        float backwardMoveDistance;
        float floatHeight;
        float originalPosMoveTime;
        float startWaitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1FlameParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1FlameParam* pInstance);
        static void Clean(BossMetaloverloadPhase1FlameParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1SelfRecoverDebris {
        int32_t stopPosNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1SelfRecoverDebris* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1SelfRecoverDebris* pInstance);
        static void Clean(BossMetaloverloadPhase1SelfRecoverDebris* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1SelfRecoverParam {
        float selfRecoverActiveHp;
        float recoverHp;
        float limitRecoverHp;
        float bossKeepDistance;
        float debrisSpeed;
        float frontSpeed;
        float upSpeed;
        float outOfControlTime;
        float keepVelocityTime;
        float miniDebrisCreateIntervalTime;
        int32_t miniDebrisNum;
        float miniDebrisSpeed;
        float floatHeight;
        heur::rfl::BossMetaloverloadPhase1SelfRecoverDebris debrisList[7];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1SelfRecoverParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1SelfRecoverParam* pInstance);
        static void Clean(BossMetaloverloadPhase1SelfRecoverParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1TimeStopParam {
        float bossKeepDistance;
        float photonDashBossKeepDistance;
        float photonDashBossKeepTime;
        float photonDashDistanceOffset;
        float photonDashAttackAfterCameraStartTime;
        float photonDashAttackAfterCameraInvalidationTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1TimeStopParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1TimeStopParam* pInstance);
        static void Clean(BossMetaloverloadPhase1TimeStopParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1DamageParam {
        float stunTime;
        float rushTime;
        float rushCameraDelayTime;
        float damageAfterTime;
        float damageAfterDistance;
        int32_t debrisBlowHitDamagePoint;
        int32_t debrisSurfSpinBlowHitDamagePoint;
        int32_t mineBlowHitDamagePoint;
        float rushFinishDamageScale;
        int32_t photonDashDamagePoint;
        float phaseChangeWaitTime;
        float photonPhaseChangeWaitTime;
        float blowPower;
        float blowUpPower;
        float blowDeceleration;
        float gravityPower;
        float blowEndHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1DamageParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1DamageParam* pInstance);
        static void Clean(BossMetaloverloadPhase1DamageParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1AttackChanceParam {
        float distanceOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1AttackChanceParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1AttackChanceParam* pInstance);
        static void Clean(BossMetaloverloadPhase1AttackChanceParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase1Param {
        int32_t useActTblHealthPoint2;
        int8_t laneNum;
        float laneWidth;
        heur::rfl::BossMetaloverloadPhase1AutorunParam autorun;
        heur::rfl::BossBattleLockOnCameraParam mainCamera;
        heur::rfl::BossPointCameraParam damageCamera;
        heur::rfl::BossPointCameraParam bossLookAtCamera;
        heur::rfl::BossMetaloverloadLockonCameraParam subCamera;
        heur::rfl::BossMetaloverloadPhase1MissileParam missileParam;
        heur::rfl::BossMetaloverloadPhase1TailParam tailParam;
        heur::rfl::BossMetaloverloadPhase1FlameParam flameParam;
        heur::rfl::BossMetaloverloadPhase1SelfRecoverParam selfRecoverParam;
        heur::rfl::BossMetaloverloadPhase1TimeStopParam timeStopParam;
        heur::rfl::BossPointCameraParam photonBeforeBossLookAtCamera;
        heur::rfl::BossPointCameraParam photonBossLookAtCamera;
        heur::rfl::BossMetaloverloadPhase1DamageParam damageParam;
        heur::rfl::BossMetaloverloadPhase1AttackChanceParam attackChanceParam;
        bool attackChanceBeforeBossLookAtCameraEneble;
        heur::rfl::BossPointCameraParam attackChanceBeforeBossLookAtCamera;
        float startCaptionTime;
        csl::ut::VariableString startCaptionLabel;
        float tutorialCaptionTime;
        csl::ut::VariableString tutorialCaptionLabel;
        float chaosBreakCaptionTime;
        csl::ut::VariableString chaosBreakCaptionLabel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase1Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase1Param* pInstance);
        static void Clean(BossMetaloverloadPhase1Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossSVCameraParam {
        float fovy;
        float toPointDistanceMin;
        float toPointDistanceMax;
        float distanceMin;
        float distanceMax;
        float gravityOffsetMin;
        float gravityOffsetMax;
        csl::math::Vector3 playerOffsetMin;
        csl::math::Vector3 playerOffsetMax;
        csl::math::Vector3 worldOffsetMin;
        csl::math::Vector3 worldOffsetMax;
        csl::math::Vector3 pointLocalOffsetMin;
        csl::math::Vector3 pointLocalOffsetMax;
        csl::ut::VariableString nodeName;
        csl::math::Vector3 pointLocalDir;
        float baseDistance;
        float addSideMoveLimitAngle;
        float addSideMoveDistance;
        float inputStickRotAngle;
        float inputStickDistanceRatioMin;
        float inputStickDistanceRatioMax;
        float inputStickOffsetHeightMin;
        float inputStickOffsetHeightMax;
        float inputStickRollMin;
        float inputStickRollMax;
        float inputStickAddRatio;
        float noInputStickAddRatio;
        float inputStickDelay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossSVCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossSVCameraParam* pInstance);
        static void Clean(BossSVCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2WaterFlowParam {
        int8_t laneNum;
        float minDistance;
        float maxDistance;
        float svPathRadius;
        float speed;
        float suctionPowerRatio;
        float playerBackSpeed;
        float moveDistance;
        bool moveUnlock;
        float bossRationAngleMin;
        float bossRationAngleMax;
        float bossRationSpeedMin;
        float bossRationSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2WaterFlowParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2WaterFlowParam* pInstance);
        static void Clean(BossMetaloverloadPhase2WaterFlowParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThornballPatternData {
        float delay;
        float popAngle;
        float popInterval;
        int8_t num;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThornballPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThornballPatternData* pInstance);
        static void Clean(BossMetaloverloadPhase2ThornballPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThornballParam {
        int32_t blowHitDamagePoint;
        float moveTime;
        float blowSpeed;
        float blowUpRatio;
        bool firstInputGuideDisplay;
        heur::rfl::BossMetaloverloadPhase2ThornballPatternData patterns[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThornballParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThornballParam* pInstance);
        static void Clean(BossMetaloverloadPhase2ThornballParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2MoveRingPatternData {
        float delay;
        float popAngle;
        float popInterval;
        int8_t num;
        float height;
        float heightPatterns[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2MoveRingPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2MoveRingPatternData* pInstance);
        static void Clean(BossMetaloverloadPhase2MoveRingPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2MoveRingParam {
        float moveTime;
        heur::rfl::BossMetaloverloadPhase2MoveRingPatternData patterns[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2MoveRingParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2MoveRingParam* pInstance);
        static void Clean(BossMetaloverloadPhase2MoveRingParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2MissileInfo {
        int8_t laneIndex;
        bool isLeft;
        float popTime;
        float height;
        bool isInvincible;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2MissileInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2MissileInfo* pInstance);
        static void Clean(BossMetaloverloadPhase2MissileInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2MissilePatternData {
        float hpRatioMin;
        float hpRatioMax;
        heur::rfl::BossMetaloverloadPhase2MissileInfo infos[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2MissilePatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2MissilePatternData* pInstance);
        static void Clean(BossMetaloverloadPhase2MissilePatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadSVCameraExtensionParam {
        float addDistance;
        float addGravityOffset;
        csl::math::Vector3 addPlayerOffset;
        csl::math::Vector3 addWorldOffset;
        csl::math::Vector3 addPointLocalOffset;
        float time;
        float easeIn;
        float easeOut;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadSVCameraExtensionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadSVCameraExtensionParam* pInstance);
        static void Clean(BossMetaloverloadSVCameraExtensionParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2MissileParam {
        int32_t blowHitDamagePoint;
        float flySpeed;
        float flySpeedByHard;
        float onWaterSpeed;
        float onWaterSpeedByHard;
        float shotAngle;
        float blowSpeed;
        float blowUpRatio;
        float radius;
        float waitTime;
        float moveTime;
        int32_t spinBlowRingNum;
        bool firstInputGuideDisplay;
        heur::rfl::BossMetaloverloadPhase2MissilePatternData patterns[4];
        heur::rfl::BossMetaloverloadPhase2MissilePatternData patternsByHard[4];
        heur::rfl::BossMetaloverloadSVCameraExtensionParam cameraEx;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2MissileParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2MissileParam* pInstance);
        static void Clean(BossMetaloverloadPhase2MissileParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThrowingFocusCameraParam {
        float hitstopStartTime;
        float startTime;
        float easeOutTime;
        float keepTime;
        csl::math::Vector3 localOffsetDirection;
        float offsetDistance;
        float cancelDelay;
        csl::math::Vector3 guideOffset;
        float targetOffsetHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThrowingFocusCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThrowingFocusCameraParam* pInstance);
        static void Clean(BossMetaloverloadPhase2ThrowingFocusCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThrowingBreakDebrisInfo {
        bool enable;
        csl::math::Vector3 landingPos;
        float landingTime;
        float blowPower;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThrowingBreakDebrisInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThrowingBreakDebrisInfo* pInstance);
        static void Clean(BossMetaloverloadPhase2ThrowingBreakDebrisInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThrowingBreakDebrisParam {
        int32_t tankBlowHitDamagePoint;
        int32_t shipBlowHitDamagePoint;
        int32_t tankBlowHitDamagePointByHard;
        int32_t shipBlowHitDamagePointByHard;
        float tankRadius;
        float shipRadius;
        float blowSpeed;
        float blowUpRatio;
        heur::rfl::BossMetaloverloadPhase2ThrowingBreakDebrisInfo tankBreakDebris[16];
        heur::rfl::BossMetaloverloadPhase2ThrowingBreakDebrisInfo shipBreakDebris[16];
        heur::rfl::BossMetaloverloadPhase2ThrowingBreakDebrisInfo tankBreakDebrisByHard[16];
        heur::rfl::BossMetaloverloadPhase2ThrowingBreakDebrisInfo shipBreakDebrisByHard[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThrowingBreakDebrisParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThrowingBreakDebrisParam* pInstance);
        static void Clean(BossMetaloverloadPhase2ThrowingBreakDebrisParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadFixedCamera {
        csl::math::Vector3 eyeLocalOffset;
        csl::math::Vector3 lookAtLocalOffset;
        float fov;
        float roll;
        float easeInTime;
        float easeOutTime;
        float keepTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadFixedCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadFixedCamera* pInstance);
        static void Clean(BossMetaloverloadFixedCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ThrowingParam {
        int32_t tankHp;
        float tankWaterline;
        csl::math::Vector3 tankStartVelocity;
        float tankEndWaitTimeByOutOfRange;
        float tankEndWaitTimeByBreak;
        float tankMoveTime;
        int32_t tankKnokbackRingNum;
        int32_t tankNormalBreakRingNum;
        int32_t tankTimeStopBreakRingNum;
        int32_t shipHp;
        int32_t shipTimeStopRefDebrisNum;
        int32_t shipTimeStopRefDebrisDamage;
        int32_t shipTimeStopRefDebrisNumByHard;
        int32_t shipTimeStopRefDebrisDamageByHard;
        float shipThrowingDecleSpeedRatio;
        float shipThrowingDecleTime;
        float shipThrowingDecleDelay;
        csl::math::Vector3 shipStartVelocity;
        float shipLandingVelocityXZ;
        float shipLandingVelocityY;
        float shipLandingPosOffsetXZ;
        float shipLandingPosOffsetSide;
        float shipEndWaitTimeByOutOfRange;
        float shipEndWaitTimeByBreak;
        int32_t shipNormalBreakRingNum;
        int32_t shipTimeStopBreakRingNum;
        heur::rfl::BossMetaloverloadSVCameraExtensionParam tankCameraEx;
        heur::rfl::BossMetaloverloadSVCameraExtensionParam tankBreakCameraEx;
        heur::rfl::BossMetaloverloadPhase2ThrowingFocusCameraParam camera;
        heur::rfl::BossMetaloverloadSVCameraExtensionParam shipBreakCameraEx;
        heur::rfl::BossMetaloverloadPhase2ThrowingBreakDebrisParam debris;
        bool shipTargetEnables[6];
        float underwaterAnimRatio;
        heur::rfl::BossMetaloverloadFixedCamera shipThrowingCamera;
        float shipThrowingCameraDelay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ThrowingParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ThrowingParam* pInstance);
        static void Clean(BossMetaloverloadPhase2ThrowingParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2ShotParam {
        int32_t reflectMaxCount;
        int32_t reflectMaxCountByHard;
        int32_t blowHitDamagePoint;
        float speed;
        float shotOffset;
        float addSpeedBoss;
        float addSpeedBossByHard;
        float addSpeedPlyer;
        float scale;
        float homingParam;
        int32_t knokbackRingNum;
        int32_t breakRingNum;
        bool firstInputGuideDisplay;
        heur::rfl::BossMetaloverloadSVCameraExtensionParam cameraEx;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2ShotParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2ShotParam* pInstance);
        static void Clean(BossMetaloverloadPhase2ShotParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadPhase2Param {
        heur::rfl::BossSVCameraParam mainCamera;
        heur::rfl::BossMetaloverloadPhase2WaterFlowParam waterFlow;
        heur::rfl::BossMetaloverloadPhase2ThornballParam thornball;
        heur::rfl::BossMetaloverloadPhase2MoveRingParam thornballEx;
        heur::rfl::BossMetaloverloadPhase2MissileParam missile;
        heur::rfl::BossMetaloverloadPhase2ThrowingParam throwing;
        heur::rfl::BossMetaloverloadPhase2ShotParam shot;
        heur::rfl::BossMetaloverloadPhase2MoveRingParam ring;
        int32_t bigDamageRaction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadPhase2Param* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadPhase2Param* pInstance);
        static void Clean(BossMetaloverloadPhase2Param* pInstance);
    };
}

namespace heur::rfl {
    struct BossMetaloverloadConfig {
        heur::rfl::BossMetaloverloadCommonParam commonParam;
        heur::rfl::BossMetaloverloadPhaseParam phaseParam[2];
        heur::rfl::BossMetaloverloadPhase1Param phase1;
        heur::rfl::BossMetaloverloadPhase2Param phase2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossMetaloverloadConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossMetaloverloadConfig* pInstance);
        static void Clean(BossMetaloverloadConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomActionData {
        enum class ActionType : int8_t {
            INVALID_ACTION = 0,
            PHASE2_IDLE = 1,
            PHASE2_ATTACK_FIREBEAM = 2,
            PHASE2_ATTACK_FIREBOMB = 3,
            PHASE3_IDLE = 4,
            ACTION_TYPE_NUM = 5,
        };

        ActionType actionType;
        float time;
        int32_t successSkip;
        int32_t patternIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomActionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomActionData* pInstance);
        static void Clean(BossPerfectblackdoomActionData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomAutorunParam {
        float speed;
        float width;
        float bossSpeedMax;
        float bossSpeedMin;
        float bossAccelSpeed;
        float bossDecelSpeed;
        float bossKeepDistanceDefault;
        float bossKeepDistanceLimit;
        float bossStanLostDistance;
        float bossDefalutDistanceReturnTime;
        float bossDefalutDistanceReturnSpeed;
        float nearBossAccelDecelTime;
        float nearBossAccelSpeed;
        float nearBossDecelSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomAutorunParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomAutorunParam* pInstance);
        static void Clean(BossPerfectblackdoomAutorunParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomBattleLockOnCameraParam {
        csl::ut::VariableString nodeName;
        csl::math::Vector3 offset;
        float playerHeightOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomBattleLockOnCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomBattleLockOnCameraParam* pInstance);
        static void Clean(BossPerfectblackdoomBattleLockOnCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomSwitchLayerData {
        csl::ut::VariableString layerName;
        int32_t phase;
        int32_t lifeMin;
        int32_t lifeMax;
        csl::ut::VariableString tag;
        bool isChangePhaseEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomSwitchLayerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomSwitchLayerData* pInstance);
        static void Clean(BossPerfectblackdoomSwitchLayerData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomCommonParam {
        float upperRotSpeed;
        float upperResetRotSpeed;
        heur::rfl::BossPerfectblackdoomSwitchLayerData switchLayers[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomCommonParam* pInstance);
        static void Clean(BossPerfectblackdoomCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhaseParam {
        int32_t lifeCount;
        int32_t healthPoint;
        heur::rfl::BossPerfectblackdoomActionData actionTable1[24];
        heur::rfl::BossPerfectblackdoomActionData actionTable2[24];
        heur::rfl::BossPerfectblackdoomActionData actionTable3[24];
        heur::rfl::BossPerfectblackdoomActionData actionTable4[24];
        int32_t useActTblHealthPoint1;
        int32_t useActTblHealthPoint2;
        int32_t useActTblHealthPoint3;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhaseParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhaseParam* pInstance);
        static void Clean(BossPerfectblackdoomPhaseParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfig {
        heur::rfl::BossPerfectblackdoomCommonParam commonParam;
        heur::rfl::BossPerfectblackdoomPhaseParam phaseParam[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfig* pInstance);
        static void Clean(BossPerfectblackdoomConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfigPhase1CommonParam {
        float floatHeight;
        int8_t laneNum;
        float laneWidth;
        float distanceOfAttackBasePointFromPlayer;
        float hormingDistanceOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfigPhase1CommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfigPhase1CommonParam* pInstance);
        static void Clean(BossPerfectblackdoomConfigPhase1CommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPointCameraParam {
        bool enable;
        float fovy;
        float toPointDistanceMin;
        float toPointDistanceMax;
        float distanceMin;
        float distanceMax;
        float gravityOffsetMin;
        float gravityOffsetMax;
        csl::math::Vector3 playerOffsetMin;
        csl::math::Vector3 playerOffsetMax;
        csl::math::Vector3 worldOffsetMin;
        csl::math::Vector3 worldOffsetMax;
        csl::math::Vector3 pointLocalOffsetMin;
        csl::math::Vector3 pointLocalOffsetMax;
        csl::ut::VariableString nodeName;
        float roll;
        float easeInTime;
        float easeOutTime;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPointCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPointCameraParam* pInstance);
        static void Clean(BossPerfectblackdoomPointCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteBeamInfo {
        enum class LaserDirectionKind : int8_t {
            UP_DIRECTION = 0,
            DOWN_DIRECTION = 1,
            RIGHT_DIRECTION = 2,
            LEFT_DIRECTION = 3,
            UP_DOWN_DIRECTION = 4,
            LEFT_RIGHT_DIRECTION = 5,
            UDLR_DIRECTION = 6,
        };

        enum class InputGuideKind : int8_t {
            INPUT_GUIDE_KIND_NONE = 0,
            INPUT_GUIDE_KIND_LEFT_STEP = 1,
            INPUT_GUIDE_KIND_RIGHT_STEP = 2,
            INPUT_GUIDE_KIND_NUM = 3,
        };

        int8_t laneNumber;
        float height;
        float createTime;
        LaserDirectionKind laserDirKind;
        float rotSpeed;
        float moveSpeedOffset;
        float length;
        InputGuideKind inputGuideKind;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteBeamInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteBeamInfo* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteBeamInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteBeamPatternData {
        float endWaitTime;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteBeamInfo meteoriteBeamInfoTabel[80];
        uint32_t randomSeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteBeamPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteBeamPatternData* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteBeamPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteBeamParam {
        float laneOffsetDistance;
        float backwardMoveDistance;
        float startWarpWaitTime;
        float startWaitTime;
        float endWarpWaitTime;
        float colRadius;
        float dsurfBlowColScale;
        float beamColRadius;
        float curveTime;
        float speed;
        float blowSpeed;
        float lifeTime;
        int32_t blowHitDamagePoint;
        float leaveDistance;
        float blowCurvedTime;
        float blowCurvedYMax;
        float floatHeight;
        float moveStopDeltaTimeScale;
        int32_t requestMeteoriteBeamCaptionPatternNo;
        float requestMeteoriteBeamCaptionTime;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteBeamPatternData meteoriteBeamPatterns[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteBeamParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteBeamParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteBeamParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteHockeyInfo {
        enum class InputGuideKind : int8_t {
            INPUT_GUIDE_KIND_NONE = 0,
            INPUT_GUIDE_KIND_LEFT_STEP = 1,
            INPUT_GUIDE_KIND_RIGHT_STEP = 2,
            INPUT_GUIDE_KIND_NUM = 3,
        };

        bool enable;
        bool isToPlayer;
        float createTime;
        float moveSpeedOffset;
        csl::math::Vector3 createPos;
        csl::math::Vector3 shotVelocity;
        InputGuideKind inputGuideKind;
        bool colliderEnable;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteHockeyInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteHockeyInfo* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteHockeyInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteHockeyPatternData {
        float endWaitTime;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteHockeyInfo meteoriteHockeyInfoTabel[80];
        uint32_t randomSeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteHockeyPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteHockeyPatternData* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteHockeyPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1MeteoriteHockeyParam {
        float backwardMoveDistance;
        float startWarpWaitTime;
        float startWaitTime;
        float endWarpWaitTime;
        float meteoColRadius;
        float dsurfBlowColScale;
        float meteoStartMoveTime;
        float meteoSpeed;
        float blowSpeed;
        float lifeTime;
        int32_t blowHitDamagePoint;
        float leaveDistance;
        float blowCurvedTime;
        float blowCurvedYMax;
        float floatHeight;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteHockeyPatternData meteoriteHockeyPatterns[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1MeteoriteHockeyParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1MeteoriteHockeyParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase1MeteoriteHockeyParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase1DamageParam {
        float rushTime;
        float rushCameraDelayTime;
        float damageAfterTime;
        float damageAfterDistance;
        float rushFinishDamageScale;
        float blowPower;
        float blowUpPower;
        float blowDeceleration;
        float gravityPower;
        float blowEndHeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase1DamageParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase1DamageParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase1DamageParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfigPhase1 {
        heur::rfl::BossPerfectblackdoomConfigPhase1CommonParam common;
        heur::rfl::BossPerfectblackdoomAutorunParam autorun;
        heur::rfl::BossPerfectblackdoomBattleLockOnCameraParam mainCamera;
        heur::rfl::BossPerfectblackdoomPointCameraParam damageCamera;
        heur::rfl::BossPerfectblackdoomPointCameraParam attackChanceBeforeCamera;
        heur::rfl::BossPerfectblackdoomPointCameraParam rushDamageCamera;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteBeamParam meteoriteBeamParam;
        heur::rfl::BossPerfectblackdoomPhase1MeteoriteHockeyParam meteoriteHockeyParam;
        heur::rfl::BossPerfectblackdoomPhase1DamageParam damageParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfigPhase1* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfigPhase1* pInstance);
        static void Clean(BossPerfectblackdoomConfigPhase1* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfigPhase2CommonParam {
        float defaultHormingDistanceOffset;
        float chanceHormingDistanceOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfigPhase2CommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfigPhase2CommonParam* pInstance);
        static void Clean(BossPerfectblackdoomConfigPhase2CommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2ResetPlayerPosData {
        int32_t lifeCount;
        float blowTime;
        csl::ut::VariableString PositionOpjName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2ResetPlayerPosData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2ResetPlayerPosData* pInstance);
        static void Clean(BossPerfectblackdoomPhase2ResetPlayerPosData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2RushParam {
        float rushTime;
        float rushCameraDelayTime;
        float damageAfterTime;
        float rushFinishDamageScale;
        float blowUpPower;
        float blowPlayerHoldTime;
        heur::rfl::BossPerfectblackdoomPhase2ResetPlayerPosData resetPlayerPosTable[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2RushParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2RushParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase2RushParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFollowCamera {
        float Fovy;
        float ZRot;
        float Distance;
        float Yaw;
        float Pitch;
        csl::math::Vector3 targetOffset;
        float gravityOffset;
        csl::math::Vector3 playerOffset;
        bool enableCollision;
        bool enableEyePositionLimit;
        float eyePositionLimitMinY;
        float easeInTime;
        float easeOutTime;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFollowCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFollowCamera* pInstance);
        static void Clean(BossPerfectblackdoomFollowCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFixedCamera {
        csl::math::Vector3 eyeLocalOffset;
        csl::math::Vector3 lookAtLocalOffset;
        float fov;
        float roll;
        float easeInTime;
        float easeOutTime;
        float keepTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFixedCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFixedCamera* pInstance);
        static void Clean(BossPerfectblackdoomFixedCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2RushAfterParam {
        bool enable;
        bool followCameraEnable;
        heur::rfl::BossPerfectblackdoomFollowCamera shortBlowFollowCamera;
        heur::rfl::BossPerfectblackdoomFixedCamera shortBlowFixedCamera;
        float shortMotionPlayerShortBlowUpPower;
        csl::math::Vector3 shortMotionPlayerShortBlowOffsetPos;
        heur::rfl::BossPerfectblackdoomFollowCamera longBlowFollowCamera;
        heur::rfl::BossPerfectblackdoomFixedCamera longBlowFixedCamera;
        float longMotionPlayerShortBlowUpPower;
        csl::math::Vector3 longMotionPlayerShortBlowOffsetPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2RushAfterParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2RushAfterParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase2RushAfterParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBeamPerformanceParam {
        float blowPlayerHoldTime;
        float fireBeamStartTime;
        float fireBeamTime;
        csl::math::Vector3 fireBeamOffsetPos;
        bool isFireBeamOmen;
        csl::ut::VariableString cameraShakeName;
        float cameraShakeStartTime;
        csl::ut::VariableString vibrationName;
        float vibrationStartTime;
        float layerOffTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBeamPerformanceParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBeamPerformanceParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBeamPerformanceParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBeamInfo {
        enum class Phase2FireBeamPointKinds : int8_t {
            INVALID = 0,
            PLAYER_POINT = 1,
            RIGHT_UP_POINT = 2,
            RIGHT_DOWN_POINT = 3,
            LEFT_UP_POINT = 4,
            LEFT_DOWN_POINT = 5,
            POINTING_POINT = 6,
            FIRE_BIAM_KIND_NUM = 7,
        };

        bool enable;
        float moveTime;
        csl::math::Vector3 targetPos;
        Phase2FireBeamPointKinds startPointKinds;
        Phase2FireBeamPointKinds endPointKinds;
        bool omenEffect;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBeamInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBeamInfo* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBeamInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBeamPatternData {
        heur::rfl::BossPerfectblackdoomPhase2FireBeamInfo fireBeamInfoTabel[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBeamPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBeamPatternData* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBeamPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBeamParam {
        float startMoveTime;
        float endReturnMoveTime;
        float lowerHeight;
        float upperHieght;
        float moveWidth;
        float beamRadius;
        float beamLength;
        csl::math::Vector3 beamDir;
        float beamStretchOutTime;
        float attackSignTime;
        float beamStopTime;
        float beamMoveSpeed;
        heur::rfl::BossPerfectblackdoomPhase2FireBeamPatternData fireBeamPatterns[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBeamParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBeamParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBeamParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBombInfo {
        bool enable;
        int32_t targetId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBombInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBombInfo* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBombInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBombPatternData {
        heur::rfl::BossPerfectblackdoomPhase2FireBombInfo fireBombInfoTabel[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBombPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBombPatternData* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBombPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomPhase2FireBombParam {
        float startWaitTime;
        float endWaitTime;
        float beforeAttackMotionSpeed;
        float attackMotionSpeed;
        float bombRadius;
        float bombLifeTime;
        float bombSpeed;
        heur::rfl::BossPerfectblackdoomPhase2FireBombPatternData fireBombPatterns[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomPhase2FireBombParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomPhase2FireBombParam* pInstance);
        static void Clean(BossPerfectblackdoomPhase2FireBombParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfigPhase2 {
        heur::rfl::BossPerfectblackdoomConfigPhase2CommonParam common;
        heur::rfl::BossPerfectblackdoomPointCameraParam mainCamera;
        heur::rfl::BossPerfectblackdoomPointCameraParam attackChanceBeforeCamera;
        heur::rfl::BossPerfectblackdoomPointCameraParam rushDamageCamera;
        heur::rfl::BossPerfectblackdoomPhase2RushParam rushParam;
        heur::rfl::BossPerfectblackdoomPhase2RushAfterParam rushAfterParam;
        heur::rfl::BossPerfectblackdoomPhase2FireBeamPerformanceParam fireBeamPerformanceParam;
        heur::rfl::BossPerfectblackdoomPhase2FireBeamParam fireBeamParam;
        heur::rfl::BossPerfectblackdoomPhase2FireBombParam fireBombParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfigPhase2* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfigPhase2* pInstance);
        static void Clean(BossPerfectblackdoomConfigPhase2* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAutorunParam {
        float speed;
        float radius;
        float areaAspectRatio;
        float bossSpeedMax;
        float bossSpeedMin;
        float bossAccelSpeed;
        float bossDecelSpeed;
        float bossKeepDistanceDefault;
        float bossKeepDistanceLimit;
        float bossDefalutDistanceReturnTime;
        float bossDefalutDistanceReturnSpeed;
        float boostChangeDistanceSpeed;
        float boostChangeDistRatioReturnTime;
        float enableHormingDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAutorunParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAutorunParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalAutorunParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalPlayerBlowParam {
        float playerBlowPower;
        float playerBlowUpPower;
        float playerBlowDeceleration;
        float playerBlowGravityPower;
        float playerBlowTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalPlayerBlowParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalPlayerBlowParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalPlayerBlowParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalRushParam {
        float rushTime;
        csl::math::Vector3 bossBlowPos;
        float bossBlowTime;
        float bossBlowResetTime;
        float endKeepDistance;
        float endKeepDistanceTime;
        heur::rfl::BossPerfectblackdoomFinalPlayerBlowParam blowParam;
        heur::rfl::BossPerfectblackdoomPointCameraParam cameraBody;
        heur::rfl::BossPerfectblackdoomPointCameraParam cameraEyeF;
        heur::rfl::BossPerfectblackdoomPointCameraParam cameraEyeB;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalRushParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalRushParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalRushParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalStunParamPatternData {
        float stunTime;
        float keepDistane;
        float changeKeepDistanceSpeed;
        float boostChangeKeepDistanceSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalStunParamPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalStunParamPatternData* pInstance);
        static void Clean(BossPerfectblackdoomFinalStunParamPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalStunParam {
        float hormingDistanceOffsetBody;
        float endKeepDistane;
        float endChangeKeepDistanceSpeed;
        heur::rfl::BossPerfectblackdoomFinalStunParamPatternData pattern[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalStunParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalStunParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalStunParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalDownParam {
        float downTime;
        float hormingDistanceOffset;
        float bossBlowTime;
        csl::math::Vector3 bossBlowPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalDownParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalDownParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalDownParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainLaser {
        bool enable;
        bool actionGuide;
        bool playSE;
        bool playMuzzleEff;
        float shotDelayTime;
        csl::math::Vector3 direction;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainLaser* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainLaser* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainLaser* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainLaserInfo {
        bool disableCollider;
        float speed;
        float maxSpeed;
        float minSpeed;
        float accel;
        float hormingSpeed;
        float hormingMaxSpeed;
        float hormingMinSpeed;
        float hormingAccel;
        float angularSpeedMaxDeg;
        float straightTime;
        float deadWaitTime;
        float reflectDeadWaitTime;
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainLaser laser[10];
        bool debugDraw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainLaserInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainLaserInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainLaserInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainLocalMove {
        bool enable;
        uint32_t useNo;
        float delayTime;
        float moveTime;
        csl::math::Vector3 localPosition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainLocalMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainLocalMove* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainLocalMove* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainLaserTable {
        bool enable;
        uint32_t laserInfoNo;
        float delayTime;
        uint32_t loopNum;
        float loopDelayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainLaserTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainLaserTable* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainLaserTable* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainPatternData {
        float actionTime;
        float finishDelayTime;
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainLocalMove localMoveInfo[4];
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainLaserTable laserInfoTable[10];
        int32_t changeStunLaserReflectNum;
        bool debugDraw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainPatternData* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAutoRunGlindParam {
        float rollSpeed;
        float pitchSpeed;
        float neutralRollSpeed;
        float neutralPitchSpeed;
        float maxRollAngle;
        float maxPitchUpAngle;
        float maxPitchDownAngle;
        float initialSpeed;
        float maxBoostSpeed;
        float maxSideSpeed;
        float areaAspectRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAutoRunGlindParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAutoRunGlindParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalAutoRunGlindParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalAmoebaMultiRainParam {
        float keepDistance;
        float changeDistanceTime;
        float keepDistanceMax;
        float endChangeDistanceTime;
        float endKeepDistanceNormal;
        float boostChangeKeepDistanceSpeed;
        float localMoveResetMoveTime;
        float rotBodySpeed;
        float rotResetTime;
        float attackStartDelay;
        float attackEndMinElevation;
        float attackEndMaxElevation;
        csl::math::Vector3 laserCreateOffset;
        int32_t laserBlowDamagePoint;
        int32_t laserKillRingNum;
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainLaserInfo laserInfo[10];
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainPatternData pattern[3];
        heur::rfl::BossPerfectblackdoomFinalAutoRunGlindParam endAccelGlindParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalAmoebaMultiRainParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalAmoebaMultiRainParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalAmoebaMultiRainParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalTornadoAbsorbParam {
        float startAbsorbTime;
        float playerMoveTime;
        float maxRadiusMoveTime;
        float minRadiusMoveTime;
        float maxAbsorbSpeedTime;
        float maxAbsorbSpeed;
        float minAbsorbSpeed;
        float absorbRotateSpeed;
        float moveRadius;
        float startKeepActionTime;
        float pathPositionMoveTime;
        csl::math::Vector3 playerMovePos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalTornadoAbsorbParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalTornadoAbsorbParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalTornadoAbsorbParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalTornadoHitPlayerParam {
        float blowTime;
        float angularSpeedDeg;
        float backMoveSpeed;
        float radiusMinSpeed;
        float backMoveDistMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalTornadoHitPlayerParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalTornadoHitPlayerParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalTornadoHitPlayerParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalTornadoFocusCameraParam {
        bool enable;
        float startDelay;
        float easeInTime;
        float easeOutTime;
        float keepTime;
        float targetOffsetDistance;
        float distance;
        float roll;
        float fovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalTornadoFocusCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalTornadoFocusCameraParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalTornadoFocusCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoRingCircleInfo {
        bool enable;
        float radius;
        uint32_t num;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoRingCircleInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoRingCircleInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoRingCircleInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoRingCirclePatternData {
        heur::rfl::BossPerfectblackdoomFinalWingTornadoRingCircleInfo circleInfo[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoRingCirclePatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoRingCirclePatternData* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoRingCirclePatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoMoveInfo {
        bool enable;
        uint32_t useNumber;
        uint32_t ringNum;
        float verticalOffset;
        float horizontalOffset;
        float offsetMaxRingNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoMoveInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoMoveInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoMoveInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoCreateRingInfo {
        bool enable;
        uint32_t nodeNo;
        float waitTime;
        uint32_t num;
        uint32_t pattern;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoCreateRingInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoCreateRingInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoCreateRingInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoPatternData {
        float attackAfterKeepDistance;
        float attackAfterDistanceChangeSpeed;
        float boostChangeKeepDistanceSpeed;
        float tornadoRingCreateTime;
        int32_t finishWarpLocatorNo;
        heur::rfl::BossPerfectblackdoomFinalWingTornadoMoveInfo tornadoMoveInfo[5];
        heur::rfl::BossPerfectblackdoomFinalWingTornadoCreateRingInfo ringCreateInfo[5];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoPatternData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoPatternData* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoPatternData* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalWingTornadoParam {
        heur::rfl::BossPerfectblackdoomFinalTornadoAbsorbParam absorbParam;
        heur::rfl::BossPerfectblackdoomFinalTornadoHitPlayerParam hitPlayerParam;
        float keepDistance;
        float changeDistanceTime;
        float endKeepDistanceNormal;
        float endChangeDistanceTime;
        float actionEndDelay;
        float endWarpDelay;
        float attackWaitTime;
        float hormingDistanceOffset;
        csl::math::Vector3 tornadoSpawnPosoffset;
        float tornadoMoveSpeed;
        float tornadoMoveSpeedMax;
        float tornadoMoveAccel;
        heur::rfl::BossPerfectblackdoomFinalTornadoFocusCameraParam camera;
        heur::rfl::BossPerfectblackdoomFinalWingTornadoRingCirclePatternData ringCirclePattern[5];
        heur::rfl::BossPerfectblackdoomFinalWingTornadoPatternData tornadRingPattern[3];
        heur::rfl::BossPerfectblackdoomFinalAutoRunGlindParam endAccelGlindParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalWingTornadoParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalWingTornadoParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalWingTornadoParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSplashBlowWarpInfo {
        int32_t patternNo;
        int32_t locatorNo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSplashBlowWarpInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSplashBlowWarpInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalSplashBlowWarpInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSplashBlowCameraInfo {
        int32_t patternNo;
        float azimuthOffset;
        float elevationOffset;
        float distanceOffset;
        csl::math::Vector3 targetOffset;
        float startDelayTime;
        float offsetTime;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSplashBlowCameraInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSplashBlowCameraInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalSplashBlowCameraInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSplashBlowHitCamera {
        csl::math::Vector3 firstEyeLocalOffset;
        csl::math::Vector3 firstLookAtLocalOffset;
        csl::math::Vector3 secondEyeLocalOffset;
        csl::math::Vector3 secondLookAtLocalOffset;
        float offsetTransitionTime;
        float fov;
        float roll;
        float easeInTime;
        float easeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSplashBlowHitCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSplashBlowHitCamera* pInstance);
        static void Clean(BossPerfectblackdoomFinalSplashBlowHitCamera* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSplashBlowDBlowInfo {
        int32_t hitDamage;
        heur::rfl::BossPerfectblackdoomFixedCamera blowDownCamera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSplashBlowDBlowInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSplashBlowDBlowInfo* pInstance);
        static void Clean(BossPerfectblackdoomFinalSplashBlowDBlowInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalSplashBlowParam {
        csl::math::Vector3 warpOffset;
        float endKeepDistance;
        float hormingPlayerSpeed;
        csl::math::Vector3 sweepBoxHalfExtents;
        float verticalBlowCollisionSizeEx;
        csl::math::Vector3 verticalBlowCollisionOffsetPos;
        float verticalBlowCollisionAngle;
        float rightBlowCollisionSizeEx;
        csl::math::Vector3 rightBlowCollisionOffsetPos;
        float rightBlowCollisionAngle;
        float leftBlowCollisionSizeEx;
        csl::math::Vector3 leftBlowCollisionOffsetPos;
        float leftBlowCollisionAngle;
        float fourVerticalBlowCollisionSizeEx;
        csl::math::Vector3 fourVerticalBlowCollisionOffsetPos;
        float fourVerticalBlowCollisionAngle;
        float hitSplashBlowMotionSpeed;
        float vertHitShadowBlowPower;
        float vertHitShadowBlowAngle;
        float horizontalHitShadowBlowPower;
        heur::rfl::BossPerfectblackdoomFinalSplashBlowWarpInfo waroInfo[4];
        heur::rfl::BossPerfectblackdoomFinalSplashBlowCameraInfo cameraInfo[4];
        heur::rfl::BossPerfectblackdoomFinalSplashBlowHitCamera hitCamera;
        heur::rfl::BossPerfectblackdoomFinalSplashBlowDBlowInfo dblowInfo;
        heur::rfl::BossPerfectblackdoomFinalAutoRunGlindParam endAccelGlindParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalSplashBlowParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalSplashBlowParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalSplashBlowParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalGameOverCameraParam {
        float roll;
        float fovy;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 cameraOffset;
        float easeInTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalGameOverCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalGameOverCameraParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalGameOverCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalGameOverParam {
        float fadeDelayTime;
        float fadeOutTime;
        float voicePlayDelay;
        heur::rfl::BossPerfectblackdoomFinalGameOverCameraParam camera;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalGameOverParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalGameOverParam* pInstance);
        static void Clean(BossPerfectblackdoomFinalGameOverParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomFinalDebugCommand {
        bool amoebaMultiRainShotDirDebugDraw;
        bool amoebaMultiRainMovePosDebugDraw;
        bool dblowCameraDebugDraw;
        bool splashBlowCameraDebugDraw;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomFinalDebugCommand* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomFinalDebugCommand* pInstance);
        static void Clean(BossPerfectblackdoomFinalDebugCommand* pInstance);
    };
}

namespace heur::rfl {
    struct BossPerfectblackdoomConfigPhase3 {
        float floatHeight;
        int32_t raiseRingNum;
        uint32_t requestLowHPCaptionRatio;
        heur::rfl::BossPerfectblackdoomFinalAutorunParam autorun;
        heur::rfl::BossPerfectblackdoomBattleLockOnCameraParam mainCamera;
        heur::rfl::BossPerfectblackdoomFinalRushParam rushParam;
        heur::rfl::BossPerfectblackdoomFinalStunParam stunParam;
        heur::rfl::BossPerfectblackdoomFinalDownParam downParam;
        heur::rfl::BossPerfectblackdoomFinalAmoebaMultiRainParam amoebaMultiRainParam;
        heur::rfl::BossPerfectblackdoomFinalWingTornadoParam wingTornadoParam;
        heur::rfl::BossPerfectblackdoomFinalSplashBlowParam splashBlowParam;
        heur::rfl::BossPerfectblackdoomFinalGameOverParam gameOverParam;
        heur::rfl::BossPerfectblackdoomFinalDebugCommand debug;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPerfectblackdoomConfigPhase3* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPerfectblackdoomConfigPhase3* pInstance);
        static void Clean(BossPerfectblackdoomConfigPhase3* pInstance);
    };
}

namespace heur::rfl {
    struct BossAttackSignalParamInfo {
        csl::ut::VariableString tagName;
        float time;
        float delay;
        float radiusMin;
        float radiusMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossAttackSignalParamInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossAttackSignalParamInfo* pInstance);
        static void Clean(BossAttackSignalParamInfo* pInstance);
    };
}

namespace heur::rfl {
    struct BossAttackSignalConfig {
        heur::rfl::BossAttackSignalParamInfo params[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossAttackSignalConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossAttackSignalConfig* pInstance);
        static void Clean(BossAttackSignalConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossPhaseParam {
        bool isUse;
        bool isUsePillar;
        float phaseChangeHpRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossPhaseParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossPhaseParam* pInstance);
        static void Clean(BossPhaseParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossLockOnCameraParam {
        enum class EaseType : int8_t {
            ET_Sin = 0,
            ET_Cubic = 1,
            ET_Quadratic = 2,
        };

        float easeTime;
        EaseType easeType;
        csl::ut::VariableString mainLookAtNodeName;
        csl::math::Vector3 mainLookOffsetPos;
        csl::ut::VariableString subLookAtNodeName;
        csl::math::Vector3 subLookOffsetPos;
        float distance;
        csl::math::Vector3 playerOffsetPos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossLockOnCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossLockOnCameraParam* pInstance);
        static void Clean(BossLockOnCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct BossStatusConfig {
        uint32_t healthPoint;
        float stunTime;
        heur::rfl::BossPhaseParam phaseParams[8];
        heur::rfl::BossLockOnCameraParam cameraParam;
        bool isDebugDraw;
        uint32_t debugDrawPhaseIndex;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossStatusConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossStatusConfig* pInstance);
        static void Clean(BossStatusConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossDropRingConfig {
        uint32_t ringNumQuickCyloopUp;
        uint32_t ringNumQuickCyloopDown;
        uint32_t ringNumSonicSpecial;
        float ringSpawnDistance;
        float ringSuckedVelocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossDropRingConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossDropRingConfig* pInstance);
        static void Clean(BossDropRingConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossBaseConfig {
        heur::rfl::BossStatusConfig status;
        heur::rfl::BossDropRingConfig dropRing;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossBaseConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossBaseConfig* pInstance);
        static void Clean(BossBaseConfig* pInstance);
    };
}

namespace heur::rfl {
    struct BossColliderStatus {
        enum class ColliderActiveType : int8_t {
            Always = 0,
            OnContactActive = 1,
            OnContactInactive = 2,
            OnMotionActive = 3,
            OnMotionInactive = 4,
            Manual = 5,
            NUM_COLLIDER_ACTIVE_TYPE = 6,
        };

        enum class ColliderProperty : int16_t {
            CpNone = 0,
            CpBattleUse = 1,
            CpBattleUnuse = 2,
            CpRestPoint = 3,
            CpHomingTarget = 4,
            CpPerceive = 5,
            CpDamage = 6,
            CpAttack = 7,
            CpContactActive = 8,
            CpContactInactive = 9,
            CpMotionActive = 10,
            CpMotionInactive = 11,
            CpManual = 12,
            CpUpperSide = 13,
            CpLowerSide = 14,
            CpFrontSide = 15,
            CpBackSide = 16,
            CpLeftSide = 17,
            CpRightSide = 18,
            CpPointA = 19,
            CpPointB = 20,
            CpPointC = 21,
            CpPointD = 22,
            CpCyloopDownUnuse = 23,
            CpDummyDamage = 24,
            NUM_COLLIDER_PROPERTY = 25,
        };

        ColliderActiveType type;
        ColliderProperty propertys[4];
        csl::ut::VariableString text;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossColliderStatus* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossColliderStatus* pInstance);
        static void Clean(BossColliderStatus* pInstance);
    };
}

namespace heur::rfl {
    struct BossResourceInfo {
        csl::ut::VariableString modelName;
        csl::ut::VariableString animName;
        csl::math::Vector3 scale;
        csl::ut::VariableString stageName;
        csl::math::Vector3 stagePos;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossResourceInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossResourceInfo* pInstance);
        static void Clean(BossResourceInfo* pInstance);
    };
}

namespace heur::rfl {
    struct HoldPoint {
        csl::ut::VariableString nodeName;
        csl::math::Vector3 offset;
        csl::math::Vector3 rot;
        csl::ut::VariableString tagName;
        int32_t nextPointId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HoldPoint* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HoldPoint* pInstance);
        static void Clean(HoldPoint* pInstance);
    };
}

namespace heur::rfl {
    struct HoldPointParameter {
        heur::rfl::HoldPoint holdPoints[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HoldPointParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HoldPointParameter* pInstance);
        static void Clean(HoldPointParameter* pInstance);
    };
}

namespace heur::rfl {
    struct CollisionPart {
        enum class Shape : int8_t {
            SHAPE_SPHERER = 0,
            SHAPE_BOX = 1,
            SHAPE_CYLINDER = 2,
            SHAPE_CAPCULE = 3,
        };

        csl::ut::VariableString nodeName;
        Shape shape;
        bool isPhysics;
        csl::math::Vector3 size;
        csl::math::Vector3 offset;
        csl::math::Vector3 rot;
        csl::ut::VariableString tagName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollisionPart* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollisionPart* pInstance);
        static void Clean(CollisionPart* pInstance);
    };
}

namespace heur::rfl {
    struct CollisionPartParameter {
        heur::rfl::CollisionPart colParts[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollisionPartParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollisionPartParameter* pInstance);
        static void Clean(CollisionPartParameter* pInstance);
    };
}

namespace heur::rfl {
    struct BossCommonParameters {
        heur::rfl::BossResourceInfo resource;
        heur::rfl::HoldPointParameter holdParam;
        heur::rfl::CollisionPartParameter colParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossCommonParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossCommonParameters* pInstance);
        static void Clean(BossCommonParameters* pInstance);
    };
}

namespace heur::rfl {
    struct BossStatusParameterBase {
        int32_t maxHp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BossStatusParameterBase* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BossStatusParameterBase* pInstance);
        static void Clean(BossStatusParameterBase* pInstance);
    };
}

namespace heur::rfl {
    struct ExplosionParameter {
        csl::math::Vector3 centerPosOffsetMin;
        csl::math::Vector3 centerPosOffsetMax;
        float range;
        float powerMin;
        float powerMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ExplosionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ExplosionParameter* pInstance);
        static void Clean(ExplosionParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ImpulseParameter {
        csl::math::Vector3 impulseDir;
        float powerMin;
        float powerMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ImpulseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ImpulseParameter* pInstance);
        static void Clean(ImpulseParameter* pInstance);
    };
}

namespace heur::rfl {
    struct DebrisPhaseParameter {
        float marginTime;
        float nextTime;
        float gravity;
        float moveStopTime;
        bool damping;
        heur::rfl::ExplosionParameter explosionParam;
        heur::rfl::ImpulseParameter impulseParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(DebrisPhaseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(DebrisPhaseParameter* pInstance);
        static void Clean(DebrisPhaseParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EffectDebrisParameter {
        heur::rfl::DebrisPhaseParameter debrisPhaseParameters[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectDebrisParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectDebrisParameter* pInstance);
        static void Clean(EffectDebrisParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ObjEffectDebrisParameters {
        heur::rfl::EffectDebrisParameter effectDebrisParameters[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjEffectDebrisParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjEffectDebrisParameters* pInstance);
        static void Clean(ObjEffectDebrisParameters* pInstance);
    };
}

namespace heur::rfl {
    struct EffectData {
        csl::ut::VariableString effectName;
        bool linkMotionStop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectData* pInstance);
        static void Clean(EffectData* pInstance);
    };
}

namespace heur::rfl {
    struct GismoBasicParam {
        csl::ut::VariableString modelName;
        csl::ut::VariableString skeltonName;
        bool noInstance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GismoBasicParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GismoBasicParam* pInstance);
        static void Clean(GismoBasicParam* pInstance);
    };
}

namespace heur::rfl {
    struct GismoCollision {
        enum class ShapeType : int8_t {
            SHAPE_BOX = 0,
            SHAPE_SPHERE = 1,
            SHAPE_CAPSULE = 2,
            SHAPE_CYLINDER = 3,
            SHAPE_MESH = 4,
            SHAPE_NONE = 5,
        };

        enum class BasePoint : int8_t {
            BASE_CENTER = 0,
            BASE_Z_PLANE = 1,
            BASE_X_PLANE = 2,
            BASE_Y_PLANE = 3,
        };

        ShapeType shape;
        BasePoint basePoint;
        float width;
        float height;
        float depth;
        csl::ut::VariableString meshName;
        csl::math::Vector3 shapeOffset;
        float shapeSizeOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GismoCollision* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GismoCollision* pInstance);
        static void Clean(GismoCollision* pInstance);
    };
}

namespace heur::rfl {
    struct PhysicsParam {
        float mass;
        float friction;
        float gravityFactor;
        float restitution;
        float linearDamping;
        float angularDamping;
        float maxLinearVelocity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PhysicsParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PhysicsParam* pInstance);
        static void Clean(PhysicsParam* pInstance);
    };
}

namespace heur::rfl {
    struct GismoRegidBody {
        enum class RigidBodyType : int8_t {
            RIGID_BODY_NONE = 0,
            RIGID_BODY_STATIC = 1,
            RIGID_BODY_DYNAMIC = 2,
        };

        enum class RigidBodyMaterial : int8_t {
            RIGID_BODY_MAT_NONE = 0,
            RIGID_BODY_MAT_WOOD = 1,
            RIGID_BODY_MAT_IRON = 2,
            NUM_RIGID_BODY_MATS = 3,
        };

        RigidBodyType rigidBodyType;
        RigidBodyMaterial rigidBodyMaterial;
        heur::rfl::PhysicsParam physicsParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GismoRegidBody* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GismoRegidBody* pInstance);
        static void Clean(GismoRegidBody* pInstance);
    };
}

namespace heur::rfl {
    struct MotionData {
        csl::ut::VariableString motionName;
        bool syncFrame;
        bool stopEndFrame;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MotionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MotionData* pInstance);
        static void Clean(MotionData* pInstance);
    };
}

namespace heur::rfl {
    struct MirageAnimData {
        csl::ut::VariableString texSrtAnimName[3];
        csl::ut::VariableString texPatAnimName[3];
        csl::ut::VariableString matAnimName[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MirageAnimData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MirageAnimData* pInstance);
        static void Clean(MirageAnimData* pInstance);
    };
}

namespace heur::rfl {
    struct ProgramMotionData {
        enum class MotionType : uint8_t {
            MOTION_SWING = 0,
            MOTION_ROTATE = 1,
            MOTION_LINEAR_SWING = 2,
        };

        MotionType motionType;
        csl::math::Vector3 axis;
        float power;
        float speedScale;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ProgramMotionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ProgramMotionData* pInstance);
        static void Clean(ProgramMotionData* pInstance);
    };
}

namespace heur::rfl {
    struct SoundData {
        csl::ut::VariableString cueName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SoundData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SoundData* pInstance);
        static void Clean(SoundData* pInstance);
    };
}

namespace heur::rfl {
    struct KillData {
        enum class KillType : int8_t {
            KILL_TYPE_NOT_KILL = 0,
            KILL_TYPE_KILL = 1,
            KILL_TYPE_BREAK = 2,
            KILL_TYPE_MOTION = 3,
        };

        KillType killType;
        float killTime;
        csl::ut::VariableString breakMotionName;
        heur::rfl::DebrisData debrisData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(KillData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(KillData* pInstance);
        static void Clean(KillData* pInstance);
    };
}

namespace heur::rfl {
    struct ReactionData {
        heur::rfl::MotionData motionData;
        heur::rfl::MirageAnimData mirageAnimData;
        heur::rfl::ProgramMotionData programMotionData;
        heur::rfl::EffectData effectData;
        heur::rfl::SoundData soundData;
        heur::rfl::KillData killData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ReactionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ReactionData* pInstance);
        static void Clean(ReactionData* pInstance);
    };
}

namespace heur::rfl {
    struct GismoConfigDesignData {
        enum class TimeStopEffect : int8_t {
            EFFECT_HIGHLIGHT = 0,
            EFFECT_GRAY_OUT = 1,
            EFFECT_ORIGIN = 2,
        };

        float rangeIn;
        float rangeDistance;
        heur::rfl::GismoBasicParam basicParam;
        heur::rfl::GismoCollision collision;
        heur::rfl::GismoRegidBody rigidBody;
        heur::rfl::ReactionData reactionIdle;
        heur::rfl::ReactionData reactionEnter;
        heur::rfl::ReactionData reactionLeave;
        heur::rfl::ReactionData reactionStay;
        heur::rfl::ReactionData reactionStayMove;
        heur::rfl::ReactionData reactionDamage;
        bool ignoreMeteorShowerAndRespawnOnReenterRange;
        TimeStopEffect timeStopEffect;
        bool isResetEffectOnMotionLoop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GismoConfigDesignData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GismoConfigDesignData* pInstance);
        static void Clean(GismoConfigDesignData* pInstance);
    };
}

namespace heur::rfl {
    struct GismoConfigPlanData {
        enum class ContactDamageType : int8_t {
            CONTACT_DAMAGE_NONE = 0,
            CONTACT_DAMAGE_LOW_SPEED = 1,
            CONTACT_DAMAGE_MIDDLE_SPEED = 2,
            CONTACT_DAMAGE_HIGH_SPEED = 3,
        };

        ContactDamageType contactDamageType;
        bool noneDamageSpin;
        bool rideOnDamage;
        bool aerialBounce;
        bool enableEnemyBreak;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GismoConfigPlanData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GismoConfigPlanData* pInstance);
        static void Clean(GismoConfigPlanData* pInstance);
    };
}

namespace heur::rfl {
    struct RingParameter {
        float suckedTime;
        float launchAngle;
        float launchMaxSpeed;
        float launchMinSpeed;
        float randomRangeMin;
        float randomRangeMax;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RingParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RingParameter* pInstance);
        static void Clean(RingParameter* pInstance);
    };
}

namespace heur::rfl {
    struct ExtremeConfig {
        enum class LineType : int8_t {
            LINE3 = 0,
            LINE5 = 1,
            LINE_INF = 2,
        };

        LineType lineType;
        float lineWidth;
        float roadLength;
        float speed;
        float barricadeInterval;
        float emergencyDistance;
        csl::math::Vector3 barricadeSize;
        csl::ut::Color8 roadColor;
        csl::ut::Color8 barricadeColor;
        float cameraFovy;
        float cameraDistance;
        float cameraUpOffset;
        float cameraShakeOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ExtremeConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ExtremeConfig* pInstance);
        static void Clean(ExtremeConfig* pInstance);
    };
}

namespace heur::rfl {
    struct NormalFloorSize {
        float length;
        float width;
        float height;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NormalFloorSize* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NormalFloorSize* pInstance);
        static void Clean(NormalFloorSize* pInstance);
    };
}

namespace heur::rfl {
    struct ObjNormalFloorConfig {
        heur::rfl::NormalFloorSize sizeInfo[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjNormalFloorConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjNormalFloorConfig* pInstance);
        static void Clean(ObjNormalFloorConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeesParameter {
        float dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeesParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeesParameter* pInstance);
        static void Clean(EnemyBeesParameter* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetleCommonConfig {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetleCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetleCommonConfig* pInstance);
        static void Clean(EnemyBeetleCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetleConfig {
        heur::rfl::EnemyBeetleCommonConfig commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetleConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetleConfig* pInstance);
        static void Clean(EnemyBeetleConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyBeetonFCConfig {
        float shotSpeedFV;
        float shotSpeedSV;
        float bulletScaleFV;
        float bulletScaleSV;
        float shotInterval;
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyBeetonFCConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyBeetonFCConfig* pInstance);
        static void Clean(EnemyBeetonFCConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflyCommon {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam headCollisionParam;
        heur::rfl::EnemyCollisionParam bodyCollisionParam;
        heur::rfl::EnemyComboParam comboParam;
        heur::rfl::EnemyCollisionParam cellCollisionParam;
        heur::rfl::EnemyComboParam cellComboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflyCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflyCommon* pInstance);
        static void Clean(EnemyChaosflyCommon* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaosflyConfig {
        heur::rfl::EnemyChaosflyCommon commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaosflyConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaosflyConfig* pInstance);
        static void Clean(EnemyChaosflyConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarCommon {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyCollisionParam collisionParamBody;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarCommon* pInstance);
        static void Clean(EnemyChaospillarCommon* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyChaospillarConfig {
        heur::rfl::EnemyChaospillarCommon commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyChaospillarConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyChaospillarConfig* pInstance);
        static void Clean(EnemyChaospillarConfig* pInstance);
    };
}

namespace heur::rfl {
    struct TimeStopDamageVelocityParam {
        uint32_t damage_num_threshold;
        float velocity_scale_base;
        float velocity_scale_linear;
        float velocity_acceleration;
        float velocity_max;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TimeStopDamageVelocityParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TimeStopDamageVelocityParam* pInstance);
        static void Clean(TimeStopDamageVelocityParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCometCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        csl::math::Vector3 colliderPositionOffset;
        csl::math::Vector3 damageColliderPositionOffset;
        float colliderRadius;
        float colliderHeight;
        float damageColliderRadiusOffset;
        float damageColliderHeightOffset;
        csl::math::Vector3 colliderPositionOffsetWhileBlownUp;
        float colliderRadiusOffsetWhileBlownUp;
        float colliderHeightOffsetWhileBlownUp;
        float attackShockWaveColliderRadiusOffset;
        float attackShockWaveColliderHeightOffset;
        float guardToShockWaveWaitTime;
        float readyShockWaveWaitTime;
        float attackingShockWaveTime;
        float attackShockWaveDamageVelocityScale;
        float closeContactDistance;
        float closeContactTime;
        float rotateLimitAngle;
        float barrierPositionFOffset;
        float barrierPositionYOffset;
        float barrierRotateIntervalTime;
        float barrierRecoveryIntervalTime;
        float barrierFlipGuardVelocityScaleV;
        float barrierFlipGuardVelocityScaleH;
        float barrierForciblyReleaseTimeForDamage;
        float stunTime;
        float downTime;
        float shootReflectorPositionYOffsetForFV;
        float shootReflectorPositionYOffsetForSV;
        float shootReflectorPositionZOffset;
        float shootReflectorWidth;
        float shootReflectorHeight;
        float shootReflectorSpeed;
        float shootReflectorLeanAngle;
        float shootReflectorLeanTime;
        float reflectorFlipGuardVelocityScaleV;
        float reflectorFlipGuardVelocityScaleH;
        float warpRadius;
        float warpHeight;
        csl::math::Vector3 warpOffsetForFV;
        csl::math::Vector3 warpOffsetForSV;
        csl::math::Vector3 warpOffsetForFVWhileBlownUp;
        csl::math::Vector3 warpOffsetForSVWhileBlownUp;
        csl::math::Vector3 warpOffsetForFVWhileBlownAway;
        csl::math::Vector3 warpOffsetForSVWhileBlownAway;
        float warpAngleForFV;
        float warpAngleForSV;
        float warpAngleForFVWhileBlownUp;
        float warpAngleForSVWhileBlownUp;
        float warpAngleForFVWhileBlownAway;
        float warpAngleForSVWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        heur::rfl::TimeStopDamageVelocityParam timeStopDamageVelocityParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCometCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCometCommonParam* pInstance);
        static void Clean(EnemyCometCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCometConfig {
        heur::rfl::EnemyCometCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCometConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCometConfig* pInstance);
        static void Clean(EnemyCometConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        int32_t maxHealthPointVehicle;
        csl::math::Vector3 colliderPositionOffset;
        csl::math::Vector3 colliderPositionOffsetVehicle;
        csl::math::Vector3 damageColliderPositionOffset;
        csl::math::Vector3 damageColliderPositionOffsetVehicle;
        float colliderRadius;
        float colliderRadiusVehicle;
        float colliderHeight;
        float colliderHeightVehicle;
        float damageColliderRadiusOffset;
        float damageColliderRadiusOffsetVehicle;
        float damageColliderHeightOffset;
        float damageColliderHeightOffsetVehicle;
        float attackColliderRadiusOffsetVehicle;
        csl::math::Vector3 colliderPositionOffsetWhileBlownUp;
        float colliderRadiusOffsetWhileBlownUp;
        float colliderHeightOffsetWhileBlownUp;
        float moveTime;
        float attackShockWaveColliderRadiusOffset;
        float attackShockWaveColliderHeightOffset;
        uint32_t changeShockWaveDamageValue;
        float readyShockWaveWaitTime;
        float attackingShockWaveTime;
        float startMoveWaitTime;
        float attackProjectileRadius;
        float attackProjectileHeight;
        float attackProjectileSpeed;
        float attackProjectileHomingAngularSpeed;
        float attackProjectileHomingOnTime;
        float attackProjectileLifeTime;
        float startProjectileWaitTime;
        float readyProjectileWaitTime;
        float readyTornadoWaitTime;
        float rotateSpeed;
        float rotateLimitAngle;
        float damageFlipGuardVelocityScaleV;
        float damageFlipGuardVelocityScaleH;
        float damageFlipGuardOutOfControlTime;
        float stunTime;
        float warpRadius;
        float warpRadiusVehicle;
        float warpHeight;
        float warpHeightVehicle;
        csl::math::Vector3 warpOffsetForFV;
        csl::math::Vector3 warpOffsetForFVVehicle;
        csl::math::Vector3 warpOffsetForFVWhileBlownUp;
        csl::math::Vector3 warpOffsetForFVWhileBlownAway;
        float warpAngleForFV;
        float warpAngleForFVVehicle;
        float warpAngleForSV;
        float warpAngleForSVVehicle;
        float warpAngleForFVWhileBlownUp;
        float warpAngleForSVWhileBlownUp;
        float warpAngleForFVWhileBlownAway;
        float warpAngleForSVWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        bool warpOffsetCalcFromNowRotVehicle;
        heur::rfl::TimeStopDamageVelocityParam timeStopDamageVelocityParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoCommonParam* pInstance);
        static void Clean(EnemyCoreMachoCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyCoreMachoConfig {
        heur::rfl::EnemyCoreMachoCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyCoreMachoConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyCoreMachoConfig* pInstance);
        static void Clean(EnemyCoreMachoConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlapperCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        csl::ut::VariableString colliderNodeName;
        float rotateSpeed;
        float stunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlapperCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlapperCommonParam* pInstance);
        static void Clean(EnemyEggFlapperCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlapperConfig {
        heur::rfl::EnemyEggFlapperCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlapperConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlapperConfig* pInstance);
        static void Clean(EnemyEggFlapperConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlyerCommonParam {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlyerCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlyerCommonParam* pInstance);
        static void Clean(EnemyEggFlyerCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggFlyerConfig {
        heur::rfl::EnemyEggFlyerCommonParam commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggFlyerConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggFlyerConfig* pInstance);
        static void Clean(EnemyEggFlyerConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGuardianCommonParam {
        float killWaitTime;
        float rotateSpeed;
        float startShootRocketPunchWaitTime;
        float rocketPunchSpeed;
        float rocketPunchHomingAngularSpeed;
        float rocketPunchHomingOnTime;
        float rocketPunchRicochetSpeed;
        float rocketPunchLifeTime;
        float startShootVulcanWaitTime;
        float readyVulcanWaitTime;
        float vulcanSpeed;
        float vulcanIntervalTime;
        float vulcanRadius;
        float vulcanRange;
        float vulcanRotateSpeedRate;
        int32_t vulcanRotateCount;
        float revivalArmsWaitTime;
        float stunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGuardianCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGuardianCommonParam* pInstance);
        static void Clean(EnemyEggGuardianCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGuardianConfig {
        heur::rfl::EnemyEggGuardianCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGuardianConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGuardianConfig* pInstance);
        static void Clean(EnemyEggGuardianConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGunnerCommon {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGunnerCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGunnerCommon* pInstance);
        static void Clean(EnemyEggGunnerCommon* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGunnerGuidedRocketParam {
        float searchDistance;
        float horzLimitDegree;
        float vertLimitDegree;
        float speed;
        float lifeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGunnerGuidedRocketParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGunnerGuidedRocketParam* pInstance);
        static void Clean(EnemyEggGunnerGuidedRocketParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggGunnerConfig {
        heur::rfl::EnemyEggGunnerCommon commonParams;
        heur::rfl::EnemyEggGunnerGuidedRocketParam guidedRocketParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggGunnerConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggGunnerConfig* pInstance);
        static void Clean(EnemyEggGunnerConfig* pInstance);
    };
}

namespace heur::rfl {
    struct LanceCollisionParam {
        float radius;
        float height;
        csl::math::Vector3 positionOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LanceCollisionParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LanceCollisionParam* pInstance);
        static void Clean(LanceCollisionParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggPawnCommonConfig {
        float stunHp;
        float chaosSpearStunTime;
        float moveAnimBaseVelocity;
        float attackAnimBaseVelocity;
        float attackAnimBaseVelocityLance;
        float prevAttackRotateTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;
        heur::rfl::LanceCollisionParam lanceCollisionParam;
        heur::rfl::LanceCollisionParam lanceCollisionParamSV;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggPawnCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggPawnCommonConfig* pInstance);
        static void Clean(EnemyEggPawnCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggPawnConfig {
        heur::rfl::EnemyEggPawnCommonConfig commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggPawnConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggPawnConfig* pInstance);
        static void Clean(EnemyEggPawnConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggpawnFcConfig {
        float shotSpeedFV;
        float shotSpeedSV;
        float bulletScaleFV;
        float bulletScaleSV;
        float bulletMaxDistanceFV;
        float bulletMaxDistanceSV;
        uint32_t shotContinuousShotNum;
        uint32_t shotContinuousShotNumConst;
        float shotCoolDownTime;
        float shotCoolDownTimeConst;
        float damageCoolDownTime;
        float shotInterval;
        float serachAngleY;
        float oneHandShotSpeedFV;
        float oneHandShotSpeedSV;
        float oneHandBulletScaleFV;
        float oneHandBulletScaleSV;
        float oneHandBulletMaxDistanceFV;
        float oneHandBulletMaxDistanceSV;
        uint32_t oneHandShotContinuousShotNum;
        float oneHandShotCoolDownTime;
        float oneHandDamageCoolDownTime;
        float oneHandShotInterval;
        float oneHandChargeTime;
        float oneHandSerachAngleY;
        float fallSpeed;
        float fallSpeedAppear;
        float fallDeadTime;
        float threadGrassRadius;
        float threadGrassTime;
        float checkOnGroundUpOffset;
        float chaosSpearStunTime;
        float respawnTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggpawnFcConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggpawnFcConfig* pInstance);
        static void Clean(EnemyEggpawnFcConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyEggTankConfig {
        csl::math::Vector3 respawnOffset;
        float respawnTime;
        float bulletFallSpeed;
        float addBulletBoostEnergy;
        float addBulletDoubleBoostEnergy;
        float fallSpeed;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyEggTankConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyEggTankConfig* pInstance);
        static void Clean(EnemyEggTankConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyFlashCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        csl::math::Vector3 colliderPositionOffset;
        csl::math::Vector3 damageColliderPositionOffset;
        float colliderRadius;
        float colliderHeight;
        float damageColliderRadiusOffset;
        float damageColliderHeightOffset;
        csl::math::Vector3 colliderPositionOffsetWhileBlownUp;
        float colliderRadiusOffsetWhileBlownUp;
        float colliderHeightOffsetWhileBlownUp;
        float rotateSpeed;
        float rotateLimitAngle;
        float shootCloneInterval;
        float cloneRadius;
        float cloneLength;
        float cloneSpeed;
        float cloneAppearDelayTime;
        float cloneAppearTime;
        float stunTime;
        float warpRadius;
        float warpHeight;
        heur::rfl::TimeStopDamageVelocityParam timeStopDamageVelocityParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyFlashCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyFlashCommonParam* pInstance);
        static void Clean(EnemyFlashCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyFlashConfig {
        heur::rfl::EnemyFlashCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyFlashConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyFlashConfig* pInstance);
        static void Clean(EnemyFlashConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyGunHunterCommonConfig {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyGunHunterCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyGunHunterCommonConfig* pInstance);
        static void Clean(EnemyGunHunterCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyGunHunterConfig {
        heur::rfl::EnemyGunHunterCommonConfig commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyGunHunterConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyGunHunterConfig* pInstance);
        static void Clean(EnemyGunHunterConfig* pInstance);
    };
}

namespace heur::rfl {
    struct Movement {
        float rotateSpeedMin;
        float rotateSpeedMax;
        float rotateSpeedMaxSpeedMin;
        float rotateSpeedMinSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Movement* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Movement* pInstance);
        static void Clean(Movement* pInstance);
    };
}

namespace heur::rfl {
    struct Eyesight {
        float distance;
        float angle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Eyesight* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Eyesight* pInstance);
        static void Clean(Eyesight* pInstance);
    };
}

namespace heur::rfl {
    struct Fight {
        float attackRange;
        float attackAngle;
        float attackSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Fight* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Fight* pInstance);
        static void Clean(Fight* pInstance);
    };
}

namespace heur::rfl {
    struct VolumeInfo {
        csl::math::Vector3 volumeSize;
        csl::math::Vector3 volumeOffset;
        csl::math::Vector3 volumeRotation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VolumeInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VolumeInfo* pInstance);
        static void Clean(VolumeInfo* pInstance);
    };
}

namespace heur::rfl {
    struct MappingPairInfo {
        enum class VolumeShape : int8_t {
            SPHERE = 0,
            BOX = 1,
            CYLINDER = 2,
            CAPSULE = 3,
            NUM = 4,
        };

        csl::ut::VariableString tagName;
        int8_t pieceNum;
        float pieceFuncFactor;
        VolumeShape volumeShape;
        csl::ut::VariableString humanNodeName;
        heur::rfl::VolumeInfo humanVolume;
        csl::ut::VariableString eggNodeName;
        heur::rfl::VolumeInfo eggVolume;
        bool effectActive;
        bool debugDraw;
        bool debugDrawVolumeAxis;
        bool debugDrawAxis;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(MappingPairInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(MappingPairInfo* pInstance);
        static void Clean(MappingPairInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManCommonConfig {
        heur::rfl::Movement movement;
        heur::rfl::Eyesight eyesight;
        heur::rfl::Fight fight;
        heur::rfl::MappingPairInfo mappingPairInfo[32];
        heur::rfl::EnemyCollisionParam humanCollisionParam;
        heur::rfl::EnemyComboParam humanComboParam;
        heur::rfl::EnemyCollisionParam eggCollisionParam;
        heur::rfl::EnemyComboParam eggComboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManCommonConfig* pInstance);
        static void Clean(EnemyManCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct ManHumanActionRate {
        float actionRate[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ManHumanActionRate* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ManHumanActionRate* pInstance);
        static void Clean(ManHumanActionRate* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManSingleConfig {
        int32_t maxHealthPoint;
        float maxStunPoint[3];
        float stunDecreaseStartTime;
        float stunDecreaseSpeed;
        float maxStaggerPoint[3];
        float staggerDecreaseStartTime;
        float staggerDecreaseSpeed;
        float stunTime;
        float attackRate;
        float attackMotionSpeed;
        float wallTime;
        int32_t wallLife;
        float guardTime;
        float guardCoolTime;
        heur::rfl::ManHumanActionRate rateTable[4];
        float coolTime[6];
        float attackCoolTime;
        float actionDistance[6];
        float nearRange;
        int32_t nearRateId;
        int32_t farRateId;
        bool isCounterGuard;
        bool isCounterWall;
        bool isSpikeWall;
        int32_t waveNum;
        float waveUpTime;
        float waveLifeTime;
        float waveDownTime;
        float waveRadius;
        float waveAddRadius;
        float waveSpawnTime;
        float waveKeepRadius;
        float waveHeight;
        float straightWaveUpTime;
        float straightWaveWaitTime;
        float straightWaveDownTime;
        float straightWaveSpeed;
        float straightWaveWidth;
        float straightWaveHeight;
        int32_t rushNum;
        float downTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManSingleConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManSingleConfig* pInstance);
        static void Clean(EnemyManSingleConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManSquadConfig {
        int32_t maxActionCount;
        float spAttackWaitTime;
        int32_t humanMaxActionCount[6];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManSquadConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManSquadConfig* pInstance);
        static void Clean(EnemyManSquadConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManTypeConfig {
        heur::rfl::EnemyManSingleConfig single;
        heur::rfl::EnemyManSquadConfig squad;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManTypeConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManTypeConfig* pInstance);
        static void Clean(EnemyManTypeConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyManConfig {
        heur::rfl::EnemyManCommonConfig commonParam;
        heur::rfl::EnemyManTypeConfig typeParams[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyManConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyManConfig* pInstance);
        static void Clean(EnemyManConfig* pInstance);
    };
}

namespace heur::rfl {
    struct VolumeSize {
        float width;
        float height;
        float depth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(VolumeSize* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(VolumeSize* pInstance);
        static void Clean(VolumeSize* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyMotoraConfig {
        float respawnTime;
        float fallSpeed;
        float threadGrassRadius;
        float threadGrassTime;
        float rigidbodyMaxSpeed;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyMotoraConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyMotoraConfig* pInstance);
        static void Clean(EnemyMotoraConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyRhinolinerCommonConfig {
        float stunHp;
        float chaosSpearStunTime;
        heur::rfl::EnemyCollisionParam collisionParam;
        heur::rfl::EnemyComboParam comboParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyRhinolinerCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyRhinolinerCommonConfig* pInstance);
        static void Clean(EnemyRhinolinerCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyRhinolinerConfig {
        heur::rfl::EnemyRhinolinerCommonConfig commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyRhinolinerConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyRhinolinerConfig* pInstance);
        static void Clean(EnemyRhinolinerConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoHomingLaserInfo {
        csl::math::Vector3 launch_position_offset;
        csl::math::Vector3 launch_direction;
        csl::math::Vector3 target_position_offset;
        float speedAtStart;
        float speed;
        float speedMin;
        float speedMax;
        float speedAcceleration;
        float relativeSpeedToDecelerate;
        float decelerateAtOverRelativeSpeed;
        float radius;
        float length;
        float damage_collider_scale;
        float lifeTime;
        float angularSpeed;
        float startDistance;
        float endDistance;
        float onTimeAtStart;
        float onTime;
        float offTime;
        float directionError;
        float targetPositionEstimatedTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoHomingLaserInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoHomingLaserInfo* pInstance);
        static void Clean(EnemySalvoHomingLaserInfo* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        csl::math::Vector3 colliderPositionOffset;
        csl::math::Vector3 damageColliderPositionOffset;
        float colliderRadius;
        float colliderHeight;
        float damageColliderRadiusOffset;
        float damageColliderHeightOffset;
        csl::math::Vector3 colliderPositionOffsetWhileBlownUp;
        float colliderRadiusOffsetWhileBlownUp;
        float colliderHeightOffsetWhileBlownUp;
        float moveSpeed;
        float retreatDistance;
        float stunTime;
        float startHomingLaserRapidFireWaitTime;
        float readyHomingLaserRapidFireWaitTime;
        float shootHomingLaserRapidFireInterval;
        heur::rfl::EnemySalvoHomingLaserInfo homingLaserRapidFire;
        float warpRadius;
        float warpHeight;
        csl::math::Vector3 warpOffsetForFV;
        csl::math::Vector3 warpOffsetForSV;
        csl::math::Vector3 warpOffsetForFVWhileBlownUp;
        csl::math::Vector3 warpOffsetForSVWhileBlownUp;
        csl::math::Vector3 warpOffsetForFVWhileBlownAway;
        csl::math::Vector3 warpOffsetForSVWhileBlownAway;
        float warpAngleForFV;
        float warpAngleForSV;
        float warpAngleForFVWhileBlownUp;
        float warpAngleForSVWhileBlownUp;
        float warpAngleForFVWhileBlownAway;
        float warpAngleForSVWhileBlownAway;
        bool warpOffsetCalcFromNowRot;
        heur::rfl::TimeStopDamageVelocityParam timeStopDamageVelocityParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoCommonParam* pInstance);
        static void Clean(EnemySalvoCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySalvoConfig {
        heur::rfl::EnemySalvoCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySalvoConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySalvoConfig* pInstance);
        static void Clean(EnemySalvoConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySoldierCommonParam {
        float killWaitTime;
        int32_t maxHealthPoint;
        csl::math::Vector3 colliderPositionOffset;
        csl::math::Vector3 damageColliderPositionOffset;
        float colliderRadius;
        float colliderHeight;
        float damageColliderRadiusOffset;
        float damageColliderHeightOffset;
        csl::math::Vector3 colliderPositionOffsetWhileBlownUp;
        float colliderRadiusOffsetWhileBlownUp;
        float colliderHeightOffsetWhileBlownUp;
        csl::math::Vector3 attackBladeColliderPositionOffset;
        csl::math::Vector3 attackBladeColliderScale;
        float readyAttackBladeWaitTime;
        float attackingBladeTime;
        float attackedBladeRecoveryTime;
        float superArmorDamageVelocityScale;
        float attackableAngle;
        float rotateSpeed;
        float rotateSpeedWhileMoving;
        float rotateLimitAngle;
        float stunTime;
        float warpRadius;
        float warpHeight;
        heur::rfl::TimeStopDamageVelocityParam timeStopDamageVelocityParams[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySoldierCommonParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySoldierCommonParam* pInstance);
        static void Clean(EnemySoldierCommonParam* pInstance);
    };
}

namespace heur::rfl {
    struct EnemySoldierConfig {
        heur::rfl::EnemySoldierCommonParam commonParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemySoldierConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemySoldierConfig* pInstance);
        static void Clean(EnemySoldierConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyTwisterCommonConfig {
        heur::rfl::EnemyCollisionParam collisionParam;
        float attackColliderRadius;
        heur::rfl::EnemyComboParam comboParam;
        heur::rfl::EnemyCollisionParam collisionParamSV;
        float attackColliderRadiusSV;
        heur::rfl::EnemyComboParam comboParamSV;
        float battleDistance;
        float rotateSpeed;
        float chaosSpearStunTime;
        bool useUniqueDebrisSetting;
        heur::rfl::DebrisParameter debris;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyTwisterCommonConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyTwisterCommonConfig* pInstance);
        static void Clean(EnemyTwisterCommonConfig* pInstance);
    };
}

namespace heur::rfl {
    struct EnemyTwisterConfig {
        heur::rfl::EnemyTwisterCommonConfig commonParams;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EnemyTwisterConfig* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EnemyTwisterConfig* pInstance);
        static void Clean(EnemyTwisterConfig* pInstance);
    };
}

namespace heur::rfl {
    struct ObjGFieldCylinderSplineSpawner : heur::rfl::GravityFieldCylinderSplineSetupParameter {

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjGFieldCylinderSplineSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjGFieldCylinderSplineSpawner* pInstance);
        static void Clean(ObjGFieldCylinderSplineSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct GimmickCameraOptionalParam {
        bool useCameraParam;
        float interoplateTimeActivate;
        float interoplateTimeDeactivate;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 cameraPosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GimmickCameraOptionalParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GimmickCameraOptionalParam* pInstance);
        static void Clean(GimmickCameraOptionalParam* pInstance);
    };
}

namespace heur::rfl {
    struct GimmickCameraParam {
        float interoplateTimeActivate;
        float interoplateTimeDeactivate;
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 cameraPosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GimmickCameraParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GimmickCameraParam* pInstance);
        static void Clean(GimmickCameraParam* pInstance);
    };
}

namespace heur::rfl {
    struct GimmickCameraSimpleParam {
        csl::math::Vector3 targetOffset;
        csl::math::Vector3 cameraPosOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GimmickCameraSimpleParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GimmickCameraSimpleParam* pInstance);
        static void Clean(GimmickCameraSimpleParam* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWindRoadSwitchCollidersSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWindRoadSwitchCollidersSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWindRoadSwitchCollidersSpawner* pInstance);
        static void Clean(ObjWindRoadSwitchCollidersSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceMaterialLuminesParameter {
        float m_width;
        float m_luminesPower;
        float m_luminesColoringWitdh;
        float m_luminesOffset;
        float m_rgb[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceMaterialLuminesParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceMaterialLuminesParameter* pInstance);
        static void Clean(WhiteSpaceMaterialLuminesParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceColoringParameter {
        float m_startHeight;
        float m_endHeight;
        float m_coloringSpeed;
        float m_startEffectTime;
        float m_cameraStartHeight;
        float m_cameraEndHeight;
        float m_middleHeight;
        heur::rfl::WhiteSpaceMaterialLuminesParameter luminesParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceColoringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceColoringParameter* pInstance);
        static void Clean(WhiteSpaceColoringParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceVanishingParameter {
        float m_startHeight;
        float m_endHeight;
        float m_coloringSpeed;
        float m_width;
        float m_noisePower;
        float m_noiseSpeed;
        float m_rgb[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceVanishingParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceVanishingParameter* pInstance);
        static void Clean(WhiteSpaceVanishingParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceStageGateColoringParameter {
        heur::rfl::WhiteSpaceColoringParameter coloringParam[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceStageGateColoringParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceStageGateColoringParameter* pInstance);
        static void Clean(WhiteSpaceStageGateColoringParameter* pInstance);
    };
}

namespace heur::rfl {
    struct WhiteSpaceColoringParameters {
        heur::rfl::WhiteSpaceVanishingParameter vainishParam;
        heur::rfl::WhiteSpaceColoringParameter coloringParam[5];
        heur::rfl::WhiteSpaceStageGateColoringParameter stagegateParam[6];
        heur::rfl::WhiteSpaceVanishingParameter eclipseParam;
        heur::rfl::WhiteSpaceVanishingParameter eclipseEndParam;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhiteSpaceColoringParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhiteSpaceColoringParameters* pInstance);
        static void Clean(WhiteSpaceColoringParameters* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceGeraldChaosSpearSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceGeraldChaosSpearSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceGeraldChaosSpearSpawner* pInstance);
        static void Clean(ObjWhiteSpaceGeraldChaosSpearSpawner* pInstance);
    };
}

namespace heur::rfl {
    struct ObjWhiteSpaceGeraldChaosSpearTargetSpawner {
        int32_t dummy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ObjWhiteSpaceGeraldChaosSpearTargetSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ObjWhiteSpaceGeraldChaosSpearTargetSpawner* pInstance);
        static void Clean(ObjWhiteSpaceGeraldChaosSpearTargetSpawner* pInstance);
    };
}

namespace app::player {
    struct PlayerCameraParameter {
        enum class CameraType : uint8_t {
            None = 0,
            Fixed = 1,
            Offset = 2,
            Follow = 3,
            Pan = 4,
            StaticPan = 5,
            PanUpByFront = 6,
        };

        enum class CameraCoordType : uint8_t {
            Orthgonal = 0,
            Spherical = 1,
        };

        CameraType type;
        float time;
        float easeinTime;
        CameraCoordType lookAtCoord;
        csl::math::Vector3 localLookAtOffset;
        csl::math::Vector3 worldLookAtOffset;
        CameraCoordType eyeCoord;
        csl::math::Vector3 localEyeOffset;
        csl::math::Vector3 worldEyeOffset;
        float roll;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerCameraParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerCameraParameter* pInstance);
        static void Clean(PlayerCameraParameter* pInstance);
    };
}

namespace app::player {
    struct PlayerCameraSetParameter {
        csl::ut::VariableString name;
        float easeoutTime;
        app::player::PlayerCameraParameter param[8];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerCameraSetParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerCameraSetParameter* pInstance);
        static void Clean(PlayerCameraSetParameter* pInstance);
    };
}

namespace app::player {
    struct PlayerCameraSetParameters {
        app::player::PlayerCameraSetParameter data[45];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerCameraSetParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerCameraSetParameters* pInstance);
        static void Clean(PlayerCameraSetParameters* pInstance);
    };
}

namespace heur::rfl {
    struct EffectRecord : heur::rfl::Record {
        csl::ut::VariableString emitterSetName[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectRecord* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectRecord* pInstance);
        static void Clean(EffectRecord* pInstance);
    };
}

namespace heur::rfl {
    struct EffectRecordBaseTable {
        heur::rfl::EffectRecord data[100];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectRecordBaseTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectRecordBaseTable* pInstance);
        static void Clean(EffectRecordBaseTable* pInstance);
    };
}

namespace heur::rfl {
    struct EffectRecordTable {
        heur::rfl::EffectRecord data[255];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(EffectRecordTable* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(EffectRecordTable* pInstance);
        static void Clean(EffectRecordTable* pInstance);
    };
}

namespace app::player {
    struct PlayerParamOffensive {
        uint16_t pointMin;
        uint16_t pointMax;
        float damageRandomRate;
        float damageRandomRateSS;
        float shapeDamageRate;
        float shapeStunRate;
        float shapeStaggerRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamOffensive* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamOffensive* pInstance);
        static void Clean(PlayerParamOffensive* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDefensive {
        uint8_t rateMin;
        uint8_t rateMax;
        uint16_t infimumDropRings;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDefensive* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDefensive* pInstance);
        static void Clean(PlayerParamDefensive* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAttackCommon {
        app::player::PlayerParamOffensive offensive;
        app::player::PlayerParamDefensive defensive;
        float criticalDamageRate;
        float criticalRate;
        float criticalRateSS;
        float downedDamageRate;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAttackCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAttackCommon* pInstance);
        static void Clean(PlayerParamAttackCommon* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAttackData {
        enum class HitSE : int8_t {
            SE_None = -1,
            Weak = 0,
            Strong = 1,
            VeryStrong = 2,
        };

        enum class Attribute {
            AttrHomingAttack = 0,
            AttrSpinAttack = 1,
            AttrRush = 2,
            AttrDummy2 = 3,
            AttrBlowOff = 4,
            AttrBlowUp = 5,
            AttrSlamDownward = 6,
            AttrDuplicatedDamage = 7,
            AttrShot = 8,
            AttrSlingShot = 9,
            AttrAcceleCombo = 10,
            AttrStomping = 11,
            AttrFinish = 12,
            AttrAcceleHitRate = 13,
            AttrNoneHitEffect = 14,
            AttrNoneHitReaction = 15,
            AttrChaosSpear = 16,
            AttrBlowOffHeavy = 17,
            AttrBlowOffDBlow = 18,
        };

        float damageRate;
        float damageRateAcceleMode;
        float damageRateManual;
        float stunPoint;
        float staggerPoint;
        csl::math::Vector3 velocity;
        float velocityKeepTime;
        float velocityKeepTimeBrake;
        float svSpeedScale;
        float svBrakeScale;
        float bsSpeedScale;
        float bsBrakeScale;
        float wsSpeedScale;
        float wsBrakeScale;
        float addComboValue;
        float addComboValueAccele;
        csl::math::Vector3 gimmickVelocity;
        float ignoreTime;
        csl::ut::Bitset<uint32_t> attributes;
        HitSE se;
        csl::ut::VariableString hitEffectName;
        csl::ut::VariableString hitStopName;
        csl::ut::VariableString hitStopNameDead;
        csl::ut::VariableString hitStopNameDeadBoss;
        csl::ut::VariableString hitCameraShakeName;
        csl::ut::VariableString hitCameraShakeNameDead;
        csl::ut::VariableString hitCameraShakeNameDeadBoss;
        csl::ut::VariableString hitVibrationName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAttackData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAttackData* pInstance);
        static void Clean(PlayerParamAttackData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAttack {
        app::player::PlayerParamAttackCommon common;
        app::player::PlayerParamAttackData spinAttack;
        app::player::PlayerParamAttackData spinDash;
        app::player::PlayerParamAttackData homingAttack;
        app::player::PlayerParamAttackData homingAttackAir;
        app::player::PlayerParamAttackData stomping;
        app::player::PlayerParamAttackData stompingAttack;
        app::player::PlayerParamAttackData boundStompingLast;
        app::player::PlayerParamAttackData sliding;
        app::player::PlayerParamAttackData boostAttack;
        app::player::PlayerParamAttackData warpAttack;
        app::player::PlayerParamAttackData dblowRush;
        app::player::PlayerParamAttackData dblowRushFinish;
        app::player::PlayerParamAttackData dblowOff;
        app::player::PlayerParamAttackData dblowUp;
        app::player::PlayerParamAttackData dblowDown;
        app::player::PlayerParamAttackData chaosSpear;
        app::player::PlayerParamAttackData dsurf;
        app::player::PlayerParamAttackData dsurfSpin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAttack* pInstance);
        static void Clean(PlayerParamAttack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAttackCollider {
        enum class Condition : int8_t {
            Time = 0,
            Animation = 1,
        };

        enum class Shape : int8_t {
            Sphere = 0,
            Cylinder = 1,
            Box = 2,
        };

        Condition condition;
        int8_t count;
        float spanTime;
        Shape shape;
        csl::math::Vector3 shapeSize;
        csl::math::Vector3 shapeOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAttackCollider* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAttackCollider* pInstance);
        static void Clean(PlayerParamAttackCollider* pInstance);
    };
}

namespace app::player {
    struct PlayerParamStompingAttack {
        app::player::PlayerParamAttackCollider hit;
        app::player::PlayerParamAttackCollider hitLast;
        float riseTime;
        float flipSpeed;
        float motionTime;
        float lastHitTime;
        float slowRatio;
        float minPressTime;
        float minPressTimeHeight;
        float maxPressTime;
        float maxPressTimeHeight;
        csl::math::Vector3 offset;
        csl::ut::VariableString cameraName;
        csl::ut::VariableString cameraNameBarrage;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamStompingAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamStompingAttack* pInstance);
        static void Clean(PlayerParamStompingAttack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBehind {
        float moveTime;
        float moveTimeSS;
        float tangentScale;
        float waitTime;
        float cameraTurnRatio;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBehind* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBehind* pInstance);
        static void Clean(PlayerParamBehind* pInstance);
    };
}

namespace app::player {
    struct PlayerParamWaterAct {
        float resistRate;
        float breatheBrake;
        float breatheTime;
        float breatheGravity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWaterAct* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWaterAct* pInstance);
        static void Clean(PlayerParamWaterAct* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBaseJump {
        float baseSpeed;
        float upSpeed;
        float upSpeedAir;
        float edgeSpeed;
        float airActionTime;
        float wallMoveTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBaseJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBaseJump* pInstance);
        static void Clean(PlayerParamBaseJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBallMove {
        float maxSpeed;
        float slidePower;
        float brakeForce;
        float slidePowerSlalom;
        float brakeForceSlalom;
        float releaseSpeed;
        bool useInput;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBallMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBallMove* pInstance);
        static void Clean(PlayerParamBallMove* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLocusData {
        float width;
        float distance;
        float u0;
        float u1;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLocusData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLocusData* pInstance);
        static void Clean(PlayerParamLocusData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLocus {
        app::player::PlayerParamLocusData data[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLocus* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLocus* pInstance);
        static void Clean(PlayerParamLocus* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlingshot {
        enum class CameraShakeTiming : int8_t {
            StartCameraInterpolation = 0,
            EndCameraInterpolation = 1,
        };

        float timeScaleInMove;
        float hitStartRestTime;
        csl::math::Vector3 hitCameraOffset;
        float hitCameraTimeEaseIn;
        float hitCameraFovyAngle;
        float hitTimeScaleValue;
        float hitTimeScaleTimeEaseIn;
        float resetCameraEaseOutTime;
        float resetTimeScaleEaseOutTime;
        float timeScaleKeepTime;
        float shotEffOffset;
        float hitEffOffset;
        CameraShakeTiming cameraShakeTiming;
        csl::ut::VariableString cameraShakeName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlingshot* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlingshot* pInstance);
        static void Clean(PlayerParamSlingshot* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAuraTrain {
        float effectSpanTime;
        float effectLifeTime;
        float effectOffsetDistance;
        float effectOverlapDistance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAuraTrain* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAuraTrain* pInstance);
        static void Clean(PlayerParamAuraTrain* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLevel {
        uint8_t ringsLevel;
        uint8_t speedLevel;
        uint8_t offensiveLevel;
        uint8_t defensiveLevel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLevel* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLevel* pInstance);
        static void Clean(PlayerParamLevel* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBarrierWall {
        float coolTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBarrierWall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBarrierWall* pInstance);
        static void Clean(PlayerParamBarrierWall* pInstance);
    };
}

namespace app::player {
    struct PlayerParamWarpAttack {
        app::player::PlayerParamAttackCollider hit;
        float rushWaitTime;
        float invincibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWarpAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWarpAttack* pInstance);
        static void Clean(PlayerParamWarpAttack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlowRush {
        app::player::PlayerParamAttackCollider hit;
        float invincibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlowRush* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlowRush* pInstance);
        static void Clean(PlayerParamDBlowRush* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlowRushFinish {
        app::player::PlayerParamAttackCollider hit;
        float invincibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlowRushFinish* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlowRushFinish* pInstance);
        static void Clean(PlayerParamDBlowRushFinish* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlowOff {
        app::player::PlayerParamAttackCollider hit;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlowOff* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlowOff* pInstance);
        static void Clean(PlayerParamDBlowOff* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlowUp {
        app::player::PlayerParamAttackCollider hit;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlowUp* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlowUp* pInstance);
        static void Clean(PlayerParamDBlowUp* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlowDown {
        app::player::PlayerParamAttackCollider hit;
        app::player::PlayerParamAttackCollider hit2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlowDown* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlowDown* pInstance);
        static void Clean(PlayerParamDBlowDown* pInstance);
    };
}

namespace app::player {
    struct PlayerParamChaosSpear {
        float speed;
        float maxSpeed;
        float accel;
        float timeStopDamper;
        float timeStopAccel;
        float maxAngle;
        float minAngleDist;
        float maxAngleDist;
        float homingSpeed;
        float life;
        float interval;
        uint8_t maxLockon;
        float lockonInterval;
        float lockonRangeMin;
        float lockonRangeMax;
        float lockonRangeMaxExpand;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamChaosSpear* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamChaosSpear* pInstance);
        static void Clean(PlayerParamChaosSpear* pInstance);
    };
}

namespace app::player {
    struct PlayerParamChaosSpearData {
        app::player::PlayerParamChaosSpear normal;
        app::player::PlayerParamChaosSpear slider;
        app::player::PlayerParamChaosSpear diving;
        app::player::PlayerParamChaosSpear dsurf;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamChaosSpearData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamChaosSpearData* pInstance);
        static void Clean(PlayerParamChaosSpearData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamMirageEffect {
        uint8_t maxNum;
        csl::ut::Colorf mirageColor1;
        csl::ut::Colorf mirageColor2;
        float mirageDistance;
        float mirageTime;
        float mirageSpeed;
        csl::ut::Colorf warpMirageColor1;
        csl::ut::Colorf warpMirageColor2;
        float warpStartMirageTime;
        float warpEndMirageTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamMirageEffect* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamMirageEffect* pInstance);
        static void Clean(PlayerParamMirageEffect* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFacingData {
        float twistLimitAngle;
        float faceLimitAngle;
        float neckLimitAngle;
        float activeAngle;
        float deactiveAngle;
        float easeRate;
        float easeTime;
        float twistWeight;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFacingData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFacingData* pInstance);
        static void Clean(PlayerParamFacingData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFacing {
        uint32_t normal;
        uint32_t stand;
        uint32_t run;
        uint32_t fall;
        app::player::PlayerParamFacingData data[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFacing* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFacing* pInstance);
        static void Clean(PlayerParamFacing* pInstance);
    };
}

namespace app::player {
    struct PlayerParamEtc {
        float limitMoveMaxSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamEtc* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamEtc* pInstance);
        static void Clean(PlayerParamEtc* pInstance);
    };
}

namespace app::player {
    struct CommonPackage {
        app::player::PlayerParamAttack attack;
        app::player::PlayerParamStompingAttack stompingAttack;
        app::player::PlayerParamBehind behind;
        app::player::PlayerParamWaterAct wateract;
        app::player::PlayerParamBaseJump basejump;
        app::player::PlayerParamBallMove ballmove;
        app::player::PlayerParamLocus locus;
        app::player::PlayerParamSlingshot slingshot;
        app::player::PlayerParamAuraTrain auratrain;
        app::player::PlayerParamLevel level;
        app::player::PlayerParamBarrierWall barrierWall;
        app::player::PlayerParamWarpAttack warpAttack;
        app::player::PlayerParamDBlowRush dblowRush;
        app::player::PlayerParamDBlowRushFinish dblowRushFinish;
        app::player::PlayerParamDBlowOff dblowOff;
        app::player::PlayerParamDBlowUp dblowUp;
        app::player::PlayerParamDBlowDown dblowDown;
        app::player::PlayerParamChaosSpearData chaosspear;
        app::player::PlayerParamMirageEffect mirageeffect;
        app::player::PlayerParamFacing facing;
        app::player::PlayerParamEtc etc;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CommonPackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CommonPackage* pInstance);
        static void Clean(CommonPackage* pInstance);
    };
}

namespace app::player {
    struct PlayerParamCommon {
        enum class SupportedPlane : int8_t {
            Flat = 0,
            Slope = 1,
            Wall = 2,
        };

        float movableMaxSlope;
        float activeLandingSlope;
        float activeLandingSlopeInBoost;
        float landingMaxSlope;
        float slidingMaxSlope;
        float wallAngleMaxSlope;
        SupportedPlane onStand;
        SupportedPlane onRunInAir;
        SupportedPlane onRun;
        bool moveHolding;
        bool wallSlideSlowInBoost;
        bool attrWallOnGround;
        float priorityInputTime;
        int32_t capacityRings;
        int32_t capacityRingsLvMax;
        float collectRingRange;
        float gravityCylinderDamper;
        float gravityCylinderEscapeAreaWidth;
        float gravityCylinderEscapeHeight;
        float gravityCylinderEscapeAngle;
        float gravityCylinderEscapeDistance;
        float gravityCylinderEscapeDistanceV;
        float ringConsumptionInterval;
        int32_t ringConsumptionNum;
        float ringConsumptionInterval2;
        int32_t ringConsumptionNum2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamCommon* pInstance);
        static void Clean(PlayerParamCommon* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpeedData {
        float initial;
        float min;
        float max;
        float minTurn;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpeedData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpeedData* pInstance);
        static void Clean(PlayerParamSpeedData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpeedAcceleData {
        float force;
        float damperRange;
        float jerkMin;
        float jerkMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpeedAcceleData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpeedAcceleData* pInstance);
        static void Clean(PlayerParamSpeedAcceleData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpeed {
        app::player::PlayerParamSpeedData normal;
        app::player::PlayerParamSpeedData boost;
        app::player::PlayerParamSpeedData boostLvMax;
        float maxAirSpeed;
        float maxSpeedOver;
        float opitonMaxSpeedLimit;
        float thresholdStopSpeed;
        float maxFallSpeed;
        app::player::PlayerParamSpeedAcceleData accele;
        app::player::PlayerParamSpeedAcceleData decele;
        float acceleAuto;
        float deceleAuto;
        float turnDeceleAngleMin;
        float turnDeceleAngleMax;
        float maxGravityAccele;
        float maxGravityDecele;
        float deceleSquat;
        float acceleSensitive;
        float boostAnimSpeedInWater;
        float startLoopSpeed;
        float endLoopSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpeed* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpeed* pInstance);
        static void Clean(PlayerParamSpeed* pInstance);
    };
}

namespace app::player {
    struct PlayerParamRotation {
        float baseRotateForce;
        float baseRotateForceSpeed;
        float minRotateForce;
        float maxRotateForce;
        bool angleRotateForceDecayEnabled;
        float frontRotateRatio;
        float rotationForceDecaySpeed;
        float rotationForceDecayRate;
        float rotationForceDecayMax;
        float autorunRotateForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamRotation* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamRotation* pInstance);
        static void Clean(PlayerParamRotation* pInstance);
    };
}

namespace app::player {
    struct PlayerParamRunning {
        float walkSpeed;
        float sneakingSpeed;
        float animSpeedSneak;
        float animSpeedWalk;
        float animSpeedRun;
        float animSpeedBoost;
        float animLRBlendSampleTime;
        float animLRBlendAngleMin;
        float animLRBlendAngleMax;
        float animLRBlendSpeed;
        float animLRBlendSpeedToCenter;
        float minChangeWalkTime;
        float fallAnimationAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamRunning* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamRunning* pInstance);
        static void Clean(PlayerParamRunning* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBalanceData {
        float rotateSpeedMinFB;
        float rotateSpeedMaxFB;
        float rotateSpeedMinLR;
        float rotateSpeedMaxLR;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBalanceData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBalanceData* pInstance);
        static void Clean(PlayerParamBalanceData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBalance {
        app::player::PlayerParamBalanceData standard;
        app::player::PlayerParamBalanceData loop;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBalance* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBalance* pInstance);
        static void Clean(PlayerParamBalance* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBrake {
        float initialSpeedRatio;
        float maxSpeed;
        float forceLand;
        float forceLandBoost;
        float forceAir;
        float endSpeed;
        float stopTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBrake* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBrake* pInstance);
        static void Clean(PlayerParamBrake* pInstance);
    };
}

namespace app::player {
    struct PlayerParamTurn {
        float thresholdSpeed;
        float thresholdAngle;
        float turnAfterSpeed;
        bool stopEdge;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamTurn* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamTurn* pInstance);
        static void Clean(PlayerParamTurn* pInstance);
    };
}

namespace app::player {
    struct PlayerParamJump {
        float preActionTime;
        float addForceTime;
        float force;
        float addForce;
        float gravitySize;
        float disableDoubleJumpTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJump* pInstance);
        static void Clean(PlayerParamJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLocalJump {
        float addForceTime;
        float force;
        float addForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLocalJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLocalJump* pInstance);
        static void Clean(PlayerParamLocalJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDWingJump {
        float addForceTime;
        float force;
        float addForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDWingJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDWingJump* pInstance);
        static void Clean(PlayerParamDWingJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamJumpSpeed {
        float limitMin;
        float limitUpSpeed;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float speed;
        float minSpeed;
        float minStickSpeed;
        float accel;
        float brake;
        float damper;
        float minStickBrake;
        float maxStickBrake;
        float minStickBrakeAngle;
        float maxStickBrakeAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJumpSpeed* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJumpSpeed* pInstance);
        static void Clean(PlayerParamJumpSpeed* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDoubleJump {
        float initialSpeed;
        float bounceSpeed;
        float limitSpeedMin;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDoubleJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDoubleJump* pInstance);
        static void Clean(PlayerParamDoubleJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDWingDoubleJump {
        float force;
        float addForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDWingDoubleJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDWingDoubleJump* pInstance);
        static void Clean(PlayerParamDWingDoubleJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFall {
        float thresholdVertSpeed;
        float tolerateJumpTime;
        float fallEndDelayTime;
        float fallEndFadeTime;
        float acceleForce;
        float deceleForce;
        float overSpeedDeceleForce;
        float rotationForce;
        float rotationForceDecaySpeed;
        float rotationForceDecayRate;
        float rotationForceDecayMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFall* pInstance);
        static void Clean(PlayerParamFall* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpringFall {
        float thresholdHorzSpeed;
        float maxParallelSpeed;
        float parallelAccel;
        float parallelBrake;
        float horzDamper;
        float turnSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpringFall* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpringFall* pInstance);
        static void Clean(PlayerParamSpringFall* pInstance);
    };
}

namespace app::player {
    struct PlayerParamHomingRebound {
        float maxParallelSpeed;
        float parallelAccel;
        float parallelBrake;
        float horzDamper;
        float turnSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHomingRebound* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHomingRebound* pInstance);
        static void Clean(PlayerParamHomingRebound* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageCommon {
        float invincibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageCommon* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageCommon* pInstance);
        static void Clean(PlayerParamDamageCommon* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageNormal {
        float initialHorzSpeed;
        float initialVertSpeed;
        float deceleForce;
        float transitFallTime;
        float gravityScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageNormal* pInstance);
        static void Clean(PlayerParamDamageNormal* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageTurnBack {
        float fixedTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageTurnBack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageTurnBack* pInstance);
        static void Clean(PlayerParamDamageTurnBack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageBlowOff {
        float initialHorzSpeed;
        float initialVertSpeed;
        float deceleForceInAir;
        float deceleForceOnGround;
        float gravityScale;
        float downTime;
        float transitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageBlowOff* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageBlowOff* pInstance);
        static void Clean(PlayerParamDamageBlowOff* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageGuarded {
        float vertSpeed;
        float horzSpeed;
        float deceleForce;
        float transitTime;
        float horzDamper;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageGuarded* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageGuarded* pInstance);
        static void Clean(PlayerParamDamageGuarded* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageRunning {
        float actionTime;
        float minSpeed;
        float lossSpeed;
        float lossTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageRunning* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageRunning* pInstance);
        static void Clean(PlayerParamDamageRunning* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageQuake {
        float actionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageQuake* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageQuake* pInstance);
        static void Clean(PlayerParamDamageQuake* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamageLava {
        csl::math::Vector3 jumpVelocity;
        float gravitySize;
        float invincibleTime;
        float noActionTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamageLava* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamageLava* pInstance);
        static void Clean(PlayerParamDamageLava* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDamage {
        app::player::PlayerParamDamageCommon common;
        app::player::PlayerParamDamageNormal normal;
        app::player::PlayerParamDamageTurnBack turnBack;
        app::player::PlayerParamDamageBlowOff blowOff;
        app::player::PlayerParamDamageGuarded guarded;
        app::player::PlayerParamDamageRunning running;
        app::player::PlayerParamDamageQuake quake;
        app::player::PlayerParamDamageLava lava;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDamage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDamage* pInstance);
        static void Clean(PlayerParamDamage* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDeadNormal {
        float invincibleTime;
        float initialHorzSpeed;
        float initialVertSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDeadNormal* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDeadNormal* pInstance);
        static void Clean(PlayerParamDeadNormal* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDead {
        app::player::PlayerParamDeadNormal normal;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDead* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDead* pInstance);
        static void Clean(PlayerParamDead* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSliding {
        float minSpeed;
        float endSpeed;
        float deceleJerk;
        float deceleJerkContinue;
        float deceleForceMax;
        float baseRotateForce;
        float baseRotateForceSpeed;
        float maxRotateForce;
        float frontRotateRatio;
        float rotationForceAutoRun;
        float movableMaxSlope;
        float gravitySize;
        float minContinueTime;
        float maxAutoRunTime;
        float endSpeedAutoRun;
        float loopKickTransitTime;
        float attackScale;
        csl::math::Vector3 attackOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSliding* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSliding* pInstance);
        static void Clean(PlayerParamSliding* pInstance);
    };
}

namespace app::player {
    struct PlayerParamStomping {
        float initialSpeed;
        float initialAccele;
        float maxAccele;
        float jerk;
        float maxFallSpeed;
        float angle;
        float landingCancelTime;
        float boundStompingCollisionScale;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamStomping* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamStomping* pInstance);
        static void Clean(PlayerParamStomping* pInstance);
    };
}

namespace app::player {
    struct PlayerParamGrind {
        float speed;
        float boostSpeed;
        float maxSpeed;
        float maxOverSpeed;
        float acceleForce;
        float gravityForce;
        float overSpeedBrake;
        float brake;
        bool updatePathPosition;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamGrind* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamGrind* pInstance);
        static void Clean(PlayerParamGrind* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFallSlope {
        float initialSpeed;
        float maxSpeed;
        float maxSpeedAmoeba;
        float brakeAngle;
        float highBrakeAngle;
        float brakeForce;
        float brakeForceHigh;
        float stickBrakeForce;
        float gravitySize;
        float gravitySizeAir;
        float endSpeedFront;
        float endSpeedBack;
        float reverseFallTime;
        float fallToSlipTime;
        float slipIdlingTime;
        float minSlipTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFallSlope* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFallSlope* pInstance);
        static void Clean(PlayerParamFallSlope* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFallFlip {
        float thresholdSpeed;
        float maxSpeed;
        float flipAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFallFlip* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFallFlip* pInstance);
        static void Clean(PlayerParamFallFlip* pInstance);
    };
}

namespace app::player {
    struct PlayerParamTumble {
        bool enabled;
        float sideSpinAngle;
        float initialVertSpeed;
        float gravitySize;
        float gravitySize2;
        float deceleForceInAir;
        float minSpeedInAir;
        float rotateEaseTimeLeftRight;
        float rotateEaseTimeFrontBack;
        float rotateSpeedMinLeftRight;
        float rotateSpeedMaxLeftRight;
        float rotateSpeedMinFrontBack;
        float rotateSpeedMaxFrontBack;
        float angleLeftRightStagger;
        float angleLeftRightRoll;
        float angleFrontBackRoll;
        float angleBigRoll;
        float inRunTime;
        float inAirTime;
        float rollSpeedFront;
        float bigRollVelocityRatio;
        float dropDashHoldTime;
        float airBrakeVertSpeed;
        float airBrakeForce;
        float airTrickHeight;
        float airTrickTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamTumble* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamTumble* pInstance);
        static void Clean(PlayerParamTumble* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpinAttack {
        float jumpForce;
        float jumpAddForce;
        float addTime;
        float acceleForce;
        float deceleForce;
        float brakeForce;
        float limitSpeedMin;
        float limitSpeedMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpinAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpinAttack* pInstance);
        static void Clean(PlayerParamSpinAttack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamHomingAttackData {
        float speed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHomingAttackData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHomingAttackData* pInstance);
        static void Clean(PlayerParamHomingAttackData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamHomingBounceData {
        float bounceVertSpeed;
        float bounceHorzSpeed;
        float bounceAcceleForce;
        float bounceDeceleForce;
        float bounceAngleWidth;
        float bounceTime;
        float attackDownTime;
        float attackDownTimeForStomp;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHomingBounceData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHomingBounceData* pInstance);
        static void Clean(PlayerParamHomingBounceData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamHomingAttack {
        app::player::PlayerParamHomingAttackData sonic;
        app::player::PlayerParamHomingBounceData sonicBounce;
        app::player::PlayerParamHomingBounceData sonicBounceWeak;
        float cameraEaseInTime;
        float cameraEaseOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHomingAttack* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHomingAttack* pInstance);
        static void Clean(PlayerParamHomingAttack* pInstance);
    };
}

namespace app::player {
    struct PlayerParamHitEnemy {
        float bounceVertSpeed;
        float bounceHorzSpeed;
        float attackDownTime;
        float enableHomingTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamHitEnemy* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamHitEnemy* pInstance);
        static void Clean(PlayerParamHitEnemy* pInstance);
    };
}

namespace app::player {
    struct SpeedParam {
        float maxVertSpeed;
        float acceleVertForce;
        float maxHorzSpeed;
        float acceleHorzForce;
        float deceleVertForce;
        float deceleHorzForce;
        float deceleNeutralForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SpeedParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SpeedParam* pInstance);
        static void Clean(SpeedParam* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDiving {
        app::player::SpeedParam normal;
        app::player::SpeedParam fast;
        app::player::SpeedParam damaged;
        app::player::SpeedParam ringdash;
        float startHeight;
        float startSpeed;
        float damageTime;
        float ringdashTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDiving* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDiving* pInstance);
        static void Clean(PlayerParamDiving* pInstance);
    };
}

namespace app::player {
    struct PlayerParamFan {
        float damperV;
        float damperH;
        float accelRate;
        float moveForceFV;
        float moveForceSV;
        float jumpCheckSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamFan* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamFan* pInstance);
        static void Clean(PlayerParamFan* pInstance);
    };
}

namespace app::player {
    struct PlayerParamStorm {
        float damperV;
        float damperH;
        float brake;
        float accelRate;
        float moveForce;
        float maxSpeedH;
        float maxSpeedV;
        float rotateSpeed;
        float rotateAngularSpeed;
        float minDrawSpeed;
        float maxDrawSpeed;
        float minDrawSpeedDistance;
        float maxDrawSpeedDistance;
        float damageTime;
        float damageNoBrakeTime;
        float forceHomingReaction;
        float forceHomingReaction2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamStorm* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamStorm* pInstance);
        static void Clean(PlayerParamStorm* pInstance);
    };
}

namespace app::player {
    struct PlayerParamCloudJump {
        float acceleForce;
        float deceleForce;
        float overSpeedDeceleForce;
        float rotationForce;
        float rotationForceDecaySpeed;
        float rotationForceDecayRate;
        float rotationForceDecayMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamCloudJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamCloudJump* pInstance);
        static void Clean(PlayerParamCloudJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAirTrick {
        uint32_t amount;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAirTrick* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAirTrick* pInstance);
        static void Clean(PlayerParamAirTrick* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDrift {
        float startAngle;
        float endSpeed;
        float minSpeed;
        float minSpeedMax;
        float maxSpeed;
        float maxSpeedMax;
        float minBoostSpeed;
        float minBoostSpeedMax;
        float maxBoostSpeed;
        float maxBoostSpeedMax;
        float accel;
        float brake;
        float maxSteerAngle;
        float steerAccel;
        float maxSteerSpeed;
        float neutralSteerAccel;
        float maxNeutralSteerSpeed;
        float maxRotateSpeed;
        float recoverTime;
        float maxChargeTime;
        float minDashSpeed;
        float maxDashSpeed;
        float minDashJumpSpeed;
        float maxDashJumpSpeed;
        float jumpSpeed;
        float checkFallTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDrift* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDrift* pInstance);
        static void Clean(PlayerParamDrift* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDriftAir {
        float startAngle;
        float endSpeed;
        float minSpeed;
        float maxSpeed;
        float accel;
        float brake;
        float maxSteerAngle;
        float steerAccel;
        float maxSteerSpeed;
        float neutralSteerAccel;
        float maxNeutralSteerSpeed;
        float maxRotateSpeed;
        float recoverTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDriftAir* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDriftAir* pInstance);
        static void Clean(PlayerParamDriftAir* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDriftDash {
        float maxSpeed;
        float brake;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float outOfControlSpeed;
        float checkDashSpeed;
        float checkDashTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDriftDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDriftDash* pInstance);
        static void Clean(PlayerParamDriftDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDropDash {
        float maxChargeTime;
        float minDashSpeed;
        float minDashSpeedMax;
        float maxDashSpeed;
        float maxDashSpeedMax;
        float tumbleDashSpeed;
        float maxSpeed;
        float brake;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float outOfControlSpeed;
        float checkDashSpeed;
        float checkDashTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDropDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDropDash* pInstance);
        static void Clean(PlayerParamDropDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBounceJump {
        float startSpeed;
        float jumpRate1;
        float jumpRate2;
        float jumpRate3;
        float inoperableTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBounceJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBounceJump* pInstance);
        static void Clean(PlayerParamBounceJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLightDash {
        float dashSpeed;
        float dashSpeedMax;
        float speed;
        float speedMax;
        float accel;
        float brake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLightDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLightDash* pInstance);
        static void Clean(PlayerParamLightDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBackflip {
        float jumpSpeed;
        float backSpeed;
        float downAccel;
        float damperV;
        float damperH;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBackflip* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBackflip* pInstance);
        static void Clean(PlayerParamBackflip* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSquatMove {
        float startSpeed;
        float maxSpeed;
        float accel;
        float brake;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSquatMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSquatMove* pInstance);
        static void Clean(PlayerParamSquatMove* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlowMove {
        float startSpeed;
        float maxSpeed;
        float accel;
        float brake;
        float damageSpeed;
        float damageBrake;
        float steeringSpeed;
        float endSteeringSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlowMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlowMove* pInstance);
        static void Clean(PlayerParamSlowMove* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpinDash {
        float time;
        float minSpeed;
        float deceleForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpinDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpinDash* pInstance);
        static void Clean(PlayerParamSpinDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSpin {
        float startSlopeAngle;
        float endSlopeAngle;
        float startSpeed;
        float endSpeed;
        float stickAngle;
        float brake;
        float forceBrake;
        float maxSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSpin* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSpin* pInstance);
        static void Clean(PlayerParamSpin* pInstance);
    };
}

namespace app::player {
    struct PlayerParamWallMove {
        float walkSpeed;
        float boostSpeed;
        float minAccessSpeed;
        float stickSpeed;
        float gravity;
        float accel;
        float brake;
        float stopBrake;
        float fallSpeed;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float startTime;
        float useEnergySpeedBase;
        float useEnergySpeedBaseOnMesh;
        float useEnergySpeedVal;
        float useEnergySpeedValOnMesh;
        float useEnergyAngle;
        float useEnergyAngleOnMesh;
        float brakeStartEnergy;
        float brakeStartEnergyOnMesh;
        float homingSearchDistanceNear;
        float homingSearchDistanceFar;
        float wallBumpHeightUpper;
        float wallBumpHeightUnder;
        float recoveryCheckTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWallMove* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWallMove* pInstance);
        static void Clean(PlayerParamWallMove* pInstance);
    };
}

namespace app::player {
    struct PlayerParamWallJump {
        float gravitySize;
        float minTime;
        float maxTime;
        float stopTime;
        float maxDownSpeed;
        float fallGroundDistance;
        float frontForce;
        float upForce;
        float impulseTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWallJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWallJump* pInstance);
        static void Clean(PlayerParamWallJump* pInstance);
    };
}

namespace app::player {
    struct PlayerParamClimbing {
        float stepSpeedFront;
        float stepSpeedFrontDash;
        float stepSpeedSide;
        float stepSpeedSideDash;
        float stepSpeedBack;
        float stepDashRate;
        float maxAnimSpeed;
        float exhaustAngle;
        float exhaustAngleOnMesh;
        float exhaustBase;
        float exhaustBaseOnMesh;
        float exhaustRate;
        float exhaustRateOnMesh;
        float useGrabGaugeSpeed;
        float useGrabGaugeSpeedOnMesh;
        float useGrabGaugeTurbo;
        float useGrabGaugeTurboOnMesh;
        float homingSearchDistanceNear;
        float homingSearchDistanceFar;
        float resetAngle;
        float recoveryCheckTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamClimbing* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamClimbing* pInstance);
        static void Clean(PlayerParamClimbing* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlideDown {
        float time;
        float speed;
        float speedOnMesh;
        float accel;
        float brake;
        float brakeOnMesh;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlideDown* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlideDown* pInstance);
        static void Clean(PlayerParamSlideDown* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBoarding {
        float maxSpeed;
        float minSpeed;
        float damageSpeed;
        float accel;
        float damageBrake;
        float damageBrakeTime;
        float damageMotionTime;
        float damageInvicibleTime;
        float damper;
        float airDamperV;
        float airDamperH;
        float gravity;
        float airJumpSpeed;
        float groundJumpSpeed;
        float airAccel;
        float maxAirAddSpeed;
        float downForceRate;
        float steeringSpeed1;
        float steeringSpeed2;
        float steeringSpeed3;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float startSpeed;
        float startSlope;
        float staticStartSlope;
        float finishSlope;
        float finishTime;
        float bigLandTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBoarding* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBoarding* pInstance);
        static void Clean(PlayerParamBoarding* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlowWalk {
        float minSpeed;
        float maxSpeed;
        float accel;
        float brake;
        float brakeSteeringAngle;
        float steeringSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlowWalk* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlowWalk* pInstance);
        static void Clean(PlayerParamSlowWalk* pInstance);
    };
}

namespace app::player {
    struct PlayerParamJog {
        float startSpeed;
        float minSpeed;
        float maxSpeed;
        float accel;
        float brake;
        float maxBrake;
        float brakeSteeringAngle;
        float stopSteeringSpeed;
        float steeringSpeed;
        float skatingStartInputLength;
        float skatingStartInputAngle;
        float skatingStartInputTime;
        float skatingStartSpeed;
        float skatingStartAccel;
        float wallBreakawaySpeed;
        float startAnimSpeed;
        float animSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJog* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJog* pInstance);
        static void Clean(PlayerParamJog* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSkate {
        float maxSpeed;
        float overSpeed;
        float accel;
        float brake;
        float maxBrake;
        float steeringSpeed;
        float steeringSpeed2;
        float steeringBrake;
        float minSteeringBrakeAngle;
        float maxSteeringBrakeAngle;
        float animSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSkate* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSkate* pInstance);
        static void Clean(PlayerParamSkate* pInstance);
    };
}

namespace app::player {
    struct PlayerParamShiftRun {
        float startSpeed;
        float shiftRate;
        float jumpSpeed;
        float airJumpSpeedFront;
        float airJumpSpeedSide;
        float airJumpSpeedDown;
        float cameraAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamShiftRun* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamShiftRun* pInstance);
        static void Clean(PlayerParamShiftRun* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBoostCamera {
        float effectTime;
        float peakTime;
        float endTime;
        float maxFovy;
        float minFovy;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBoostCamera* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBoostCamera* pInstance);
        static void Clean(PlayerParamBoostCamera* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBoostBlur {
        enum class BlurType : int8_t {
            BLURTYPE_PREV_SURFACE = 0,
            BLURTYPE_RADIAL = 1,
            BLURTYPE_CAMERA = 2,
            BLURTYPE_COUNT = 3,
        };

        enum class FocusType : int8_t {
            FOCUSTYPE_CENTER = 0,
            FOCUSTYPE_LOOKAT = 1,
            FOCUSTYPE_USER_SETTING = 2,
            FOCUSTYPE_COUNT = 3,
        };

        bool enable;
        BlurType blurType;
        float blurPower;
        FocusType focusType;
        csl::math::Vector3 focusPosition;
        float focusRange;
        float alphaSlope;
        int32_t sampleNum;
        float easeInTime;
        float easeOutTime;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBoostBlur* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBoostBlur* pInstance);
        static void Clean(PlayerParamBoostBlur* pInstance);
    };
}

namespace app::player {
    struct PlayerParamBoost {
        float maxSpeed;
        float startSpeed;
        float accel;
        float landingAccel;
        float initialConsumptionValue;
        float initialConsumptionValueAir;
        float consumptionSpeed;
        float consumptionSpeedAir;
        float consumptionSpeedEx;
        float recoverySpeed;
        float recoveryInterval;
        float recoveryByRing;
        float recoveryByAttack;
        float endSpeed;
        float endSpeedTime;
        float attackScale;
        csl::math::Vector3 attackOffset;
        app::player::PlayerParamBoostCamera camera;
        app::player::PlayerParamBoostBlur blur;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamBoost* pInstance);
        static void Clean(PlayerParamBoost* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAirBoost {
        float startHSpeed;
        float startVSpeed;
        float minHSpeed;
        float brakeTime;
        float minKeepTime;
        float maxKeepTime;
        float maxTime;
        float gravityRate;
        float steeringSpeed;
        float additionalTransitTime;
        float finishTime;
        float attackTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAirBoost* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAirBoost* pInstance);
        static void Clean(PlayerParamAirBoost* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAutorun {
        float initialSideSpeed;
        float acceleSideForce;
        float deceleSideForce;
        float maxSideSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAutorun* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAutorun* pInstance);
        static void Clean(PlayerParamAutorun* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlider {
        float maxSpeed;
        float accel;
        float damper;
        float gravity;
        float jumpSpeed;
        float jumpCheckTime;
        float jumpRotateRate;
        float jumpDownForceRate;
        float jumpHorzDamper;
        float downForceRate;
        float steeringSpeed1;
        float steeringSpeed2;
        float steeringSpeed3;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float damageSpeed;
        float damageBrake;
        float damageTime;
        float damageInvincibleTime;
        float pathForce;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlider* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlider* pInstance);
        static void Clean(PlayerParamSlider* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSideStep {
        float speed;
        float brakeForce;
        float motionSpeedRatio;
        float stepSpeed;
        float maxStepDistance;
        float minStepDistance;
        float maxStepSpeed;
        float minStepSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSideStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSideStep* pInstance);
        static void Clean(PlayerParamSideStep* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSideStep2 {
        float speed;
        float brakeForce;
        float motionSpeedRatio;
        float stepSpeed;
        float maxStepDistance;
        float minStepDistance;
        float maxStepSpeed;
        float minStepSpeed;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSideStep2* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSideStep2* pInstance);
        static void Clean(PlayerParamSideStep2* pInstance);
    };
}

namespace app::player {
    struct PlayerParamQuickStep {
        float needSpeed;
        float acceleForce;
        float acceleSideForce;
        float stepInitialSpeed;
        float avoidForce;
        float justBoostForce;
        float justBoostMax;
        float justBoostTime;
        float justBoostBrake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamQuickStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamQuickStep* pInstance);
        static void Clean(PlayerParamQuickStep* pInstance);
    };
}

namespace app::player {
    struct PlayerParamParry {
        float minRecieveTime;
        float maxRecieveTime;
        float frozenTime;
        float justEffectEasein;
        float justEffectEaseout;
        float justEffectTime;
        float justEffectEasein2;
        float justEffectEaseout2;
        float justEffectTime2;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamParry* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamParry* pInstance);
        static void Clean(PlayerParamParry* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAvoidData {
        float speed;
        float damper;
        float parryTime;
        float invincibleTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAvoidData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAvoidData* pInstance);
        static void Clean(PlayerParamAvoidData* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAvoid {
        float time;
        float fixedTime;
        float reentryInputPriorityTime;
        float reentryTime;
        float frontAngle;
        float backAngle;
        float addFallSpeed;
        app::player::PlayerParamAvoidData data[7];
        float baseDistance;
        float limitAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAvoid* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAvoid* pInstance);
        static void Clean(PlayerParamAvoid* pInstance);
    };
}

namespace app::player {
    struct PlayerParamTimeStop {
        float consumptionSpeed;
        float searchPathDistance;
        float startMargin;
        int32_t gaugeMax;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamTimeStop* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamTimeStop* pInstance);
        static void Clean(PlayerParamTimeStop* pInstance);
    };
}

namespace app::player {
    struct PlayerParamPhotonDash {
        float speed;
        float accel;
        float fixSpeed;
        float finishTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamPhotonDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamPhotonDash* pInstance);
        static void Clean(PlayerParamPhotonDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamJumpDash {
        float speed;
        float keepVelocityTime;
        float brakeTime;
        float damper;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamJumpDash* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamJumpDash* pInstance);
        static void Clean(PlayerParamJumpDash* pInstance);
    };
}

namespace app::player {
    struct PlayerParamRunOnWater {
        float startSpeed;
        float sinkSpeed;
        float fallSpeed;
        float vSpeed;
        float brake;
        float sinkWidth;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamRunOnWater* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamRunOnWater* pInstance);
        static void Clean(PlayerParamRunOnWater* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDBlow {
        float maxAimTime;
        float minAimTime;
        float maxChaseTime;
        float limitAimAngleH;
        float limitAimAngleV;
        float aimSpeed;
        float aimCameraDistanceScale;
        float aimCameraUpOffset;
        float aimCameraLeftOffset;
        float aimCameraAngle;
        float blowOffCameraChaseRate;
        bool aimByRightStick;
        bool aimReverseH;
        bool aimReverseV;
        float aimLineWidth;
        float aimLineLength;
        float aimLineScrollSpeed;
        csl::ut::Color8 aimLineColor1;
        csl::ut::Color8 aimLineColor2;
        float aimTargetSearchDistance;
        float aimTargetSearchAngle;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDBlow* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDBlow* pInstance);
        static void Clean(PlayerParamDBlow* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDSurf {
        float maxSpeed;
        float minSpeed;
        float overSpeed;
        float gravityAccel;
        float minTurnSpeed;
        float accel;
        float brake;
        float steeringBrake;
        float brakeAngle;
        float maxSteeringBrakeAngle;
        bool cameraTurn;
        float steeringSpeed1;
        float steeringSpeed2;
        float steeringSpeedAir;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float steeringAssistSpeed;
        float steeringAssistAngle;
        float spring;
        float airSpringRate;
        float damper;
        float resetDepth;
        float jumpSpeed;
        float virticalJumpSpeed;
        float virticalMoveSpeed;
        float virticalMoveAccel;
        float virticalMoveBrake;
        float virticalRotateSpeed;
        float damageVSpeed;
        float damageHSpeed;
        float wallHitAngle;
        float wallHitSpeed;
        float finishDamper;
        float waterFlowRate;
        float maxSideSpeedFV;
        float sideAccelFV;
        float sideBrakeFV;
        float maxSideSpeedAirFV;
        float sideAccelAirFV;
        float sideBrakeAirFV;
        float frontStickAngleFV;
        float maxSpeedSV;
        float minSpeedSV;
        float accelSV;
        float brakeSV;
        float sideAccelSV;
        float maxSideSpeedSV;
        float stompingFallSpeed;
        float startDashSpeed;
        float startDashTime;
        float startDashStartTime;
        float dashCheckStartTime;
        float dashCheckEndTime;
        float dashEffectTime;
        float waterDepth;
        float wallHitTime;
        float turnSpeed;
        float turnDamper;
        float attackScale;
        csl::math::Vector3 attackOffset;
        app::player::PlayerParamBoostCamera camera;
        app::player::PlayerParamBoostBlur blur;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDSurf* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDSurf* pInstance);
        static void Clean(PlayerParamDSurf* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDSurfSpinParam {
        float outOfControlTime;
        float cancelTime;
        float cancelJumpTime;
        float cancelMoveTime;
        float cancelBrakeTime;
        float speed;
        float minSpeed;
        float speedKeepTime;
        float brake;
        float brakeTime;
        float time;
        float forceBrake;
        float attackTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDSurfSpinParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDSurfSpinParam* pInstance);
        static void Clean(PlayerParamDSurfSpinParam* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDSurfSpin {
        float checkTime;
        float flightTime;
        app::player::PlayerParamDSurfSpinParam front;
        app::player::PlayerParamDSurfSpinParam side;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDSurfSpin* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDSurfSpin* pInstance);
        static void Clean(PlayerParamDSurfSpin* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDSurfSpinSV {
        float flightTime;
        app::player::PlayerParamDSurfSpinParam param;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDSurfSpinSV* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDSurfSpinSV* pInstance);
        static void Clean(PlayerParamDSurfSpinSV* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDAmoeba {
        float minSpeed;
        float maxSpeed;
        float accel;
        float moveAccel;
        float brake;
        float damper;
        float groundDamper;
        float groundBrake;
        float cancelTime;
        float cancelDist;
        float cancelSpeed;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float steeringBrake;
        float steeringBrakeSpeed;
        float minSteeringBrakeAngle;
        float maxSteeringBrakeAngle;
        float turnSpeed;
        float jumpSpeed;
        float minJumpSpeedH;
        float maxLandingSpeed;
        float minLandingSpeed;
        float landingSpeedRate;
        float minDashSpeed;
        float maxDashSpeed;
        float dashKeepSpeedTime;
        float dashOutOfControlTime;
        float dashInterval;
        float damageInvincibleTime;
        float attackScale;
        csl::math::Vector3 attackOffset;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDAmoeba* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDAmoeba* pInstance);
        static void Clean(PlayerParamDAmoeba* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDAmoebaAir {
        float damperSpeed;
        float damper;
        float steeringSpeed1;
        float steeringSpeed2;
        float startSteeringSpeed;
        float endSteeringSpeed;
        float minSpeed;
        float accel;
        float rotateSpeed;
        float svBrake;
        float bossDamper;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDAmoebaAir* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDAmoebaAir* pInstance);
        static void Clean(PlayerParamDAmoebaAir* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDAmoebaHoming {
        float damper;
        float catchTime;
        float shrinkTime;
        float swingSpeed;
        float swingRadius;
        float limitSwingRadius;
        float swingDamper;
        float shrinkSpring;
        float shrinkDamper;
        float maxShrinkSpeed;
        float gravity;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDAmoebaHoming* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDAmoebaHoming* pInstance);
        static void Clean(PlayerParamDAmoebaHoming* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDWingGuardParam {
        float backSpeed;
        float damper;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDWingGuardParam* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDWingGuardParam* pInstance);
        static void Clean(PlayerParamDWingGuardParam* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDWingGuard {
        app::player::PlayerParamDWingGuardParam normal;
        app::player::PlayerParamDWingGuardParam tornado;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDWingGuard* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDWingGuard* pInstance);
        static void Clean(PlayerParamDWingGuard* pInstance);
    };
}

namespace app::player {
    struct PlayerParamDWingFlinch {
        float backSpeed;
        float damper;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamDWingFlinch* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamDWingFlinch* pInstance);
        static void Clean(PlayerParamDWingFlinch* pInstance);
    };
}

namespace app::player {
    struct PlayerParamWaterFlow {
        float brake;
        float flowBrake;
        float spring;
        float damper;
        float outOfControlTime;
        float returnDistance;
        float returnTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamWaterFlow* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamWaterFlow* pInstance);
        static void Clean(PlayerParamWaterFlow* pInstance);
    };
}

namespace app::player {
    struct PlayerParamSlalomStep {
        float startSpeed;
        float startAngle;
        float searchTime1;
        float searchTime2;
        float searchTime3;
        float wallOffset;
        float wallOffsetMin;
        float wallOffsetMax;
        float justStepTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamSlalomStep* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamSlalomStep* pInstance);
        static void Clean(PlayerParamSlalomStep* pInstance);
    };
}

namespace app::player {
    struct PlayerParamGliding2 {
        float fallSpeed;
        float fallAccel;
        float maxSteerSpeed;
        float gravity;
        float stickThreshold;
        float lostSpeedPitchSpeed;
        float recoverPitchSpeed;
        float recoverAngle;
        float yawSpeed;
        float yawAssistSpeed;
        float yawAssistAngle;
        float height;
        float startHeight;
        float startTime;
        float outOfControlTime;
        float rollingAttackTime;
        float exAccel;
        float exBrake;
        float exDamper;
        float initialAccel;
        float boostAccel;
        float pathFixSpeed;
        float debuffSpeedRate;
        float debuffSideSpeedRate;
        float maxRollBrakeRate;
        float attackScale;
        csl::math::Vector3 attackOffset;
        float boostRate;
        app::player::PlayerParamBoostCamera camera;
        app::player::PlayerParamBoostBlur blur;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamGliding2* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamGliding2* pInstance);
        static void Clean(PlayerParamGliding2* pInstance);
    };
}

namespace app::player {
    struct PlayerParamChaosSpearAir {
        float damper;
        float maxSpeed;
        float accel;
        float brake;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamChaosSpearAir* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamChaosSpearAir* pInstance);
        static void Clean(PlayerParamChaosSpearAir* pInstance);
    };
}

namespace app::player {
    struct ModePackage {
        app::player::PlayerParamCommon common;
        app::player::PlayerParamSpeed speed;
        app::player::PlayerParamRotation rotation;
        app::player::PlayerParamRunning running;
        app::player::PlayerParamBalance balance;
        app::player::PlayerParamBrake brake;
        app::player::PlayerParamTurn turn;
        app::player::PlayerParamJump jump;
        app::player::PlayerParamLocalJump localjump;
        app::player::PlayerParamDWingJump dwingjump;
        app::player::PlayerParamJumpSpeed jumpSpeed;
        app::player::PlayerParamDoubleJump doubleJump;
        app::player::PlayerParamDWingDoubleJump dwingdoublejump;
        app::player::PlayerParamFall fall;
        app::player::PlayerParamSpringFall springfall;
        app::player::PlayerParamHomingRebound homingrebound;
        app::player::PlayerParamDamage damage;
        app::player::PlayerParamDead dead;
        app::player::PlayerParamSliding sliding;
        app::player::PlayerParamStomping stomping;
        app::player::PlayerParamGrind grind;
        app::player::PlayerParamFallSlope fallSlope;
        app::player::PlayerParamFallFlip fallFlip;
        app::player::PlayerParamTumble tumble;
        app::player::PlayerParamSpinAttack spinAttack;
        app::player::PlayerParamHomingAttack homingAttack;
        app::player::PlayerParamHitEnemy hitEnemy;
        app::player::PlayerParamDiving diving;
        app::player::PlayerParamFan fan;
        app::player::PlayerParamStorm storm;
        app::player::PlayerParamCloudJump cloudJump;
        app::player::PlayerParamAirTrick airtrick;
        app::player::PlayerParamDrift drift;
        app::player::PlayerParamDriftAir driftair;
        app::player::PlayerParamDriftDash driftDash;
        app::player::PlayerParamDropDash dropDash;
        app::player::PlayerParamBounceJump bounceJump;
        app::player::PlayerParamLightDash lightDash;
        app::player::PlayerParamBackflip backflip;
        app::player::PlayerParamSquatMove squatmove;
        app::player::PlayerParamSlowMove slowmove;
        app::player::PlayerParamSpinDash spindash;
        app::player::PlayerParamSpin spin;
        app::player::PlayerParamWallMove wallmove;
        app::player::PlayerParamWallJump walljump;
        app::player::PlayerParamClimbing climbing;
        app::player::PlayerParamSlideDown slidedown;
        app::player::PlayerParamBoarding boarding;
        app::player::PlayerParamSlowWalk slowwalk;
        app::player::PlayerParamJog jog;
        app::player::PlayerParamSkate skate;
        app::player::PlayerParamShiftRun shiftrun;
        app::player::PlayerParamBoost boost;
        app::player::PlayerParamAirBoost airboost;
        app::player::PlayerParamAutorun autorun;
        app::player::PlayerParamSlider slider;
        app::player::PlayerParamSideStep sidestep;
        app::player::PlayerParamSideStep2 sidestep2;
        app::player::PlayerParamQuickStep quickstep;
        app::player::PlayerParamParry parry;
        app::player::PlayerParamAvoid avoid;
        app::player::PlayerParamTimeStop timestop;
        app::player::PlayerParamPhotonDash photondash;
        app::player::PlayerParamJumpDash jumpdash;
        app::player::PlayerParamRunOnWater runonwater;
        app::player::PlayerParamDBlow dblow;
        app::player::PlayerParamDSurf dsurf;
        app::player::PlayerParamDSurfSpin dsurfspin;
        app::player::PlayerParamDSurfSpinSV dsurfspinsv;
        app::player::PlayerParamDAmoeba damoeba;
        app::player::PlayerParamDAmoebaAir damoebaair;
        app::player::PlayerParamDAmoebaHoming damoebahoming;
        app::player::PlayerParamDWingGuard dwingguard;
        app::player::PlayerParamDWingFlinch dwingflinch;
        app::player::PlayerParamWaterFlow waterflow;
        app::player::PlayerParamSlalomStep slalomstep;
        app::player::PlayerParamGliding gliding;
        app::player::PlayerParamGliding2 gliding2;
        app::player::PlayerParamChaosSpearAir chaosspearair;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ModePackage* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ModePackage* pInstance);
        static void Clean(ModePackage* pInstance);
    };
}

namespace app::player {
    struct PlayerParamAerialFinish {
        app::player::PlayerParamAttackCollider hit;
        float ignoreSwingingTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamAerialFinish* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamAerialFinish* pInstance);
        static void Clean(PlayerParamAerialFinish* pInstance);
    };
}

namespace app::player {
    struct PlayerParameters {
        app::player::CommonPackage common;
        app::player::ModePackage forwardView;
        app::player::ModePackage sideView;
        app::player::ModePackage boss;
        app::player::ModePackage whiteSpace;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParameters* pInstance);
        static void Clean(PlayerParameters* pInstance);
    };
}

namespace app::player {
    struct PlayerParamLowAltitudeJump {
        float upSpeed;
        float frontSpeed;
        float damperV;
        float damperH;
        float gravity;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayerParamLowAltitudeJump* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayerParamLowAltitudeJump* pInstance);
        static void Clean(PlayerParamLowAltitudeJump* pInstance);
    };
}

namespace heur::rfl {
    struct ScriptParameter {
        uint32_t intervalMinuntes;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(ScriptParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(ScriptParameter* pInstance);
        static void Clean(ScriptParameter* pInstance);
    };
}

namespace heur::rfl {
    struct TalkEventCameraPresetParameter {
        enum class GazePositionType : int8_t {
            Base = 0,
            Head = 1,
            Eye = 2,
            Center = 3,
        };

        bool enable;
        GazePositionType primaryTarget;
        GazePositionType secondaryTarget;
        float targetRatio;
        float rotateDegreePitch;
        float rotateDegreeYaw;
        float cameraOffsetRatio;
        float fovy;
        float targetOffsetX;
        float targetOffsetY;
        float targetOffsetZ;
        float easeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TalkEventCameraPresetParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TalkEventCameraPresetParameter* pInstance);
        static void Clean(TalkEventCameraPresetParameter* pInstance);
    };
}

namespace heur::rfl {
    struct TalkEventCameraPresetParameters {
        heur::rfl::TalkEventCameraPresetParameter param[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(TalkEventCameraPresetParameters* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(TalkEventCameraPresetParameters* pInstance);
        static void Clean(TalkEventCameraPresetParameters* pInstance);
    };
}

namespace app::snd {
    struct AmbBaseNoiseParameter {
        csl::ut::VariableString cueName;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbBaseNoiseParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbBaseNoiseParameter* pInstance);
        static void Clean(AmbBaseNoiseParameter* pInstance);
    };
}

namespace app::snd {
    struct AmbInfo {
        csl::ut::VariableString cueName;
        float fadeInTime;
        float fadeOutTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbInfo* pInstance);
        static void Clean(AmbInfo* pInstance);
    };
}

namespace app::snd {
    struct AmbNearPointParameter {
        csl::ut::VariableString cueName;
        float sensorRebootTime;
        float sensorRepositionTime;
        float lifeAreaRadius;
        float lifeTime;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbNearPointParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbNearPointParameter* pInstance);
        static void Clean(AmbNearPointParameter* pInstance);
    };
}

namespace app::snd {
    struct AmbRelativeWindParameter {
        csl::ut::VariableString cueName;
        float speedThreshold;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbRelativeWindParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbRelativeWindParameter* pInstance);
        static void Clean(AmbRelativeWindParameter* pInstance);
    };
}

namespace app::snd {
    struct AmbRiverParameter_Multiple3D {
        csl::ut::VariableString cueName;
        float attenuationDistance;
        float maxLevelPerPoint;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbRiverParameter_Multiple3D* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbRiverParameter_Multiple3D* pInstance);
        static void Clean(AmbRiverParameter_Multiple3D* pInstance);
    };
}

namespace app::snd {
    struct AmbRiverParameter_Nearest {
        csl::ut::VariableString cueName;
        float sensorRadius;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbRiverParameter_Nearest* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbRiverParameter_Nearest* pInstance);
        static void Clean(AmbRiverParameter_Nearest* pInstance);
    };
}

namespace app::snd {
    struct AmbSoundParameter {
        app::snd::AmbInfo ambSoundInfo[8];
        app::snd::AmbBaseNoiseParameter baseNoise;
        app::snd::AmbRelativeWindParameter relativeWind;
        app::snd::AmbNearPointParameter insect;
        app::snd::AmbNearPointParameter grass;
        app::snd::AmbRiverParameter_Nearest riverNearest;
        app::snd::AmbRiverParameter_Multiple3D riverMultiple3D;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AmbSoundParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AmbSoundParameter* pInstance);
        static void Clean(AmbSoundParameter* pInstance);
    };
}

namespace app::snd {
    struct AisacChangeInfo {
        float value;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AisacChangeInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AisacChangeInfo* pInstance);
        static void Clean(AisacChangeInfo* pInstance);
    };
}

namespace app::snd {
    struct AisacChangeInfoList {
        app::snd::AisacChangeInfo beginTimeStopBGM;
        app::snd::AisacChangeInfo endTimeStopBGM;
        app::snd::AisacChangeInfo beginTimeStopSE;
        app::snd::AisacChangeInfo endTimeStopSE;
        app::snd::AisacChangeInfo beginUnderWater;
        app::snd::AisacChangeInfo endUnderWater;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AisacChangeInfoList* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AisacChangeInfoList* pInstance);
        static void Clean(AisacChangeInfoList* pInstance);
    };
}

namespace app::snd {
    struct BGMInfo {
        enum class Priority : int8_t {
            PRIORITY_LOW = 0,
            PRIORITY_DEFAULT = 1,
            PRIORITY_HIGH = 2,
            PRIORITY_SUPER_HIGH = 3,
            NUM_PRIORITY = 4,
            PRIORITY_INVALID = -1,
        };

        enum class InterruptType : int8_t {
            INTERRUPT_TYPE_STOP = 0,
            INTERRUPT_TYPE_PAUSE = 1,
            INTERRUPT_TYPE_OVERLAP = 2,
            NUM_INTERRUPT_TYPE = 3,
        };

        csl::ut::VariableString cueName;
        int32_t blockId;
        float fadeInTime;
        float fadeOutTime;
        float delayTime;
        csl::ut::VariableString aisacName;
        float aisacValue;
        float aisacFadeTime;
        bool isVolumeControl;
        bool isOverlapPlay;
        Priority priority;
        InterruptType interruptType;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMInfo* pInstance);
        static void Clean(BGMInfo* pInstance);
    };
}

namespace app::snd {
    struct BGMTransitInfo {
        enum class InterruptType : int8_t {
            INTERRUPT_TYPE_STOP = 0,
            INTERRUPT_TYPE_PAUSE = 1,
            INTERRUPT_TYPE_OVERLAP = 2,
            NUM_INTERRUPT_TYPE = 3,
        };

        csl::ut::VariableString tagName;
        int32_t beforeId;
        int32_t beforeIdMax;
        int32_t afterId;
        InterruptType type;
        float fadeOutTime;
        float fadeInTime;
        float delayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMTransitInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMTransitInfo* pInstance);
        static void Clean(BGMTransitInfo* pInstance);
    };
}

namespace app::snd {
    struct BGMSceneInfo {
        csl::ut::VariableString sceneName;
        int32_t bgmId;
        bool disableSameBgmId;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMSceneInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMSceneInfo* pInstance);
        static void Clean(BGMSceneInfo* pInstance);
    };
}

namespace app::snd {
    struct BGMInfoParameter {
        app::snd::BGMInfo changeBgmInfo[32];
        app::snd::BGMTransitInfo transitBgmInfo[32];
        app::snd::BGMSceneInfo sceneBgmInfo[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMInfoParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMInfoParameter* pInstance);
        static void Clean(BGMInfoParameter* pInstance);
    };
}

namespace app::snd {
    struct BGMVolumeChangeInfo {
        float value;
        float delayTime;
        float fadeTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMVolumeChangeInfo* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMVolumeChangeInfo* pInstance);
        static void Clean(BGMVolumeChangeInfo* pInstance);
    };
}

namespace app::snd {
    struct BGMVolumeChangeInfoList {
        app::snd::BGMVolumeChangeInfo playerStop;
        app::snd::BGMVolumeChangeInfo playerWalk;
        app::snd::BGMVolumeChangeInfo playerRun;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(BGMVolumeChangeInfoList* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(BGMVolumeChangeInfoList* pInstance);
        static void Clean(BGMVolumeChangeInfoList* pInstance);
    };
}

namespace app::snd {
    struct SoundCommonParameter {
        float pauseFadeOutTime;
        float pauseFadeInTime;
        float enterWhitespaceFadeOutTime;
        float leaveWhitespaceResultFadeOutTime;
        app::snd::BGMVolumeChangeInfoList bgmVolumeInfo;
        app::snd::AisacChangeInfoList aisacInfo;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SoundCommonParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SoundCommonParameter* pInstance);
        static void Clean(SoundCommonParameter* pInstance);
    };
}

namespace heur::rfl {
    struct LabelData {
        enum class DisplayType : int8_t {
            Caption = 0,
        };

        DisplayType display;
        csl::ut::VariableString label;
        float waitTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(LabelData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(LabelData* pInstance);
        static void Clean(LabelData* pInstance);
    };
}

namespace heur::rfl {
    struct Discussion {
        heur::rfl::LabelData labels[20];
        bool isForcePlay;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(Discussion* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(Discussion* pInstance);
        static void Clean(Discussion* pInstance);
    };
}

namespace heur::rfl {
    struct CaptionParameter {
        heur::rfl::Discussion discussions[10];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CaptionParameter* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CaptionParameter* pInstance);
        static void Clean(CaptionParameter* pInstance);
    };
}

namespace app::save {
    struct PlayLog {
        csl::ut::VariableString stagecode;
        csl::ut::VariableString play;
        csl::ut::VariableString option;
        csl::math::Vector3 position;
        float time;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayLog* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayLog* pInstance);
        static void Clean(PlayLog* pInstance);
    };
}

namespace app::save {
    struct PlayStatsSummary {
        csl::ut::VariableString stagecode;
        int32_t highTime;
        int32_t highScore;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayStatsSummary* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayStatsSummary* pInstance);
        static void Clean(PlayStatsSummary* pInstance);
    };
}

namespace app::save {
    struct PlayStatsData {
        int32_t enemies;
        int32_t damages;
        int32_t misses;
        int32_t retry;
        int32_t restart;
        csl::ut::MoveArray<app::save::PlayLog> logs;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayStatsData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayStatsData* pInstance);
        static void Clean(PlayStatsData* pInstance);
    };
}

namespace app::save {
    struct PlayStats {
        csl::ut::VariableString username;
        csl::ut::VariableString time;
        csl::ut::MoveArray<app::save::PlayStatsSummary> summaries;
        app::save::PlayStatsData playLog;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayStats* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayStats* pInstance);
        static void Clean(PlayStats* pInstance);
    };
}

namespace app::save {
    struct StageData {
        enum class RankType : uint8_t {
            RANK_S = 0,
            RANK_A = 1,
            RANK_B = 2,
            RANK_C = 3,
            RANK_D = 4,
            RANK_NUM = 4,
        };

        uint16_t flags;
        uint32_t bestScore;
        uint32_t bestScoreDwing;
        uint32_t bestRing;
        uint32_t bestRingDwing;
        uint32_t bestTime[3];
        uint32_t bestTimeDwing[3];
        RankType bestRank;
        RankType bestRankDwing;
        int16_t bgmId;
        uint8_t numBossGateKey;
        int8_t collectionGearDatas[3];
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageData* pInstance);
        static void Clean(StageData* pInstance);
    };
}

namespace app::save {
    struct WorldFlagData {
        uint32_t bitFlags[1024];
        int8_t byteFlags[1024];
        uint32_t intDatas[512];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WorldFlagData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WorldFlagData* pInstance);
        static void Clean(WorldFlagData* pInstance);
    };
}

namespace app::save {
    struct AddContentDataGame {
        app::save::StageData stages[10];
        app::save::WorldFlagData worldDatas[10];
        uint32_t reserved[128];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AddContentDataGame* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AddContentDataGame* pInstance);
        static void Clean(AddContentDataGame* pInstance);
    };
}

namespace app::save {
    struct RankingData {
        enum class RankType : uint8_t {
            RANK_S = 0,
            RANK_A = 1,
            RANK_B = 2,
            RANK_C = 3,
            RANK_D = 4,
            RANK_NUM = 4,
        };

        uint8_t flags;
        uint32_t bestScore;
        uint32_t bestScoreDwing;
        uint32_t bestRing;
        uint32_t bestRingDwing;
        uint32_t bestTime[3];
        uint32_t bestTimeDwing[3];
        RankType bestRank;
        RankType bestRankDwing;
        uint32_t clearCount;
        bool uploaded;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RankingData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RankingData* pInstance);
        static void Clean(RankingData* pInstance);
    };
}

namespace app::save {
    struct AddContentDataSystem {
        app::save::RankingData addRanking[10];
        uint32_t reserved[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(AddContentDataSystem* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(AddContentDataSystem* pInstance);
        static void Clean(AddContentDataSystem* pInstance);
    };
}

namespace app::save {
    struct CharacterData {
        uint16_t numRings;
        uint8_t numBossGateKey[5];
        uint8_t numRocketParts;
        uint8_t numDgear[5];
        uint8_t numTreasureChestGear[3];
        uint8_t hasDpower[5];
        uint32_t flags;
        uint32_t reserved[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CharacterData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CharacterData* pInstance);
        static void Clean(CharacterData* pInstance);
    };
}

namespace app::save {
    struct UnlockData {
        uint8_t flags;
        uint8_t reserved[3];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UnlockData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UnlockData* pInstance);
        static void Clean(UnlockData* pInstance);
    };
}

namespace app::save {
    struct CollectionData {
        app::save::UnlockData artParam[140];
        app::save::UnlockData movieParam[35];
        app::save::UnlockData soundParam[120];
        app::save::UnlockData characterParam[20];
        app::save::UnlockData historyParam[15];
        app::save::UnlockData noteParam[30];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CollectionData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CollectionData* pInstance);
        static void Clean(CollectionData* pInstance);
    };
}

namespace app::save {
    struct CRMContainerData {
        int8_t uuid[40];
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(CRMContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(CRMContainerData* pInstance);
        static void Clean(CRMContainerData* pInstance);
    };
}

namespace app::save {
    struct FlagContainerData {
        uint32_t bitFlags[24];
        int8_t byteFlags[128];
        uint32_t intDatas[16];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(FlagContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(FlagContainerData* pInstance);
        static void Clean(FlagContainerData* pInstance);
    };
}

namespace app::save {
    struct HeaderData {
        enum class Status : int8_t {
            STATUS_ZERO_FILL = 0,
            STATUS_INITIALIZED = 1,
        };

        enum class Sequence : int8_t {
            NewGame = 0,
            DSpearTutorialAfter = 1,
            FinalBossBefore = 2,
            FinalBossAfter = 3,
        };

        uint32_t signature;
        uint8_t version;
        Status status;
        uint8_t config;
        Sequence sequence;
        uint32_t playTime;
        uint8_t reserved0;
        uint16_t reserved1;
        int64_t saveDate;
        uint8_t index;
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(HeaderData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(HeaderData* pInstance);
        static void Clean(HeaderData* pInstance);
    };
}

namespace app::save {
    struct GamePlayData {
        enum class Status : int8_t {
            STATUS_NEWGAME = 0,
            STATUS_CONTINUE = 1,
        };

        Status status;
        int8_t lastPlayedStageNo;
        uint8_t flags;
        csl::math::Vector3 position;
        csl::math::Quaternion rotation;
        uint32_t day;
        uint32_t hour;
        uint32_t minute;
        float second;
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GamePlayData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GamePlayData* pInstance);
        static void Clean(GamePlayData* pInstance);
    };
}

namespace app::save {
    struct WhitespaceStageData {
        csl::math::Vector3 destination;
        uint32_t flags;
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhitespaceStageData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhitespaceStageData* pInstance);
        static void Clean(WhitespaceStageData* pInstance);
    };
}

namespace app::save {
    struct StageContainerData {
        app::save::StageData stages[50];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StageContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StageContainerData* pInstance);
        static void Clean(StageContainerData* pInstance);
    };
}

namespace app::save {
    struct UnlockQAData {
        bool unlocked;
        bool displayed;
        uint8_t reserved[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(UnlockQAData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(UnlockQAData* pInstance);
        static void Clean(UnlockQAData* pInstance);
    };
}

namespace app::save {
    struct QAData {
        app::save::UnlockQAData qaParam[50];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(QAData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(QAData* pInstance);
        static void Clean(QAData* pInstance);
    };
}

namespace app::save {
    struct WorldFlagContainerData {
        app::save::WorldFlagData worldDatas[50];
        app::save::WorldFlagData debugWorldData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WorldFlagContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WorldFlagContainerData* pInstance);
        static void Clean(WorldFlagContainerData* pInstance);
    };
}

namespace app::save {
    struct StatValue {
        int32_t value;
        bool assigned;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatValue* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatValue* pInstance);
        static void Clean(StatValue* pInstance);
    };
}

namespace app::save {
    struct StatsContainerData {
        app::save::StatValue stats[1];
        float runLength;
        uint32_t reserved[32];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(StatsContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(StatsContainerData* pInstance);
        static void Clean(StatsContainerData* pInstance);
    };
}

namespace app::save {
    struct GameData {
        app::save::HeaderData header;
        app::save::GamePlayData gameplay;
        app::save::CharacterData character;
        app::save::WhitespaceStageData whitespace;
        app::save::StageContainerData stages;
        app::save::CollectionData collection;
        app::save::QAData qa;
        app::save::FlagContainerData flags;
        app::save::WorldFlagContainerData worldFlags;
        app::save::StatsContainerData stats;
        app::save::AddContentDataGame addData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GameData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GameData* pInstance);
        static void Clean(GameData* pInstance);
    };
}

namespace app::save {
    struct NoSaveData {
        bool enterOptionMenu;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(NoSaveData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(NoSaveData* pInstance);
        static void Clean(NoSaveData* pInstance);
    };
}

namespace app::save {
    struct OptionAudioData {
        uint8_t masterVolume;
        uint8_t sfxVolume;
        uint8_t musicVolume;
        uint8_t voiceVolume;
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OptionAudioData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OptionAudioData* pInstance);
        static void Clean(OptionAudioData* pInstance);
    };
}

namespace app::save {
    struct OptionCameraData {
        enum class MovementStyle : int8_t {
            PadSimulate = 0,
            Aiming = 1,
        };

        float rotateSpeedPad;
        float rotateSpeedVertMouse;
        float rotateSpeedHorzMouse;
        float reticleSpeedPad;
        float reticleSpeedVertMouse;
        float reticleSpeedHorzMouse;
        uint8_t rotateSpeedRate;
        uint8_t distanceRate;
        uint8_t fovyRate;
        MovementStyle movementStyle;
        uint8_t config;
        uint32_t reserved[4];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OptionCameraData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OptionCameraData* pInstance);
        static void Clean(OptionCameraData* pInstance);
    };
}

namespace app::save {
    struct OptionControlsData {
        enum class InputButtonImageKind : int8_t {
            Default = 0,
            PS4 = 1,
            PS5 = 2,
            XBOX = 3,
            SCARLETT = 4,
            SWITCH = 5,
            STEAM = 6,
            Num = 7,
        };

        enum class InputStyleKind : int8_t {
            Default = 0,
            Style2 = 1,
            Custom = 2,
            Num = 3,
        };

        enum class InputKey : int32_t {
            Invalid = -1,
            GamePad_DPadLeft = 0,
            GamePad_DPadRight = 1,
            GamePad_DPadUp = 2,
            GamePad_DPadDown = 3,
            GamePad_ButtonLeft = 4,
            GamePad_ButtonRight = 5,
            GamePad_ButtonTop = 6,
            GamePad_ButtonBottom = 7,
            GamePad_LeftX = 8,
            GamePad_LeftY = 9,
            GamePad_RightX = 10,
            GamePad_RightY = 11,
            GamePad_LeftShoulder = 12,
            GamePad_LeftTrigger = 13,
            GamePad_LeftClick = 14,
            GamePad_RightShoulder = 15,
            GamePad_RightTrigger = 16,
            GamePad_RightClick = 17,
            GamePad_LeftStickLeft = 18,
            GamePad_LeftStickRight = 19,
            GamePad_LeftStickUp = 20,
            GamePad_LeftStickDown = 21,
            GamePad_RightStickLeft = 22,
            GamePad_RightStickRight = 23,
            GamePad_RightStickUp = 24,
            GamePad_RightStickDown = 25,
            GamePad_Start = 26,
            GamePad_Select = 27,
            GamePad_LeftSideTriggerLeft = 28,
            GamePad_LeftSideTriggerRight = 29,
            GamePad_RightSideTriggerLeft = 30,
            GamePad_RightSideTriggerRight = 31,
            Keyboard_Nop = 32,
            Keyboard_A = 33,
            Keyboard_B = 34,
            Keyboard_C = 35,
            Keyboard_D = 36,
            Keyboard_E = 37,
            Keyboard_F = 38,
            Keyboard_G = 39,
            Keyboard_H = 40,
            Keyboard_I = 41,
            Keyboard_J = 42,
            Keyboard_K = 43,
            Keyboard_L = 44,
            Keyboard_M = 45,
            Keyboard_N = 46,
            Keyboard_O = 47,
            Keyboard_P = 48,
            Keyboard_Q = 49,
            Keyboard_R = 50,
            Keyboard_S = 51,
            Keyboard_T = 52,
            Keyboard_U = 53,
            Keyboard_V = 54,
            Keyboard_W = 55,
            Keyboard_X = 56,
            Keyboard_Y = 57,
            Keyboard_Z = 58,
            Keyboard_1 = 59,
            Keyboard_2 = 60,
            Keyboard_3 = 61,
            Keyboard_4 = 62,
            Keyboard_5 = 63,
            Keyboard_6 = 64,
            Keyboard_7 = 65,
            Keyboard_8 = 66,
            Keyboard_9 = 67,
            Keyboard_0 = 68,
            Keyboard_Enter = 69,
            Keyboard_Escape = 70,
            Keyboard_BackSpace = 71,
            Keyboard_Tab = 72,
            Keyboard_Spacebar = 73,
            Keyboard_Minus = 74,
            Keyboard_Accent = 75,
            Keyboard_Atmark = 76,
            Keyboard_LeftBracket = 77,
            Keyboard_BackSlash = 78,
            Keyboard_RightBracket = 79,
            Keyboard_SemiColon = 80,
            Keyboard_Colon = 81,
            Keyboard_Comma = 82,
            Keyboard_Period = 83,
            Keyboard_Slash = 84,
            Keyboard_CapsLock = 85,
            Keyboard_Grave = 86,
            Keyboard_Equals = 87,
            Keyboard_Apostrophe = 88,
            Keyboard_OEM_102 = 89,
            Keyboard_ABNT_C1 = 90,
            Keyboard_F1 = 91,
            Keyboard_F2 = 92,
            Keyboard_F3 = 93,
            Keyboard_F4 = 94,
            Keyboard_F5 = 95,
            Keyboard_F6 = 96,
            Keyboard_F7 = 97,
            Keyboard_F8 = 98,
            Keyboard_F9 = 99,
            Keyboard_F10 = 100,
            Keyboard_F11 = 101,
            Keyboard_F12 = 102,
            Keyboard_Insert = 103,
            Keyboard_Home = 104,
            Keyboard_PageUp = 105,
            Keyboard_Delete = 106,
            Keyboard_End = 107,
            Keyboard_PageDown = 108,
            Keyboard_LeftArrow = 109,
            Keyboard_RightArrow = 110,
            Keyboard_UpArrow = 111,
            Keyboard_DownArrow = 112,
            Keyboard_PadSlash = 113,
            Keyboard_PadAsterisk = 114,
            Keyboard_PadMinus = 115,
            Keyboard_PadPlus = 116,
            Keyboard_PadEnter = 117,
            Keyboard_PadNum1 = 118,
            Keyboard_PadNum2 = 119,
            Keyboard_PadNum3 = 120,
            Keyboard_PadNum4 = 121,
            Keyboard_PadNum5 = 122,
            Keyboard_PadNum6 = 123,
            Keyboard_PadNum7 = 124,
            Keyboard_PadNum8 = 125,
            Keyboard_PadNum9 = 126,
            Keyboard_PadNum0 = 127,
            Keyboard_PadPeriod = 128,
            Keyboard_LeftCtrl = 129,
            Keyboard_RightCtrl = 130,
            Keyboard_LeftShift = 131,
            Keyboard_RightShift = 132,
            Keyboard_LeftAlt = 133,
            Keyboard_RightAlt = 134,
            Keyboard_LeftGui = 135,
            Keyboard_RightGui = 136,
            Mouse_X = 137,
            Mouse_Y = 138,
            Mouse_ButtonLeft = 139,
            Mouse_ButtonRight = 140,
            Mouse_ButtonMiddle = 141,
            Mouse_ButtonX1 = 142,
            Mouse_ButtonX2 = 143,
            Mouse_ButtonX3 = 144,
            Mouse_ButtonX4 = 145,
            Mouse_ButtonX5 = 146,
            Mouse_Wheel = 147,
            Mouse_WheelUp = 148,
            Mouse_WheelDown = 149,
        };

        InputButtonImageKind buttonImageKind;
        InputStyleKind gamepadStyleKind;
        InputKey padMappings[45];
        InputKey mainMappings[45];
        InputKey subMappings[45];
        uint8_t reserved[1];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OptionControlsData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OptionControlsData* pInstance);
        static void Clean(OptionControlsData* pInstance);
    };
}

namespace app::save {
    struct OptionGamePlayData {
        enum class VoiceLanguageType : int8_t {
            VOICE_LANGUAGE_ENGLISH = 0,
            VOICE_LANGUAGE_FRENCH = 1,
            VOICE_LANGUAGE_ITALIAN = 2,
            VOICE_LANGUAGE_GERMAN = 3,
            VOICE_LANGUAGE_SPANISH = 4,
            VOICE_LANGUAGE_JAPANESE = 5,
            NUM_VOICE_LANGUAGES = 6,
        };

        enum class LanguageType : int8_t {
            LANGUAGE_ENGLISH = 0,
            LANGUAGE_FRENCH = 1,
            LANGUAGE_ITALIAN = 2,
            LANGUAGE_GERMAN = 3,
            LANGUAGE_SPANISH = 4,
            LANGUAGE_POLISH = 5,
            LANGUAGE_PORTUGUESE = 6,
            LANGUAGE_RUSSIAN = 7,
            LANGUAGE_JAPANESE = 8,
            LANGUAGE_ZHONGWEN = 9,
            LANGUAGE_ZHONGWEN_S = 10,
            LANGUAGE_KOREAN = 11,
            LANGUAGE_THAI = 12,
            NUM_LANGUAGES = 13,
        };

        enum class SkinType : int8_t {
            Original = 0,
            Type1 = 1,
        };

        uint8_t initialSpeedRate;
        uint8_t boostInitialSpeedRate;
        uint8_t acceleRate;
        uint8_t maxSpeedRate;
        uint8_t minTurnSpeedRate;
        uint8_t boostMinTurnSpeedRate;
        uint8_t rotateForceRate;
        uint8_t bumpJumpGravityRate;
        uint8_t brakeRate;
        VoiceLanguageType speech;
        LanguageType text;
        uint16_t config;
        uint8_t padSensibilityRate;
        uint8_t mouseSensibilityRate;
        uint8_t flags;
        SkinType dlcSkinGeneClassic;
        SkinType dlcSkinGeneModern;
        SkinType dlcSkinShadow;
        uint8_t dlcConfig;
        uint8_t reserved1[5];
        uint32_t reserved2[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OptionGamePlayData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OptionGamePlayData* pInstance);
        static void Clean(OptionGamePlayData* pInstance);
    };
}

namespace app::save {
    struct OptionGraphicsData {
        enum class FrameRate : int8_t {
            FPS60 = 0,
            FPS30 = 1,
            FPS120 = 2,
            FPSNoLimit = 3,
        };

        enum class Shadow : int8_t {
            High = 0,
            Low = 1,
        };

        enum class Bloom : int8_t {
            High = 0,
            Low = 1,
        };

        enum class VolumetricLight : int8_t {
            High = 0,
            Low = 1,
        };

        enum class AntiAliasing : int8_t {
            TAA = 0,
            FXAA = 1,
            None = 2,
        };

        enum class AnisotropicFiltering : int8_t {
            None = 0,
            Low = 1,
            Medium = 2,
            High = 3,
        };

        enum class DOF : int8_t {
            Disabled = 0,
            Low = 1,
            Medium = 2,
            High = 3,
        };

        enum class RederingScale : int8_t {
            High = 0,
            Medium = 1,
            Low = 2,
        };

        FrameRate frameRate;
        Shadow shadow;
        Bloom bloom;
        VolumetricLight volumetricLight;
        uint8_t brightness;
        AntiAliasing antiAliasing;
        AnisotropicFiltering anisotropicFiltering;
        DOF depthOfField;
        uint8_t config;
        RederingScale renderingScale;
        uint16_t width;
        uint16_t height;
        uint8_t reserved1[1];
        uint32_t reserved[2];

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(OptionGraphicsData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(OptionGraphicsData* pInstance);
        static void Clean(OptionGraphicsData* pInstance);
    };
}

namespace app::save {
    struct PlayLogCoordData {
        uint16_t time;
        uint16_t x;
        uint16_t y;
        uint16_t z;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayLogCoordData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayLogCoordData* pInstance);
        static void Clean(PlayLogCoordData* pInstance);
    };
}

namespace app::save {
    struct PlayLogEventData {
        enum class EventType : int8_t {
            InvalidEvent = -1,
            Dead = 0,
            Damage = 1,
            BeginStage = 2,
            CompleteStage = 3,
            RestartStage = 4,
            GiveupStage = 5,
            EndStage = 6,
            TimeStop = 7,
            QteResult = 8,
            BossPhaseChange = 9,
            OpenCollectionBox = 10,
        };

        app::save::PlayLogCoordData coord;
        EventType eventType;
        int8_t option;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayLogEventData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayLogEventData* pInstance);
        static void Clean(PlayLogEventData* pInstance);
    };
}

namespace app::save {
    struct PlayLogData {
        uint32_t numFootMarks;
        uint32_t footMarksIndex;
        app::save::PlayLogCoordData footmarks[36000];
        uint32_t numEvents;
        uint32_t eventsIndex;
        app::save::PlayLogEventData events[50000];
        uint32_t wsPlayTime;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(PlayLogData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(PlayLogData* pInstance);
        static void Clean(PlayLogData* pInstance);
    };
}

namespace app::save {
    struct RankingContainerData {
        app::save::RankingData ranking[25];
        bool enableDWing;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(RankingContainerData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(RankingContainerData* pInstance);
        static void Clean(RankingContainerData* pInstance);
    };
}

namespace app::save {
    struct SystemData {
        app::save::HeaderData header;
        app::save::OptionGamePlayData gameplay;
        app::save::OptionControlsData controls;
        app::save::OptionCameraData camera;
        app::save::OptionAudioData audio;
        app::save::OptionGraphicsData graphics;
        app::save::RankingContainerData rankings;
        app::save::CRMContainerData crm;
        app::save::AddContentDataSystem addData;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(SystemData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(SystemData* pInstance);
        static void Clean(SystemData* pInstance);
    };
}

namespace heur::rfl {
    struct WhitespaceMapGridData {
        uint8_t x;
        uint8_t y;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhitespaceMapGridData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhitespaceMapGridData* pInstance);
        static void Clean(WhitespaceMapGridData* pInstance);
    };
}

namespace heur::rfl {
    struct WhitespaceMapData {
        heur::rfl::WhitespaceMapGridData grid[2];
        uint16_t numReleaseGrids;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(WhitespaceMapData* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(WhitespaceMapData* pInstance);
        static void Clean(WhitespaceMapData* pInstance);
    };
}

