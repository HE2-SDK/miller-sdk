#pragma once

namespace hh::gfx {
    class ISkeletalMeshPose {
    public:
        virtual ~ISkeletalMeshPose() = default;
        virtual uint64_t ISMP_UnkFunc1() = 0;
        virtual uint64_t ISMP_UnkFunc2() = 0;
        virtual uint64_t ISMP_UnkFunc3() = 0;
        virtual uint64_t ISMP_UnkFunc4() = 0;
        virtual uint64_t ISMP_UnkFunc5() = 0;
    };
}
