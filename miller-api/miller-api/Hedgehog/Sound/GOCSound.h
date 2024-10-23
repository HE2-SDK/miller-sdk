#pragma once

#ifdef PlaySound
#undef PlaySound
#endif

namespace hh::snd {
    class GOCSound : public game::GOComponent {
        uint64_t unk101;
        uint64_t unk102;
        uint32_t unk103;
        csl::ut::MoveArray<void*> unk104;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
    
    public:
        struct SetupInfo {
            uint32_t unk1a;
            uint32_t unk1b;
            uint32_t unk2;
            bool unk3;
        };

        void Setup(const SetupInfo& setupInfo);
        SoundHandle PlaySound(const char* resourceName, float time);

        GOCOMPONENT_CLASS_DECLARATION(GOCSound);
    };
}
