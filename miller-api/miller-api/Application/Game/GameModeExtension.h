#pragma once

namespace app::game {
    class GameModeExtension : public hh::fnd::BaseObject {
    public:
        virtual unsigned int GetNameHash() = 0;
        virtual void Initialize() {}
        virtual void Destroy() {}
        virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) {}
        virtual uint64_t UnkFunc1() {}

        DEFAULT_CREATE_FUNC(GameModeExtension);
    };
}
