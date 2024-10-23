#pragma once

namespace hh::gfx {
    class RenderingEngineNeedle : public RenderingEngine {
        class Impl : public fnd::ReferencedObject {
        public:
            class ResourceListener : public fnd::ReferencedObject, fnd::ResourceManager::ResourceListener {
                RenderingEngineNeedle* renderingEngine;
                csl::ut::MoveArray<void*> unk1;
            };

            class NeedleShaderListInfo : public needle::ShaderListInfo {
                csl::ut::PointerMap<void*, void*> vertexShaders;
                csl::ut::PointerMap<void*, void*> pixelShaders;
            public:
                virtual needle::VertexShader* GetVertexShader(const char* name) override;
                virtual needle::PixelShader* GetPixelShader(const char* name) override;
            };
        
        private:
            RenderingEngineNeedle* renderingEngine;
            needle::SupportFX* supportFX;
            needle::RenderingDevice* renderingDevice;
            fnd::Reference<ResourceListener> resourceListener;
            fnd::Reference<NeedleShaderListInfo> shaderListInfo;
            fnd::Reference<needle::PrimitiveRenderer> primitiveRenderer;
            fnd::Reference<NeedleRenderer> renderers[10]; // one created for each in unk1 in graphicscontext
            fnd::Reference<RenderingWorld> world;

        public:
            Impl(csl::fnd::IAllocator* allocator);
        };

        Impl* implementation;

    public:
        RenderingEngineNeedle(csl::fnd::IAllocator* allocator);
        virtual bool Setup(const gfnd::RenderManagerBase::SetupInfo& setupInfo) override;
        virtual void BeforeRender(const needle::SupportFX::FxRenderParam& renderParam) override {}
        virtual bool Render(const needle::SupportFX::FxRenderParam& renderParam) override;
        virtual void AfterRender(const needle::SupportFX::FxRenderParam& renderParam) override {}
        virtual ID3D11Device* GetNativeDevice() override;
        virtual uint64_t Startup() override;
        virtual uint64_t Shutdown() override;
        virtual needle::RenderingDevice* GetRenderingDevice();
        virtual needle::RenderingDeviceContext* GetRenderingDeviceContext();
        virtual void SetSupportFX(needle::SupportFX* supportFX);
        virtual needle::SupportFX* GetSupportFX();
        virtual void SetFXParameter(hh::needle::NeedleFxParameter* parameter, needle::CNameIDObject* renderUnitName) {}
        virtual void GetFXParameter(hh::needle::NeedleFxParameter* parameter) {}
        virtual void SetSceneConfig(hh::needle::NeedleFxSceneConfig* sceneConfig) {}
        virtual void GetSceneConfig(hh::needle::NeedleFxSceneConfig* sceneConfig) {}
        virtual uint64_t CreateRenderTextureHandle(const needle::RenderTextureCreateArgs& createArgs, csl::fnd::IAllocator* allocator);
        virtual uint64_t DestroyRenderTextureHandle(needle::RenderTextureHandle* handle);
        virtual void AddRenderableToRenderTextureHandle(needle::RenderTextureHandle* handle, gfnd::Renderable* renderable) {}
        virtual unsigned int UnkFunc18() { return 0; }
        virtual void SetDebugViewType(unsigned int debugViewType) {}
        virtual void* GetWorld() const;
        virtual void UnkFunc21() {}
        virtual void UnkFunc22() {}
        virtual needle::RenderingPipeline* GetMainRenderingPipeline() const { return 0; }
        virtual void SetupMainRenderUnit() {}

        void AddComponent(RenderingComponent* component);
    };
}
