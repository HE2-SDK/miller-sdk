#pragma once

#define GAMEOBJECT_CLASS_DECLARATION_BASE(ClassName) private:\
		static const hh::game::GameObjectClass gameObjectClass;\
		static hh::game::GameObject* Create(csl::fnd::IAllocator* allocator);\
		ClassName(csl::fnd::IAllocator* allocator);

#define GAMEOBJECT_CLASS_DECLARATION(ClassName) GAMEOBJECT_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static const hh::game::GameObjectClass* GetClass();

#define GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ClassName) GAMEOBJECT_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static inline const hh::game::GameObjectClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(gameObjectClass);\
		}

namespace hh::ui {
	class LayerController;
}

namespace hh::game
{
	class GameManager;
	class GameObject;
	class GOComponent;
	class GOComponentClass;

	class GameObjectListener {
	public:
		virtual ~GameObjectListener() = default;
		virtual void ComponentAddedCallback(GameObject* gameObject, GOComponent* component) {}
		virtual void ComponentRemovedCallback(GameObject* gameObject, GOComponent* component) {}
		virtual void ObjectLayerSetCallback(GameObject* gameObject) {}
		virtual void ObjectAddedToLayerCallback(GameObject* gameObject, int layer) {}
		virtual void ObjectRemovedFromLayerCallback(GameObject* gameObject, int layer) {}
	};

	class GameObjectCallbackUtil {
		static void FireComponentAdded(GameObject* gameObject, GOComponent* component);
		static void FireComponentRemoved(GameObject* gameObject, GOComponent* component);
		static void FireObjectLayerSet(GameObject* gameObject);
		static void FireObjectAddedToLayer(GameObject* gameObject, int layer);
		static void FireObjectRemovedFromLayer(GameObject* gameObject, int layer);
	};

	class GameObjectClass {
	public:
		typedef GameObject* CreateFunction(csl::fnd::IAllocator* allocator);

		const char* name{};
		const char* scopedName{};
		uint64_t unk12{};
		size_t objectSize{};
		CreateFunction* instantiator{};
		uint64_t unk15{};
		uint64_t unk16{};
		uint64_t unk17{};
		uint32_t attributeCount{};
		const hh::fnd::RflClassMember::Value* attributes{};
		const hh::fnd::RflClass* spawnerDataRflClass{};
	private:
		GameObject* Create(csl::fnd::IAllocator* pAllocator) const;
	public:
		GameObjectClass() {}
		GameObjectClass(const char* name, const char* scopedName, size_t objectSize, GameObject* (*instantiator)(csl::fnd::IAllocator* allocator), uint32_t attributeCount, const hh::fnd::RflClassMember::Value* attributes, const hh::fnd::RflClass* spawnerDataRflClass)
			: name{ name }, scopedName{ scopedName }, objectSize{ objectSize }, instantiator{ instantiator }, attributeCount{ attributeCount }, attributes{ attributes }, spawnerDataRflClass{ spawnerDataRflClass } {}
		template<typename T>
		T* Create(csl::fnd::IAllocator* pAllocator) const { return static_cast<T*>(Create(pAllocator)); }
		const fnd::RflClassMember::Value* GetAttribute(const char* name) const;
		const void* GetAttributeValue(const char* name) const;
    };

	class WorldObjectStatus;
	class GameObject : public fnd::Messenger
	{
		class Unk1 {
			GameObject* pGameObject;
			csl::ut::MoveArray<GOComponent*> componentsToAdd;
		};

		struct Unk2 {
			int64_t unk31;
			int64_t unk32;
			int64_t unk33;
			int64_t unk34;
		};

	public:
		enum class StatusFlags : char {
			KILLED,
			ASLEEP,
			EDITOR = 2,
			UNK4 = 4,
		};

		csl::ut::Bitset<StatusFlags> statusFlags;
		char layer{ 6 };
		csl::ut::Bitset<fnd::UpdatingPhase, uint8_t> forcedUpdateFlags;
		csl::ut::Bitset<fnd::UpdatingPhase, uint8_t> updateFlags;
		char unk48;
		uint32_t componentsLengthWithUnk48InHiWordByUpdatingPhase[3];
		GameManager* gameManager{};

		uint32_t numComponentsCurrentlyBeingAdded;
		uint32_t nextComponentIndex;
		//??GameObjectClass* pStaticClass{};

		GameObject(csl::fnd::IAllocator* allocator);
		csl::ut::InplaceMoveArray<GOComponent*, 8> components;
		csl::ut::VariableString name;

		csl::ut::InplaceMoveArray<hh::fnd::Property, 2> properties;
		csl::ut::MoveArray<GameObjectListener*> listeners;
		uint32_t componentsMessageMask{};
		csl::ut::MoveArray<GOComponent*> componentsByUpdatingPhase[3];
		csl::ut::MoveArray<fnd::Handle<GameObject>> children;
		Unk1 deferredComponentAdditions;

