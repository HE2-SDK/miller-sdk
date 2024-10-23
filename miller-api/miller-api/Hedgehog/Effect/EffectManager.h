#pragma once

namespace hh::eff {
    class EffectHandle {
    public:
        int unk1;
        void* unk2;
        EffectHandle();
        EffectHandle(const EffectHandle& other);

        const csl::math::Vector3& GetScale() const;
        const csl::ut::Color8& GetColor() const;
        uint8_t GetAlpha() const;

        void SetScale(const csl::math::Vector3& scale);
        void SetColor(const csl::ut::Color8& color);
        void SetAlpha(uint8_t alpha);
    };

    class EffectManager : public game::GameService, public game::GameStepListener, public game::GameUpdateListener {
    public:
        struct RenderableInfo {
            unsigned int renderPass;
            unsigned int unk1;
        };

        struct SetupInfo {
            unsigned int cyanSystemSize;
            unsigned int cyanRenderSize;
            unsigned int cyanTagSize;
            unsigned int cyanEffectSize;
            unsigned int cyanEmitterSize;
            unsigned int cyanElementSize;
            unsigned int cyanAnimationSize;
            unsigned int cyanMeshRenderSize;
            unsigned int cyanDebugSize;
            unsigned int renderWidth;
            unsigned int renderHeight;
            unsigned int numRenderables;
            RenderableInfo* renderables;
            unsigned int (*unk1)(uint8_t unkParam);
            unsigned int (*unk2)(unsigned int unkParam);
        };

        class Impl {
        public:
            class ResourceListener : public fnd::ResourceManager::ResourceListener {
                Impl* effectManagerImpl;

            public:
                virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;
            };

            class CyanAllocator : public Cyan::System::IAllocator {
            public:
                void* unk1;
                csl::fnd::IAllocator* allocator;
                uint16_t word170;
                csl::fnd::Mutex mutex;

                virtual void* Alloc(size_t size, size_t alignment) override;
                virtual void* Alloc2(size_t size, size_t alignment) override;
                virtual void Free(void* ptr) override;
                virtual void UnkFunc4() override {}
                virtual void SetUnk1(void* unkParam1) override;
                virtual void* GetUnk1() const override;
                virtual void* Alloc3(size_t size, size_t alignment);
                virtual void* Alloc4(size_t size, size_t alignment);
            };

            struct Unk1 {
                struct Unk2 {
                    uint64_t unk1;
                    uint64_t unk2;
                    uint64_t unk3;
                    int unk4;

                    // Unk2();
                };

                uint64_t unk1;
                uint64_t unk2;
                uint32_t unk3;
                char pad4[0x2000];
                Unk2 unk5[8];
            };

            rsdx::SJobJoint* jobJoint1;
            rsdx::SJobJoint* jobJoint2;
            rsdx::SJobJoint* jobJoint3;
            rsdx::SJobJoint* jobJoint4;
            rsdx::SJobJoint* jobJoint5;
            csl::fnd::IAllocator* allocator;
            Cyan::Manager* cyanManager;
            csl::ut::MoveArray<void*> unk2;
            uint64_t unk3;
            uint32_t unk4;
            float unk5;
            uint8_t gap68[16];
            float dword78;
            ResourceListener resourceListener1;
            ResourceListener resourceListener2;
            csl::ut::MoveArray<void*> unkA0;
            uint16_t wordC0;
            csl::fnd::IAllocator* unkAllocator;
            uint32_t dwordD0;
            Unk1* unkD8;
            uint32_t dwordE0;
            csl::ut::PointerMap<void*, void*>* unkE8;
            csl::fnd::IAllocator* unkAllocator2;
            CyanRenderHandler cyanRenderHandler;
            CyanAllocator cyanAllocator;

            CREATE_FUNC(Impl, const SetupInfo& setupInfo);
        };

        class Listener {
        public:
            virtual void UnkFunc1() {}
            virtual void UnkFunc2() {}
            virtual void UnkFunc3() {}
        };

        class Resolver : public fnd::ResourceResolver {
        public:
            EffectManager* effMgr;
            csl::ut::VariableString unk1;
            virtual fnd::ManagedResource* Resolve(csl::fnd::IAllocator* allocator, const char* name, const fnd::ResourceTypeInfo* typeInfo);
        };

        Impl* implementation;
        Listener listener;
        Resolver resolver;
        csl::ut::MoveArray<void*> unk2;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
		virtual void PostGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;

        void Setup(const SetupInfo& setupInfo);
        EffectHandle CreateEffect(char const* resourceName, const csl::math::Matrix34& location, const game::GameObject* object, unsigned int layer, uint32_t unkParam1, uint32_t unkParam2, float unkParam3, void* node);

        GAMESERVICE_CLASS_DECLARATION(EffectManager)
    };
}
