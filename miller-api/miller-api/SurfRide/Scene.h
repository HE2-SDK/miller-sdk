#pragma once

namespace SurfRide
{
	class Project;
	class Scene : public ReferencedObject
	{
	public:
		enum class Flag : unsigned int {
			HIDE,
		};

		SRS_SCENE* sceneData;
		Project* project;
		Camera camera;
		csl::ut::MoveArray<Layer*> layers;
		uint32_t unk1;
		csl::ut::Bitset<Flag> flags;

		Scene(csl::fnd::IAllocator* allocator, const SRS_SCENE& sceneData, Project* project);

		Layer* GetLayer(const char* layers);
		Layer* GetLayer(unsigned int id);
		Vector2 GetResolution() const;
		Vector2 ToScreenCoordinates(const Vector2& coords) const;
		void SetHideFlag(bool enabled);
		bool Hides() const;
		

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
