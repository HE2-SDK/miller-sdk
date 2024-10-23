#pragma once

namespace hh::needle {
    // rsdx_noncopyable...
    class PipelineInfo;
    class ParamBuildJob : public NeedleRefcountObject {
    public:
        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) = 0;
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) = 0;
    };
}
