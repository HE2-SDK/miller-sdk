#pragma once

namespace hh::path {
    class PathManagerListener {
    public:
        virtual ~PathManagerListener() = default;
        virtual void PathComponentAddedCallback(PathManager* pathManager, PathComponent* pathComponent) {}
        virtual void PathComponentRemovedCallback(PathManager* pathManager, PathComponent* pathComponent) {}
        virtual void PostStepCallback(PathManager* pathManager, float time) {}
    };

    class PathManager : public game::GameService, public game::GameStepListener {
    public:
        struct SetupInfo {
            unsigned int maxPaths;
        };

        csl::ut::MoveArray<PathComponent*> pathComponents;
        csl::ut::MoveArray<PathManagerListener*> listeners;
        csl::ut::StringMap<PathComponent*> pathComponentsByName;
        fnd::Reference<PathCollisionHandler> pathCollisionHandler;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void UpdateCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
        
        void Setup(const SetupInfo& setupInfo);
        void AddObject(PathComponent* obj);
        void RemoveObject(PathComponent* obj);
        PathComponent* GetPathObject(const char* name);
        void AddListener(PathManagerListener* listener);
        void RemoveListener(PathManagerListener* listener);

        GAMESERVICE_CLASS_DECLARATION(PathManager);
    };
}
