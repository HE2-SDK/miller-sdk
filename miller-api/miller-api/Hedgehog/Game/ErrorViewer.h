#pragma once

namespace hh::game {
    class ErrorViewerListener {
    public:
        virtual ~ErrorViewerListener() = default;
        virtual void EVL_UnkFunc1() {}
        virtual void EVL_UnkFunc2(int unkParam1, int unkParam2, int& unkParam3) {}
    };
}
