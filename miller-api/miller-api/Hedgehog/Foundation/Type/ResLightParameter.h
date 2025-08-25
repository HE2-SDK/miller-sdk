#pragma once
#include <ucsl/resources/light/v2.h>

namespace hh::fnd {
    struct ResLightParameter {
        struct PointLightParam{
            float radius;
            float attenuationRadius;
            bool shadowEnabled;
        };

        struct SpotLightParam{
            float innerConeAngle;
            float outerConeAngle;
            float attenuationRadius;
            bool shadowEnabled;
        };

        ucsl::resources::light::v2::LightType lightType;
        float color[3];
        csl::math::Position lightPosition;
        csl::math::Position direction;
        union{
            PointLightParam pointLightParam;
            SpotLightParam spotLightParam;
        };

        void SetTransformByHFrame(HFrame* hFrame);
    };
}
