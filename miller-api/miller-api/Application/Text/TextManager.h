#pragma once

namespace app::text {
    class TextManager
        : public hh::game::GameService
        , public hh::fnd::ResourceManager::ResourceListener
        , public hh::game::ErrorViewerListener
        , public app::fnd::AppResourceManagerListener
    {
        void* unk101;
        void* unk102;
        void* unk103;
        hh::text::TagReplacer* tagReplacer;
        void* unk104;

    public:
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;

        virtual void ResourceLoadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(hh::fnd::ManagedResource* resource) override;
        virtual void EVL_UnkFunc2(int unkParam1, int unkParam2, int& unkParam3) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;

        GAMESERVICE_CLASS_DECLARATION(TextManager)
    };
}
