#pragma once

namespace hh::needle {
    class CallbackJob : public RenderJob {
    public:
        unsigned int viewportId;
        RenderJobCallback callback;
 
        CallbackJob(unsigned int viewportId, RenderJobCallback::Function* function, void* userData);
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
    };
}
