#pragma once

namespace hh::game {
    class CameraManager;
    class CameraComponent : public fnd::ReferencedObject {
    public:
        struct CreateInfo {
            int viewportId;
            int priority;
            const char* name;
        };

        char viewportId;
        char priority;
        bool enabled;
        CameraManager* cameraManager;
        gfnd::ViewportData viewportData;
        csl::ut::VariableString name;

        CameraComponent(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
        static CameraComponent* Create(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
        void SetEnabled(bool enabled);
        void SetViewMatrix(const csl::math::Matrix34& viewMatrix);
        void SetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
        void SetLookAtPos(const csl::math::Vector3& lookAtPos);
    };
}
