#pragma once

namespace hh::needle {
    class PrimitiveRenderable : public Renderable {
    public:
        void Render(const RenderInfo& renderInfo) override;
    };
}
