#pragma once

namespace hh::ui {
    class LayerController : public fnd::ReferencedObject {
    public:
        enum class Flag : unsigned char {
            UNK0,
            COPIED,
        };

        GOCSprite* gocSprite;
        fnd::Handle<SurfRideLayerHandle> layer;
        uint16_t id;
        char unk1;
        csl::ut::MoveArray<int> reservedAnimations;
        csl::ut::Bitset<Flag> flags;
        fnd::Handle<SurfRideCastHandle> posCast;
        uint32_t unk5;
        uint64_t unk6;
        csl::ut::MoveArray<void*> unk7; // Delegate that triggers when a new anim is started i think, check QueueAnimations
    
        static bool SetAnimation(SurfRide::Layer* layer, int animationId, float initialFrame, bool playInReverse);

        struct AnimationList {
            const char** start;
            const char** end;
        };

        LayerController(csl::fnd::IAllocator* pAllocator, GOCSprite* gocSprite, SurfRide::Layer* layer, uint16_t id);
        SurfRide::Cast* GetCast(const char* name) const;
        SurfRide::Layer* GetLayer() const;
        LayerController* CreateRefCastLayerController(const char* refCastName, uint16_t id);
        bool IsVisible() const;
        void SetVisible(bool visible);
        void SetParameter(const char* name, float value);
        void SetParameterNormalized(const char* name, float value);
        bool IsExistingAnimation(const char* name) const;
        bool IsCurrentAnimation(const char* name) const;
        void UnkFunc1(const char* castName, bool flagDisabled);
        void ClearReservedAnimation();
        void ReserveAnimation(const char* name);
        void ReserveAnimations(const AnimationList& animations);
        void PlayReservedAnimation();
        bool PlayAnimation(const char* name);
        void SetCastText(const char* name, const char* text);
        bool GetCastPosition(const char* name, csl::math::Vector3& position);
        void SetCastPosition(const char* name, const csl::math::Vector3& position);
        bool SetAnimationFinishedDelegate(const char* animation, const csl::fnd::Delegate<void (hh::ui::LayerController *, char const *)>& delegate);
        void CopyedFlag(bool enabled);
        void SetPosition(const csl::math::Vector3& position);
        bool ConvertToScreenCoordinates(const csl::math::Vector3& normalized, csl::math::Vector3& out);
    };
}
