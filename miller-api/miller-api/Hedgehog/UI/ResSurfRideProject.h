#pragma once

namespace hh::ui {
    class ResSurfRideProject : public fnd::ManagedResource {
    public:
        csl::ut::MoveArray<fnd::Reference<surfride::SurfRideTextureDataMIRAGE>> textureDatas;
        void* reloadedData;
        bool textureDatasInitialized;
        bool unk104;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(hh::fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;

        void* GetData() const;
        
        MANAGED_RESOURCE_CLASS_DECLARATION(ResSurfRideProject);
    };
}
