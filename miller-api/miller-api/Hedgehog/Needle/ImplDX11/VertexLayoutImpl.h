#pragma once

#define NEEDLE_RESOURCE_DX11_VERTEX_LAYOUT_OBJECT  0x304F4C5631315844ui64 // '0OLV11XD'

namespace hh::needle::ImplDX11 {
    template<size_t MyResourceId>
    class VertexLayoutDX11Impl {
        uint32_t index;
        SInputElement* inputElement;
        char debugObjectName[256];
    public:
        virtual ~VertexLayoutDX11Impl();
    };

    class VertexLayoutImpl : public NeedleResourceContainer<hh::needle::VertexLayout, VertexLayoutDX11Impl<NEEDLE_RESOURCE_DX11_VERTEX_LAYOUT_OBJECT>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> {
    public:
        virtual void SetDebugObjectName(char const* name) override;
        virtual uint64_t GetInputElementCount() const override;
        virtual uint64_t GetInputElement() const override;
    };

    class VertexLayoutImplKey : public VertexLayoutImpl {
    };
}
