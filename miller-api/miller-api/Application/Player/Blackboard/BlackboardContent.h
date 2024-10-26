#pragma once

namespace app::player {
    class BlackboardContent : public hh::fnd::ReferencedObject {
    public:
        void* unk1;

        virtual unsigned int GetNameHash() const;

        DEFAULT_CREATE_FUNC(BlackboardContent)
    };
}
