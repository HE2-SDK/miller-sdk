#pragma once

namespace Cyan::Elements {
    struct FieldArgs {
        csl::math::Vector3& force;
        const Resource::FieldParam* param;
        float unkScale;
    };
}
