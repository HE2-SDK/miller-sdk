#pragma once

#define DECLARE_EMISSION(CLASS_NAME)public:\
        CLASS_NAME(Emitter* emitter, const csl::math::Matrix44& emissionMatrix);\
        void CreateElements();\
        virtual bool EmitElement() override;

namespace Cyan{
    class EmissionBase {
    public:
        int64_t unk0;
        Emitter* emitter;
        ManagerImpl* manager;
        EmitParam emitParam;
        csl::math::Matrix44 emissionMatrix;

        EmissionBase(Emitter* emitter, const csl::math::Matrix44& emissionMatrix);

        bool EntryElement(EmitParam* emitParam, const Resource::ElementParam* elementParam);

        virtual bool EmitElement() = 0;
    };

    class EmissionPoint : public EmissionBase {
    public:
        DECLARE_EMISSION(EmissionPoint)
    };

    class EmissionSphere : public EmissionBase {
    public:
        struct EmitOption {
            float azimuthFraction;
            float elevationFraction;
        };

        bool EmitElement(const EmitOption& emitOption, const Resource::EmitterParam* emitterParam);
        
        DECLARE_EMISSION(EmissionSphere)
    };

    class EmissionDisc : public EmissionBase {
    public:
        struct EmitOption {
            float normalizedSpreadOffset;
        };

        bool EmitElement(const EmitOption& emitOption, const Resource::EmitterParam* emitterParam);

        DECLARE_EMISSION(EmissionDisc)
    };

    class EmissionCylinder : public EmissionBase {
    public:
        struct EmitOption {
            float azimuthFraction;
            float elevationFraction;
        };

        bool EmitElement(const EmitOption& emitOption, const Resource::EmitterParam* emitterParam);

        DECLARE_EMISSION(EmissionCylinder)
    };

    class EmissionLine : public EmissionBase {
    public:
        struct EmitOption {
            float unk0;
        };

        bool EmitElement(const EmitOption& emitOption, const Resource::EmitterParam* emitterParam);

        DECLARE_EMISSION(EmissionLine)
    };

    class EmissionTorus : public EmissionBase {
    public:
        struct EmitOption {
            float unk0;
        };

        bool EmitElement(const EmitOption& emitOption, const Resource::EmitterParam* emitterParam);

        DECLARE_EMISSION(EmissionTorus)
    };

    class EmissionCube : public EmissionBase {
    public:
        DECLARE_EMISSION(EmissionCube)
    };

    class EmissionFixed : public EmissionBase {
    public:
        DECLARE_EMISSION(EmissionFixed)
    };
}
