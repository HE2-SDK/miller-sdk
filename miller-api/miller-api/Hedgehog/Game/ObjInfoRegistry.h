#pragma once

namespace hh::game
{
    class ObjInfoRegistry : fnd::BaseObject {
        static ObjInfoClass* staticObjInfoClasses[430];
    public:
        csl::ut::MoveArray<ObjInfoClass*> objInfos;
        csl::ut::StringMap<ObjInfoClass*> objInfosByName;
        static ObjInfoRegistry* instance;
        ObjInfoRegistry(csl::fnd::IAllocator* pAllocator);
    };
}
