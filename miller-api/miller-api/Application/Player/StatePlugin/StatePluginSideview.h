#pragma once

namespace app::player {
    class StatePluginSideview : public PlayerStatePlugin {
    public:
    static constexpr const char* name = "StatePluginSideview";
        bool isSideView;
         
        StatePluginSideview(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase, const float deltaTime) override;
    };
}