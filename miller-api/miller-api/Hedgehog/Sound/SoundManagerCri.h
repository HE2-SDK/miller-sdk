#pragma once

namespace hh::snd {
    class SoundManagerCri : public SoundManager, public fnd::ResourceManager::ResourceListener {
    public:
        uint64_t unk201;
        csl::ut::MoveArray<hh::fnd::Reference<hh::snd::ResAtomCueSheet>> cueSheets;
        csl::ut::MoveArray<void*> debugUnk202;
		virtual void* GetRuntimeTypeInfo() const override;
        virtual void ResourceLoadedCallback(fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;

        GAMESERVICE_CLASS_DECLARATION(SoundManagerCri);
    };
}