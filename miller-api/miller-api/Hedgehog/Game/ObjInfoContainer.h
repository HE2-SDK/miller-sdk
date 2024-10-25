#pragma once

namespace hh::game {
    /*
     * Holds ObjInfos. You can pre-load and pre-init all ObjInfos contained.
     * Unloaded ObjInfos are loaded and initialized the first time GetInfo is called on them.
     * The ObjInfo's flags attribute is used to track this.
     */
    class ObjInfoContainer : public GameService {
    public:
        csl::ut::StringMap<ObjInfo*> objInfosByName;
        csl::ut::MoveArray<ObjInfo*> objInfos;

        virtual void* GetRuntimeTypeInfo() const override;

        ObjInfo* GetInfo(const char* name);
        void Initialize();
        void Finalize();
        bool Unk1();
        void LoadRequestAll();
        bool Register(const char* name, ObjInfo* objInfo);
        bool Unregister(const char* name);

        GAMESERVICE_CLASS_DECLARATION(ObjInfoContainer)
    };
}
