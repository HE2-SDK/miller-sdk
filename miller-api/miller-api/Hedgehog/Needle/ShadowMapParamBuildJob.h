#pragma once

namespace hh::needle {
    class CachedShadowMapRenderJob;
    class ShadowMapParamBuildJob : public ParamBuildJob {
        CachedShadowMapRenderJob* renderJob;
    public:
        ShadowMapParamBuildJob(CachedShadowMapRenderJob* renderJob);
        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override;
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override;
    };
}
