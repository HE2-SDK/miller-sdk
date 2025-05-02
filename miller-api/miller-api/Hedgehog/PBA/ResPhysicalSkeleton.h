#pragma once
#include <ucsl/resources/pba/v1.h>

namespace hh::pba{
    class ResPhysicalSkeleton : public hh::fnd::ManagedResource {
    public:
        struct RigidBody {
            csl::ut::VariableString boneName;
            bool isStaticObject;
            bool isShapeBox;
            float shapeRadius;
            float shapeHeight;
            float shapeDepth;
            float mass;
            float friction;
            float resitution;
            float linearDamping;
            float angularDamping;
            csl::math::Vector3 offsetPosition;
            csl::math::Quaternion offsetRotation;
        };

        struct Constraint {
            csl::ut::VariableString boneName;
            char unk0;
            char unk1;
            short numIterations;
            short localParentBoneIndex;
            short localBoneIndex;
            short realParentBoneIndex;
            ucsl::resources::pba::v1::Limit angularLimits[3];
            ucsl::resources::pba::v1::Limit linearLimits[3];
            csl::math::Vector3 offsetPositionA;
            csl::math::Quaternion offsetRotationA;
            csl::math::Vector3 offsetPositionB;
            csl::math::Quaternion offsetRotationB;
        };

        struct Node {
            csl::ut::VariableString boneName;
            float mass;
            short unk1;
            bool ifPinned;
            int unk1b;
            short childIdx;
            short parentIdx;
            short unk2[2];
            short leftIdx;
            short rightIdx;
        };

        struct SoftBody{
            csl::ut::VariableString name;
            csl::ut::MoveArray<Node> nodes;
            csl::ut::MoveArray<ucsl::resources::pba::v1::Link> links;
            float scale;
            float dampingCoeff;
            float dragCoeff;
            float liftCoeff;
            float dynamicFrictionCoeff;
            float poseMatchingCoeff;
            float rigidContactsCoeff;
            float kineticContactsHardness;
            float softContactsHardness;
            float anchorsHardness;
            int positionIterations;
            char unk2;
            char unk3;
        };

        csl::ut::MoveArray<RigidBody> rigidbodies;
        csl::ut::MoveArray<Constraint> constraints;
        csl::ut::MoveArray<SoftBody> softbodies;
        csl::ut::MoveArray<short> unkArray3; // contains somekind of indices
        csl::ut::MoveArray<short> unkArray4; // contains somekind of indices
        csl::ut::MoveArray<short> unkArray5; // contains somekind of indices

        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicalSkeleton)

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
    };
}