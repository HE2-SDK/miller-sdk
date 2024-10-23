#pragma once

namespace hh::gfx {
    class ResModel : public ResModelNeedle {
    public:
        MANAGED_RESOURCE_CLASS_DECLARATION(ResModel)
        needle::MeshResource* GetMeshResource();
        bool IsLodModel() const;
    };
}
