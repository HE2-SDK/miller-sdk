#pragma once

namespace app::gfx {
    struct FxColCollisionShape {
        enum class Shape : uint8_t {
            SPHERE,
            CYLINDER,
            ANISOTROPIC_OBB,
            ISOTROPIC_OBB,
        };

        enum class Type : uint8_t {
            SCENE_PARAMETER_INDEX,
            LIGHT_PARAMETER_INDEX,
            CAMERA,
            HEAT_HAZE,
        };

        struct SphereExtents {
            float radius;
            float borderThickness;
        };

        struct CylinderExtents {
            float radius;
            float halfHeight;
            float borderThickness;
        };

        struct AnisotropicObbExtents {
            float depth;  // Z
            float width;  // X
            float height; // Y
            float maybeWidthAndHeightBorderThickness;
            float positiveDepthBorderThickness;
            float negativeDepthBorderThickness;
        };

        struct IsotropicObbExtents {
            float depth;  // Z
            float width;  // X
            float height; // Y
            float borderThickness;
        };

        union Extents {
            SphereExtents sphere;
            CylinderExtents cylinder;
            AnisotropicObbExtents anisotropicObb;
            IsotropicObbExtents isotropicObb;
        };

        struct SceneParameterIndexParameters {
            unsigned int sceneParameterIndex;
            float interpolationTime;
        };

        struct LightParameterIndexParameters {
            unsigned int lightParameterIndex;
        };

        struct HeatHazeParameters {
            float heatHazeMaxHeight;
            float interpolationTime;
        };

        struct CameraParameters {
            uint32_t unk1;
            uint32_t unk2;
            float bloomScale;
            float autoExposureMiddleGray;
            uint32_t unk3;
            float luminance;
            float autoExposureAdaptedRatio;
            float interpolationTime;
        };

        union Parameters {
            SceneParameterIndexParameters sceneParameterIndex;
            LightParameterIndexParameters lightParameterIndex;
            HeatHazeParameters heatHaze;
            CameraParameters camera;
        };

        const char* name;
        Shape shape;
        Type type;
        uint8_t unk1;
        uint8_t priority;
        Extents extents;
        Parameters parameters;
        const char* unk2;
        csl::math::Position position;
        csl::math::Rotation rotation;
    };

    struct FxColBoundingVolume {
        unsigned int shapeCount;
        int shapeStartIdx;
        csl::math::Position aabbMin;
        csl::math::Position aabbMax;
    };

    struct FxColUnk1 {
        int unk1;
        int unk2;
    };

    struct FxColData {
        char magic[4];
        unsigned int version;
        unsigned int collisionShapeCount;
        FxColCollisionShape* collisionShapes;
        unsigned int boundingVolumeCount;
        FxColBoundingVolume* boundingVolumes;
        unsigned int unk1Count;
        FxColUnk1* unk1s;
    };

    class ResFxColFile2 : public hh::fnd::ManagedResource {
    public:
        FxColData* fxColData;
        virtual void Load(void* data, size_t size) override;
    };
}
