#pragma once

namespace hh::game {
    class ObjectWorldListener {
    public:
        virtual ~ObjectWorldListener() = default;
        virtual void WorldChunkAddedCallback(ObjectWorldChunk* chunk) {}
        virtual void WorldChunkRemovedCallback(ObjectWorldChunk* chunk) {}
    };

    class ObjectWorld : public GameService, public GameStepListener {
    public:
        csl::ut::MoveArray<ObjectWorldChunk*> worldChunks;
        csl::ut::MoveArray<ObjectWorldListener*> listeners;
        csl::ut::MoveArray<ObjectWorldExtension*> extensions;
        fnd::Packfile* packFile;
        uint8_t flags; // 0 = LEVEL_STARTED, 1 = EDITOR_STARTED

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void UpdateCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        csl::ut::MoveArray<ObjectWorldChunk*>& GetWorldChunks() const;
        void AddWorldChunk(ObjectWorldChunk* chunk);
        void RemoveWorldChunk(ObjectWorldChunk* chunk);
        void RemoveWorldChunkAll();
        void AddWorldListener(ObjectWorldListener* chunk);
        void RemoveWorldListener(ObjectWorldListener* chunk);
        void AddWorldExtension(ObjectWorldExtension* chunk);
        void RemoveWorldExtension(ObjectWorldExtension* chunk);
        void RemoveWorldExtensionAll();
        ObjectDataAccessor GetObjectDataByObjectId(ObjectId objectId) const;
        fnd::Handle<Messenger> GetGameObjectHandleByObjectId(ObjectId objectId) const;
        // void SendObjectMessageImm(ObjectId objectId, fnd::Message& msg, const GameObjectHandleBase& handle, bool unkParam);
        void SpawnObjectBySetObjectID(ObjectId objectId) const;
        WorldObjectStatus GetWorldObjectStatusByObjectId(ObjectId objectId) const;
        void LevelStarted();
        void LevelEnded();
        void EditorStarted();
        void EditorEnded();

        GAMESERVICE_CLASS_DECLARATION(ObjectWorld)
    };
}
