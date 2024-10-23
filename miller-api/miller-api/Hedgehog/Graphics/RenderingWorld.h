#pragma once

namespace hh::gfx {
    class RenderingWorld : public fnd::ReferencedObject {
    public:
        RenderingWorld(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual uint64_t UnkFunc3();
        virtual uint64_t UnkFunc4();
        virtual void UnkFunc5() {}
    };
}
