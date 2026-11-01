#pragma once

namespace app::game{
    class GameModeInputExtension : public GameModeExtension{
    public:
        static constexpr const char* name = "GameModeInputExtension";

        struct UnkStr {
            csl::ut::MoveArray<int64_t> qword0;
            void* qword20;
            int dword28;
        };

        csl::ut::MoveArray<hh::fnd::Reference<hh::game::InputComponent>> inputComponents;
        UnkStr qword38;

        virtual unsigned int GetNameHash() override;
        virtual void Destroy() override;

        hh::game::InputComponent* CreateInputComponent(unsigned int playerInputIdx, unsigned int priority, unsigned actionMonitorCount, const char* objectName);
        hh::game::InputComponent* GetInputComponent(unsigned int playerInputIdx) const;

        GameModeInputExtension(csl::fnd::IAllocator* allocator);
    };
}
