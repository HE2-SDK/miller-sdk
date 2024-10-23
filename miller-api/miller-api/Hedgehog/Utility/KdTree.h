#pragma once

namespace hh::ut {
    class KdTreeNode : public fnd::ReferencedObject {
    public:
        enum class Type : unsigned int {
            SPLIT_X,
            SPLIT_Y,
            SPLIT_Z,
            LEAF,
        };

        Type type;
        csl::geom::Aabb aabb;

        // Empty space between left and right that contains nothing.
        float deadzoneStartCoord;
        float deadzoneEndCoord;

        fnd::Reference<KdTreeNode> left;
        fnd::Reference<KdTreeNode> right;

        // TODO: Find out how this is still valid when FxParamManager::LoadFxColResource frees the array of BvWorldHandles.
        csl::ut::MoveArray<BvWorldHandle*> handles;

        DEFAULT_CREATE_FUNC(KdTreeNode);
    };

    class ResKdTreeNodeData {
        float deadZoneStartCoordNodeTypeAndLeafIndex; // Type is in lower 2 bits for intermediate nodes, and deadzone start is in the other bits. For leaf nodes it's just the leaf index in the lower 2 bits.
        float deadZoneEndCoord;
    };

    class ResKdTreeLeafNodeData {
        int numObjects;
        int startObjectIndex;
    };

    class ResKdTreeData {
        int depth;
        int nodeCount;
        ResKdTreeNodeData* nodes;
        int leafCount;
        ResKdTreeLeafNodeData* leaves;
        int objectCount;
        unsigned int* objects;
    };

    class KdTree;

    class KdTreeUtil {
        static void build(const KdTreeNode* node, int offset, ResKdTreeNodeData* nodeData, int* nextLeafIndex);
        static void orderLeafNodesAndObjects(const KdTreeNode* node, ResKdTreeLeafNodeData** leafNodeData, unsigned int* objects, int* nextObjectIndex);
    public:
        static size_t CalcMemorySize(const KdTree& tree);
        static void BuildResource(const KdTree& tree, void* resource);
        static void QueryAabb(const ResKdTreeData* resource, const csl::geom::Aabb& aabb, csl::ut::MoveArray<unsigned int>& results);
    };

    class KdTreeBuilder {
        struct InternalObject {
            BvWorldHandle* bvWorldHandle;
            uint64_t unk1;
            csl::math::Vector3 volumeCenter;
        };

        struct InternalPlane {
            KdTreeNode::Type normalAxis;
            float coordinate;
        };

        csl::fnd::IAllocator* allocator;
        int maxLeafNodeObjects;

    public:
        struct BuildStatistics {
            int maxDepth;
            int totalNodes;
            int totalSplitNodes;
            int totalLeaves;
        };
    
    private:
        void CalcAabb(InternalObject* obj1, InternalObject* obj2, csl::geom::Aabb* aabb);
        void PartitionFunc(const InternalObject& obj, const InternalPlane& plane);
        unsigned int GetObjectSide(const InternalObject& obj, const InternalPlane& plane);
        bool GetBestSplitter(const csl::geom::Aabb& aabb, InternalObject* obj1, InternalObject* obj2, InternalPlane* splitterPlane);
        void Terminated(const csl::geom::Aabb& aabb, InternalObject* obj1, InternalObject* obj2);
        void makeLeafNode(KdTreeNode* node, InternalObject* obj1, InternalObject* obj2);
        KdTreeNode* BuildR(InternalObject* start, InternalObject* end, int depth, csl::fnd::IAllocator *, BuildStatistics& buildStatistics);
    public:
        KdTreeBuilder();
        void SetMaxLeafNodeObjects(int count);
        KdTree* Build(const BvWorld& bvWorld, csl::fnd::IAllocator* allocator);
    };

    class KdTree : public fnd::ReferencedObject {
    public:
        KdTreeBuilder::BuildStatistics buildStatistics;
        int volumeCount;
        KdTreeNode* rootNode;

        DEFAULT_CREATE_FUNC(KdTree);
    };
}
