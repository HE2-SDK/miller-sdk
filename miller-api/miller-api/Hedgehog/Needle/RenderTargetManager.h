#pragma once

namespace hh::needle {
    struct RenderTargetReference {
        enum class Type {
            NONE,
            INDEX,
            POINTER,
        };

        Type type;
        uint32_t index;
        intrusive_ptr<RenderTarget> pointer;

        RenderTargetReference(unsigned int index);
        RenderTargetReference(RenderTarget* renderTarget);
    };

    class RenderTargetManager : public NeedleObject {
    public:
        struct Unk1 {
            unsigned int unk1;
            bool unk2;
        };

        RenderingDeviceContext* renderingDeviceContext;
        RenderProperty* renderProperty;

        intrusive_ptr<RenderTarget> renderTargets[65]; // 17 = luminance
        intrusive_ptr<Texture> renderTargetViews[65];
        intrusive_ptr<RenderTarget> depthStencils[24];
        intrusive_ptr<Texture> depthStencilViews[24];
        uint64_t pad1;
        uint64_t pad2;
        intrusive_ptr<RenderTarget> unk6[4];
        intrusive_ptr<Texture> unk7[4];
        Unk1 unk8[4];

        int unk9;
        csl::ut::StringMap<void*> unk10;
        unsigned int renderResX;
        unsigned int renderResY;
        unsigned int resX;
        unsigned int resY;
        uint8_t unk10a; // set in RenderManager::InitializeMainRenderTarget
        uint32_t unk11;
        uint32_t unk11a;
        uint32_t unk12;
        uint32_t unk12a;
        uint32_t unk13;
        uint32_t unk13a;
        uint32_t unk14;
        uint32_t unk14a;
        uint8_t unk15;

        RenderTargetManager(unsigned int x, unsigned int y, unsigned int width, unsigned int height, RenderProperty* renderProperty, csl::fnd::IAllocator* allocator);
        virtual ~RenderTargetManager();

        void Initialize(RenderingDevice* renderingDevice, RenderingDeviceContext* renderingDeviceContext, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        void ClearDepthStencil(const RenderTargetReference& renderTargetReference, bool unkParam);
        unsigned int GetRenderTargetWidth(const RenderTargetReference& renderTargetReference) const;
        unsigned int GetRenderTargetHeight(const RenderTargetReference& renderTargetReference) const;
        unsigned int GetDepthStencilWidth(const RenderTargetReference& renderTargetReference) const;
        unsigned int GetDepthStencilHeight(const RenderTargetReference& renderTargetReference) const;
        RenderTarget* GetRenderTarget(const RenderTargetReference& renderTargetReference) const;
        Texture* GetRenderTargetView(const RenderTargetReference& renderTargetReference) const;
        RenderTarget* GetDepthStencil(const RenderTargetReference& renderTargetReference) const;
        Texture* GetDepthStencilView(const RenderTargetReference& renderTargetReference) const;
    };
}
