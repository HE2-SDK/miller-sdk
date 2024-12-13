#pragma once

namespace hh::fw {
    class SaveManagerInterface : public fnd::ReferencedObject, public fnd::user::UserInfoEventListener, public save::SaveProcessListener {
    public:
        uint32_t dword28;
        uint32_t dword2C;
        uint64_t qword30;
        uint8_t byte38;
        save::EncryptionKeys* pEncryptionKeys; // points to the embedded class
        csl::fnd::IAllocator* encryptionKeyAllocator;
        save::EncryptionKeys encryptionKeys;
        uint8_t encryptionKey1[32];
        uint8_t encryptionKey2[16];
        csl::ut::MoveArray<void*> unkB0;
        csl::ut::MoveArray<void*> unkD0;
        uint16_t wordF0;
        uint64_t qwordF8;
        uint64_t qword100;

        SaveManagerInterface(csl::fnd::IAllocator* allocator);
        virtual void UIEL_UnkFunc1() override;
    };
}
