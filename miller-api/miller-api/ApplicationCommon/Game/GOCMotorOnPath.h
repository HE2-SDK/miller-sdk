#pragma once

namespace app_cmn::game {
    class GOCMotorOnPath : public GOCMotor {
    public:
        struct SetupInfo : GOCMotor::SetupInfo {
            float speed;
            float waitTime;
            float phase;
            bool loop;
            bool isReverse;
            bool boolEE;
            bool boolEF;
            hh::fnd::Handle<hh::path::PathComponent> path;
        };

        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;

            Unk1();
        };

        SetupInfo setupInfo;
        Unk1 unkF8;
        uint32_t qword104;
        uint32_t qword108;
        csl::ut::MoveArray<void*> unk110;
        uint32_t dword130;
        uint8_t byte134;

        GOCMotorOnPath(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void InitTransform(csl::math::Transform& transform) override;
        virtual void UpdateSetEditor() override;
        virtual void InitConfig() override;
        virtual void UpdateTransform(float time, csl::math::Transform& transform) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMotorOnPath);
    };
}
