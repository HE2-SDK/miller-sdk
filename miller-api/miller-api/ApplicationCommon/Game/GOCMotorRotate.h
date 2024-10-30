#pragma once

namespace app_cmn::game {
    class GOCMotorRotate : public GOCMotor {
    public:
        struct SetupInfo : GOCMotor::SetupInfo {
            csl::math::Vector3 axis{ 1.0f, 0.0f, 0.0f };
            float speed{ 0.1f };
            float unk1{ 0.0f };
            float cycle{ 0.0f };
            float unk2{ 0.0f };
            uint64_t unk6{};
        };

        SetupInfo setupInfo;
        uint8_t byte110;

        GOCMotorRotate(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateSetEditor() override;
        virtual void InitConfig() override;
        virtual void UpdateTransform(float time, csl::math::Transform& transform) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMotorRotate);
    };
}
