#pragma once

namespace hh::gfx {
    class VisibilityManager : public game::GameService {
    public:
        csl::ut::MoveArray<game::GameObject*> visibleObjects;
        void* testFunction;

        virtual void* GetRuntimeTypeInfo() override;

        GAMESERVICE_CLASS_DECLARATION(VisibilityManager)
    };
}
