#pragma once

namespace hh::needle {
    class InstanceParameterContainerData;
    struct SGlobalParameterSceneSetting {
        InstanceParameterContainerData** instanceParameterContainers;
        unsigned int instanceParameterContainerCount;
    };
}
