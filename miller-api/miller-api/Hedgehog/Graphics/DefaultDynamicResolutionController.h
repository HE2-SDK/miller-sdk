#pragma once

namespace hh::gfx {
    class DefaultDynamicResolutionController : public DynamicResolutionController {
    public:
        float resolutionRatio; 
 
        DEFAULT_CREATE_FUNC(DefaultDynamicResolutionController);
        virtual void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4]) override;
        virtual float GetResolutionRatio() const override;

        void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4], float resolutionRatio, bool unbounded);
    };
}
