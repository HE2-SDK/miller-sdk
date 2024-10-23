#pragma once

namespace hh::gfx {
    class ResModelBase : public fnd::ManagedResource {
    public:
        csl::ut::MoveArray<void*> unk101;

        ResModelBase();

        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
    };
}
