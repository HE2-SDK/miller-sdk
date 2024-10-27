#pragma once

namespace app::game {
    class StageObjectModule : public GameModeResourceModule {
    public:
        enum class CharacterFilter : uint8_t {
            SONIC = 1,
            AMY = 2,
            KNUCKLES = 4,
            TAILS = 8,
        };
        static void LoadCharacterObjInfo(hh::game::GameManager* gameManager, CharacterFilter* characterFilter, csl::fnd::IAllocator* allocator);
    };
}