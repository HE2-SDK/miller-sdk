#pragma once

namespace app::player {
    class Blackboard : public hh::fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<BlackboardContent>> contents;

        BlackboardContent* GetContent(unsigned int nameHash);

        template<typename T>
        T* GetContent() {
            return static_cast<T*>(GetContent(csl::ut::HashString(T::name)));
        }

        DEFAULT_CREATE_FUNC(Blackboard);
    };
}
