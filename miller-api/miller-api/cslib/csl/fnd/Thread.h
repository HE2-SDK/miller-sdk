#pragma once

namespace csl::fnd{
    typedef int ThreadExecFunc(void* userData);

    class Thread {
    public:
        HANDLE threadHandle;
        ThreadExecFunc* threadExecFunc;
        void* threadOwner;
        bool unhandled;
        IAllocator* allocator;
        int64_t unk;

        void Create(
            unsigned int stackSize,
            ThreadExecFunc* execFunc,
            void* owner,
            int priority,
            int processor,
            const char* name
        );
        char Exit(); // Returns exit code
        ~Thread();
    };
}
