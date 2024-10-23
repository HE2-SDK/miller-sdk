#pragma once

namespace hh::game {
    class WorldObjectStatus {
    public:
        // This is all very speculative
        enum class Flag : uint8_t {
            ENABLED,
            IS_ALIVE,
            SHUTDOWN,
            NO_RESTART,
        };

        ObjectData* objectData;
        csl::ut::Bitset<Flag> flags;
        uint32_t state;
        int spawnPriority;
        virtual ~WorldObjectStatus() = default;

        inline void Shutdown() {
            return flags.set(Flag::SHUTDOWN);
        }

        inline bool IsShutdown() {
            return flags.test(Flag::SHUTDOWN);
        }

        inline bool IsNoRestart() {
            return flags.test(Flag::NO_RESTART);
        }

        inline void Restart() {
            flags.reset(Flag::SHUTDOWN);
        }

        uint16_t GetObjectState(unsigned int stateId);
        void SetObjectState(unsigned int stateId, uint16_t state);
    };
}
