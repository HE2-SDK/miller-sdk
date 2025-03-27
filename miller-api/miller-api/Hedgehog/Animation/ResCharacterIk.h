#pragma once

namespace hh::anim {
    class ResCharacterIk : public fnd::ManagedResource {
    public:
        csl::ut::MoveArray<fnd::Reference<IkInfoBase>> infos;

        virtual void Load(void* data, size_t size) override {}
        virtual void Unload() override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResCharacterIk);
    };
}
