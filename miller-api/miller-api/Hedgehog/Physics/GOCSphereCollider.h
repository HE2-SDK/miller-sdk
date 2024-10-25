#pragma once

#pragma once

namespace hh::physics {
    class GOCSphereCollider : public GOCCollider {
    public:
        struct SetupInfo : public GOCCollider::SetupInfo {
            float radius{};
            uint8_t unk1{};

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::SPHERE) {}
        };

        float radius;
		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCSphereCollider);
    };
}
