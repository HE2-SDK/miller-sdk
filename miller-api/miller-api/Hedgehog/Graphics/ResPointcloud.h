#pragma once
#include <ucsl/resources/pointcloud/v2.h>

namespace hh::gfx {
    class ResPointcloud : public fnd::ManagedResource {
    public:
        ucsl::resources::pointcloud::v2::PointcloudData* pointcloudData;
        void* reloadedData;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;
    };
}
