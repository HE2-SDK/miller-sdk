#pragma once

#define VIEWER_CLASS_DECLARATION(ClassName) private:\
        ClassName(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::dbg::ViewerClass viewerClass;\
		static ClassName* Create(csl::fnd::IAllocator* allocator);

namespace hh::dbg {
    class ViewerManager;
    class Viewer : public fnd::ReferencedObject {
    public:
        bool unk1;
        uint64_t unk2;
        const char* name;
        uint32_t unk4;
        ViewerManager* viewerManager;
        Viewer(csl::fnd::IAllocator* allocator);

        virtual void* GetFamilyID();
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual int OnLifeCycleChange(bool created);

        ViewerContext* GetViewerContext(ViewerContextClass* viewerContextClass);

        template<typename T>
        T* GetViewerContext() {
            return static_cast<T*>(GetViewerContext(T::GetClass()));
        }
    };
    
    struct ViewerClass {
        const char* name;
        Viewer* (*instantiator)(csl::fnd::IAllocator* allocator);
    };
}
