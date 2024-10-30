#pragma once

namespace app::camera {
    class CameraService
        : public hh::game::GameService
        , public hh::game::GameManagerListener
        , public hh::game::GameStepListener
    {
    public:
        struct CameraBridgeUnit {
            hh::fnd::Handle<Messenger> cameraFrame;
            CameraBridge cameraBridge;
            hh::fnd::Reference<hh::game::CameraComponent> cameraComponent;
            CameraBridgeUnit();
        };

        csl::fnd::Mutex mutex1;
        csl::fnd::Mutex mutex2;
        CameraBridgeUnit cameraBridges[3];
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::CameraShakeTable>> cameraShakeTable;
        uint64_t unk2;
        float timeLeftInZoom;
        csl::ut::LinkList<CameraBridge> unk4; // This CameraBridge is a dummy, I don't yet know what's inside.
        hh::physics::PhysicsWorld* physicsWorld;
        hh::game::CameraManager* cameraManager;
        uint32_t dword1A8;
        uint8_t word1AC;
        bool word1ACb;
        uint16_t unk5[2];

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        app_cmn::camera::CameraFrame* CreateDefaultCameraFrame(int componentId, int viewportId, int priority, float nearClip, float farClip, float fov);
        hh::fnd::Handle<Messenger> GetCameraFrame(int index);
        static hh::fnd::Handle<Messenger> GetCameraFrame(hh::game::GameManager gameManager, int index);

        GAMESERVICE_CLASS_DECLARATION(CameraService)
    };
}
