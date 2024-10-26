#pragma once

namespace app::player {
    class VisualLocator : public hh::fnd::ReferencedObject {
    public:
        camera::CameraBridge cameraBridge;
        csl::math::Transform transform;

        DEFAULT_CREATE_FUNC(VisualLocator);

        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4() {}
        virtual uint64_t UnkFunc5() {}
    };
}
