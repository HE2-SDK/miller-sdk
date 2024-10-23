#pragma once

namespace hh::gfnd {
    class RenderableContainer : public fnd::ReferencedObject {
    public:
        csl::fnd::Mutex mutex;
        csl::ut::LinkList<Renderable> renderables;
    };
}
