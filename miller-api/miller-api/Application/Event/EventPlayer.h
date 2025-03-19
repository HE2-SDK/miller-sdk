#pragma once

namespace app::evt {
    class EventPlayerListener {
    public:
        virtual void EPL_UnkFunc1() {}
        virtual void EPL_UnkFunc2() {}
        virtual void EPL_UnkFunc3() {}
        virtual void EPL_UnkFunc4() {}
        virtual void EPL_UnkFunc5() {}
        virtual void EPL_UnkFunc6() {}
        virtual void EPL_UnkFunc7() {}
        virtual void EPL_UnkFunc8() {}
        virtual void EPL_UnkFunc9() {}
        virtual void EPL_UnkFunc10() {}
        virtual void EPL_UnkFunc11() {}
    };

    class EventPlayer {
    public:
        void AddListener(EventPlayerListener* listener);
        void RemoveListener(EventPlayerListener* listener);
    };
}
