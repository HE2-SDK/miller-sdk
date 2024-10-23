#pragma once

namespace hh::needle {
    class AtmosphereListener {
    public:
        virtual void UnkFunc1();
    };

    class SebastienSky : public RenderJob, public AtmosphereListener {
    public:
        csl::fnd::IAllocator* allocator;
        uint32_t viewportId;
        uint32_t dword5C;
        intrusive_ptr<ParameterValueObject> parameterValueObject1;
        intrusive_ptr<ParameterValueObject> daySkyParameters;
        intrusive_ptr<ParameterValueObject> nightSkyParameters;
        intrusive_ptr<ParameterValueObject> heightFogParameters;
        intrusive_ptr<ParameterValueObject> parameterValueObject5;
        intrusive_ptr<ShaderObject> transmittanceShader;
        intrusive_ptr<RenderTarget> renderTarget1;
        intrusive_ptr<Texture> renderTargetView1;
        intrusive_ptr<ShaderObject> multipleScatteringShader;
        intrusive_ptr<Texture> qwordA8;
        void* unorderedAccessView1;
        intrusive_ptr<ShaderObject> viewLUTShader;
        uint64_t qwordC0;
        intrusive_ptr<Texture> qwordC8;
        intrusive_ptr<ShaderObject> cameraVolumeShader;
        intrusive_ptr<ShaderObject> cameraVolumeComputeShader;
        uint64_t qwordE0[32];
        intrusive_ptr<Texture> qword1E0;
        uint64_t qword1E8;
        intrusive_ptr<ShaderObject> raymarchingShader;
        intrusive_ptr<ShaderObject> sunIrradianceShader;
        intrusive_ptr<ShaderObject> raymarchingComputeShader;
        intrusive_ptr<Texture> qword208;
        void* unorderedAccessView2;
        intrusive_ptr<ShaderObject> postEffectShader;
        uint64_t qword220;
        uint64_t qword228;
        uint64_t qword230;
        uint64_t qword238;
        uint64_t qword240;
        uint64_t qword248;
        uint64_t qword250;
        uint64_t qword258;
        uint64_t qword260;
        uint64_t qword268;
        uint8_t byte270;

        SebastienSky(csl::fnd::IAllocator* allocator, unsigned int unkParam1, unsigned int unkParam2);
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;

        void LoadDaySkyParameters(PipelineInfo* pipelineInfo, ParameterValueObject* daySkyParameters);
        void LoadNightSkyParameters(PipelineInfo* pipelineInfo, ParameterValueObject* nightSkyParameters);
        void LoadHeightFogParameters(PipelineInfo* pipelineInfo, ParameterValueObject* heightFogParameters);
    };
}
