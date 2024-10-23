#pragma once

namespace hh::game {
    class ObjInfo;
    class ObjInfoContainer;

    class ObjInfoClass {
    public:
        const char *pName;
        ObjInfo* (*Create)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
        enum class Flag {
            LOADED = 0,
            INITIALIZED = 1,
        };

        csl::ut::Bitset<Flag> flags;
        fnd::ResourceLoader* resourceLoader;
        void* unk7;
        GameManager* gameManager;
    public:
        ObjInfo(csl::fnd::IAllocator* pAllocator);
        virtual void Load() {}
        virtual void Initialize(GameManager* gameManager) {}
        virtual void Finalize() {}
        virtual const char* GetInfoName();
        virtual void RegistCallback(ObjInfoContainer* container) {}
    };
}
