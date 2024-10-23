#pragma once

namespace hh::needle {
    class Renderable : public NeedleRefcountObject {
    public:
        struct RenderInfo {
            RenderingDeviceContext* deviceContext;
            FxCamera* camera;
        };

        virtual unsigned int UnkFunc1(void* unkParam1, void* unkParam2) { return 0; }
        virtual void Render(const RenderInfo& renderInfo) = 0;
    };
}
