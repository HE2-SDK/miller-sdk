#pragma once

namespace app::player {
    class Blackboard;

    class BlackboardContent : public hh::fnd::ReferencedObject {
    public:
        Blackboard* blackboard;

        virtual unsigned int GetNameHash() const;

        DEFAULT_CREATE_FUNC(BlackboardContent)
    };
}
