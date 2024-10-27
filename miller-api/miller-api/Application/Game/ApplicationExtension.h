#pragma once

namespace app {
    class MyApplication;
}

namespace app::game {
    class ApplicationExtension
        : public hh::fnd::BaseObject
    {
        app::MyApplication* application;
    
    public:
        virtual uint64_t GetNameHash() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
    };
}
