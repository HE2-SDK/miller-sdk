#pragma once

namespace app::player {
    class BlackboardStatus : public BlackboardContent {
    public:
        enum class StateFlag : unsigned int
        {
            BOOST = 0x00,
            AIR_BOOST = 0x04,
            GRIND_JUMP = 0x06,
            GRIND = 0x07,
            JUMP = 0x08,
            DOUBLE_JUMP = 0x09,
            BOUNCE_JUMP = 0x0A,
            FALL = 0x0B,
            STOMP = 0x0C,
            DIVING = 0x0D,
            DIVING_BOOST = 0x0E,
            CYLOOP = 0x11,
            CYLOOP_END = 0x12,
            DRIFT = 0x13,
            HOMING = 0x17,
            PARRY = 0x18,
            WALL_CLIMB = 0x19,
            IDLE = 0x1A,
            WALL_CLIMB_IDLE = 0x1C,
            BOARDING = 0x1E,
            SPRING_JUMP = 0x21,
            SPIN_DASH = 0x22,
        };

        enum class CombatFlag : unsigned int
        {
            SIDE_STEP = 0x05,
            PARRY = 0x0F,
            PERFECT_PARRY = 0x10,
            AIR_TRICK = 0x1A,
            GRAND_SLAM = 0x22,
            QUICK_CYLOOP = 0x28,
            PHANTOM_RUSH = 0x2A,
            CYCLONE_KICK = 0x2B,
            RECOVERY_SMASH = 0x2C,
            SONIC_BOOM = 0x2E,
            WILD_RUSH = 0x2F,
            LOOP_KICK = 0x30,
            SPIN_SLASH = 0x31,
            STOMP_ATTACK = 0x32,
            HOMING_SHOT = 0x34,
            CROSS_SLASH = 0x35,
            AUTO_COMBO = 0x39,
            SPIN_DASH = 0x3F,
        };

        enum class WorldFlag : unsigned int
        {
            KILLED = 0x01,
            DAMAGED_OR_REPELLED = 0x02,
            OUT_OF_CONTROL = 0x07,
            AUTO_RUN = 0x0A,
            CYBER_SPACE = 0x1E,
            WALL_JUMP_LAND = 0x22,
            POWER_BOOST = 0x28,
            AIR_TRICK = 0x2A,
            HEIGHT_MAP_COLLISION = 0x37,
            NO_CLIP = 0x38,
            BATTLE = 0x3A,
            NITRO_BOOST = 0x43,
            MAX_SPEED_CHALLENGE = 0x44,
        };

        enum class Difficulty : uint8_t
        {
            EASY = 0x00,
            NORMAL = 0x01,
            HARD = 0x02,
            EXTREME = 0x03,
        };

        enum class Dimension : unsigned int {

        };

        static constexpr const char* name = "BlackboardStatus";
        uint16_t word20;
        uint32_t dword24;
        csl::ut::Bitset<CombatFlag, uint64_t> combatFlags[2];
        csl::ut::Bitset<StateFlag, uint64_t> stateFlags;
        csl::ut::Bitset<WorldFlag, uint64_t> worldFlags[2];
        float outOfControlTime;
        float inControlTime;
        uint64_t qword58;
        uint64_t qword60;
        ut::PriorityList<bool, hh::fnd::Handle<hh::fnd::Messenger>> qword68;
        csl::ut::InplaceMoveArray<uint32_t, 4> qword90;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordC0;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordF0;
        uint64_t qword120;
        uint32_t dword128;
        ut::PriorityList<Dimension, hh::fnd::Handle<hh::fnd::Messenger>> qword130;
        csl::math::Vector4 oword160;
        uint32_t dword170;
        uint32_t qword174;
        uint32_t qword178;
        uint32_t dword17C;
        Difficulty byte180;
        uint32_t qword184;
        uint32_t qword188;

        virtual unsigned int GetNameHash() const override;

        void SetCombatFlag(CombatFlag combatFlag, bool enabled);
        void SetStateFlag(StateFlag stateFlag, bool enabled);
        void SetWorldFlag(WorldFlag worldFlag, bool enabled);
        bool GetCombatFlag(CombatFlag combatFlag);
        bool GetStateFlag(StateFlag stateFlag);
        bool GetWorldFlag(WorldFlag worldFlag);

        DEFAULT_CREATE_FUNC(BlackboardStatus);
    };
}
