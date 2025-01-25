#pragma once

namespace app::player {
    class MsgAddNotifyPreDeadListener : public fnd::AppMessage<MsgAddNotifyPreDeadListener> {
    public:
        MsgAddNotifyPreDeadListener() : fnd::AppMessage<MsgAddNotifyPreDeadListener>{ hh::fnd::MessageID::ADD_NOTIFY_PRE_DEAD_LISTENER } {}
    };

    class MsgReplayCommand : public fnd::AppMessageCustom<MsgReplayCommand> {
    public:
        enum class Command {
            TOGGLE_PLAYBACK,
            TOGGLE_RECORDING,
            TOGGLE_PLAYBACK_2,
            TOGGLE_PLAYBACK_SPEED,
            TOGGLE_REPLAY_CAMERA,
            LOAD,
            SAVE,
        };

        Command command{};

        MsgReplayCommand(Command command) : fnd::AppMessageCustom<MsgReplayCommand>{ hh::fnd::MessageID::REPLAY_COMMAND }, command{ command } {}
    };
}
