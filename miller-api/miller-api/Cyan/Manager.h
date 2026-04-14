#pragma once

namespace Cyan {
    struct UpdateLightParam {
        enum class Action : unsigned int {
            ADD,
            REMOVE,
            UPDATE,
        };

        Action action;
        unsigned int lightId;
        csl::math::Position position;
        float attenuationRadius;
        float color[3];
    };

    class Emitter;
    class Manager {
    public:
        struct SceneParameter
        {
            struct Unk1 {
                struct Unk2 {
                    csl::math::Matrix34 unk1;
                    char gap1[0x10];
                };

                uint64_t unk1[3];
                Unk2 unk2[3];

                Unk1();
            };

            float float0;
            float float4;
            float float8;
            float floatC;
            uint64_t qword10;
            float float18;
            float float1C;
            float float20;
            float float24;
            float float28;
            float float2C;
            uint64_t gap1;
            float float38;
            float float3C;
            float float40;
            float float44;
            float float48;
            float float4C;
            uint8_t byte50;
            unsigned int dword54;
            uint16_t word58;
            uint8_t byte5A;
            uint8_t gap5B;
            float float5C;
            float float60;
            float float64;
            float float68;
            float float6C;
            float float70;
            uint8_t byte74;
            uint8_t byte75;
            uint8_t byte76;
            uint8_t gap77;
            uint64_t qword78;
            uint64_t qword80;
            uint64_t qword88;
            uint64_t qword88b;
            uint64_t qword88c;
            uint8_t gap90[0x20];
            Unk1 unkB0[5];
            uint64_t qword600;
            uint8_t gap608[16];
            unsigned int dword618;
            uint8_t gap61C[4];
            uint64_t qword620;
            uint64_t qword628;
            uint64_t qword630;
            uint8_t byte638;
            uint8_t gap639[7];
            hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject640;
            hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject648;
            uint64_t qword650;
            uint64_t qword658;
            uint64_t qword660;
            uint64_t qword668;
            uint64_t qword670;
            uint64_t qword678;
            uint64_t qword680;
            uint64_t qword688;
            uint64_t qword690;
            uint64_t qword698;
            uint64_t qword6A0;
            uint64_t qword6A8;
            uint64_t qword6B0;
            uint64_t qword6B8;
            uint8_t gap6C0[16];
            float float6D0;
            float float6D4;
            float float6D8;
            float float6DC;
            float float6E0;
            float float6E4;
            float float6E8;
            float float6EC;
            uint8_t byte6F0;
            uint32_t unk704[16];

            SceneParameter();
        };

        typedef void NotifyCallback(void* userData, EffectHandle effect, NotifyData notifyData);

        template<typename T> using RequestResourceHandler = bool (Effect* effect, Resource::ResObject<T>* resource, void* userData);
        template<typename T> using UpdateLightHandler = bool (UpdateLightParam* updateLightParam, void* userData);

