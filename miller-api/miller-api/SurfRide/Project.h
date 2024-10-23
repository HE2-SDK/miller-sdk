#pragma once

namespace SurfRide
{
    struct SRS_PROJECT
    {
        const char* name{};
        unsigned short sceneCount{};
        unsigned short unk1{};
        unsigned short textureListCount{};
        unsigned short fontCount{};
        SRS_SCENE* scenes{};
        SRS_TEXTURELIST* textureLists{}; // SRS_TEXTURELIST
        SRS_FONT* fonts{}; // SRS_FONT
        SRS_CAMERA camera{};
        int startFrame{};
        int endFrame{};
        float frameRate{};
        void* userData{};
    };

    class BinaryData;
    class Project : public ReferencedObject
    {
        void LoadTextureListChunk(void* data, BinaryData& binaryData);
        void LoadProjectChunk(void* data, BinaryData& binaryData, bool cloneBinaryData);
    public:
        Camera camera;
        SRS_PROJECT* projectData;
        uint32_t unk1;
        TextureList** textureLists;
        uint32_t textureListCount;
        Scene** scenes;
        uint32_t sceneCount;
        BinaryData* binaryData;
        void* binaryDataData;

        Project();
        static Project* Create(const BinaryData& binaryData, bool cloneBinaryData);
        SRS_CAMERA* GetCameraData();
        Scene* GetScene(const char* name);
        void ApplyMemoryImageToTextureList(void* image, BinaryData* binaryData);
        void ApplyMemoryImageToProject(void* image, BinaryData* binaryData, bool unkParam);

#ifndef EXPORTING_TYPES
        inline CountedCollection<Scene*> GetScenes() const {
            return { scenes, sceneCount };
        }
#endif
    };

	struct ProjectIterator {
		SRS_PROJECT* project;

		SceneCollection GetScenes() const;
	};
}
