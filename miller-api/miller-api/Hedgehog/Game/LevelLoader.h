#pragma once

namespace hh::game {
    class LevelLoader : public fnd::ReferencedObject {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            csl::ut::VariableString name;
        };

        csl::ut::MoveArray<Unk1> levelsToLoad;
        csl::ut::MoveArray<void*> unk1;
        uint8_t unk2;

        CREATE_FUNC(LevelLoader);

        void LoadLevel(const char* name, const Level::LoadInfo& unk1Param = {});
    };
}
