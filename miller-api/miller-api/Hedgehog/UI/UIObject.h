#pragma once

namespace hh::ui {
    class UIObject : public fnd::ReferencedObject {
        Position position;
        Dimensions dimensions;
    public:
        virtual void* GetRuntimeTypeInfo();
        virtual void UnkFunc1() {}
        virtual void Update() {}
    };
}
