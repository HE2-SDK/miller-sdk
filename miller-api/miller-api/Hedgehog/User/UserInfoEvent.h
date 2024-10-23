#pragma once

namespace hh::fnd::user {
    class UserInfoEventListener {
    public:
        virtual ~UserInfoEventListener() = default;
        virtual void UIEL_UnkFunc1() = 0;
    };
}
