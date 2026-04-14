#pragma once

namespace Cyan {
    class Scene {
    public:
        Graphics::Renderer renderer;
        Graphics::MeshRenderer meshRenderer;
        Graphics::ExternalMeshRenderer externalMeshRenderer;
        ManagerImpl* managerImpl;
        System::LinkList<EffectImpl> effects;

        Scene(ManagerImpl* managerImpl);

        void PrepareRender(const Graphics::DeviceContainer& deviceContainer);
        void SetGammaCorrect(bool enabled);
    };
}