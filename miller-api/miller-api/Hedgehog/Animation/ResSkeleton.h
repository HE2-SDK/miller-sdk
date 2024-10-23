#pragma once

namespace hh::anim {
    class ResSkeleton : public fnd::ManagedResource {
    public:
        virtual int GetNumBones() const = 0;
        virtual int GetBoneIndex(const char* name) const = 0;
        virtual const char* GetBoneName(int boneIndex) const = 0;
        virtual void SetBoneName(int boneIndex, const char* name) = 0;
        virtual int GetBoneGroup(int boneIndex) const = 0;
        virtual void SetBoneGroup(int boneIndex, int groupId) = 0;
        virtual csl::math::Transform GetBoneTransform(int boneIndex) const = 0;
        virtual void SetBoneTransform(int boneIndex, const csl::math::Transform& transform) = 0;
        virtual void MarkDescendants(int boneIndex, csl::ut::BitArray& marks) const = 0;
        virtual uint64_t UnkFunc15() = 0;
        virtual uint64_t UnkFunc16() = 0;
        virtual uint64_t UnkFunc17() = 0;
        virtual uint64_t UnkFunc18() = 0;
    };
}
