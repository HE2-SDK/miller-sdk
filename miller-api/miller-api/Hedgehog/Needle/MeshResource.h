#pragma once

#define NEEDLE_RESOURCE_MESH_RESOURCE 0x305345524853454Dui64 // '0SERHSEM'

namespace hh::needle {
    class MeshResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_MESH_RESOURCE, NeedleRefcountResource> {
    public:
        uint64_t qword18;
        uint64_t qword20;
        unsigned short* materialIndices;
        CNameIDObject** materialNames;
        MaterialResource** materialResources;
        uint64_t qword40;
        char pad48[32];
        MaterialResource** nodeMaterialResources;
        uint64_t qword70;
        uint64_t qword78;
        uint16_t nodeCount;
        uint16_t word82;
        uint16_t word84;
        uint16_t materialCount;
        uint16_t word88;
        uint16_t word8A;
        uint32_t dword8C;
        csl::math::Position aabbMin;
        csl::math::Position aabbMax;
        uint32_t dwordA8;

        static MeshResource* Create(GraphicsMemoryLayout* gfxMemLayout, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, unsigned int unkParam5, void* unkParam6);

        virtual NeedleRefcountObject* GetDependRefcountObject() override;
        virtual void SetDebugObjectName(char const* name) override;
        virtual NeedleSStr* GetNeedleSStr() override;

        void GetAABB(float_vector3 (*aabb)[2]);
        unsigned int GetLODCount() const;
        unsigned int GetLODID(unsigned int lodIndex) const;
        unsigned int GetScenePassIDCount(unsigned int lodIndex) const;
        unsigned int GetScenePassIDStartIndex(unsigned int lodIndex) const;
        void* GetScenePassID(unsigned int scenePassIDIndex) const;
        unsigned int GetMeshCount(unsigned int scenePassIDIndex) const;
        void* GetMeshDataArrayTop() const;
        unsigned int GetMeshDataIndex(unsigned int scenePassIDIndex, unsigned int meshDataIndex) const;
        unsigned int GetMaterialCount() const;
        unsigned short* GetMaterialIndexArrayTop() const;
        unsigned int GetMaterialIndex(unsigned int scenePassIDIndex, unsigned int meshIndex) const;
        CNameIDObject* GetMaterialNameID(unsigned int materialIndex) const;
        MaterialResource* GetMaterialResource(unsigned int materialIndex) const;
        unsigned int GetNodeCount() const;
        CNameIDObject* GetNodeNameID() const;
        const char* GetNodeName(unsigned int nodeIndex) const;
        MaterialResource* GetNodeMaterialResource(unsigned int nodeIndex) const;
        unsigned int GetParentNodeIndex(unsigned int nodeIndex) const;
    };
}
