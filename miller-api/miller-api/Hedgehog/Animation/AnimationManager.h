#pragma once

namespace hh::anim {
    class AnimationManager : public game::GameService {
        csl::ut::LinkList<GOCAnimationSingle> gocAnimations;
        uint64_t unk1;
        uint64_t unk2;

    public:
        void AddGOCAnimation(GOCAnimationSingle* gocAnimation);
        void RemoveGOCAnimation(GOCAnimationSingle* gocAnimation);

        GAMESERVICE_CLASS_DECLARATION(AnimationManager)    
    };
}
