#pragma once

namespace app::player {
    class Player;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class PlayerSpeedParam;
    class PlayerExtraParam;
    class PlayerGrindSpeedParam;
    
    class PostureManager : hh::fnd::BaseObject {
        virtual void UnkFunc1();
        virtual void UnkFunc2();
    }

    class PostureMoveManager : PostureManager {

    }

    class PostureMoveManager : PostureManager {
        
    }

    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        Player* playerObject;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        BlackboardStatus* blackboardStatus;
        float dword30 { 360.0f };
        uint8_t byte34;
        // there is more




        PlayerPostureContext(csl::fnd::IAllocator* allocator, app::player::Player* playerObject);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}