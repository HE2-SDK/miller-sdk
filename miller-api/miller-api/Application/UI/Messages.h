#pragma once

namespace app::ui {
    class MsgUISetGameCockpitVisibility : public fnd::AppMessage<MsgUISetGameCockpitVisibility> {
    public:
        size_t uiMask;
        bool visible;

        MsgUISetGameCockpitVisibility(size_t uiMask, bool visible) : fnd::AppMessage<MsgUISetGameCockpitVisibility>{ hh::fnd::MessageID::UI_SET_GAME_COCKPIT_VISIBILITY }, uiMask{ uiMask }, visible{ visible } {}
    };

    class MsgUISetGameCockpitEnableRender : public fnd::AppMessage<MsgUISetGameCockpitEnableRender> {
    public:
        bool enabled;

        MsgUISetGameCockpitEnableRender(bool enabled) : fnd::AppMessage<MsgUISetGameCockpitEnableRender>{ hh::fnd::MessageID::UI_SET_GAME_COCKPIT_ENABLE_RENDER }, enabled{ enabled } {}
    };
}
