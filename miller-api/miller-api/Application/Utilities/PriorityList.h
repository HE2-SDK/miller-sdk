#pragma once

namespace app::ut {
    template<typename P, typename T>
    class PriorityList {
    public:
        csl::ut::MoveArray<void*> underlying;

        virtual ~PriorityList() = default;
    };
}
