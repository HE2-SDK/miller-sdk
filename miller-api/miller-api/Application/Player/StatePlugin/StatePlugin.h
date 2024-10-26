#pragma once

namespace app::gfx {
    class SceneParameters;
}

namespace app::player {
    class StatePluginBase : public hh::fnd::ReferencedObject {
    public:
        // I currently don't have a way to know where in the hierarchy these belong...
        uint8_t unk1;
        uint8_t unk2;

        StatePluginBase(csl::fnd::IAllocator* allocator) : hh::fnd::ReferencedObject{ allocator, true } {}
    };

    template<typename Ctx>
    class StatePlugin : public StatePluginBase {
    public:
        Ctx* context;
        StatePlugin(csl::fnd::IAllocator* allocator) : StatePluginBase{ allocator } {}
    };

    class PlayerStatePlugin : public StatePlugin<PlayerHsmContext> {};
}
