#pragma once

namespace app::player {
    template<typename Ctx>
    class StatePluginManager : public hh::fnd::BaseObject {
    public:
        Ctx* context;
        csl::ut::MoveArray<hh::fnd::Reference<StatePlugin<Ctx>>> plugins;
        bool unk1;
        StatePluginManager(csl::fnd::IAllocator* allocator);
        static StatePluginManager* Create(csl::fnd::IAllocator* allocator);
        StatePlugin<Ctx>* GetPlugin(unsigned int nameHash);
        void AddPlugin(StatePlugin<Ctx>* plugin);
        void RemovePlugin(StatePlugin<Ctx>* plugin);
        template<typename T>
        inline T* GetPlugin() {
            return static_cast<T*>(GetPlugin(csl::ut::HashString(T::name)));
        }
    };
}
