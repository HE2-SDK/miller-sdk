#pragma once

#define OBJINFO_CLASS_DECLARATION(ClassName) private:\
		static const hh::game::ObjInfoClass objInfoClass;\
		ClassName(csl::fnd::IAllocator* allocator);\
		static hh::game::ObjInfo* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::game::ObjInfoClass* GetClass();

namespace hh::game {
    class ObjInfo;
    class ObjInfoContainer;

    class ObjInfoClass {
    public:
        const char *name;
        ObjInfo* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
    public:
        enum class Flag {
            LOADED = 0,
            INITIALIZED = 1,
        };

        csl::ut::Bitset<Flag> flags;
        fnd::Reference<fnd::ResourceLoader> resourceLoader;
        fnd::Reference<LevelLoader> levelLoader;
        GameManager* gameManager;

        ObjInfo(csl::fnd::IAllocator* pAllocator);
        virtual void Load() {}
        virtual void Initialize(GameManager* gameManager) {}
        virtual void Finalize() {}
        virtual const char* GetInfoName();
        virtual void RegistCallback(ObjInfoContainer* container) {}
    };
}
