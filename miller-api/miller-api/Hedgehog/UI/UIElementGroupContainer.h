#pragma once

// .data:0000000142AC8860 ; public struct hh::ui::`anonymous namespace'::MyTraverser /* mdisp:0 */ :
// .data:0000000142AC8860 ;   public struct hh::ui::UIElementGroupContainer::Traverser /* mdisp:0 */
// .data:0000000142AC8860 struct hh::ui::`anonymous namespace'::MyTraverser `RTTI Type Descriptor' dq offset const type_info::`vftable'

namespace hh::ui {
    class UIElementGroupContainer : public UIElement {
        void* unk101;
        csl::ut::InplaceMoveArray<UIElementGroupContainer*, 4> childContainers;
        csl::ut::StringMap<UIElementGroupContainer*> childContainersByName;
        csl::ut::InplaceMoveArray<UIElementGroup*, 8> elementGroups;
        csl::ut::StringMap<UIElementGroup*> elementGroupsByName;
    public:
        UIElementGroupContainer(csl::fnd::IAllocator* pAllocator, GOCUIComposition* gocUIComposition, const char* name, void* unkParam);
        UIElementGroup* FindGroup(const char* name);
        UIElement* FindElement(const char* name);
    };
}
