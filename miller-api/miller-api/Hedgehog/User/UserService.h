#pragma once

namespace hh::fnd {
    struct UserId {
        unsigned long long id;
    };

    struct UserInfo {
        UserId id;
        uint64_t unk1;
        char pad1[8];
    };

    class UserService : public BaseObject {
    public:
        struct Unk1 {
            unsigned int unk1;
            char pad1[12];
            UserInfo unk2;
        };

        struct Unk2 {
            uint64_t qword0;
            csl::ut::InplaceMoveArray32<char, 32> username;
            uint64_t gap1;
            int dword48;
            uint32_t dword4C;
            uint64_t qword50;
            uint32_t dword58;
            uint64_t qword60;

            Unk2();
        };

        struct Unk3 : Unk2 {
            int dword68;

            Unk3();
        };

        struct Unk4 : Unk2 {
            uint8_t dword68;

            Unk4();
        };

        struct Unk5 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
        };

        UserId userId;
        csl::ut::InplaceMoveArray<Unk1, 16> unk18;
        Unk3 unk2B8[4];
        csl::ut::StringMap<void*> unk478;
        Unk4 unk498[8];
        csl::ut::InplaceMoveArray<Unk5, 4> unk818;
        csl::ut::MoveArray<user::UserInfoEventListener*> userInfoEventListeners;
        unsigned int gap888[4];
        uint64_t qword898;
        uint8_t byte8A0;

        virtual void Initialize() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual void CreateUserData() = 0;
        virtual void UnkFunc4() {}
        virtual unsigned long long LoadUserId() = 0;
        virtual csl::ut::String LoadUserName(const UserId& userId) const = 0;
        virtual uint64_t UnkFunc7(const UserId& userId);
        virtual uint64_t UnkFunc8();
        virtual uint64_t UnkFunc9();

        void AddUserInfoEventListener(user::UserInfoEventListener* listener);
        bool RemoveUserInfoEventListener(user::UserInfoEventListener* listener);
        UserId GetUserId() const;
        const char* GetUserName(const UserId& userId) const;

        DEFAULT_CREATE_FUNC(UserService);
    };

    class UserServiceSteam : public UserService, public csl::fnd::Singleton<UserService> {
    public:
        bool unk8A8;
        csl::fnd::Mutex mutex8B0;
        csl::ut::MoveArray<void*> unk8D8;
        unsigned long long steamId;
        csl::ut::MoveArray<void*> unk900;
        uint64_t unk920;

        virtual void Initialize() override;
        virtual uint64_t UnkFunc2() override;
        virtual void CreateUserData() override;
        virtual unsigned long long LoadUserId() override;
        virtual csl::ut::String LoadUserName(const UserId& userId) const override;

        DEFAULT_CREATE_FUNC(UserServiceSteam);
    };
}
