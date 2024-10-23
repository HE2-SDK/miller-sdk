#pragma once

namespace hh::anim {
    class Bindable {
    public:
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;

        virtual void Bind(float value, void* unkParam) = 0;
    };
}
