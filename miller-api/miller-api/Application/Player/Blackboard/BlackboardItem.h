#pragma once

namespace app::player {
    class BlackboardItem : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardItem";
        uint32_t unk1;
        uint32_t ringCapacity;
        uint32_t ringCount;
        uint16_t unk2;
        uint8_t unk3;
        uint8_t unk3b;
        uint8_t unk4;
        uint8_t unk5;
        uint8_t unk5b;
        uint8_t unk5c;
        uint16_t unk6;
        uint16_t unk7;
        uint8_t unk8;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardItem);
    };
}
