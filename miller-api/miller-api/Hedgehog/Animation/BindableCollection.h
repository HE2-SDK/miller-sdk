#pragma once

namespace hh::anim {
    class BindableCollection {
    public:
        float collectionFloat;
        csl::ut::LinkList<Bindable> items;

        void AddBindable(Bindable* bindable);
        void RemoveBindable(Bindable* bindable);
    };
}