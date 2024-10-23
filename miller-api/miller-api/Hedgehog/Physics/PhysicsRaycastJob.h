#pragma once

namespace hh::physics {
    class PhysicsRaycastJob : public PhysicsQueryJob {
    public:
        csl::ut::InplaceMoveArray<PhysicsQueryResult, 1> results;
        uint64_t unk101;
        PhysicsQueryResult otherResults[2];

        PhysicsRaycastJob(csl::fnd::IAllocator* allocator);
    };
}
