#pragma once

namespace hh::needle::ImplDX11 {
    class StatusCacheOneStage {
    public:
        SFlushParameterContext flushParameterContext;
        uint32_t constantBufferDirtyBits;
        uint32_t samplerDirtyBits;
        uint32_t shaderResourceDirtyBits;
    };
}
