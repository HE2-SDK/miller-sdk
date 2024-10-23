#pragma once

namespace hh::path {
    class PathCollisionHandler : public fnd::ReferencedObject {
    public:
        PathCollisionHandler(csl::fnd::IAllocator* allocator);

        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;
        virtual uint64_t UnkFunc9() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual uint64_t UnkFunc13() = 0;
    };

    // class PathCollisionHandlerStandard : public PathCollisionHandler {
    // public:
    //     csl::fnd::PoolHeapTemplate<csl::fnd::DummyLock> heap;

    //     PathCollisionHandlerStandard(csl::fnd::IAllocator* allocator);

    //     virtual uint64_t UnkFunc1() override;
    //     virtual uint64_t UnkFunc2() override;
    //     virtual uint64_t UnkFunc3() override;
    //     virtual uint64_t UnkFunc4() override;
    //     virtual uint64_t UnkFunc5() override;
    //     virtual uint64_t UnkFunc6() override;
    //     virtual uint64_t UnkFunc7() override;
    //     virtual uint64_t UnkFunc8() override;
    //     virtual uint64_t UnkFunc9() override;
    //     virtual uint64_t UnkFunc10() override;
    //     virtual uint64_t UnkFunc11() override;
    //     virtual uint64_t UnkFunc12() override;
    //     virtual uint64_t UnkFunc13() override;
    // };
}
