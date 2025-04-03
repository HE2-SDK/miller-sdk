#pragma once

namespace hh::physics {
    class GOCCylinderCollider : public GOCCollider {
    public:
        struct SetupInfo : GOCCollider::SetupInfo {
            float radius{};
            float halfHeight{};

            SetupInfo() : GOCCollider::SetupInfo{ ColliShape::Type::CYLINDER } {}
        };

        float radius{};
        float halfHeight{};

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCylinderCollider);
    };
}
