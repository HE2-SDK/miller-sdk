#pragma once

// .data:0000000142AC8860 ; public struct hh::ui::`anonymous namespace'::MyTraverser /* mdisp:0 */ :
// .data:0000000142AC8860 ;   public struct hh::ui::UIElementGroupContainer::Traverser /* mdisp:0 */
// .data:0000000142AC8860 struct hh::ui::`anonymous namespace'::MyTraverser `RTTI Type Descriptor' dq offset const type_info::`vftable'

namespace hh::ui {
    // actually UIElementGroupContainer::Traverser but my script is shit.
    class UIElementGroupContainerTraverser {
    public:
        virtual void BeginContainer(UIElementGroupContainer* container) {}
        virtual void EndContainer(UIElementGroupContainer* container) {}
        virtual void BeginGroup(UIElementGroup* group) {}
        virtual void EndGroup(UIElementGroup* group) {}
    };

    class UIElementGroupContainer : public UIElement {
    public:
        UIElementGroupContainer* parentContainer;
        csl::ut::InplaceMoveArray<fnd::Reference<UIElementGroupContainer>, 4> childContainers;
        csl::ut::StringMap<UIElementGroupContainer*> childContainersByName;
        csl::ut::InplaceMoveArray<fnd::Reference<UIElementGroup>, 8> elementGroups;
        csl::ut::StringMap<UIElementGroup*> elementGroupsByName;

        UIElementGroupContainer(csl::fnd::IAllocator* pAllocator, GOCUIComposition* gocUIComposition, const char* name, UIElementGroupContainer* parent);

        virtual void* GetRuntimeTypeInfo() const override;

        void AddChildContainer(UIElementGroupContainer* container);
        void AddGroup(UIElementGroup* group);
        UIElementGroupContainer* FindChildContainer(const char* name);
        UIElementGroup* FindGroup(const char* name);
        UIElement* FindElement(const char* name);
        void Traverse(UIElementGroupContainerTraverser* traverser);
    };
}
