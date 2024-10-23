#pragma once

namespace hh::game {
	struct WorldObjectCInfo {
		csl::ut::InplaceMoveArray<hh::game::GOComponentConfiguration, 5> componentConfig;
		fnd::Packfile* packFile; // see 1.40 0x140D48348 -- Packfile*??? see 0x140CFC8C5
                       //     1.41 0x140D4B1F7
	};

    class ObjectWorldChunk;
    class ObjectWorldChunkListener {
    public:
        virtual ~ObjectWorldChunkListener() = default;
        virtual void ObjectDataAddedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void ObjectDataRemovedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void ObjectDataChangedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void FinishEditorCallback() {}
        virtual void OWC_UnkFunc1() {}
    };

	// If spawntype is ETERNAL or EXTRINSIC, then don't spawn, otherwise spawn.
	bool IsSpawnBySpawnType(const GameObjectClass* gameObjectClass);

    bool GetStatusEternal(const GameObjectClass* gameObjectClass, int* type);
    bool GetStatusExtrinsic(const GameObjectClass* gameObjectClass, int* type);

    class ObjectWorld;
    class ObjectWorldChunkLayer;
    class ObjectWorldChunk : public fnd::ReferencedObject, public GameManagerListener {
        enum class Flag : uint8_t {
            EDITOR,
        };

        ObjectWorld* objectWorld;
        GameManager* gameManager;
        csl::ut::Bitset<Flag> flags;
        csl::ut::MoveArray<ObjectWorldChunkListener*> listeners;
        csl::ut::MoveArray<ObjectWorldChunkLayer*> layers;
        csl::ut::StringMap<ObjectWorldChunkLayer*> layersByName;
        csl::ut::MoveArray<GameObject*> objects;
        csl::ut::MoveArray<WorldObjectStatus> objectStatuses;
        csl::ut::StringMap<WorldObjectStatus*> objectStatusesByName;
        hh::game::ObjectMap<int> objectIndicesByObjectId;
        csl::ut::PointerMap<GameObjectClass*, csl::ut::MoveArray<GameObject*>*> objectsByClass;
        csl::ut::MoveArray<void*> unk11;
    public:
        typedef bool (*ObjectAttribute)(const GameObjectClass* gameObjectClass, int* attributeFlags);

        ObjectWorldChunk(csl::fnd::IAllocator* allocator, GameManager* gameManager);
		virtual void GameObjectRemovedCallback(GameManager* gameManager, GameObject* gameObject);
        void AddLayer(ObjectWorldChunkLayer* layer);
        inline void RemoveLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayerAll();
        const csl::ut::MoveArray<ObjectWorldChunkLayer*>& GetLayers() const;
        void SetLayerEnabled(const char* name, bool enabled);

        ObjectWorldChunkLayer* GetLayerByName(const char* name) const;

        void AddWorldObjectStatus(ObjectData* objectData, bool enabled, int spawnPriority);
        void RemoveWorldObjectStatus(ObjectData* objectData);
        
        inline void AddWorldObjectStatus(ObjectData* objectData, bool enabled) {
            AddWorldObjectStatus(objectData, enabled, 0);
        }

        void AddListener(ObjectWorldChunkListener* listener);
        void RemoveListener(ObjectWorldChunkListener* listener);
        void Despawn(const ObjectData* objectData); // inlined :/
        void DespawnByIndex(int index);
        ObjectDataAccessor GetObjectDataByObjectId(ObjectId id) const;
        ObjectDataAccessor GetObjectDataByName(const char* name) const;
        GameObject* Spawn(const ObjectData* objectData);
        GameObject* SpawnByObjectId(ObjectId id);
        GameObject* SpawnByObjectId(ObjectId id, ObjectAttribute filter);
        GameObject* SpawnByIndex(int index, ObjectAttribute filter);
        GameObject* SpawnByAttribute(ObjectAttribute filter);
        GameObject* RespawnByObjectId(ObjectId id);
        GameObject* RespawnByObjectId(ObjectId id, ObjectAttribute filter);

        GameObject* GetActiveGameObjectByIndex(int index);
        GameObject* GetGameObjectByObjectId(ObjectId id) const;
        WorldObjectStatus GetWorldObjectStatusByObjectId(ObjectId id) const;

        inline GameObject* GetGameObject(ObjectData* objectData) const {
            return GetGameObjectByObjectId(objectData->id);
        }

        inline const csl::ut::MoveArray<WorldObjectStatus>& GetObjectStatuses() const {
            return objectStatuses;
        }

        inline int GetObjectIndexById(ObjectId id) const {
            return objectIndicesByObjectId.GetValueOrFallback(id, -1);
        }

        inline int GetObjectIndexByObjectData(const ObjectData* objData) {
            return GetObjectIndexById(objData->id);
        }

        inline GameObject* GetObjectByIndex(int i) const {
            if (i < 0 && i >= objects.size())
                return nullptr;

            return objects[i];
        }

        inline WorldObjectStatus GetWorldObjectStatusByIndex(int i) const {
            assert(i >= 0 && i < objects.size());

            return objectStatuses[i];
        }

        inline void DespawnAll() {
            for (int i = 0; i < objects.size(); i++) {
                DespawnByIndex(i);
            }
        }

        inline void Despawn(ObjectData* objData) {
            int index = GetObjectIndexById(objData->id);

            if (index >= 0 && index < objects.size())
                DespawnByIndex(index);
        }

        inline void Shutdown(int index) {
            if (index >= 0 && index < objects.size())
                objectStatuses[index].Shutdown();
        }
        
        inline void Restart(int index, bool force) {
            if (index >= 0 && index < objects.size())
                objectStatuses[index].Restart();
        }

        inline void Restart(bool force) {
            if (force) {
                for (int i = 0; i < objects.size(); i++) {
                    objectStatuses[i].Restart();
                }
            }
            else {
                for (int i = 0; i < objects.size(); i++) {
                    if (!objectStatuses[i].IsNoRestart())
                        objectStatuses[i].Restart();
                }
            }
        }

        inline void ShutdownPendingObjects() {
            gameManager->ShutdownPendingObjects();
        }

        inline void SetEditorStatus(bool status) {
            flags.set(Flag::EDITOR, status);
        }
        inline bool IsStatusEditor() {
            return flags.test(Flag::EDITOR);
        }
    };
}
