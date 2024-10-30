#pragma once

namespace app_cmn::game {
    class GOCMotorConstant : public GOCMotor {
    public:
        struct SetupInfo : GOCMotor::SetupInfo {
            csl::math::Vector3 direction{ 1.0f, 0.0f, 0.0f };
            float distance{ 50.0f };
            float travelTime{ 1.0f };
            float travelWaitTime{ 0.5f };
            float returnTime{ 0.5f };
            float returnWaitTime{ 0.5f };
            float unk5{};
            uint64_t unk6{};
        };

        SetupInfo setupInfo;
        float travelTimeReciprocal;
        float waitTimeReciprocal;
        int unk212;

        GOCMotorConstant(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateSetEditor() override;
        virtual void InitConfig() override;
        virtual void UpdateTransform(float time, csl::math::Transform& transform) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMotorConstant);
    };
}
