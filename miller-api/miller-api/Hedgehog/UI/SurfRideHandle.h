#pragma once

namespace hh::ui {
    class SurfRideHandleBase : public fnd::RefByHandleObject {
    protected:
        void* surfRideObject;
    public:
        typedef fnd::HandleManager<SurfRideHandleBase> HandleManager;
        SurfRideHandleBase(csl::fnd::IAllocator* pAllocator, void* surfRideObject);
    };

    class SurfRideLayerHandle : public SurfRideHandleBase {
    protected:
        void* buffer;
        uint32_t length;
        uint32_t capacity;
        csl::fnd::IAllocator* pAllocator;
    public:
        SurfRideLayerHandle(csl::fnd::IAllocator* pAllocator, SurfRide::Layer* layer);
    };

    class GOCSprite;
    class SurfRideCastHandle : public SurfRideHandleBase {
    protected:
        GOCSprite* gocSprite;
        void* buffer;
        uint32_t length;
        uint32_t capacity;
        csl::fnd::IAllocator* pAllocator;
    public:
        SurfRideCastHandle(csl::fnd::IAllocator* pAllocator, GOCSprite* gocSprite, SurfRide::Cast* cast);
    };
}
