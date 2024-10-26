#pragma once

namespace app::player {
    class MsgAddNotifyPreDeadListener : public fnd::AppMessage<MsgAddNotifyPreDeadListener> {
    public:
        MsgAddNotifyPreDeadListener() : fnd::AppMessage<MsgAddNotifyPreDeadListener>{ hh::fnd::MessageID::ADD_NOTIFY_PRE_DEAD_LISTENER } {}
    };
}