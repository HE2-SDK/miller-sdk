#pragma once

namespace hh::dbg {
    class ViewerContextManager : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<fnd::Reference<dbg::ViewerContext>> viewerContexts{ GetAllocator() };
        inline ViewerContextManager(csl::fnd::IAllocator* allocator) : fnd::ReferencedObject{ allocator, true } {
        }

        ViewerContext* CreateViewerContext(const ViewerContextClass* viewerContextClass) {
            ViewerContext* ctx = ViewerContext::Create(GetAllocator(), viewerContextClass);
            ctx->Initialize(viewerContexts);
            viewerContexts.push_back(ctx);
            ctx->OnCreated();
            return ctx;
        }

        template<typename T>
        T* CreateViewerContext() {
            return static_cast<T*>(CreateViewerContext(T::GetClass()));
        }
    };
}
