#pragma once

namespace hh::ui {
    class alignas(8) UIElementBase : public fnd::ReferencedObject {
    public:
        csl::fnd::Delegate<void ()> unk1;
        csl::fnd::Delegate<void ()> unk2;
        csl::fnd::Delegate<void ()> unk3;
        csl::fnd::Delegate<void ()> unk4;
        csl::fnd::Delegate<void ()> unk5;
        csl::fnd::Delegate<void ()> unk6;
        csl::fnd::Delegate<void ()> unk6a;
        fnd::Handle<GOCUIComposition> hGOCUIComposition;
        fnd::Handle<GOCUICollider> hGOCUICollider;
        fnd::Handle<GOCSprite> hGOCSprite;
        csl::fnd::Delegate<void ()> unk7;
        csl::fnd::Delegate<void ()> unk8;
        csl::ut::VariableString name;
        csl::ut::VariableString type;
        fnd::Handle<SurfRideLayerHandle> hLayer;
        fnd::Handle<SurfRideCastHandle> hCast;
        void* unk12;
        csl::ut::MoveArray<fnd::Reference<UIElementBase>> children;
        bool maybeHasCast;
        bool unk14b;
        bool unk14c;
        bool unk14d;

        UIElementBase(csl::fnd::IAllocator* pAllocator, const char* name, GOCUIComposition* gocUIComposition);
        GOCSprite* GetGOCSprite();
        GOCUIComposition* GetGOCUIComposition();
        // This is a strange interface. The this pointer doesn't seem to be used in the function. Instead it uses parent.
        UIElementBase* FindDescendant(const char*& name, UIElementBase* parent);
        virtual void GetRuntimeTypeInfo();
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual bool UnkFunc9() { return false; }
        virtual void UnkFunc10() {}
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual bool CheckSomethingInTheCast();
        virtual bool UnkFunc14() { return true; }
        virtual void UnkFunc15() {}
        virtual void NotifyUnk1();
        virtual void NotifyUnk3();
        virtual void NotifyUnk2();
        virtual void DoSomethingWithUnk7();
    };
}
