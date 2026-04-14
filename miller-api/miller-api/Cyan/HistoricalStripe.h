#pragma once

namespace Cyan{
    class HistoricalStripe {
    public:
        static unsigned int CalcSize(unsigned int count);
        static HistoricalStripe* Create(unsigned int count, void* memory, Elements::Particle* owner);
        void Update(float deltaTime);
        bool UpdateOnFading(float deltaTime);
        void PrepareRender(Graphics::ParticleDecl* particleDecl);
    };
}
