#pragma once

namespace hh::ui {
    class UIObject : public fnd::ReferencedObject {
    public:
        Position position;
        Dimensions dimensions;

        virtual void* GetRuntimeTypeInfo() const;
        virtual void UnkFunc1() {}
        virtual void Update() {}
    };
}
