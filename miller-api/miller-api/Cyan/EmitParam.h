#pragma once

namespace Cyan{
    struct EmitParam {
        csl::math::Matrix44 emissionMatrix;
        csl::math::Vector3 emissionPosition;
        csl::math::Vector3 normal;
        csl::math::Vector3 direction1;
        csl::math::Vector3 direction2;
    };
}
