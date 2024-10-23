#pragma once

namespace hh::fnd {
    class CollectionBase : public BaseObject {
        csl::ut::MoveArray<void*> array;
        csl::ut::StringMap<void*> map;
    };

    template <typename T>
    class CollectionTemplate : public CollectionBase {
    };
}