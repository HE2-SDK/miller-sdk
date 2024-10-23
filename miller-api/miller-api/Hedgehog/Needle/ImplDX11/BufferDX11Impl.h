#pragma once

#define NEEDLE_RESOURCE_DX11_BUFFER_OBJECT_X        0x30584A4F46554244ui64 // '0XJOFUBD'

#define NEEDLE_RESOURCE_DX11_CONSTANT_BUFFER_OBJECT 0x3254465542313144ui64 // '0OBC11XD'
#define NEEDLE_RESOURCE_DX11_VERTEX_BUFFER_OBJECT   0x304f425631315844ui64 // '0OBV11XD'

namespace hh::needle::ImplDX11 {
    class SBufferObject {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_DX11_BUFFER_OBJECT_X;
        ID3D11Buffer* buffer;
    };

    template<typename BufferObject, size_t MyResourceId>
    class BufferDX11Impl {
        BufferObject buffer;

    public:
        static constexpr size_t resourceId = MyResourceId;

        virtual ~BufferDX11Impl();

        void* QueryResource(size_t id);
        //     switch (id) {
        //         case resourceId: return this;
        //         case BufferObject::resourceId: return &buffer;
        //         default: return nullptr;
        //     }
        // }

        const void* QueryResource(size_t id) const;
        //     switch (id) {
        //         case resourceId: return this;
        //         case BufferObject::resourceId: return &buffer;
        //         default: return nullptr;
        //     }
        // }
    };

    typedef NeedleResourceContainer<needle::ConstantBuffer, BufferDX11Impl<SBufferObject, NEEDLE_RESOURCE_DX11_CONSTANT_BUFFER_OBJECT>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> ConstantBuffer;
    typedef NeedleResourceContainer<Buffer, BufferDX11Impl<SBufferObject, NEEDLE_RESOURCE_DX11_VERTEX_BUFFER_OBJECT>, NEEDLE_RESOURCE_CONTAINER, SQueryTypeOwn, SDupTypeNotSupport> VertexBuffer;
}
