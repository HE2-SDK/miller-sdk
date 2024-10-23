#pragma once

namespace hh::needle {
    struct SRawImageInfo {
        void* data;
        unsigned int rowPitch;
        unsigned int depthPitch;
        MapType mapType;
    };
}
