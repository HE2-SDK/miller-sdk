#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class CopyColor;
    class RenderUnit;
    class RenderTextureHandle;
    class RenderTextureCreateArgs;
    class SupportFX {
    public:
        struct FxViewport {
            FxCamera* camera;
            uint32_t x;
            uint32_t y;
            uint32_t resX;
            uint32_t resY;
            uint32_t prevRenderResX;
            uint32_t prevRenderResY;
            uint32_t renderResX;
            uint32_t renderResY;
            uint32_t unk7;
        };

        struct FxRenderParam {
            // uint8_t unk1[240];
            // uint32_t unk2;
            // uint32_t unk3;
            // uint32_t unk4;
            // uint32_t unk5;
            // uint32_t unk6;
            FxViewport viewports[5];
            uint32_t numViewports;
            float unk32;
            float unk33;
            float unk34;
            float unk35;
        };

        class SFXAllocator {
        public:
            uint64_t unk1;
            uint8_t unk2;
            uint32_t unk2a[36];
            csl::ut::MoveArray<void*> unk3;
            csl::ut::MoveArray<void*> unk4;
            csl::ut::MoveArray<void*> unk5;
            uint64_t unk6;

            SFXAllocator();
            virtual ~SFXAllocator();
            
            virtual void* Alloc(size_t in_size, size_t in_alignment);
            virtual void Free(void* in_pMemory);
        };
    
        uint32_t vertexShaderCount;
        void* vertexShaderData[128];
        size_t vertexShaderSizes[128];
        uint32_t pixelShaderCount;
        void* pixelShaderData[128];
        size_t pixelShaderSizes[128];
        uint32_t computeShaderCount;
        void* computeShaderData[128];
        size_t computeShaderSizes[128];
        VertexShader* vertexShaders[128];
        PixelShader* pixelShaders[128];
        ComputeShader* computeShaders[128];
        void* unk6a[5];
        RenderingDevice* renderingDevice;
        VertexShader* commonVertexShader;
        VertexShader* zPrepassSimpleVertexShader;
        VertexShader* zPrepassSimplePTVertexShader;
        PixelShader* commonPixelShader;
        PixelShader* unkPixelShader; // not filled in? zPrepassSimplePixelShader?
        PixelShader* zPrepassSimplePTPixelShader;
        ShaderObject* commonShaderObject;
        ShaderObject* zPrepassSimpleShaderObject;
        ShaderObject* zPrepassSimplePTShaderObject;
        ShaderListInfo* shaderListInfo;
        DisplaySwapDevice* swapDevice;
        intrusive_ptr<RenderManager> renderManager;
        intrusive_ptr<PBRModelInstanceRenderer> modelInstanceRenderer;
        void* unk10_4;
        intrusive_ptr<ParameterValueObject> globalParameters;
        csl::ut::MoveArray<intrusive_ptr<SceneContextManager>> sceneContextManagers;
        float worldScale;
        Texture* textures[13];
        void* unk13_0;
        void* unk13_1;
        CopyColor* copyColor1;
        CopyColor* copyColor2;
        RenderTarget* renderTarget;
        Texture* renderTargetTextureView;
        csl::ut::MoveArray<void*> unk13_6;
        uint64_t unk13b[7];
        uint64_t unk14;
        float deltaTime;
        float totalTime[4];
        uint32_t frameCount;
        uint32_t unk16b;
        uint8_t unk17;
        uint32_t unk18;
        uint32_t unk19;
        void* unk20;
        void* unkVtbl1;
        uint64_t unk21;
        uint64_t unk22;
        int32_t unk23;
        uint64_t unk24;
        intrusive_ptr<RenderingDeviceContext> renderingDeviceContextTLS;
        intrusive_ptr<RenderingDeviceContext> renderingDeviceContext;
        intrusive_ptr<RenderingContextManager> renderingContextManager;
        intrusive_ptr<PrimitiveRenderer> primitiveRenderer;
        SupportFX* unkBackRef;
        uint32_t unk29;
        void* unk30;
        void* unk31;

        class CaptureIBLListener {
        public:
            virtual ~CaptureIBLListener() = default;
            virtual void CIL_UnkFunc1();
            virtual void CIL_UnkFunc2();
        };

        bool CreateDevice(unsigned int resX, unsigned int resY, void* unkParam3, intrusive_ptr<RenderingDevice>& renderingDevice, bool unkParam4, void* unkParam5, void* unkParam6);
        void CreateRenderManager(unsigned int resX, unsigned int resY, unsigned int renderResX, unsigned int renderResY, intrusive_ptr<RenderingDevice>& renderingDevice, void* unkParam5);
        RenderingDevice* GetRenderingDevice() const;
        RenderingDeviceContext* GetRenderingContext() const;
        RenderingDeviceContext* GetRenderingContext2() const;
        RenderingContextManager* GetRenderingContextManager() const;
        RenderManager* GetRenderManager() const;
        SceneContextManager* GetSceneContextManager(const char* name) const;
        SceneContextManager* GetSceneContextManager(const CNameIDObject* name) const;
        VertexShader* GetVertexShader(unsigned int idx) const;
        PixelShader* GetPixelShader(unsigned int idx) const;
        ComputeShader* GetComputeShader(unsigned int idx) const;
        void AddSceneContextManager(SceneContextManager* sceneContextManager);
        void SetWorldScale(float scale);
        void AddRenderUnit(RenderUnit* unit);
        RenderTarget* GetRenderTarget(unsigned int index) const;
        Texture* GetRenderTargetView(unsigned int index) const;
        RenderTarget* GetDepthStencil(unsigned int index) const;
        Texture* GetDepthStencilView(unsigned int index) const;
        void GetRenderTargetDimensions(unsigned int index, unsigned int& width, unsigned int& height) const;
        VertexShader* GetVertexShader(void* data, size_t size);
        PixelShader* GetPixelShader(void* data, size_t size);
        ComputeShader* GetComputeShader(void* data, size_t size);

        static SupportFX* instance;

        SupportFX();
        virtual ~SupportFX();
        virtual void UnkFunc1(RenderManager* renderManager) = 0;
        virtual bool Render(const FxRenderParam& renderParam, RenderTarget* renderTarget) { return true; }
        virtual bool UnkFunc3();
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras);
    };

    class SupportFXAll : public SupportFX {
    public:
        void* unk101;
        void* unk102;
        void* unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint8_t unk109;
        csl::ut::LinkList<RenderUnit> renderUnits;
        const char* mainSceneName;
        csl::ut::MoveArray<void*> unk112;
        float globalUserParams[4][4];
        needle::Texture* unk114[3];

        SupportFXAll();

        virtual void UnkFunc1(RenderManager* renderManager) override;
        virtual bool Render(const FxRenderParam& renderParam, RenderTarget* renderTarget) override;
        virtual bool UnkFunc3() override;
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras) override;

        RenderTextureHandle* CreateRenderTextureHandle(const RenderTextureCreateArgs& createArgs);
    };
}
