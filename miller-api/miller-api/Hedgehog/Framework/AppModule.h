#pragma once

#define APPMODULE_CLASS_DECLARATION(ClassName) private:\
		static const hh::fw::AppModuleClass staticModuleClass;\
		static hh::fw::AppModule* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::fw::AppModuleClass* GetClass();

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
