#pragma once

namespace hh::game {
	class CameraManagerListener {
	public:
		virtual ~CameraManagerListener() = default;
	};

	class InternalCameraStack : public fnd::ReferencedObject {
		int id;
		csl::ut::MoveArray<CameraComponent*> components;
		volatile uint32_t spinlock;
	public:
		InternalCameraStack(csl::fnd::IAllocator* allocator);
	};

	class CameraManager : public GameService {
		csl::ut::MoveArray<CameraComponent*> components;
		csl::ut::MoveArray<InternalCameraStack*> cameraStacks;
		csl::ut::InplaceMoveArray<CameraManagerListener*, 1> listeners;
		bool cameraStackEnabledFlags;

	public:
		void AddComponent(CameraComponent* component);
		void RemoveComponent(CameraComponent* component);

		CameraComponent* GetTopComponent(int viewportId);
		void GetComponents(int viewportId, csl::ut::MoveArray<CameraComponent*>& components);
		void AddComponentToStack(CameraComponent* component);
		void RemoveComponentFromStack(CameraComponent* component);

		void SetComponentLookAtPos(CameraComponent* component, const csl::math::Vector3& lookAtPos);
		void SetComponentViewMatrix(CameraComponent* component, csl::math::Matrix44& viewMatrix);
		void SetComponentPerspectiveProjectionMatrix(CameraComponent* component, float fov, float aspectRatio, float nearClip, float farClip);

		void AddListener(CameraManagerListener* listener);
		void RemoveListener(CameraManagerListener* listener);

		inline size_t GetCameraCount() {
			return cameraStacks.size();
		}

		inline csl::ut::MoveArray<CameraComponent*>& GetComponents() {
			return components;
		}

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		
		GAMESERVICE_CLASS_DECLARATION(CameraManager)
	};
}
