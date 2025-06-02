#pragma once

namespace hh::pba{
    class PhysicalSkeletonBinding : public hh::fnd::ReferencedObject{
    public:
        hh::anim::ResSkeleton* targetSkeletonRes;
        hh::pba::ResPhysicalSkeleton* physicalSkeletonRes;
        csl::ut::MoveArray<void*> unkArray0; //maybe handles
        csl::ut::MoveArray<void*> unkArray1;

        PhysicalSkeletonBinding(csl::fnd::IAllocator* allocator, int64_t a3, int64_t a4);
    };
}