        virtual EffectHandle CreateEffect(Resource::EffectParam* effectParam, const EffectInstanceParam& instanceParam, bool unkParam6, int unkParam7, float unkParam8) = 0;
        virtual int UnkFunc2(const char* unkParam1, void* unkParam2) = 0;
        virtual int DestroyEffect(const EffectHandle& effectHandle) = 0;
        virtual int Initialize(const Graphics::DeviceContainer& deviceContainer) = 0;
        virtual void SetDeviceContainer(const Graphics::DeviceContainer& deviceContainer) = 0;
        virtual void UnkFunc6(void* unkParam1) = 0;
        virtual void* UnkFunc7() const = 0;
        virtual void* UnkFunc8() const = 0;
        virtual void* UnkFunc9() const = 0;
        virtual void BeginProcess(float unkParam1, unsigned int someType, bool unkParam2) = 0;
        virtual void EndProcess() = 0;
        virtual bool IsFinishedProcess() const = 0;
        virtual void Update() = 0;
        virtual void UnkFunc14() = 0;
        virtual void UnkFunc15() = 0;
        virtual bool UnkFunc16() const = 0;
        virtual void UnkFunc17(bool unkParam1) = 0;
        virtual void UnkFunc18() = 0;
        virtual void PrepareRender(Graphics::DeviceContainer& deviceContainer) = 0;
        virtual void Render(Graphics::DeviceContainer& deviceContainer) = 0;
        virtual void PostRender(Graphics::DeviceContainer& deviceContainer) = 0;
        virtual bool IsReadyRender() const = 0;
        virtual int UnkFunc23(void* unkParam1, unsigned int sceneIdx, int unkParam3, int unkParam4, int unkParam5, void* unkParam6) = 0;
        virtual bool UnkFunc24(unsigned int unkParam1, int unkParam2, int unkParam3, int unkParam4, int unkParam5) = 0;
        virtual bool SetViewProjection(unsigned int cameraIdx, const float* viewMatrix, const float* projMatrix, float unkParam4, float unkParam5) = 0;
        virtual void SetGammaCorrect(unsigned int sceneIdx, bool enabled) = 0;
        virtual void SetGammaCorrect2(unsigned int sceneIdx, bool enabled) = 0;
        virtual void UnkFunc28(unsigned int cameraIdx, float unkParam1, float unkParam2) = 0;
        virtual void StopAll() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;
        virtual void Step() = 0;
        virtual void Sleep() = 0;
        virtual void Wake() = 0;
        virtual void SetWorldScale(float scale) = 0;
        virtual void SetDirectionalLight(const float* unkParam1, const float* unkParam2) = 0;
        virtual void GetDirectionalLight(float* unkParam1, float* unkParam2) const = 0;
        virtual void SetSceneParameter (const SceneParameter& sceneParameter) = 0;
        virtual SceneParameter& GetSceneParameter() const = 0;
        virtual SceneParameter& GetSceneParameter2() const = 0;
        virtual void SetDropPriority(char priority) = 0;
        virtual char GetDropPriority() const = 0;
        virtual bool IsSleeping() const = 0;
        virtual void SetNotifyCallback(NotifyCallback* notifyCallback, void* userData) = 0;
        virtual void ResetNotifyCallback() = 0;
        virtual void Bind(Resource::EffectParam* effectParam) = 0;
        virtual void SetNodeAnimRequestResourceHandler(RequestResourceHandler<Resource::NodeAnim>* handler, void* userData) = 0;
        virtual void SetSkeletonRequestResourceHandler(RequestResourceHandler<Resource::Skeleton>* handler, void* userData) = 0;
        virtual void SetModelRequestResourceHandler(RequestResourceHandler<Resource::Model>* handler, void* userData) = 0;
        virtual void SetEffectRequestResourceHandler(RequestResourceHandler<Resource::Effect>* handler, void* userData) = 0;
        virtual void SetComputeShaderRequestResourceHandler(RequestResourceHandler<Resource::ComputeShader>* handler, void* userData) = 0;
        virtual void SetShaderRequestResourceHandler(RequestResourceHandler<Resource::Shader>* handler, void* userData) = 0;
        virtual void SetTextureRequestResourceHandler(RequestResourceHandler<Resource::Texture>* handler, void* userData) = 0;
        virtual void UnkFunc53(void* handler, void* userData) = 0;
        virtual void SetUpdateLightHandler(void* handler, void* userData) = 0;
        virtual void UnkFunc55(void* handler, void* userData) = 0;
        virtual void UnkFunc56(void* handler, void* userData) = 0;
        virtual void UnkFunc56b(void* handler, size_t unkParam2) = 0;
        virtual void UnkFunc57(void* handler, size_t unkParam2) = 0;
        virtual System::IAllocator* GetRenderAllocator() const = 0;
        virtual void UnkFunc59() = 0;
        virtual void UnkFunc60() = 0;
        virtual void UnkFunc61() = 0;
        virtual void UnkFunc62() = 0;
        virtual int UnkFunc63() const = 0;
        virtual void UnkFunc64() = 0;
        virtual ~Manager();
        virtual void UnkFunc65() = 0;
    };

    class ManagerImpl : public Manager {
    public:
        struct ResourceRequest{
            void* handler;
            void* userData;
        };

        struct Camera{
            csl::math::Matrix44 viewMatrix;
            csl::math::Matrix44 projMatrix;
            csl::math::Matrix44 invProjMatrix;
            csl::math::Matrix44 mat[6];
            csl::math::Vector4 unk1;
        };

