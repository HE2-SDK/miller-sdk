#pragma once

namespace SurfRide
{
	struct SRS_SCENE
	{
		const char* name{};
		int id{};
		int flags{};
		bool loaded{};
		int layerCount{};
		SRS_LAYER* layers{};
		unsigned short cameraCount;
		unsigned short currentCameraIndex{};
		SRS_CAMERA* cameras{};
		int backgroundColor{};
		csl::math::Vector2 resolution{};
		SRS_USERDATA* userData{};
	};

	class Project;
	class Scene : public ReferencedObject
	{
	public:
		SRS_SCENE* sceneData;
		Project* project;
		Camera camera;
		csl::ut::MoveArray<Layer*> layers;
		uint32_t unk1;
		uint32_t flags;

		Scene(const SRS_SCENE& sceneData, Project* project);

		Layer* GetLayer(const char* layers);
		

        inline csl::ut::MoveArray<SurfRide::Layer*>& GetLayers() {
            return layers;
        }
	};

	struct SceneCollection {
		SRS_SCENE* current;
		SRS_SCENE* end;
	};

	struct SceneIterator {
		SRS_SCENE* scene;

		void Next();
		LayerCollection GetLayers() const;
	};
}
