#pragma once

namespace hh::dbg {
    class ViewerManager : public fnd::BaseObject {
    public:
        csl::ut::MoveArray<fnd::Reference<dbg::Viewer>> viewers{ GetAllocator() };
        csl::ut::MoveArray<void*> unk1;
        void* unk2[2];
        fnd::Reference<ViewerContextManager> viewerContextManager;
        inline ViewerManager(csl::fnd::IAllocator* allocator) : fnd::BaseObject{ allocator } {
	        viewerContextManager = new (allocator) ViewerContextManager(allocator);
        }

        inline Viewer* CreateViewer(const ViewerClass* viewerClass) {
            auto* viewer = viewerClass->instantiator(GetAllocator());
            viewer->name = viewerClass->name;
            viewers.push_back(viewer);
            viewer->OnLifeCycleChange(true);
            return viewer;
        }

        template<typename T>
        T* CreateViewer() {
            return static_cast<T*>(CreateViewer(&RESOLVE_STATIC_VARIABLE(T::viewerClass)));
        }

        Viewer* GetViewerByName(const char* name);

        static ViewerManager* instance;
    };
}
