#pragma once

namespace hh::needle::ImplDX11 {
    class SParameterBuffer : public NeedleRefcountObject {
    public:
        struct Unk1 {
            ID3D11Buffer* constantBuffer;
            uint64_t unk2;

            Unk1();
        };

        struct SConstantData {
            uint8_t buffer[7168];

            unsigned int IsValidToWrite(void* data, size_t size);
        };

        struct SConstantContext {
            Unk1 constantBuffers[14];
            SConstantData constantData[14];
            uint16_t unk3;
            uint16_t dirtyBits;
            uint16_t sizes[14];
            uint16_t enabledOptionsBits;

            void SetParameterValue(void* data, size_t size, uint8_t slot, uint16_t offset);

            template<typename T, typename V, typename FlushParameterContext>
            void SetParameterValue(CNameIDObject* name, V* value, FlushParameterContext& flushParameterContext);
            
            template<> void SetParameterValue<SVSTypeDX11>(CNameIDObject* name, SParameterQueue::SBoolParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SVSTypeDX11>(CNameIDObject* name, SParameterQueue::SIntParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SVSTypeDX11>(CNameIDObject* name, SParameterQueue::SFloatParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SPSTypeDX11>(CNameIDObject* name, SParameterQueue::SBoolParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SPSTypeDX11>(CNameIDObject* name, SParameterQueue::SIntParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SPSTypeDX11>(CNameIDObject* name, SParameterQueue::SFloatParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SCSTypeDX11>(CNameIDObject* name, SParameterQueue::SBoolParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SCSTypeDX11>(CNameIDObject* name, SParameterQueue::SIntParameterValue* value, SFlushParameterContext& flushParameterContext);
            template<> void SetParameterValue<SCSTypeDX11>(CNameIDObject* name, SParameterQueue::SFloatParameterValue* value, SFlushParameterContext& flushParameterContext);

            SConstantContext();
        };

        SParameterQueue parameterQueue;
        SConstantContext constantContexts[3];

        SParameterBuffer();

        void VSSetConstantBufferMemory(ID3D11DeviceContext* deviceContext, void* unkParam, unsigned int slot);
        void PSSetConstantBufferMemory(ID3D11DeviceContext* deviceContext, void* unkParam, unsigned int slot);
        void CSSetConstantBufferMemory(ID3D11DeviceContext* deviceContext, void* unkParam, unsigned int slot);

        template<typename T>
        void SetFlushParameter(ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
        
        template<> void SetFlushParameter<SVSTypeDX11>(ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
        template<> void SetFlushParameter<SPSTypeDX11>(ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
        template<> void SetFlushParameter<SCSTypeDX11>(ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);

        template<typename T, typename U>
        void Flush(ID3D11DeviceContext* deviceContext, const ShaderMaterialContainerObjectDX11Impl* materialContainerObject, unsigned int materialIndex, const InstanceParametersBuildParameter& instanceParametersBuildParameter, ID3D11InputLayout** inputLayout, U** shader, StatusCacheOneStage* statusCache);
        template<> void Flush<SVSTypeDX11, ID3D11VertexShader>(ID3D11DeviceContext* deviceContext, const ShaderMaterialContainerObjectDX11Impl* materialContainerObject, unsigned int materialIndex, const InstanceParametersBuildParameter& instanceParametersBuildParameter, ID3D11InputLayout** inputLayout, ID3D11VertexShader** shader, StatusCacheOneStage* statusCache);
        template<> void Flush<SPSTypeDX11, ID3D11PixelShader>(ID3D11DeviceContext* deviceContext, const ShaderMaterialContainerObjectDX11Impl* materialContainerObject, unsigned int materialIndex, const InstanceParametersBuildParameter& instanceParametersBuildParameter, ID3D11InputLayout** inputLayout, ID3D11PixelShader** shader, StatusCacheOneStage* statusCache);
        template<> void Flush<SCSTypeDX11, ID3D11ComputeShader>(ID3D11DeviceContext* deviceContext, const ShaderMaterialContainerObjectDX11Impl* materialContainerObject, unsigned int materialIndex, const InstanceParametersBuildParameter& instanceParametersBuildParameter, ID3D11InputLayout** inputLayout, ID3D11ComputeShader** shader, StatusCacheOneStage* statusCache);
    };

    template<typename T, typename Target, typename FlushParameterContext>
    void SetQueueParameter(const SParameterQueue&, Target* target, FlushParameterContext& flushParameterContext);

    template<> void SetQueueParameter<SVSTypeDX11>(const SParameterQueue& parameterQueue, SParameterBuffer::SConstantContext* constantContext, SFlushParameterContext& flushParameterContext);
    template<> void SetQueueParameter<SPSTypeDX11>(const SParameterQueue& parameterQueue, SParameterBuffer::SConstantContext* constantContext, SFlushParameterContext& flushParameterContext);
    template<> void SetQueueParameter<SCSTypeDX11>(const SParameterQueue& parameterQueue, SParameterBuffer::SConstantContext* constantContext, SFlushParameterContext& flushParameterContext);
    template<> void SetQueueParameter<SVSTypeDX11>(const SParameterQueue& parameterQueue, ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
    template<> void SetQueueParameter<SPSTypeDX11>(const SParameterQueue& parameterQueue, ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
    template<> void SetQueueParameter<SCSTypeDX11>(const SParameterQueue& parameterQueue, ID3D11DeviceContext* deviceContext, SFlushParameterContext& flushParameterContext);
}
