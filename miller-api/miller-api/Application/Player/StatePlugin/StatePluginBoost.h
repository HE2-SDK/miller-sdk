#pragma once

namespace app::player {
    class StatePluginBoost : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginBoost";
        void SetNitroMode();
        void SetBoostType(uint8_t type);
        void SetUnk1(uint8_t type);
    };
}
