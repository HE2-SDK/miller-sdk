#pragma once

namespace hh::physics {
    class GOCCylinderCollider : public GOCCollider {
    public:
        float radius;
        float halfHeight;

		virtual void* GetRuntimeTypeInfo() override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCylinderCollider);
    };
}
