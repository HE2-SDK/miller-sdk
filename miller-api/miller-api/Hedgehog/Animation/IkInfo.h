#pragma once

namespace hh::anim {
    class IkInfoBase : public fnd::ReferencedObject {
    public:
        virtual void* GetRuntimeTypeInfo() const;
        virtual void UnkFunc1(void* unkParam1) {}
    };

    class FootIkInfo : public IkInfoBase {
    public:
        struct FootDef {
            csl::math::Vector3 csl__math__vector30;
            csl::math::Vector3 csl__math__vector310;
            uint64_t qword20;
            float dword28;
            float dword2C;
            float qword30;
            float qword34;
            short thighBoneIndex;
            short calfBoneIndex;
            short footBoneIndex;
            short toeBoneIndex;
            float dword40;
            float dword44;
            float dword48;
            float dword4C;
            float dword50;
            float dword54;
            float dword58;
            uint64_t qword60;
            uint64_t qword68;
            uint64_t qword70;
            uint64_t qword78;

            FootDef();
        };

        uint8_t byte18;
        csl::ut::InplaceMoveArray<FootDef, 2> feet;
        uint64_t qword140;
        uint32_t dword148;
        float qword14C;
        uint32_t qword150;
        uint32_t dword154;
        uint8_t byte158;

        DEFAULT_CREATE_FUNC(FootIkInfo);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc1(void* unkParam1) override;
    };

    class LookAtIkInfo : public IkInfoBase {
    public:
        uint8_t byte18;
        csl::math::Vector3 csl__math__vector320;
        csl::math::Vector3 csl__math__vector330;
        csl::math::Vector3 csl__math__vector340;
        uint64_t qword50;
        uint64_t qword58;
        uint32_t qword60;
        float maxLookUpAngle; // this + 3 below are speculative
        float maxLookDownAngle;
        float maxLookLeftAngle;
        float maxLookRightAngle;
        short headBoneIndex;
        short neckBoneIndex;
        bool bool78;
        uint8_t byte79;
        csl::math::Vector3 csl__math__vector380;
        csl::math::Vector3 csl__math__vector390;
        uint64_t qwordA0;
        uint64_t qwordA8;
        csl::ut::MoveArray<void*> unkB0;

        DEFAULT_CREATE_FUNC(LookAtIkInfo);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc1(void* unkParam1) override;

        void SetLookAt(ResSkeleton* skeleton, const csl::math::Vector3& target, const csl::math::Vector3& up);
    };

    class HandIkInfo : public IkInfoBase {
    public:
        struct HandDef {
            csl::math::Vector3 csl__math__vector30;
            csl::math::Vector3 csl__math__vector310;
            csl::math::Vector3 csl__math__vector320;
            uint64_t qword30;
            short armBoneIndex;
            short underArmBoneIndex;
            short handBoneIndex;
            short fingerBoneIndex;
            uint16_t word3C;
            uint8_t byte3E;
            uint64_t qword40;
            uint64_t qword48;
            uint64_t qword50;

            HandDef();
        };

        uint8_t byte18;
        csl::ut::InplaceMoveArray<HandDef, 2> hands;

        DEFAULT_CREATE_FUNC(HandIkInfo);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc1(void* unkParam1) override;
    };

    class CharacterIkInfo : public fnd::ReferencedObject {
    public:
        hh::fnd::Reference<HandIkInfo> handIkInfo;
        hh::fnd::Reference<FootIkInfo> footIkInfo;
        hh::fnd::Reference<LookAtIkInfo> lookAtIkInfo;

        DEFAULT_CREATE_FUNC(CharacterIkInfo);
    };
}
