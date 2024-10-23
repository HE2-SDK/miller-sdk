#pragma once

namespace hh::needle {
    // rsdx_noncopyable...
    class PipelineInfo;
    struct RenderJobCallback {
        typedef void (Function)(PipelineInfo* pipelineInfo, unsigned int viewportId, void* userData);

        Function* function;
        void* userData;
    };

    class RenderingPipeline;
    class SupportFX;
    struct RenderJobContext {
        RenderingDevice* renderingDevice;
        RenderManager* renderManager;
        RenderingPipeline* renderingPipeline;
        SupportFX* supportFX;
        csl::fnd::IAllocator* allocator;
    };

    class RenderJob : public NeedleRefcountObject {
    public:
        uint32_t unk1;
        uint64_t unk2;
        uint32_t unk3;
        uint64_t unk4;
        intrusive_ptr<CNameIDObject> name;
        unsigned int enabledBits;
        uint64_t renderMaskBits;

        virtual unsigned int GetUnk3();
        virtual void SetUnk3(unsigned int newUnk3);
        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo);
        virtual void Start(const RenderJobContext& context) = 0;
        virtual void Stop() = 0;
        virtual void UnkFunc9() {}
        virtual void Render(PipelineInfo* pipelineInfo) {}
        virtual void CallRender(PipelineInfo* pipelineInfo);
        virtual bool IsEnabled(unsigned int bit);
        virtual bool IsAnyEnabled();
        virtual void SetAllEnabled(bool enabled);
        virtual unsigned int GetNameHash() = 0;
        virtual const char* GetName() = 0;
        virtual unsigned int UnkFunc16() = 0;
        virtual unsigned int UnkFunc17();
        virtual void SetUnk7(uint64_t newUnk7);
    };
}
