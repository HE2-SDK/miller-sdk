#pragma once

namespace hh::ui {
    class UIListener {
    public:
        virtual ~UIListener();
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
        virtual void UnkFunc3() = 0;
    };
}
