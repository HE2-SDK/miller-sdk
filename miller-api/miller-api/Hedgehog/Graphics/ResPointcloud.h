#pragma once
#include <ucsl/resources/pointcloud/v2.h>

namespace hh::gfx {
    class ResPointcloud : public fnd::ManagedResource {
    public:
        ucsl::resources::pointcloud::v2::PointcloudData* pointcloudData;
        void* reloadedData;
        csl::ut::MoveArray<int64_t> unk0;

        virtual void Load(void* data, size_t size) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResPointcloud)
    };
}
