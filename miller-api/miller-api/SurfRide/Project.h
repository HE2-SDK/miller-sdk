#pragma once

namespace SurfRide
{
    class BinaryData;
    class Project : public ReferencedObject
    {
        void LoadTextureListChunk(void* data, BinaryData& binaryData);
        void LoadProjectChunk(void* data, BinaryData& binaryData, bool cloneBinaryData);
    public:
        SRS_PROJECT* projectData;
        TextureList** textureLists;
        uint32_t textureListCount;
        csl::ut::MoveArray<SurfRide::Scene*> scenes;
        BinaryData* binaryData;
        void* binaryDataData;

        Project();
        static Project* Create(const BinaryData& binaryData, bool cloneBinaryData);
        SRS_CAMERA* GetCameraData();
        Scene* GetScene(const char* name);
        void ApplyMemoryImageToTextureList(void* image, BinaryData* binaryData);
        void ApplyMemoryImageToProject(void* image, BinaryData* binaryData, bool unkParam);

        inline csl::ut::MoveArray<SurfRide::Scene*> GetScenes() const {
            return scenes;
        }
    };

	struct ProjectIterator {
		SRS_PROJECT* project;

		SceneCollection GetScenes() const;
	};
}
