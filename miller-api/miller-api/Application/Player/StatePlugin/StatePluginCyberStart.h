#pragma once

namespace app::player {
    class StatePluginCyberStart : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginCyberStart";
        uint16_t unk101;
        uint32_t unk102;

        StatePluginCyberStart(csl::fnd::IAllocator* allocator);
        void Setup();
    };
}
