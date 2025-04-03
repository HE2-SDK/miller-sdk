#pragma once

namespace hh::game {
    class GOCTransform;
}

namespace hh::fnd {
    // class HFrame : public ReferencedObject {
    // public:
    //     uint64_t unk1;
    //     uint64_t unk2;
    //     uint64_t unk3;
    //     uint64_t unk4;
    //     uint64_t unk5;
    //     uint16_t unk6;
    //     uint64_t unk8;
    //     int unk7;
    //     void* unk9;
    //     void* unk10;
    //     csl::ut::InplaceMoveArray<void*, 10> unk11;
    //     csl::math::Vector4 unk12;
    //     csl::math::Vector4 unk13;
    //     csl::math::Vector4 unk14;
    //     csl::math::Vector4 unk15;
    //     csl::math::Vector4 unk16;
    //     csl::math::Vector4 unk17;
    //     HFrame(csl::fnd::IAllocator* allocator);
    // };
    class HFrame;

    class HFrameListener {
    public:
        virtual ~HFrameListener() = default;
        virtual void HFrameUpdatedCallback(const HFrame* frame, bool unkParam) {}
    };

    class HFrame : public ReferencedObject {
    public:
        class Listener {
        public:
            virtual ~Listener() = default;
            virtual void HFrameUpdatedCallback(const HFrame* frame, bool unkParam) {}
        };

        enum Flag : unsigned short {
            DIRTY = (1 << 0),
            CHILD_DIRTY = (1 << 1),
            UPDATE = (1 << 2),
            CHILD_UPDATE = (1 << 3),
            TRANSFORM_POSITION = (1 << 4),
            TRANSFORM_ROTATION = (1 << 5),
            GOC_DIRTY = (1 << 6), // unsure
            NEEDS_UPDATE = (1 << 7),
            CHILD_NEEDS_UPDATE = (1 << 8), // unsure. see AddChild, need to know what unk5 is first
        };

    private:
        csl::ut::LinkListNode linkListNode;

    public:
        HFrame* parent;
        HFrame* hierarchyRoot;
        hh::game::GOCTransform* gocTransform;
        Flag flags;
        csl::ut::LinkList<HFrame> children;//{ offsetof(HFrame, linkListNode) };
        csl::ut::InplaceMoveArray<Listener*, 10> listeners;
        csl::math::Transform fullTransform;
        csl::math::Transform localTransform;
        HFrame(csl::fnd::IAllocator* allocator);
    
        void AddChild(HFrame* child);
        void RemoveChild(HFrame* child);
        void AddListener(Listener* child);
        void RemoveListener(Listener* child);
        void SetHierarchyRoot(HFrame* frame);
        void SetLocalTransform(const csl::math::Transform& transform);
        void SetLocalTranslation(const csl::math::Vector3& position);
        void SetLocalRotation(const csl::math::Quaternion& rotation);
        void SetLocalTranslationAndRotation(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
        void MarkDirty();
        void MarkUpdate();
        bool IsChildDirtyOrUpdate();
        void NotifyUpdate(bool unkParam);
        void ResetFlag(Flag flag);
        void SetFlag(Flag flag);
        void SetFlag(Flag flag, bool enabled);

        // The boolean here is `isDirty`
        // I'm pretty sure this pair is actually `ListenerInfo`
        void Sync(csl::ut::MoveArray<csl::ut::Pair<hh::fnd::HFrame*, bool>>& updatedFrames, bool ifRequested);
        void SyncRecursive(csl::ut::MoveArray<csl::ut::Pair<hh::fnd::HFrame*, bool>>& updatedFrames, Flag propagatingFlags, csl::math::Transform* targetTransform);

        virtual void* GetRuntimeTypeInfo() const;
        virtual void OnSync(const csl::math::Transform& parentTransform, csl::math::Transform* targetTransform);

        static csl::math::Transform CalculateTransform(const csl::math::Transform& parent, const csl::math::Transform& child, bool transformPosition, bool transformRotation);
    };
}
