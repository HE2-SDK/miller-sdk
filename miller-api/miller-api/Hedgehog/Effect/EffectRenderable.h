#pragma once

namespace hh::eff {
    class EffectManager {
    public:
        class Impl;
    };

    class EffectRenderable : public gfnd::Renderable {
    public:
        struct SetupInfo {
            needle::RenderingDevice* renderingDevice;
            needle::RenderingDeviceContext* renderingDeviceContext;
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;

            SetupInfo();
            void SetRenderingDeviceContext(needle::RenderingDevice* renderingDevice, needle::RenderingDeviceContext* renderingDeviceContext);
        };

        EffectManager::Impl* effectManagerImpl;

    };
}
