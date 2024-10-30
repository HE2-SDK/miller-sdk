#pragma once

namespace app_cmn::camera {

    class CameraFrame;
    class CameraController;
    class CameraFrameHistory : public hh::fnd::ReferencedObject, public hh::game::GameManagerListener {
    public:
        hh::fnd::Handle<hh::fnd::Messenger> cameraFrame;
        uint64_t unk1;
        float fov;
        CameraFrameHistory(csl::fnd::IAllocator* allocator, CameraFrame* cameraFrame);
    };

    class CameraFrame : public hh::game::GameObject {
    public:
        struct Listener {
            int cameraFrameId;
            app_cmn::camera::CameraFrame* cameraFrame;

            virtual void CFL_UnkFunc1(const FrustumParameter& frustumParameter) {}
            virtual void CFL_UnkFunc2(const csl::math::Matrix34& viewMatrix, const app_cmn::camera::FrustumParameter& frustumParameter) {}
            virtual ~Listener() = default;
        };

        struct ControllerUnit {
            CameraController* controller;
            unsigned int priority;
        };

        struct SetupInfo {
            FrustumParameter frustumParameter;
            int id;
            uint32_t gameObjectLayer;
            uint8_t unk3;
            uint8_t unk4;
        };

        class BlendNode : public hh::fnd::ReferencedObject {
        public:
            BlendNode* child1;
            BlendNode* child2;
            CameraController* controller;
            CameraInterpolator* interpolator;
            CameraParameter cameraParameter;
            bool noParameters;

            DEFAULT_CREATE_FUNC(BlendNode);
        };

        FrustumParameter frustumParameter1;
        FrustumParameter frustumParameter2;
        CameraParameter cameraParameter1;
        CameraParameter cameraParameter2;
        CameraPose pose;

        csl::ut::MoveArray<ControllerUnit> controllers;
        BlendNode* blendTree;
        csl::ut::MoveArray<hh::fnd::Reference<CameraExtension>> extensions;
        Listener* listener;
        csl::math::Matrix44 matrix34400;
        int id;
        float dword444;
        uint8_t byte448;
        csl::fnd::Mutex mutex;
        uint64_t qword478;
        uint64_t qword480;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual bool fUnk3() override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UnkFunc11(uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) override;

        void Setup(const SetupInfo& setupInfo);
        void SetListener(Listener* listener);
        void AddToBlendTree(CameraController* controller, CameraInterpolator* interpolator);
        void SearchBlendNode(BlendNode* blendNode, CameraController* controller, csl::ut::MoveArray<BlendNode*>* results) const;
        void RemoveBlendNodeHierarchy(BlendNode* blendNode);

        GAMEOBJECT_CLASS_DECLARATION(CameraFrame)
    };
}