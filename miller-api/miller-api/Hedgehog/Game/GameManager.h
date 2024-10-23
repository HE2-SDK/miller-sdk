#pragma once

namespace hh::game
{
    struct GameStepInfo {
        uint32_t layerUpdateMask;
        fnd::SUpdateInfo updateInfo;
    };

	class alignas(8) GameStepListener
	{
	public:
		virtual ~GameStepListener() = default;
		virtual void PreStepCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) {}
		virtual void PostStepCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) {}
		virtual void UpdateCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) {}
	};
	
    class alignas(8) GamePauseListener {
	public:
		virtual ~GamePauseListener() = default;
        virtual void GPL_UnkFunc1() {}
        virtual void GPL_UnkFunc2() {}
    };

	class alignas(8) GameUpdateListener
	{
	public:
		virtual ~GameUpdateListener() = default;
		virtual void PreGameUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
		virtual void PostGameUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
	};
    
	class alignas(8) ObjectUpdateListener
	{
	public:
		virtual ~ObjectUpdateListener() = default;
		virtual void PreObjectUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
		virtual void PostObjectUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) {}
	};

	class alignas(8) ComponentListener
	{
	public:
		virtual ~ComponentListener() = default;
		virtual void ComponentAddedCallback(GOComponent* component) {}
		virtual void ComponentRemovedCallback(GOComponent* component) {}
	};

	class alignas(8) GameManagerListener
	{
	public:
		virtual ~GameManagerListener() = default;
		virtual void GameObjectAddedCallback(GameManager* gameManager, GameObject* gameObject) {}
		virtual void GameObjectRemovedCallback(GameManager* gameManager, GameObject* gameObject) {}
		virtual void GameServiceAddedCallback(GameService* gameService) {}
		virtual void GameServiceRemovedCallback(GameService* gameService) {}
		virtual void MessageProcessedCallback(GameManager* gameManager, const fnd::Message& msg) {}
		virtual void PreShutdownObjectCallback(GameManager* gameManager) {}
		virtual void PostShutdownObjectCallback(GameManager* gameManager) {}
		virtual void GML_UnkFunc8() {}
	};

	class EditorStepListener {
	public:
		virtual ~EditorStepListener() = default;
		virtual void ESL_UnkFunc1() {}
	};

	class GameManager;

	struct GameManagerOperation {
		enum class OperationId : uint8_t {
			SET_OBJECT_LAYER = 1,
			MAYBE_RELEASE_OBJECT = 4,
		};

		OperationId id;
		GameObject* gameObject;
		uint32_t layerId; // could be variable based on operation id, don't know yet
		uint32_t unk1;
		uint64_t unk2;
		uint64_t unk3; // unsure, just based off of array stride
	};
	class GameManagerOperationQueue : public fnd::ReferencedObject {
		GameManager* pGameManager;
		csl::ut::MoveArray<void*> unk1;
		csl::ut::MoveArray<GameManagerOperation> pendingOperations; // or maybe specifically layer operations
		fnd::MessageQueue messageQueue;
		csl::fnd::Mutex mutex;
	public:
		GameManagerOperationQueue(csl::fnd::IAllocator* pAllocator, GameManager* pGameManager);
		void ExecuteAllPendingLayerOperations();
	};

	class GameManagerCallbackUtil {
		friend class GameManager;
		static void FirePreShutdownObject(GameManager* gameManager);
		static void FirePostShutdownObject(GameManager* gameManager);
		static void FireGameObjectAdded(GameManager* gameManager, GameObject* gameObject);
		static void FireGameObjectRemoved(GameManager* gameManager, GameObject* gameObject);
		static void FireComponentAdded(GameManager* gameManager, GOComponent* component);
		static void FireComponentRemoved(GameManager* gameManager, GOComponent* component);
		static void FireObjectLayerSet(GameManager* gameManager, GameObject* gameObject);
		static void FireObjectAddedToLayer(GameManager* gameManager, GameObject* gameObject, int layer);
		static void FireObjectRemovedFromLayer(GameManager* gameManager, GameObject* gameObject, int layer);
		static void FireMessageProcessed(GameManager* gameManager, const fnd::Message& message);
        static void FirePreGameUpdate(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
        static void FirePostGameUpdate(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
		static void FirePreObjectUpdate(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
		static void FirePostObjectUpdate(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo);
		static void FirePreStep(GameManager* gameManager, const game::GameStepInfo& gameStepInfo);
		static void FirePostStep(GameManager* gameManager, const game::GameStepInfo& gameStepInfo);
		static void FireUpdate(GameManager* gameManager, const game::GameStepInfo& gameStepInfo);
	};

	class GameApplication;

	struct WorldObjectCInfo;

	class GameManager : public fnd::ReferencedObject, public fnd::ReloaderListener, private csl::ut::NonCopyable
	{
		GameService* CreateService(const GameServiceClass* gameServiceClass, csl::fnd::IAllocator* residentAllocator);
		static bool DispatchFunc(const fnd::Message& message, void* userData);
		void RiseMessageProcessed(const fnd::Message& message);
	public:
		uint32_t unk33;
		uint32_t unk34;
		float globalTime;
		uint32_t unk36;
		GameObjectLayer* gameObjectLayers[32]{};
		csl::ut::MoveArray<GameObject*> objects{ pAllocator };
		csl::ut::MoveArray<GameService*> services{ pAllocator };
		csl::ut::PointerMap<GameServiceClass*, GameService*> servicesByClass{ pAllocator };
		csl::ut::MoveArray<GameObject*> shutdownObjects;
		csl::ut::MoveArray<GameManagerListener*> managerListeners{ pAllocator };
		// not sure if this is a layer listener or a gameobject listener, but 0x20 is called when object added to layer
		csl::ut::MoveArray<GameObjectListener*> gameObjectListeners;
		csl::ut::MoveArray<ComponentListener*> componentListeners;
		csl::ut::MoveArray<void*> unk44;
		csl::ut::MoveArray<ObjectUpdateListener*> objectUpdateListeners{ pAllocator };
		csl::ut::MoveArray<GamePauseListener*> gamePauseListeners{ pAllocator };
		csl::ut::MoveArray<GameStepListener*> gameStepListeners{ pAllocator };
		csl::ut::MoveArray<GameUpdateListener*> gameUpdateListeners{ pAllocator };
		csl::ut::MoveArray<EditorStepListener*> editorStepListeners{ pAllocator };
		uint32_t unk50; // See GameManagerCallbackUtil::FirePostShutdownObject
		uint32_t unk50b;
		uint32_t unk51;
		csl::ut::MoveArray<void*> unk52;
		fnd::MessageQueue messageQueue;
		GameManagerOperationQueue* pOperationQueue;
		uint32_t unk55;
		GameApplication* pApplication;

		GameManager(csl::fnd::IAllocator* pAllocator, GameApplication* pApplication);
		virtual void PreResourceReloadCallback(fnd::ManagedResource* resource) override;
		virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;

		static GameManager* instance;
		static GameManager* GetInstance();

		//template <typename T>
		//T* GetService()
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, T::GetServiceName()) == 0)
		//			return reinterpret_cast<T*>(pService);
		//	}
		//
		//	return { nullptr };
		//}

		//GameService* GetService(const char* in_pServiceName)
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, in_pServiceName) == 0)
		//			return pService;
		//	}

		//	return { nullptr };
		//}

		// template <typename T>
		// T* GetGameObject()
		// {
		// 	for (auto* pObject : m_Objects)
		// 	{
		// 		if (pObject == nullptr)
		// 			continue;

		// 		if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
		// 			return reinterpret_cast<T*>(pObject);
		// 	}

		// 	return { nullptr };
		// }

		GameService* GetService(const GameServiceClass* gameServiceClass);

		template<typename T>
		T* GetService() {
			return static_cast<T*>(GetService(T::GetClass()));
		}

		GameObject* GetGameObject(const char* in_pObjectName)
		{
			for (auto* pObject : objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->name, in_pObjectName) == 0)
					return pObject;
			}

			return { nullptr };
		}

		template<typename T>
		T* CreateService(csl::fnd::IAllocator* residentAllocator) {
			return static_cast<T*>(CreateService(T::GetClass(), residentAllocator));
		}

		csl::ut::MoveArray<GameService*>& GetServices() {
			return services;
		}

		inline GameApplication* GetApplication() const {
			return pApplication;
		}

		void RegisterService(GameService* service);
		void UnregisterService(GameService* service);
		void AddGameObject(GameObject* object, fnd::WorldPosition* transform, GameObject* parent, const WorldObjectCInfo& cInfo);
		void AddGameObject(GameObject* object, const char* name, bool copyName, fnd::WorldPosition* transform, GameObject* parent);
		inline void RemoveGameObject(GameObject* object) {
			gameObjectLayers[object->layer]->RemoveObject(object);
			GameManagerCallbackUtil::FireGameObjectRemoved(this, object);
		}
		void RegisterGameStepListener(GameStepListener& listener);
		void UnregisterGameStepListener(GameStepListener& listener);
		void RegisterGamePauseListener(GamePauseListener& listener);
		void UnregisterGamePauseListener(GamePauseListener& listener);
		void AddListener(GameManagerListener* listener);
		void RemoveListener(GameManagerListener* listener);
		void AddGameObjectListener(GameObjectListener* listener);
		void RemoveGameObjectListener(GameObjectListener* listener);
		void AddEditorStepListener(EditorStepListener* listener);
		void RemoveEditorStepListener(EditorStepListener* listener);
		void ReloadInputSettings(bool unkParam1);
		void ShutdownPendingObjects();
		void ClearAllGameObjects();
		fnd::MessageAsyncHandler* SendMessage(fnd::Message& message);
		void SendMessageImm(fnd::Message& message);
		void SendMessageImmToLayer(int layer, fnd::Message& message);
		void SendMessageImmToService(fnd::Message& message);
		void SetObjectLayer(GameObject* gameObject, int layerId);
		void PerformMessages();
		void UpdateGlobalTime(const fnd::SUpdateInfo& updateInfo);
		void GetViewportData(int viewportId);
		bool IsWorldFlagSet(int index, int type);
	};
}
