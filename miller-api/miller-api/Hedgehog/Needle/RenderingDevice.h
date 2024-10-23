#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE 0x56454452444e4552ui64

namespace hh::needle {
    enum class PredicationQueryType : unsigned int {
        OCCLUSION_PREDICATE,
        OCCLUSION,
        UNKNOWN,
    };

    class ParameterProcessQueueHandle;

    class GatherMaterialBuildLocalData {};

    class RenderingDevice : public TNeedleRefcountResource<NEEDLE_RESOURCE_RENDERING_DEVICE, NeedleRefcountResource> {
    public:
        virtual RenderingDeviceContext* CreateDeviceContext(unsigned int maybeId) = 0;
        virtual void* UnkFunc9() = 0;
        virtual void OtherCreateDeviceContext() = 0; // CreateDeviceDispatch?
        virtual Texture* CreateTexture(const TextureCreationInfo& creationInfo) = 0;
        virtual Texture* CreateTextureView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual RenderTarget* CreateRenderTarget(const TextureCreationInfo& creationInfo) = 0;
        virtual RenderTarget* CreateRenderTargetView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual DepthStencil* CreateDepthStencil(const TextureCreationInfo& creationInfo) = 0;
        virtual DepthStencil* CreateDepthStencilView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual DepthStencil* CreateUnorderedAccessView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual Buffer* CreateVertexBuffer(const BufferCreationInfo& creationInfo) = 0;
        virtual Buffer* CreateIndexBuffer(const BufferCreationInfo& creationInfo) = 0;
        virtual bool CreateVertexLayout(const SInputElement* inputElement, uint32_t unkParam, VertexLayout** vertexLayout) = 0;
        virtual void UnkFunc20() = 0;
        virtual void UnkFunc21() = 0;
        virtual VertexShader* CreateVertexShader(const void* data, size_t size) = 0;
        virtual PixelShader* CreatePixelShader(const void* data, size_t size) = 0;
        virtual ComputeShader* CreateComputeShader(const void* data, size_t size) = 0;
        virtual PredicationObjectContainer* CreateOcclusionPredicate(unsigned int count, PredicationQueryType type) = 0;
        virtual PredicationObjectContainer* CreateOcclusionQuery(unsigned int count, PredicationQueryType type) = 0;
        virtual ConstantBuffer* CreateConstantBuffer(const BufferCreationInfo& creationInfo) = 0;
        virtual ShaderObject* CreateShaderObject(const ShaderObjectCreationInfo& creationInfo) = 0;
        virtual bool CreateShaderMaterialContainer(const ShaderMaterialContainerCreationInfo& creationInfo, ShaderMaterialContainer** shaderMaterialContainer) = 0;
        virtual InstanceParameterContainerData* GetDeviceBaseInstanceParameterContainerData() const = 0;
        virtual void BeginGatherMaterialBuildLocal(GatherMaterialBuildLocalData& gatherMaterialBuildLocalData) const = 0;
        virtual void EndGatherMaterialBuildLocal(GatherMaterialBuildLocalData& gatherMaterialBuildLocalData) const = 0;
        virtual ParameterProcessQueueHandle* SetupParameterProcessQueue(CScratchMemoryContext* memCtx) const = 0;
        virtual void FlushParameterProcessQueueSegment(ParameterProcessQueueHandle* queue, CScratchMemoryContext* memCtx, void* unkParam, size_t maybeUnkParamSize, unsigned int size) const = 0;
        virtual void SamplerObjectClearForExtended() = 0;
        virtual void UnkFunc36() = 0;
        virtual void UnkFunc37() = 0;
        virtual float GetGpuTime() const = 0;
        virtual void UnkFunc39() = 0;
        virtual void UnkFunc40() = 0;
        virtual void UnkFunc41() = 0;
        virtual void UnkFunc42() = 0;
        virtual void UnkFunc43() = 0;
        virtual void UnkFunc44() = 0;
        virtual void UnkFunc45() = 0;
        virtual void UnkFunc46() = 0;
    };
}