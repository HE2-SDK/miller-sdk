#pragma once


#define NEEDLE_RESOURCE_DX11_BUFFER_TEXTURE_2D     0x3254465542313144ui64 // '2TFUB11D'

#define NEEDLE_RESOURCE_DX11_TEXTURE_VIEW          0x3056585431315844ui64 // '0VXT11XD'
#define NEEDLE_RESOURCE_DX11_VIEW_TEXTURE_2D       0x3258545756313144ui64 // '2XTWV11D'

#define NEEDLE_RESOURCE_DX11_RENDER_TARGET_VIEW    0x3056545231315844ui64 // '0VTR11XD'
#define NEEDLE_RESOURCE_DX11_VIEW_RENDER_TARGET    0x3054525756313144ui64 // '0TRWV11D'

#define NEEDLE_RESOURCE_DX11_UNORDERED_ACCESS_VIEW 0x3056415531315844ui64 // '0VAU11XD'
#define NEEDLE_RESOURCE_DX11_VIEW_UNORDERED_ACCESS 0x3041555756313144ui64 // '0AUWV11D'

#define NEEDLE_RESOURCE_DX11_DEPTH_STENCIL_VIEW    0x3056534431315844ui64 // '0VSD11XD'
#define NEEDLE_RESOURCE_DX11_VIEW_DEPTH_STENCIL    0x3053445756313144ui64 // '0SDWV11D'

namespace hh::needle::ImplDX11 {
    class SBufferTexture2D {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_BUFFER_TEXTURE_2D;
        ID3D11Texture2D* buffer;
    };

    class SViewTexture2D {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_VIEW_TEXTURE_2D;
        ID3D11ShaderResourceView* view;
    };

    class SViewRenderTarget {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_VIEW_RENDER_TARGET;
        ID3D11RenderTargetView* view;
    };

    class SViewUnorderedAccess {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_VIEW_UNORDERED_ACCESS;
        ID3D11UnorderedAccessView* view;
    };

    class SViewDepthStencil {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_VIEW_DEPTH_STENCIL;
        ID3D11DepthStencilView* view;
    };

    template<typename TextureBuffer, typename TextureView, size_t MyResourceId>
    class TextureDX11Impl {
        TextureBuffer buffer;
        TextureView view;
        char unk1[0x30];
        void* textureStreamingImpl;
        uint32_t unk3;

    public:
        static constexpr size_t resourceId = MyResourceId;

        virtual ~TextureDX11Impl();

        void* QueryResource(size_t id);
        //     switch (id) {
        //         case resourceId: return this;
        //         case TextureBuffer::resourceId: return &buffer;
        //         case TextureView::resourceId: return &view;
        //         default: return nullptr;
        //     }
        // }

        const void* QueryResource(size_t id) const;
        //     switch (id) {
        //         case resourceId: return this;
        //         case TextureBuffer::resourceId: return &buffer;
        //         case TextureView::resourceId: return &view;
        //         default: return nullptr;
        //     }
        // }
    };

    // I think these actually end in Impl, like TextureImpl etc.
    typedef NeedleResourceContainer<Texture, TextureDX11Impl<SBufferTexture2D, SViewTexture2D, NEEDLE_RESOURCE_DX11_TEXTURE_VIEW>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeSupport> Texture2DView;
    typedef NeedleResourceContainer<RenderTarget, TextureDX11Impl<SBufferTexture2D, SViewRenderTarget, NEEDLE_RESOURCE_DX11_RENDER_TARGET_VIEW>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> RenderTargetView;
    typedef NeedleResourceContainer<UnorderedAccessView, TextureDX11Impl<SBufferTexture2D, SViewUnorderedAccess, NEEDLE_RESOURCE_DX11_UNORDERED_ACCESS_VIEW>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> UnorderedAccessView;
    typedef NeedleResourceContainer<DepthStencil, TextureDX11Impl<SBufferTexture2D, SViewDepthStencil, NEEDLE_RESOURCE_DX11_DEPTH_STENCIL_VIEW>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> DepthStencilView;
}
