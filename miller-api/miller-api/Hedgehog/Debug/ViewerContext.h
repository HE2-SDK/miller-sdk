#pragma once

#define VIEWER_CONTEXT_CLASS_DECLARATION(ClassName) private:\
		static const hh::dbg::ViewerContextClass viewerContextClass;\
        ClassName(csl::fnd::IAllocator* allocator);\
		static ClassName* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::dbg::ViewerContextClass* GetClass();

namespace hh::dbg {
    class ViewerContext;

    struct ViewerContextClass {
        const char* name;
        ViewerContext* (*instantiator)(csl::fnd::IAllocator* allocator);
    };

    class ViewerContext : public fnd::ReferencedObject {
        uint64_t unk1;
        const ViewerContextClass* viewerContextClass;
    public:
        ViewerContext(csl::fnd::IAllocator* allocator);
        
        static ViewerContext* Create(csl::fnd::IAllocator* allocator, const ViewerContextClass* viewerContextClass) {
            ViewerContext* ctx = viewerContextClass->instantiator(allocator);
            ctx->viewerContextClass = viewerContextClass;
            return ctx;
        }

        template<typename T>
        static T* Create(csl::fnd::IAllocator* allocator) {
            return static_cast<T*>(Create(allocator, T::GetClass()));
        }

        virtual uint64_t Initialize(const csl::ut::MoveArray<fnd::Reference<ViewerContext>>& viewerContexts);
        virtual uint64_t OnCreated();
        virtual uint64_t OnDestroyed();
    };
}
