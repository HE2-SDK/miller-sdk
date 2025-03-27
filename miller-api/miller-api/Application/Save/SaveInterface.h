#pragma once

namespace app::save {
    class SaveInterface : public hh::fw::SaveManagerInterface {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
        };

        hh::fnd::UserId userId;
        csl::ut::MoveArray<hh::fnd::Reference<UserElement>> userElements;
        uint32_t dword130;
        uint32_t dword134;
        uint32_t dword138;
        uint8_t byte13C;
        uint16_t word13E;
        uint32_t qword140;
        uint32_t qword144;
        uint8_t byte148;
        uint32_t dword14C[4];
        csl::ut::MoveArray<void*> unkE0;
        csl::ut::InplaceMoveArray<Unk1, 32> unk100;
        uint64_t qword320;
        uint8_t word328;
        uint32_t dword32C;
        uint64_t dword330[16];

        SaveInterface(csl::fnd::IAllocator* allocator);

        UserElement* AddUserElement(const hh::fnd::UserId& userId);

        GameDataAc GetGameDataAccessor();
        // ArcadeDataAc GetArcadeDataAccessor();
        // OptionAc GetOptionAccessor();
        // ChallengeDataAc GetChallengeDataAccessor();
    };

    GameDataAc GetGameDataAccessor(hh::game::GameManager* gameManager);
    // ArcadeDataAc GetArcadeDataAccessor(hh::game::GameManager* gameManager);
    // OptionAc GetOptionAccessor(hh::game::GameManager* gameManager);
    // ChallengeDataAc GetChallengeDataAccessor(hh::game::GameManager* gameManager);
    GameDataAc GetGameDataAccessor(hh::game::GameObject* gameObject);
    // ChallengeDataAc GetChallengeDataAccessor(hh::game::GameObject* gameObject);
}
