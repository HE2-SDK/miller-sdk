#pragma once

namespace app::game {
    class MsgNotifyLevelStatus : public hh::fnd::Message {
    public:
        uint32_t status;
        uint16_t unk1;
        uint8_t unk2;
    };

    // Recipients: Game
    class MsgChangeLayerTimeScale : public app::fnd::AppMessage<MsgChangeLayerTimeScale> {
    public:
        char interpolatorId[16];
        float timeScale;
        uint32_t layerMask;
        uint32_t unk1{};
        bool unk2{};

        inline MsgChangeLayerTimeScale(const char* interpolatorId, uint32_t layerMask, float timeScale) : fnd::AppMessage<MsgChangeLayerTimeScale>{ hh::fnd::MessageID::CHANGE_LAYER_TIME_SCALE }, layerMask{ layerMask }, timeScale{ timeScale } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgChangeGlobalTimeScale : public app::fnd::AppMessage<MsgChangeGlobalTimeScale> {
    public:
        char interpolatorId[16];
        float timeScale;
        uint32_t unk1{};

        inline MsgChangeGlobalTimeScale(const char* interpolatorId, float timeScale) : fnd::AppMessage<MsgChangeGlobalTimeScale>{ hh::fnd::MessageID::CHANGE_GLOBAL_TIME_SCALE }, timeScale{ timeScale } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgRevertLayerTimeScale : public app::fnd::AppMessage<MsgRevertLayerTimeScale> {
    public:
        char interpolatorId[16];
        uint32_t layerMask;
        int unk2{};

        inline MsgRevertLayerTimeScale(const char* interpolatorId, uint32_t layerMask) : fnd::AppMessage<MsgRevertLayerTimeScale>{ hh::fnd::MessageID::REVERT_LAYER_TIME_SCALE }, layerMask{ layerMask } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgRevertGlobalTimeScale : public app::fnd::AppMessage<MsgRevertGlobalTimeScale> {
    public:
        char interpolatorId[16];
        int unk2{};

        inline MsgRevertGlobalTimeScale(const char* interpolatorId) : fnd::AppMessage<MsgRevertGlobalTimeScale>{ hh::fnd::MessageID::REVERT_GLOBAL_TIME_SCALE } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };
}
