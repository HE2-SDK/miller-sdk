#pragma once

namespace hh::physics {
    class GOCBoxCollider : public GOCCollider {
    public:
        csl::math::Vector3 dimensions;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCBoxCollider);
    };
}
