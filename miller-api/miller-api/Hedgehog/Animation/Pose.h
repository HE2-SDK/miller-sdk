#pragma once

namespace hh::anim {
    class Pose : public fnd::ReferencedObject, public gfx::ISkeletalMeshPose {
    public:
        fnd::Reference<ResSkeleton> resource;

        CREATE_FUNC(Pose, ResSkeleton* resource);

        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
    };

    class PosePxd : public Pose {
    public:
        struct Unk1 {
            fnd::Reference<ResSkeletonPxd> resource;
            csl::ut::MoveArray<void*> unk1;
            csl::ut::MoveArray<csl::math::Transform> transforms;
            uint64_t qword48;
            uint64_t qword50;
            uint64_t qword58;
            uint64_t qword60;
            uint64_t qword68;
            uint8_t gap70[32];
            uint64_t qword90;
            uint64_t qword98;
            uint64_t qwordA0;
            uint64_t qwordA8;
            uint64_t qwordB0;
            uint8_t gapB8[32];
            uint16_t wordD8;

            Unk1(csl::fnd::IAllocator* allocator, ResSkeletonPxd* resource);
        };

        Unk1 unk1;

        static PosePxd* Create(ResSkeletonPxd* resource, csl::fnd::IAllocator* allocator);
        
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t ISMP_UnkFunc1() override;
        virtual uint64_t ISMP_UnkFunc2() override;
        virtual uint64_t ISMP_UnkFunc3() override;
        virtual uint64_t ISMP_UnkFunc4() override;
        virtual uint64_t ISMP_UnkFunc5() override;
    };
}
