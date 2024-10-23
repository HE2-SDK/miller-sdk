#pragma once

namespace hh::gfnd {
    class SharedDebugDrawResourceNeedle : public SharedDebugDrawResource {
        void* unk[2];
        static SharedDebugDrawResourceNeedle* MyCreate(csl::fnd::IAllocator* allocator);
    public:
        SharedDebugDrawResourceNeedle(csl::fnd::IAllocator* allocator);
    };
}
