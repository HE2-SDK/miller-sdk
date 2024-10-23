#pragma once

namespace hh::gfx {
    class RenderingComponent : public fnd::ReferencedObject {
        uint32_t flags; // flag 1 (i.e. value 2) = UnkFunc3 will be called when UnkFunc8 is called on the render engine
    public:
        RenderingComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
        virtual void UnkFunc3() = 0;
        virtual int UnkFunc4() = 0;
        virtual const char* GetName() = 0;
    };
}
