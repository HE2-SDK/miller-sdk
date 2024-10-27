#pragma once

namespace app::game {
    class PostureImpl : public hh::fnd::ReferencedObject {
    public:
        PostureImpl(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const = 0;
        virtual unsigned int UnkFunc2() = 0;
        virtual void Enter() {}
        virtual void Leave() {}
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) {}
        virtual void UnkFunc6() {}
    };

    template<typename T>
    class PostureBase : public PostureImpl {
    public:
        T* context;
    };
}
