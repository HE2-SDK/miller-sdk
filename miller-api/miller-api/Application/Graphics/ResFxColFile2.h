#pragma once
#include <ucsl/resources/fxcol/v1.h>

namespace app::gfx {
    using ucsl::resources::fxcol::v1::FxColCollisionShapeData;
    using ucsl::resources::fxcol::v1::FxColBoundingVolumeData;
    using ucsl::resources::fxcol::v1::FxColUnk1Data;
    using ucsl::resources::fxcol::v1::FxColData;

    class ResFxColFile2 : public hh::fnd::ManagedResource {
    public:
        FxColData* fxColData;
        virtual void Load(void* data, size_t size) override;
    };
}
