#pragma once

namespace app::dv{
    class DvElementShadowMapParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class ShadowFilter : unsigned int {
                SHADOW_FILTER_POINT,
                SHADOW_FILTER_PCF,
                SHADOW_FILTER_PCSS,
                SHADOW_FILTER_ESM,
                SHADOW_FILTER_MSM,
                SHADOW_FILTER_VSM_POINT,
                SHADOW_FILTER_VSM_LINEAR,
                SHADOW_FILTER_VSM_ANISO_2,
                SHADOW_FILTER_VSM_ANISO_4,
                SHADOW_FILTER_VSM_ANISO_8,
                SHADOW_FILTER_VSM_ANISO_16,
                SHADOW_FILTER_COUNT,
                SHADOW_FILTER_VSM_FIRST,
                SHADOW_FILTER_VSM_LAST
            };

            enum class ShadowRangeType : unsigned int {
                SHADOW_RANGE_TYPE_CAMERA_LOOKAT,
                SHADOW_RANGE_TYPE_POSITION_MANUAL,
                SHADOW_RANGE_TYPE_FULL_MANUAL,
                SHADOW_RANGE_TYPE_COUNT,
                SHADOW_RANGE_TYPE_DEFAULT
            };

            enum class FitProjection : unsigned int {
                FIT_PROJECTION_TO_CASCADES,
                FIT_PROJECTION_TO_SCENE,
                FIT_PROJECTION_TO_ROTATE_CASCADES
            };

            enum class FitNearFar : unsigned int {
                FIT_NEARFAR_ZERO_ONE,
                FIT_NEARFAR_AABB,
                FIT_NEARFAR_SCENE_AABB
            };

            enum class PartitionType : unsigned int {
                PARTITION_PSSM,
                PARTITION_MANUAL,
            };

            enum class Flags : unsigned int {
                ENABLE_BACK_FACE_SHADOW,
                ENABLE_SHADOW_CAMERA,
                ENABLE_DRAW_SCENE_AABB,
                ENABLE_DRAW_SHADOW_FRUSTRUM,
                ENABLE_DRAW_CASCADE,
                ENABLE_DRAW_CAMERA_FRUSTRUM,
                ENABLE_PAUSE_CAMERA
            };

            ShadowFilter shadowFilter;
            ShadowRangeType shadowRangeType;
            FitProjection fitProjection;
            FitNearFar fitNearFar;
            PartitionType partitionType;
            float sceneRange;
            csl::math::Position sceneCenter;
            csl::math::Position manualLightPos;
            float pssmLambda;
            float cascadeOffset;
            int cascadeLevel;
            float cascadeSplits[4];
            float cascadeBias[4];
            float bias;
            float offset;
            float normalBias;
        private:
            char empty[8];
        public:
            int blurQuality;
            int blurSize;
            float fadeoutDistance;
            float cascadeTransitionFadeDistance;
            csl::ut::Bitset<Flags> flags;
        };

        bool jobGenerated;
        int unk0;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementShadowMapParam)
    };
}
