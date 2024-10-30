#pragma once

namespace app::save {
    template<typename Data>
    class SaveDataAccessor {
    public:
        Data* data;
        hh::fnd::Reference<SaveDataLock> lock;

        SaveDataAccessor(hh::game::GameObject* gameObject);
        virtual ~SaveDataAccessor() = default;
    };
}
