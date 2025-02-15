#pragma once

namespace hh::game {
    class LevelManagerListener {
    public:
        virtual ~LevelManagerListener() = default;

        void LML_UnkFunc1() {}
        void LML_UnkFunc2() {}
        void LML_UnkFunc3() {}
        void LML_UnkFunc4() {}
        void LML_UnkFunc5() {}
    };

    class LevelManager
        : public hh::game::GameService
        , public hh::game::MasterLevelListener
        , public hh::fnd::ResourceManager::ResourceListener
        , public hh::fw::FrameworkFrameListener
    {
        csl::fnd::IAllocator* levelAllocator;
        uint64_t unk101;
        csl::ut::MoveArray<hh::game::MasterLevel*> masterLevels;
        csl::ut::InplaceMoveArray<LevelManagerListener*, 1> listeners;
        bool unk104;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void MLL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) override;
        virtual void MLL_UnkFunc2() override;
        virtual void MLL_UnkFunc3() override;
        virtual void ResourceLoadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void FFL_UnkFunc1() override;

        Level* GetLevelByName(const char* name) const;

        GAMESERVICE_CLASS_DECLARATION(LevelManager);
    };
}
