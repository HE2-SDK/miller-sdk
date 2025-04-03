#pragma once
#include <ucsl/resources/vibration/v21.h>

namespace hh::hid{
    using ucsl::resources::vibration::v21::VibData;

    class ResVibration : public fnd::ManagedResource{
    public:
        VibData* vibData;    

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        MANAGED_RESOURCE_CLASS_DECLARATION(ResVibration)
    };
}
