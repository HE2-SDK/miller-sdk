#pragma once

namespace hh::font {
    class FontContainerListener {
    public:
        virtual ~FontContainerListener() = default;
        virtual void FCL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) {}
        virtual void FCL_UnkFunc2() {}
        virtual void FCL_UnkFunc3() {}
    };

    class FontContainer : public hh::fnd::ReferencedObject {

    };
}
