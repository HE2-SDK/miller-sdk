#pragma once

namespace hh::needle {
    template<typename T>
    class TNeedleRefcountUniqueObjectBase : public T {
        EntryLink entryLink;
        uint32_t hash;
        uint32_t tnruoUnk4;
    public:
    };
}
