#pragma once

namespace hh::gfx {
    class DynamicResolutionController : public fnd::ReferencedObject {
    public:
        struct ResolutionInfo {
            float unk1;
            unsigned int viewportCount;
        };

    protected:
        needle::FxDynamicResolutionParameter settings;
        uint8_t unk101;
        bool modeChanged;

    public:
        DEFAULT_CREATE_FUNC(DynamicResolutionController);
        virtual void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4]) = 0;
        virtual void SetDynamicResolutionSettings(const needle::FxDynamicResolutionParameter& settings);
        virtual float GetResolutionRatio() const = 0;
    };
}
