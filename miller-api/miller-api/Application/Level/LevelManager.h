#pragma once

namespace app::level {
    class LevelManager
        : public hh::game::GameService
        , public hh::font::FontContainerListener
        , public hh::fnd::ResourceManager::ResourceListener
        , public hh::fw::FrameworkFrameListener
    {
        uint64_t unk100;
        uint64_t unk101;
        csl::ut::MoveArray<void*> unk102;
        csl::ut::InplaceMoveArray<void*, 1> unk103;
        bool unk104;

		virtual void* GetRuntimeTypeInfo();
        virtual void FCL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3);
        virtual void FCL_UnkFunc2();
        virtual void FCL_UnkFunc3();
        virtual void ResourceLoadedCallback(hh::fnd::ManagedResource* resource);
        virtual void ResourceUnloadedCallback(hh::fnd::ManagedResource* resource);
        virtual void FFL_UnkFunc1();

        GAMESERVICE_CLASS_DECLARATION(LevelManager)
    };
}