		WorldObjectStatus* status;
		const GameObjectClass* objectClass;
		Unk2 unk70;
		Unk2 unk71;
		Unk2 unk72;
		
	public:
		virtual ~GameObject();
		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(fnd::Message& message) override;
		virtual bool ReceiveMessage(fnd::Message& message) override;
		virtual bool IsAcceptingMessages() override;
		virtual void AddCallback(GameManager* gameManager) {}
		virtual void RemoveCallback(GameManager* gameManager) {}
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) {}
		virtual void UnkFunc9() {}
		virtual void UnkFunc10() {}
		virtual void UnkFunc11(uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4);

	private:
		void SetUpdateFlags(fnd::UpdatingPhase phase);
	protected:
		// template <typename T>
		// T* GetGOC()
		// {
		// 	for (auto* pComponent : m_Components)
		// 	{
		// 		if (pComponent == nullptr)
		// 			continue;

		// 		if (strcmp(pComponent->pStaticClass->pName, T::GetComponentName()) == 0)
		// 			return reinterpret_cast<T*>(pComponent);
		// 	}

		// 	return { nullptr };
		// }

		// template <typename T>
		// T* GetComponent()
		// {
		// 	return GetGOC<T>();
		// }

		hh::game::GOComponent* CreateComponent(const GOComponentClass* gocClass);

	protected:
		template<typename T>
		T* CreateComponent() {
			return static_cast<T*>(CreateComponent(T::GetClass()));
		}

		void AddComponent(GOComponent* component);
		void RemoveComponent(GOComponent* component);
		void SetUpdateFlag(fnd::UpdatingPhase phase, bool enabled);
		void SetComponentLengths(fnd::UpdatingPhase phase);

		
		fnd::MessageAsyncHandler* SendMessageToGame(fnd::Message& message);
		bool SendMessageImmToGame(fnd::Message& message);
		fnd::MessageAsyncHandler* SendMessageToGameObject(const fnd::Handle<GameObject>& handle, fnd::Message& message);
		template<typename T>
		fnd::MessageAsyncHandler* SendMessageToGameObject(const fnd::Handle<T, fnd::HandleManager<hh::fnd::Messenger>>& handle, fnd::Message& message) {
			return SendMessageToGameObject(reinterpret_cast<const fnd::Handle<GameObject>&>(handle), message);
		}
		bool SendMessageImmToGameObject(const fnd::Handle<GameObject>& handle, fnd::Message& message);
		template<typename T>
		bool SendMessageImmToGameObject(const fnd::Handle<T, fnd::HandleManager<hh::fnd::Messenger>>& handle, fnd::Message& message) {
			return SendMessageImmToGameObject(reinterpret_cast<const fnd::Handle<GameObject>&>(handle), message);
		}

		void SetLayer(char layer);

		void LinkActionToUIKey(ui::LayerController* layerController, const char* uiPath, const char* actionName, void* unkParam);
		const void* GetWorldDataByClass(const fnd::RflClass& rflClass) const;
		void KillChildren();

		
		GameService* GetService(const GameServiceClass* componentClass);
		template<typename T>
		T* GetService() {
			return static_cast<T*>(GetService(T::GetClass()));
		}
	public:
		inline void UNSAFE_SetUpdateFlags(fnd::UpdatingPhase phase) {
			SetUpdateFlags(phase);
		}
		inline void UNSAFE_AddComponent(GOComponent* component) {
			AddComponent(component);
		}
		inline void UNSAFE_RemoveComponent(GOComponent* component) {
			RemoveComponent(component);
		}
		inline void UNSAFE_SetComponentLengths(fnd::UpdatingPhase phase) {
			SetComponentLengths(phase);
		}
		GOComponent* GetComponent(const GOComponentClass* componentClass);
		template<typename T>
		T* GetComponent() {
			return static_cast<T*>(GetComponent(T::GetClass()));
		}

		void AddListener(GameObjectListener* listener);
		void RemoveListener(GameObjectListener* listener);
		void SetEditorStatus(bool status);
		bool GetEditorStatus() const;
		void NotifyDestroy();
		void Shutdown();
		void Sleep();
		void Resume();
		static GameObject* Create(const GameObjectClass* gameObjectClass, csl::fnd::IAllocator* allocator);
		template<typename T>
		static T* Create(csl::fnd::IAllocator* allocator) {
			return static_cast<T*>(Create(T::GetClass(), allocator));
		}
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);
		
		template<typename T>
		const T* GetWorldDataByClass() const {
			return static_cast<const T*>(GetWorldDataByClass(T::rflClass));
		}

		void Kill();
		inline WorldObjectStatus* GetWorldObjectStatus() const {
			return status;
		}

		const csl::ut::MoveArray<fnd::Handle<GameObject>>& GetChildren();
	};
}