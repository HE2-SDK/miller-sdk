#pragma once

namespace hh::ut {
    bool IntersectionRay3Aabb(const csl::math::Vector3& from, const csl::math::Vector3& direction, float distance, const csl::geom::Aabb& aabb, float* entry, float* exit);

    class AabbTreeHandle {
        unsigned int handle;
    };
    //  {
    // public:
    //     AabbTreeHandle(csl::fnd::IAllocator* allocator);
    //     static AabbTreeHandle* Create(csl::fnd::IAllocator* allocator);
    // };

    class AabbTree : public fnd::ReferencedObject {
    public:
        struct Unk1 {
            csl::ut::MoveArray<AabbTreeHandle*> handles;
        };

        struct InternalNode {
        private:
            uint32_t itemCount; // sign bit is set if it is a leaf
        public:
            unsigned short* items;
            csl::geom::Aabb aabb;

            inline bool IsLeaf() const {
                return itemCount & 0x80000000;
            }

            inline bool GetItemCount() const {
                return itemCount & (~0x80000000);
            }
        };

        struct InternalPlane {

        };

        enum class Flag : uint8_t {
            REBUILD_REQUIRED,
            OBJECT_ADDED,
        };

        volatile LONG spinLock;
        Flag flags;
        uint32_t maxDepth;
        uint32_t maxLeafObjects;
        Unk1 handles;
        csl::ut::MoveArray<csl::geom::Aabb> aabbs;
        csl::ut::MoveArray<csl::math::Vector3> aabbCenters;
        csl::ut::MoveArray<InternalNode> nodes; // root node is at index 1
        csl::ut::MoveArray<unsigned short> objectIndices;

    private:
        void BuildR(const csl::geom::Aabb& aabb, unsigned short* start, unsigned short* end, int depth, unsigned int offset);
        void GetBestSplitter(const csl::geom::Aabb& aabb, unsigned short* start, unsigned short* end, InternalPlane* plane);
        
    public:
        AabbTree(csl::fnd::IAllocator* allocator, int capacity, int maxDepth); // maxDepth does not include the leaf nodes
        static AabbTree* Create(csl::fnd::IAllocator* allocator, int capacity, int maxDepth);
        void AddObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        void UpdateObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        void AddOrUpdateObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        bool IsObjectInTree(hh::ut::AabbTreeHandle* handle);
        void RemoveObject(hh::ut::AabbTreeHandle* handle);
        bool GetAabb(csl::geom::Aabb* aabb);
        void GetAllAabbs(csl::ut::MoveArray<csl::geom::Aabb>* aabbs) const;
        bool Raycast(const csl::math::Vector3& from, const csl::math::Vector3& to, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryPoint(const csl::math::Vector3& point, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryAabb(const csl::geom::Aabb& aabb, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryAabbBruteForce(const csl::geom::Aabb& aabb, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void Build();
        void Verify();
        bool IsRebuildRequired();

        inline void Lock() {
            InterlockedBitTestAndSet(&spinLock, 0);
        }
        
        inline void Unlock() {
            spinLock = 0;
        }
    };
}
