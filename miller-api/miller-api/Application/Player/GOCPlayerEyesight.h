#pragma once

namespace app::player {
    class GOCPlayerEyesight : public hh::game::GOComponent {
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        }
        csl::ut::MoveArray<Unk1> Unk;

    };
}