#pragma once

namespace hh::physics {
    class GOCMeshCollider : public GOCCollider {
    public:
        struct SetupInfo : public GOCCollider::SetupInfo {
            hh::fnd::ReferencedObject* meshResource;

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::SPHERE) {}
        };

        fnd::Reference<hh::fnd::ReferencedObject> meshResource;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMeshCollider);
    };
}
