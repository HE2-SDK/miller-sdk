#pragma once

namespace hh::fw {
    class AppModule;

    class AppModuleClass {
        const char* name;
        AppModule* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class AppModule : public fnd::ReferencedObject {
        AppModuleClass* appModuleClass;
        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
    };
}
