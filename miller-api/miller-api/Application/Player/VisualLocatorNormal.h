#pragma once

namespace app::player {
    class VisualLocatorNormal : public VisualLocator {
    public:
        csl::math::Transform transform2;
        float unkTau;
        uint8_t unk101;

        DEFAULT_CREATE_FUNC(VisualLocatorNormal);

        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual uint64_t UnkFunc3();
        virtual uint64_t UnkFunc4() {}
        virtual uint64_t UnkFunc5();
    };
}
