#pragma once

namespace hh::gfx {
    class DynamicResolutionController;
    class RenderingEngineNeedle;
    class RenderManager : public gfnd::RenderManagerBase {
    public:
        class Impl : public fnd::ReferencedObject {
        public:
            // Returns camera info based on viewportdata. id = viewport id
            class LocalFxCamera : public needle::FxCamera {
            public:
                Impl* renderManagerImplementation;
                uint32_t id;

                LocalFxCamera();

                virtual csl::math::Vector3 GetEyePos() const override;
                virtual void GetEyePosF(float* eyePos) const override;
                virtual csl::math::Vector3 GetLookAtPos() const override;
                virtual void GetLookAtPosF(float* lookAtPos) const override;
                virtual csl::math::Matrix44 GetViewMatrix() const override;
                virtual void GetViewMatrixF(float* viewMatrix) const override;
                virtual csl::math::Matrix44 GetProjectionMatrix() const override;
                virtual void GetProjectionMatrixF(float* projectionMatrix) const override;
                virtual void GetClipPlanes(float* near, float* far) const override;
            };
            needle::SupportFX::FxViewport viewports[4];
            LocalFxCamera fxCameras[4];
            uint64_t unk2;
            uint32_t numMainViewports;
            uint32_t unk3;
            float unk4;
            float unk5;
            uint32_t unk6;
            needle::SupportFX::FxRenderParam renderParam;
            uint32_t maybeSupportFXWidth;
            uint32_t maybeSupportFXHeight;
            fnd::Reference<DynamicResolutionController> dynamicResolutionController;
            SetupInfo setupInfo;
            RenderingEngineNeedle* renderingEngine;
            fnd::Reference<RenderingWorld> renderingWorld;
            csl::math::Vector4 unk25;
            RenderManager* renderManager;
            uint64_t unk26;
            fnd::Reference<fnd::ResourceLoader> resourceLoader;
            uint8_t unk28;
            csl::ut::MoveArray<void*> unk29;
            uint8_t unk30[128];
            bool unk31;

            static Impl* Create(csl::fnd::IAllocator* allocator);
            Impl(csl::fnd::IAllocator* allocator, RenderManager* renderManager);
            bool Setup(const SetupInfo& setupInfo);
        };

        Impl* implementation;

        struct SModelCreationInfo {
            // Check GOCVisualModelImpl::Setup
            fnd::ManagedResource* unk325; // suspected
            fnd::ManagedResource* unk326; // suspected
            fnd::ManagedResource* unk327; // suspected
            needle::MeshResource* meshResource;
        };

        static RenderManager* instance;

        static RenderManager* Create(csl::fnd::IAllocator* allocator);

        RenderManager(csl::fnd::IAllocator* allocator);

        virtual bool Setup(const SetupInfo& setupInfo) override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual void UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;

        void CreateModelFromResource2(needle::Model** model, const SModelCreationInfo& modelCreationInfo);
        needle::ModelInstance* CreateModelInstance(needle::Model* model, const SModelCreationInfo& modelCreationInfo) const;
        gfx::RenderingEngineNeedle* GetNeedleResourceDevice();
        void SetRenderingWorld(RenderingWorld* renderingWorld);
        void GetResolution(unsigned int& resX, unsigned int& resY);
        void SetDynamicResolutionController(DynamicResolutionController dynamicResolutionController);
        DynamicResolutionController* GetDynamicResolutionController() const;
    };
}
