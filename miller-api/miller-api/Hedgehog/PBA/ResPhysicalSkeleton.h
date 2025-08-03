#pragma once
#include <ucsl/resources/pba/v1.h>

namespace hh::pba{
    struct RigidBody {
        csl::ut::VariableString boneName;
        ucsl::resources::pba::v1::RigidBody::Type type;
        ucsl::resources::pba::v1::RigidBody::Shape shape;
        uint8_t unk1;
        char group;
        float shapeRadius;
        float shapeHeight;
        float shapeDepth;
        float mass;
        float friction;
        float restitution;
        float linearDamping;
        float angularDamping;
        hh::fnd::WorldPosition offset;
    };

    struct Constraint {
        csl::ut::VariableString boneName;
        bool disableCollisionsBetweenLinkedBodies;
        char unk1;
        short overrideSolverIterationCount;
        short parentRigidBodyIndex;
        short childRigidBodyIndex;
        short skeletonParentBoneIndex;
        ucsl::resources::pba::v1::Limit angularLimits[3];
        ucsl::resources::pba::v1::Limit linearLimits[3];
        hh::fnd::WorldPosition offsetA;
        hh::fnd::WorldPosition offsetB;
    };

    struct Node {
        csl::ut::VariableString boneName;
        float mass;
        short rigidBodyIndex;
        bool isPinned;
        bool disableCollisionBetweenLinkedBodies;
        float influence;
        short downSiblingIndex;
        short upSiblingIndex;
        short backSiblingIndex;
        short forwardSiblingIndex;
        short leftSiblingIndex;
        short rightSiblingIndex;
    };

    struct SoftBody{
        csl::ut::VariableString name;
        csl::ut::MoveArray<Node> nodes;
        csl::ut::MoveArray<ucsl::resources::pba::v1::Link> links;
        float margin;
        float dampingCoeff;
        float dragCoeff;
        float liftCoeff;
        float dynamicFrictionCoeff;
        float poseMatchingCoeff;
        float rigidContactsHardness;
        float kineticContactsHardness;
        float softContactsHardness;
        float anchorsHardness;
        int positionSolverIterationCount;
        char unk0;
        char group;
    };

    class ResPhysicalSkeleton : public hh::fnd::ManagedResource {
    public:

        csl::ut::MoveArray<RigidBody> rigidbodies;
        csl::ut::MoveArray<Constraint> constraints;
        csl::ut::MoveArray<SoftBody> softbodies;
        csl::ut::MoveArray<short> unkArray3; // contains somekind of indices
        csl::ut::MoveArray<short> unkArray4; // contains somekind of indices
        csl::ut::MoveArray<short> unkArray5a; // contains somekind of indices

        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicalSkeleton)

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
    };
}