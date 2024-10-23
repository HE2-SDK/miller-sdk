#pragma once

namespace hh::fnd {
    class LogData {
        csl::ut::MoveArray<void*> data;

    public:
        void Clean();
    };
}
