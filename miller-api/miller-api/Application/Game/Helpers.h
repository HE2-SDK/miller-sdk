#pragma once

namespace app::game {
    hh::game::ObjInfo* GetObjInfo(hh::game::GameManager* gameManager, const char* name);

    template<typename T>
    T* GetObjInfo(hh::game::GameManager* gameManager) {
        return (T*)GetObjInfo(gameManager, T::GetClass()->name);
    }
}
