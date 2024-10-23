#pragma once

namespace hh::fnd
{
	class HandleManagerBase : public ReferencedObject {
        csl::ut::MoveArray<RefByHandleObject*> objects;
        void* begin;
        void* end;
        void* count;
        void* field_50;
        void* current;
        void* pAllocator2;
        volatile int spinlock;
    public:
        HandleManagerBase(size_t size);
        void AddObject(RefByHandleObject* obj);
        void RemoveObject(RefByHandleObject* obj);
    };

    template<typename T>
    class HandleManager : public HandleManagerBase {
    public:
        static HandleManager<T>* instance;
        static HandleManager<T>* Create(csl::fnd::IAllocator* pAllocator, size_t size);

        // inline void AddObject(T* obj) {
        //     HandleManagerBase::AddObject(obj);
        // }
        // inline void RemoveObject(T* obj) {
        //     HandleManagerBase::RemoveObject(obj);
        // }
    };
}