        unsigned int dword8;
        Scene* scenes;
        unsigned int numRenderables;
        volatile int nextEffectId;
        System::LinkList<void> unk20;
        System::LinkList<void> unk48;
        System::LinkList<void> unk70;
        System::LinkList<EffectImpl> effects;
        float deltaTime;
        uint32_t dwordC4;
        float floatC8[32];
        float worldScale;
        uint32_t gap14C[9];
        SceneParameter sceneParameter;
        uint32_t dword870;
        uint8_t byte874;
        Graphics::DeviceContainer deviceContainer;
        System::RandomTable randomTable;
        EmissionGpuBase* emissionPrimitives[9];
        int64_t qword8f8;
        hh::needle::ImplDX11::ShaderMaterialContainerDX11Impl* computeShaderMatContainer[2];
        System::FreeListAllocator systemAllocator;
        System::FreeListAllocator renderAllocator;
        System::ArrayAllocator<16> tagAllocator;
        System::ArrayAllocator<320> effectAllocator;
        System::ArrayAllocator<7104> emitterAllocator;
        System::ArrayAllocator<1888> elementAllocator;
        System::ArrayAllocator<1184> animationAllocator;
        csl::fnd::Mutex mutex1;
        System::FreeListAllocator unkFreeListAllocator;
        uint64_t qword14B8;
        void* meshMemoryPtr;
        size_t meshMemorySize;
        ResourceRequest textureResourceRequestHandler;
        ResourceRequest shaderResourceRequestHandler;
        ResourceRequest computeShaderResourceRequestHandler;
        ResourceRequest effectResourceRequestHandler;
        ResourceRequest modelResourceRequestHandler;
        ResourceRequest skeletonResourceRequestHandler;
        ResourceRequest nodeAnimResourceRequestHandler;
        ResourceRequest unkResourceRequestHandler;
        ResourceRequest lightResourceRequestHandler;
        ResourceRequest unkResourceRequestHandler2[2];
        unsigned int numActiveRequests;
        Camera cameras[5];
        Camera cameras2[5];
        uint32_t dword2C00;
        uint32_t dword2C04;
        ResourceRequest unkFuncStr2c08;
        csl::fnd::Mutex mutex2;

        struct Config {
            void* memoryPtr;
            size_t memorySize;
            uint64_t unk1;
            uint64_t unk2;
            unsigned int cyanSystemSize;
            unsigned int cyanRenderSize;
            unsigned int cyanTagSize;
            unsigned int cyanEffectSize;
            unsigned int cyanEmitterSize;
            unsigned int cyanElementSize;
            unsigned int cyanAnimationSize;
            unsigned int cyanMeshRenderSize;
            unsigned int cyanDebugSize;
            unsigned int numRenderables;
            float worldScale;
        };

        ManagerImpl(unsigned int unkParam1, const Config& config);

