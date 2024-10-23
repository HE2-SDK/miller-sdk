#pragma once

namespace hh::physics {
    class PhysicsQueryJob : public fnd::ReferencedObject {
    public:
        uint16_t unk1;

        PhysicsQueryJob(csl::fnd::IAllocator* allocator);
    };
}
