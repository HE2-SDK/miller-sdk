#pragma once
#include <ucsl/resources/fxcol/v1.h>

namespace app::gfx {
    using FxColCollisionShapeData = ucsl::resources::fxcol::v1::ShapeData;
    using FxColKdTreeLeafData = ucsl::resources::fxcol::v1::KdTreeLeafData;
    using FxColKdTreeNodeData = ucsl::resources::fxcol::v1::KdTreeNodeData;
    using ucsl::resources::fxcol::v1::FxColData;

    class ResFxColFile2 : public hh::fnd::ManagedResource {
    public:
        FxColData* fxColData;
        virtual void Load(void* data, size_t size) override;
    };
}
