#pragma once

namespace hh::needle::ImplDX11 {
    class GpuTimer {
    public:
        enum class Phase : unsigned int {
            BEFORE_PROFILE_BLOCK,
            IN_PROFILE_BLOCK,
            AFTER_PROFILE_BLOCK,
        };

        ID3D11Device* d3dDevice;
        ID3D11DeviceContext* d3dDeviceContext;
        uint32_t currentTimestampIndex;
        Phase phase;
        ID3D11Query* disjointQueries[5];
        ID3D11Query* startQueries[5];
        ID3D11Query* endQueries[5];
        uint64_t frequency;
        uint64_t ticksElapsed;

        void Initialize(ID3D11Device* d3dDevice);
        void StartProfilingBlock();
        void EndProfilingBlock();
        void CollectProfilingData();
    };
}
