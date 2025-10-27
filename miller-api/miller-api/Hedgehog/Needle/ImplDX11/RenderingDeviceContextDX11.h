#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE_CONTEXT_DX11 0x5F43313156454452ui64

namespace hh::needle::ImplDX11 {
    class RenderingDeviceContextDX11 : public RenderingDeviceContext {
        RenderingDeviceDispatchDX11Impl* renderingDeviceDispatch;
        uint64_t unk2;
        DeviceObjectDX11* deviceObject;
    public:
        RenderingDeviceContextDX11();
        virtual ~RenderingDeviceContextDX11();
        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
        virtual void BeginRendering(unsigned int unkParam) override;
        virtual RenderingCommandList* EndRendering() override;
        virtual bool ExecuteRendering(RenderingCommandList* commandList) override;
        virtual bool UnkFunc1() override { return true; }
        virtual bool UnkFunc2() override { return true; }
        virtual uint32_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6b() override;
        virtual void SetVertexBuffer(unsigned int bufferSize, SourceBufferSetting* unused, unsigned int totalSize) override;
        virtual uint64_t UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
        virtual void DrawVerticesUP(const void* vertices, unsigned int vertexCount, unsigned int vertexStride) override;
        virtual void DrawIndexedVerticesUP(const unsigned short* indices, unsigned int indexCount, const void* vertices, unsigned int vertexCount, unsigned int vertexStride) override;
        virtual void DrawIndexed(unsigned int indexCount, unsigned int startIndexLocation, int baseVertexLocation) override;
        virtual void DrawIndexedInstanced(unsigned int indexCountPerInstance, unsigned int instanceCount, unsigned int startIndexLocation, int baseVertexLocation, unsigned int startInstanceLocation) override;
        virtual void DrawIndexedInstancedIndirect(NeedleRefcountResource* bufferForArgs, unsigned int alignedByteOffsetForArgs) override;
        virtual void Draw(unsigned int vertexCount, unsigned int startVertexLocation) override;
        virtual void Dispatch(unsigned int threadGroupCountX, unsigned int threadGroupCountY, unsigned int threadGroupCountZ) override;
        virtual void DispatchIndirect(NeedleRefcountResource* bufferForArgs, unsigned int alignedByteOffsetForArgs) override;
        virtual void SetShaderObject(const ShaderObject* shaderObject, const InstanceParameterContainerData** ipcd, unsigned int unkParam1, const unsigned char* unkParam2, unsigned int unkParam3) override;
        virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) override;
        virtual void ResetShaderResource() override;
        virtual void SetShaderParameter(const void* statusContext) override;
        virtual void SetShaderParameterNativeChunk(const void* statusContext) override;
        virtual void FlushStatus() override;
        virtual void FlushClear() override;
        virtual void FlushInternal() override;
        virtual void FlushInternalWithoutDirty() override;
        virtual void InvalidateStatus() override;
        virtual void SetVertexBuffer(unsigned int startSlot, const SourceBufferSetting* sourceBufferSetting, unsigned int numBuffers) override;
        virtual void SetIndexBuffer(const IndexBuffer* indexBuffer, unsigned int offset) override;
        virtual void DoNothing1() override;
        virtual void DoNothing2() override;
        virtual void SetPixelShader(::hh::needle::PixelShader* shader) override;
        virtual void SetComputeShader(::hh::needle::ComputeShader* shader) override;
        virtual void DoNothing3() override {}
        virtual void SetVertexBufferDirect() override;
        virtual void SetIndexBufferDirect() override;
        virtual void SetConstantBufferDirect() override;
        virtual void SetRegularBufferDirect() override;
        virtual void SetShaderConstantMemory(ShaderStage shaderStage, unsigned int slot, const void* data, size_t size) override;
        virtual void SetShaderParameterFloat(CNameIDObject* parameterName, const float* data, unsigned int count) override;
        virtual void SetShaderParameterInt(CNameIDObject* parameterName, const float* data, unsigned int count) override;
        virtual void SetShaderParameterBool(CNameIDObject* parameterName, const float* data, unsigned int count) override;
        virtual void SetShaderResourceView(ShaderStage shaderStage, unsigned int slot, void* unkParam) override;
        virtual void SetTexture(CNameIDObject* parameterName, Texture* texture) override;
        virtual void SetSampler(ShaderStage shaderStage, unsigned int slot, const SamplerStateSetting* samplerStateSetting) override;
        virtual void UnkFunc49() override;
        virtual void SetTextureSampler(CNameIDObject* parameterName, Texture* texture, const SamplerStateSetting* samplerStateSetting) override;
        virtual void SetCullMode(CullMode cullMode) override;
        virtual void SetFillMode(FillMode fillMode) override;
        virtual void SetScissorEnable(bool enabled) override;
        virtual void UnkFunc54() override;
        virtual void SetDepthEnable(bool enabled) override;
        virtual void SetDepthWriteEnable(bool enabled) override;
        virtual void SetDepthComparisonFunc(ComparisonFunc comparisonFunc) override;
        virtual void SetTwoSidedStencil(bool unkParam1, ComparisonFunc comparisonFunc1, int unkParam21, unsigned int unkParam31, StencilOp stencilOp11, StencilOp stencilOp12, StencilOp stencilOp13, unsigned int unkParam41, ComparisonFunc comparisonFunc2, int unkParam22, unsigned int unkParam32, StencilOp stencilOp21, StencilOp stencilOp22, StencilOp stencilOp23, unsigned int unkParam42) override;
        virtual void SetStencil(bool unkParam1, ComparisonFunc comparisonFunc, int unkParam2, unsigned int unkParam3, StencilOp stencilOp1, StencilOp stencilOp2, StencilOp stencilOp3, unsigned int unkParam4) override;
        virtual void SetColorWriteEnable(bool enabled) override;
        virtual void SetBlendDescSetting() override;
        virtual void SetBlendModeWithAlpha(bool enabled, BlendMode src, BlendMode dst, BlendOp op, BlendMode alphaSrc, BlendMode alphaDst, BlendOp alphaOp) override;
        virtual void SetBlendMode(bool enabled, BlendMode src, BlendMode dst, BlendOp op) override;
        virtual void SetViewport(const ViewportSetting* viewportSetting, unsigned int count) override;
        virtual void UnkFunc66() override;
        virtual void SetScissor(const Rectangle* scissorRects, unsigned int count) override;
        virtual uint64_t UnkFunc68() override;
        virtual uint64_t UnkFunc69(bool enabled, int64_t* bits) override;
        virtual uint64_t UnkFunc70() override;
        virtual void GetRsFlagMask(RsFlagMask& rsFlagMask) override;
        virtual void SetRenderTargets(const RenderTargetsSetting& renderTargetsSetting) override;
        virtual void GetRenderTargets(RenderTargetsSetting& renderTargetsSetting) override;
        virtual void ClearRenderTarget(const RenderTarget* renderTarget, const float (&colorRGBA)[4]) override;
        virtual void ClearDepthStencil(const DepthStencil* depthStencil, unsigned int clearFlags, float depth, unsigned char stencil) override;
        virtual void SetUnorderedAccessViews(const UnorderedAccessViewsSetting& unorderedAccessViewsSetting) override;
        virtual uint64_t UnkFunc77() override;
        virtual void ClearUnorderedAccessViewFloat(const ::hh::needle::UnorderedAccessView* uav, const float (&values)[4]) override;
        virtual void ClearUnorderedAccessViewUint(const ::hh::needle::UnorderedAccessView* uav, const unsigned int (&values)[4]) override;
        virtual void Resolve(const NeedleRefcountResource* srcResource, unsigned int srcLevel, NeedleRefcountResource* dstResource, unsigned int dstLevel) override;
        virtual void ResolveMain(const NeedleRefcountResource* srcResource, NeedleRefcountResource* dstResource) override;
        virtual void CopySubresourceRegion(const NeedleRefcountResource* srcResource, NeedleRefcountResource* dstResource) override;
        virtual void CopyResource(const NeedleRefcountResource* srcResource, unsigned int srcLevel, NeedleRefcountResource* dstResource, unsigned int dstLevel) override;
        virtual bool DoNothing4() override;
        virtual bool Maybe_IsCapturingNow() override;
        virtual void PushMarker(const char* id) override;
        virtual void PopMarker() override;
        virtual void SetMarker(const char* id) override;
        virtual void GenerateMips(Texture* texture) override;
        virtual void Map(const NeedleRefcountResource* resource, unsigned int unkParam, MapType mapType, SRawImageInfo* rawImageInfo) override;
        virtual void Unmap(const NeedleRefcountResource* resource, const SRawImageInfo* rawImageInfo) override;
        virtual void UpdateResource(const NeedleRefcountResource* resource, unsigned int level, const Box& box, const SRawImageInfo rawImageInfo) override;
        virtual uint64_t UnkFunc93() override;
        virtual uint64_t UnkFunc94() override;
        virtual uint64_t UnkFunc95() override;
        virtual uint64_t UnkFunc96() override;
        virtual uint64_t UnkFunc97() override;
        virtual uint64_t UnkFunc98() override;
        virtual uint64_t UnkFunc99() override;
        virtual uint64_t UnkFunc100() override;
        virtual void SetLockConstantBuffer(ShaderStage shaderStage, unsigned int slot, ::hh::needle::ConstantBuffer* buffer) override;
        virtual void ResetUnlockConstantBuffer(ShaderStage shaderStage, unsigned int slot, ::hh::needle::ConstantBuffer* buffer) override;
        virtual void ResetUnlockShaderResourceView(ShaderStage shaderStage, unsigned int slot) override;
        virtual void ResetUnlockSampler(ShaderStage shaderStage, unsigned int slot) override;
        virtual uint32_t DoNothing5() override { return 0; }
        virtual uint64_t UnkFunc106() override;
        virtual InstanceParameterContainerData* GetInstanceParameterContainerData() const override;
        virtual bool DoNothing6() override { return false; }
        virtual uint64_t UnkFunc109() override;
        virtual bool DoNothing7() override { return false; }
        virtual void DoNothing8() override {}
        virtual uint64_t UnkFunc111() override;

        void SetDeviceObjectAndDispatch(DeviceObjectDX11* deviceObject, RenderingDeviceDispatchDX11Impl* dispatch);
    };
}
