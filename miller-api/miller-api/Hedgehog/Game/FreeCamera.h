#pragma once

namespace hh::game {
    class FreeCameraListener {
    public:
        virtual ~FreeCameraListener() = default;
        virtual void FCL_UnkFunc1() {}
        virtual void FCL_UnkFunc2() {}
        virtual void FCL_UnkFunc3() {}
    };

    class FreeCameraControllerBase;
    class FreeCamera : public fnd::ReferencedObject, public GameManagerListener, public GameUpdateListener {
    public:
        struct CreateInfo {
            CameraComponent::CreateInfo cameraComponentCreateInfo;
            uint32_t internalPlayerInputIndex;
            uint32_t inputPriority;
            bool captureInput;
            const char unk3[64];
            bool unk4;
        };

    public:
        CreateInfo createInfo;
        fnd::Reference<GameManager> gameManager;
        fnd::Reference<CameraManager> cameraManager;
        fnd::Reference<InputManager> inputManager;
        fnd::Reference<CameraComponent> createdCameraComponent;
        fnd::Reference<CameraComponent> cameraComponent;
        fnd::Reference<InputComponent> inputComponent;
        fnd::Reference<FreeCameraControllerBase> controller;
        csl::ut::MoveArray<void*> unk8;
        gfnd::ViewportData viewportData;

        FreeCamera(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo);
        void Initialize(csl::fnd::IAllocator* allocator);
        bool HasCamera();
		virtual void GameServiceRemovedCallback(GameService* gameService) override;
		virtual void PostGameUpdateCallback(GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;

        inline void SetLocked(bool value) {
            inputComponent->SetListening(!value);
        }

        inline bool IsLocked() {
            return !inputComponent->IsListening();
        }
    };

    class FreeCameraUnk2 {
    public:
        struct CameraSettings {
            csl::math::Vector3 origin;
            csl::math::Vector3 position;
            float yaw;
            float pitch;
            float zoom;
            csl::math::Vector3 up;
            float roll;
        };
        struct ViewportSettings {
            float nearClip;
            float farClip;
            float fov;
        };

        CameraSettings camera;
        ViewportSettings viewport;

        FreeCameraUnk2(csl::fnd::IAllocator* allocator);
    };

    class FreeCameraControllerBase : public fnd::ReferencedObject {
        FreeCamera* camera;
    public:
        FreeCameraControllerBase(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;
        virtual uint64_t UnkFunc9() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual uint64_t UnkFunc13() = 0;
    };

    class PadFreeCameraController : public fnd::ReferencedObject, public FreeCameraListener {
    public:
        void* unk1;
        gfnd::ViewportData viewportData;
        FreeCameraUnk2 unk3;
        float unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        float currentSpeed;
        csl::ut::MoveArray<float> speedOptions;
        unsigned int currentSpeedOptionIdx;
        bool unk12;
        float unk13;
        uint16_t unk14;

        PadFreeCameraController(csl::fnd::IAllocator* allocator);
        void LoadSpeedOptions(float* speeds, size_t count);
    };
    
    class UnkPadFreeCameraController : public PadFreeCameraController {
    public:
        uint64_t unk101; // set from unk6 on defaultcontroller
        csl::math::Vector4 unk102;

        UnkPadFreeCameraController(csl::fnd::IAllocator* allocator);
    };

    class ArcBallCameraController : public fnd::ReferencedObject {
    public:
        struct CreateInfo {
            uint32_t resX;
            uint32_t resY;
            float unk1;
            csl::math::Vector4 unk2;
            float unk3;
            float unk4;
            float unk5;
            uint32_t axisMonitorOffset;
            uint32_t actionMonitorOffset;
        };
    private:
        CreateInfo createInfo;
        fnd::Reference<InputComponent> inputComponent; // set in ctor
        uint32_t unk3;
        float unk4;
        float unk5;
        float unk6;
        float unk7;
        csl::math::Matrix44 unk8;
        uint32_t unk9;
        char unk10;

    public:
        ArcBallCameraController(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, InputComponent* inputComponent);
    };

    class DefaultFreeCameraController : public FreeCameraControllerBase {
    public:
        fnd::Reference<UnkPadFreeCameraController> padController;
        fnd::Reference<ArcBallCameraController> arcBallController;
        bool unk4;
        bool unk5; // comes from unk4 on freeCamera createinfo
        uint64_t unk6;
        DefaultFreeCameraController(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override { return false; }
        virtual uint64_t UnkFunc4() override { return true; }
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override {}
        virtual uint64_t UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
    };

    class DebugCameraManager : public fnd::BaseObject, public csl::fnd::Singleton<DebugCameraManager>, public FreeCameraListener {
    public:
        struct DebugCameraInitInfo {
            uint32_t inputPriority;
            uint32_t playerInputIndex;
            bool captureInput;
            const char* debugCameraName;
        };

    private:
        fnd::Reference<FreeCamera> camera;
        csl::ut::MoveArray<void*> maybeListeners;
        uint64_t unk2;
        char unk3;
    public:
        bool isActive;
        static DebugCameraManager* Create();
        void ActivateDebugCamera(const DebugCameraInitInfo& initInfo);
        void DeactivateDebugCamera();
        inline FreeCamera* GetCamera() {
            return camera;
        }
    };
}
