#pragma once

namespace app::game {
    class MsgNotifyAction : public fnd::AppMessage<MsgNotifyAction> {
    public:
        char action;
    };
}