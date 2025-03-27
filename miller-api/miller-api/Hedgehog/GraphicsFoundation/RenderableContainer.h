#pragma once

namespace hh::gfnd {
    class RenderableContainer : public fnd::ReferencedObject {
    public:
        csl::fnd::Mutex mutex;
        csl::ut::LinkList<Renderable> renderables;

        DEFAULT_CREATE_FUNC(RenderableContainer);

        void AddRenderable(hh::gfnd::Renderable* renderable);
        void RemoveRenderable(hh::gfnd::Renderable* renderable);
    };
}
