#pragma once

namespace hh::anim {
    class ResSkeletonPxd : public ResSkeleton {
    public:
        uint64_t unk101;
        uint64_t unk102;
        csl::ut::MoveArray<void*> unk103;
        uint64_t unk104;
        csl::ut::PointerMap<void*, void*> unk105;
        uint64_t unk106;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual int GetNumBones() const override;
        virtual int GetBoneIndex(const char* name) const override;
        virtual const char* GetBoneName(int boneIndex) const override;
        virtual void SetBoneName(int boneIndex, const char* name) override;
        virtual int GetBoneGroup(int boneIndex) const override;
        virtual void SetBoneGroup(int boneIndex, int groupId) override;
        virtual csl::math::Transform GetBoneTransform(int boneIndex) const override;
        virtual void SetBoneTransform(int boneIndex, const csl::math::Transform& transform) override;
        virtual void MarkDescendants(int boneIndex, csl::ut::BitArray& marks) const override;
        virtual uint64_t UnkFunc15() override;
        virtual uint64_t UnkFunc16() override;
        virtual uint64_t UnkFunc17() override;
        virtual uint64_t UnkFunc18() override;
    };
}
