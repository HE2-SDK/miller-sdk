#pragma once

namespace app::player {
    class BlackboardStatus : public BlackboardContent {
    public:
        enum class StateFlag : unsigned int
        {
            BOOST = 0x00,
            AIR_BOOST = 0x03,
            QUICK_STEP = 0x04,
            GRIND_STEP = 0x05,
            GRIND_JUMP = 0x06,
            GRIND = 0x07,
            JUMP = 0x08,
            DOUBLE_JUMP = 0x09,
            BOUNCE_JUMP = 0x0A,
            FALL = 0x0B,
            STOMP = 0x0C,
            DIVING = 0x0D,
            DIVING_BOOST = 0x0E,
            CURVE_MOVE = 0x0F,
            DRIFT = 0x11,
            DRIFT_DASH = 0x12,
            HOMING = 0x13, // jumpdash
            TURN = 0x16,
            SEVENTEEN = 0x17,
            STAND_ROOT_AFK = 0x18,
            WALL_CLIMB = 0x19,
            IDLE = 0x1A,
            BOARDING = 0x1B,
            WALL_CLIMB_IDLE = 0x1C,
            BOARDINGTWO = 0x1E,
            SLIDER = 0x20,
            D_SURF = 0x21,
            CHAOS_SPEAR = 0x22,
            D_AMOEBA = 0x23,
            D_AMOBEA_RELATED = 0x24,
            D_BLOW_OFF = 0x25,
            D_BLOW_OFF_2nd = 0x26,
            D_BLOW_DOWN = 0x27,
            D_BLOW_UP = 0x29,
            WARP_ATTACK = 0x2A,
            RUN_ON_WATER = 0x2E,
            DAMAGE_RUNNING = 0x31,
        };
        enum class CombatFlag : unsigned int
        {
            JUMP = 0x00,
            DOUBLE_JUMP = 0x01, // turning off double jump allows to do jump dash
            BOOST = 0x02,
            AIR_BOOST = 0x03,
            HOMING_ATTACK = 0x04,
            SIDE_STEP = 0x05,
            SLALOM_STEP = 0x06,
            CROUCH = 0x0D,
            STOMP = 0x0E,
            SLIDE = 0x10,
            BRAKE = 0x11,
            DROP_DASH = 0x19,
            WALLJUMP = 0x1A,
            BOARDING = 0x1B, // Frontiers skateboarding
            CAMERA_MOVEMENT = 0x20,
            MOVEMENT = 0x21,
		    WALL_JUMP_LAND = 0x22,
            RAIL_GRINDING = 0x2A,
            CYBER_CORRUPTION_CHAOS = 0x30, // Frontiers leftover
            CYBER_CORRUPTOIN_RHEA = 0x31,  // Frontiers leftover
            DOOM_BLAST = 0x32,
            DOOM_SURF = 0x33,
            DOOM_MORPH = 0x34,
            DOOM_WINGS = 0x35,
            DOOM_SPEARS = 0x36,
        };
        enum class WorldFlag : unsigned int
        {
            KILLED = 0x01,
            DAMAGED_OR_REPELLED = 0x02,
            OUT_OF_CONTROL = 0x07,
            AUTO_RUN = 0x0A,
            BRAKEMaybe=0x13,
            BATTLE = 0x14,
            CYBER_SPACE = 0x1E,
            AIR_TRICK = 0x2A,
            GRIND = 0x33,
            HEIGHT_MAP_COLLISION = 0x37,
            DOOM_WINGS = 0x38,
            aBATTLE = 0x3A,
            THREE_C = 0x3C,
            NITRO_BOOST = 0x43,
            MAX_SPEED_CHALLENGE = 0x44,
        };
        
        enum class Dimension : unsigned int {

        };

        struct Description {
            char playerId;
            float unk8;
        };

        static constexpr const char* name = "BlackboardStatus";
        char playerId;
        uint32_t dword24;
        uint32_t dword28; // equals to 3 if Movie Shadow
        csl::ut::Bitset<CombatFlag, uint64_t> combatFlags;
        csl::ut::Bitset<StateFlag, uint64_t> stateFlags;
        csl::ut::Bitset<WorldFlag, uint64_t> worldFlags;
        float float48;
        uint32_t dword4C;
        float outOfControlTime;
        float inControlTime;
        float float58;
        uint32_t dword5C;
        uint64_t qword60;
        ut::PriorityList<bool, hh::fnd::Handle<hh::fnd::Messenger>> qword68;
        csl::ut::InplaceMoveArray<uint32_t, 4> qword90;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordC0;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordF0;
        uint32_t qword120;
        uint32_t dword124;
        ut::PriorityList<Dimension, hh::fnd::Handle<hh::fnd::Messenger>> qword128;
        csl::math::Vector4 oword150;
        uint64_t qword160;
        uint8_t word168;
        uint8_t word169;
        uint8_t byte16A;
        uint32_t dword16C;

        virtual unsigned int GetNameHash() const override;


        void SetCombatFlag(CombatFlag combatFlag, bool enabled);
        void SetStateFlag(StateFlag stateFlag, bool enabled);
        void SetWorldFlag(WorldFlag worldFlag, bool enabled);
        bool GetCombatFlag(CombatFlag combatFlag);
        bool GetStateFlag(StateFlag stateFlag);
        bool GetWorldFlag(WorldFlag worldFlag);

        void Setup(const Description& desc);

        DEFAULT_CREATE_FUNC(BlackboardStatus);
    };
}
