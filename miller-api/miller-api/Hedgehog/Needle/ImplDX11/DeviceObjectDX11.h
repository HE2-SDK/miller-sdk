#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class DeviceObjectDX11 : public NeedleRefcountObject {
        public:
            struct Unk2 {
                SLIST_ENTRY slistEntry;
                uint64_t pad1[11];
            };

            struct Unk3 {
                SLIST_ENTRY slistEntry;
                uint64_t pad1[37];
            };

            template<typename T, size_t Len>
            struct Unk1 {
                uint64_t unk1;
                char unk2[0x2088];
                T slistEntries[Len];
                SLIST_HEADER slistHeader;
                uint64_t unk3;
                uint32_t unk4;
            };

            intrusive_ptr<DevicUniqueObjectContainerDX11> objContainer;
            uint64_t pad1;
            intrusive_ptr<NeedleRefcountObject> unk1[512];
            short unk2;
            Unk1<Unk2, 512> unk3;
            intrusive_ptr<NeedleRefcountObject> unk3a[48];
            Unk1<Unk2, 16> unk4;
            intrusive_ptr<NeedleRefcountObject> unk5[17];
            Unk1<Unk3, 256> unk6;
            intrusive_ptr<NeedleRefcountObject> unk7[1504];
            uint64_t pad2[86];
            uint32_t unk8;
            uint32_t unk9;
            intrusive_ptr<NeedleRefcountObject> unk10[32];
            csl::fnd::Mutex mutex;
            uint64_t unk11;
            intrusive_ptr<NeedleRefcountObject> unk12[508];
            uint64_t unk13;
            PerfDiagnostics perfDiagnostics;

            enum class CreateDispatchFlags : unsigned int {
                NO_PARAMETER_BUFFER = 1,
                NO_INITIALIZE_UNK1 = 2,
            };

            struct TextureFormatMapping {
                uint32_t unk1;
                uint32_t unk2;
                DXGI_FORMAT format;
                uint32_t unk3;
                uint32_t unk4;
                uint32_t unk5;
                uint32_t unk6;
                uint32_t unk7;
            };

            struct TextureBufferCreationInfo {
                TextureCreationInfo textureCreationInfo;
                uint32_t unk1;
                SurfaceDescription* surfaceFormat;
                void* unk2; // unk2 from renderingdevice
            };

            static TextureFormatMapping formatMap[41];
            static DXGI_USAGE usageMap[6];

            DeviceObjectDX11(ID3D11Device* d3dDevice);

            static TextureFormatMapping* GetTextureFormatMapping(uint8_t format);

            RenderingDeviceDispatchDX11Impl* CreateDispatch(ID3D11DeviceContext* deviceContext, CreateDispatchFlags flags);
            Texture2DView* CreateTexture(struct TextureBufferCreationInfo& creationInfo);
        };
    }
}