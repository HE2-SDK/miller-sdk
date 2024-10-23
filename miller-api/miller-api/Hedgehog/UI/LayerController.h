#pragma once

namespace hh::ui {
    class LayerController : public fnd::ReferencedObject {
        GOCSprite* gocSprite;
        fnd::Handle<SurfRideLayerHandle> layer;
        uint16_t id;
        char unk1;
        csl::ut::MoveArray<int> unkAnimationIds; // queued animations?
        char unk3;
        fnd::Handle<SurfRideCastHandle> posCast;
        uint32_t unk5;
        uint64_t unk6;
        csl::ut::MoveArray<void*> unk7; // Delegate that triggers when a new anim is started i think, check QueueAnimations
    
    public:
        struct AnimationList {
            const char** start;
            const char** end;
        };

        LayerController(csl::fnd::IAllocator* pAllocator, GOCSprite* gocSprite, SurfRide::Layer* layer, uint16_t id);
        SurfRide::Cast* GetCast(const char* name);
        SurfRide::Layer* GetLayer();
        LayerController* GetChildLayer(const char* refCastName, uint16_t id);
        void SetVisibility(bool visible);
        void StartAnimation(const char* name, float initialFrame);
        void UnkFunc1(const char* castName, bool flagDisabled);
        void QueueAnimations(const AnimationList& animations);
    };
}