        virtual EffectHandle CreateEffect(Resource::EffectParam* effectParam, const EffectInstanceParam& instanceParam, bool unkParam6, int unkParam7, float unkParam8) override;
        virtual int UnkFunc2(const char* unkParam1, void* unkParam2) override;
        virtual int DestroyEffect(const EffectHandle& effectHandle) override;
        virtual int Initialize(const Graphics::DeviceContainer& deviceContainer) override;
        virtual void SetDeviceContainer(const Graphics::DeviceContainer& deviceContainer) override;
        virtual void UnkFunc6(void* unkParam1) override;
        virtual void* UnkFunc7() const override;
        virtual void* UnkFunc8() const override;
        virtual void* UnkFunc9() const override;
        virtual void BeginProcess(float unkParam1, unsigned int someType, bool unkParam2) override;
        virtual void EndProcess() override;
        virtual bool IsFinishedProcess() const override;
        virtual void Update() override;
        virtual void UnkFunc14() override;
        virtual void UnkFunc15() override;
        virtual bool UnkFunc16() const override;
        virtual void UnkFunc17(bool unkParam1) override;
        virtual void UnkFunc18() override;
        virtual void PrepareRender(Graphics::DeviceContainer& deviceContainer) override;
        virtual void Render(Graphics::DeviceContainer& deviceContainer) override;
        virtual void PostRender(Graphics::DeviceContainer& deviceContainer) override;
        virtual bool IsReadyRender() const override;
        virtual int UnkFunc23(void* unkParam1, unsigned int sceneIdx, int unkParam3, int unkParam4, int unkParam5, void* unkParam6) override;
        virtual bool UnkFunc24(unsigned int unkParam1, int unkParam2, int unkParam3, int unkParam4, int unkParam5) override;
        virtual bool SetViewProjection(unsigned int cameraIdx, const float* viewMatrix, const float* projMatrix, float unkParam4, float unkParam5) override;
        virtual void SetGammaCorrect(unsigned int sceneIdx, bool enabled) override;
        virtual void SetGammaCorrect2(unsigned int sceneIdx, bool enabled) override;
        virtual void UnkFunc28(unsigned int cameraIdx, float unkParam1, float unkParam2) override;
        virtual void StopAll() override;
        virtual void Pause() override;
        virtual void Resume() override;
        virtual void Step() override;
        virtual void Sleep() override;
        virtual void Wake() override;
        virtual void SetWorldScale(float scale) override;
        virtual void SetDirectionalLight(const float* unkParam1, const float* unkParam2) override;
        virtual void GetDirectionalLight(float* unkParam1, float* unkParam2) const override;
        virtual void SetSceneParameter (const SceneParameter& sceneParameter) override;
        virtual SceneParameter& GetSceneParameter() const override;
        virtual SceneParameter& GetSceneParameter2() const override;
        virtual void SetDropPriority(char priority) override;
        virtual char GetDropPriority() const override;
        virtual bool IsSleeping() const override;
        virtual void SetNotifyCallback(NotifyCallback* notifyCallback, void* userData) override;
        virtual void ResetNotifyCallback() override;
        virtual void Bind(Resource::EffectParam* effectParam) override;
        virtual void SetNodeAnimRequestResourceHandler(RequestResourceHandler<Resource::NodeAnim>* handler, void* userData) override;
        virtual void SetSkeletonRequestResourceHandler(RequestResourceHandler<Resource::Skeleton>* handler, void* userData) override;
        virtual void SetModelRequestResourceHandler(RequestResourceHandler<Resource::Model>* handler, void* userData) override;
        virtual void SetEffectRequestResourceHandler(RequestResourceHandler<Resource::Effect>* handler, void* userData) override;
        virtual void SetComputeShaderRequestResourceHandler(RequestResourceHandler<Resource::ComputeShader>* handler, void* userData) override;
        virtual void SetShaderRequestResourceHandler(RequestResourceHandler<Resource::Shader>* handler, void* userData) override;
        virtual void SetTextureRequestResourceHandler(RequestResourceHandler<Resource::Texture>* handler, void* userData) override;
        virtual void UnkFunc53(void* handler, void* userData) override;
        virtual void SetUpdateLightHandler(void* handler, void* userData) override;
        virtual void UnkFunc55(void* handler, void* userData) override;
        virtual void UnkFunc56(void* handler, void* userData) override;
        virtual void UnkFunc56b(void* handler, size_t unkParam2) override;
        virtual void UnkFunc57(void* handler, size_t unkParam2) override;
        virtual System::IAllocator* GetRenderAllocator() const override;
        virtual void UnkFunc59() override;
        virtual void UnkFunc60() override;
        virtual void UnkFunc61() override;
        virtual void UnkFunc62() override;
        virtual int UnkFunc63() const override;
        virtual void UnkFunc64() override;
        virtual ~ManagerImpl();
        virtual void UnkFunc65() override;

        void UpdateEffect();
        EffectHandle CreateEffect(Resource::EffectParam* effectParam, const EffectInstanceParam& instanceParam, const InheritChildParam* inheritChildParam, EffectImpl* parent, bool unkParam6, int unkParam7, float unkParam8);
        Element* CreateElement(const Resource::ElementParam* elementParam);
        Emitter* CreateEmitter(EffectImpl* effect, const Resource::EmitterParam* emitterParam, const InheritChildParam* inheritChildParam, float unkParam1);
        bool UpdateLight(UpdateLightParam& param);
        Graphics::MeshRenderer& GetMeshRenderer();
        void DestroyElement(Element* element);

        void* RenderAlloc(unsigned int size, unsigned int unk);
        void RenderFree(void* ptr);

        Camera& GetCamera(unsigned int viewportId);
        Camera& GetCamera2(unsigned int viewportId);

        template<typename T> void RequestResource(EffectImpl* effect, Resource::ResObject<T>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::Texture>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::Effect>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::Model>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::NodeAnim>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::Skeleton>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::Shader>* resource);
        template<> void RequestResource(EffectImpl* effect, Resource::ResObject<Resource::ComputeShader>* resource);
    };
}
