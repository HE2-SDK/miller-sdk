#pragma once

namespace hh::ut {
    namespace internal {
        class StateImpl : public fnd::ReferencedObject {
        };
    }

    template<typename T>
    class StateBase : public internal::StateImpl {

    };
}
