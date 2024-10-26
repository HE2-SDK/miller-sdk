#pragma once

namespace app::player {
    class PlayerController : public hh::fnd::ReferencedObject {
    public:
        struct Unk1 {
            csl::math::Vector3 unk3;
            csl::math::Quaternion unk4;
            csl::math::Vector3 unk5;
            csl::math::Vector3 unk6;
            csl::math::Vector3 unk7;
            uint32_t unk8;
            GOCPlayerKinematicParams::Unk1 unk1;
            uint32_t unk10;

            Unk1();
        };

        hh::fnd::Reference<PlayerCollision> playerCollision;
        csl::ut::MoveArray<void*> unk20;
        Unk1 unk40;
        Unk1 unkF0;
        uint8_t byte1A0;
        csl::ut::InplaceMoveArray<void*, 1> unk1A8;
        uint64_t qword1D0;
        uint64_t qword1D8;

        CREATE_FUNC(PlayerController, PlayerCollision* playerCollision);
    };
}
