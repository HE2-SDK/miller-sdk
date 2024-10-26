#pragma once

namespace app::player {
    class Player;
    class GOCPlayerHsm;
    class GOCPlayerPosture;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class BlackboardItem;
    class PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener {
        class OutOfControlTimerList : public PlayerCounterTimer {
            PlayerHsmContext* pPlayerHsmContext;
        public:
            OutOfControlTimerList(csl::fnd::IAllocator* pAllocator);
        };

        class DamagedObjects : public hh::fnd::BaseObject {
            csl::ut::MoveArray<void*> objects;
        public:
            DamagedObjects(csl::fnd::IAllocator* pAllocator);
        };

    public:
        Player* playerObject;
        BlackboardStatus* blackboardStatus;
        BlackboardItem* blackboardItem;
        GOCPlayerHsm* gocPlayerHsm;
        GOCPlayerPosture* gocPlayerPosture;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        csl::ut::MoveArray<void*> unk8;
        OutOfControlTimerList* pOutOfControlTimerList;
        DamagedObjects* pDamagedObjects;

        PlayerHsmContext(csl::fnd::IAllocator* pAllocator);
        ~PlayerHsmContext();

        void Setup(GOCPlayerHsm* gocPlayerHsm);
    };
}
