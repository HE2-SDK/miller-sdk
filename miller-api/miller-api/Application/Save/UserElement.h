#pragma once

namespace app::save {
    class UserElement : public hh::fnd::ReferencedObject {
    public:
        csl::fnd::Mutex mutex;
        uint64_t qword40;
        GameData gamedata50;
        GameData gamedataA8420;
        // OptionData optiondata1507F0;
        // OptionData optiondata150B80;
        // ArcadeData arcadedata150F10;
        // ArcadeData arcadedata15124C;
        // ChallengeData challengedata151588;
        // ChallengeData challengedata1531A0;
        csl::ut::MoveArray<void*> unk154DB8;
        csl::ut::MoveArray<void*> unk154DD8;
        csl::ut::MoveArray<void*> unk154DF8;
        csl::ut::MoveArray<void*> unk154E18;
        uint8_t byte154E38;

        UserElement(void* unkParam);
    };
}
