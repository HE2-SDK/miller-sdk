#pragma once

namespace Cyan::Graphics {
    class DeviceContainer {
        hh::needle::RenderingDevice* device;
        hh::needle::RenderingDeviceContext* deviceContext;
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;

    public:

        DeviceContainer();

        void SetDevice(hh::needle::RenderingDevice* device, hh::needle::RenderingDeviceContext* deviceContext);

        hh::needle::RenderingDevice* GetDevice() const;
        hh::needle::RenderingDeviceContext* GetDeviceContext() const;
    };
}
