#pragma once

namespace hh::needle {
    struct SRefCountAddReleaseNeedleObject;
    // class NeedleRefcountObject : public NeedleObject, public rsdx::rsdx_noncopyable {
    class NeedleRefcountObject : public NeedleObject {
    public:
        friend struct SRefCountAddReleaseNeedleObject;
        uint32_t pad;
        uint32_t refCount;

        NeedleRefcountObject();
        virtual void ReleasePostDestroyInternal();
        virtual NeedleRefcountObject* GetDependRefcountObject();
        virtual ~NeedleRefcountObject();
        void AddRef();
        void Release();
    };
}
