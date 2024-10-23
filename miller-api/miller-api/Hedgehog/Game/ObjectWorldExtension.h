#pragma once

namespace hh::game {
    class ObjectWorld;
    class ObjectWorldExtension : public fnd::ReferencedObject {
        ObjectWorld* objectWorld;
    public:
        virtual void* GetRuntimeTypeInfo() const = 0;
        virtual void Initialize() = 0;
        virtual void Deinitialize() = 0;
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
    };
}
