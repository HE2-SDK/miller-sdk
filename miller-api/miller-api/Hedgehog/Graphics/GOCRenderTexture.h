#pragma once

namespace hh::gfx {
    class GOCRenderTexture : public game::GOComponent {
    public:
        // enum class Flag {
        // };

        struct CameraSettings {
            float width{ 1024.0f };
            float height{ 1024.0f };
            csl::math::Vector3 globalLightPosition{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 globalLightColor{ 1.0f, 1.0f, 1.0f };
            csl::math::Vector3 m12860{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 cameraPosition{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 cameraUp{ 0.0f, 1.0f, 0.0f };
            csl::math::Vector3 cameraTargetPos{ 0.0f, 0.0f, 1.0f };
            float fov{ 0.78539819f };
            float nearClip{ 10.0f };
            float farClip{ 5000.0f };
        };

        struct ShaderSettings {
            fnd::Reference<hh::needle::NeedleRefcountObject>* pipeline{};
            const char* name{};
            const char* sceneName{};
            uint8_t byteA0{};
        };

        struct SetupInfo {
            CameraSettings cameraSettings{};
            bool byte80{};
            bool byte81{};
            bool byte82{};
            bool byte83{};
            ShaderSettings shaderSettings{};
        };

        needle::RenderTextureHandle* renderTextureHandle;
        float width;
        float height;
        gfnd::ViewportData viewportData;
        csl::math::Vector3 globalLightPosition;
        csl::math::Vector3 globalLightColor;
        csl::math::Vector3 m12860;
        char rtFlags;
        uint8_t byte1E4;
        uint64_t pipeline;
        uint64_t copyColor;
        ShaderSettings shaderSettings;
        csl::ut::String name;
        uint64_t unk230[10];

        GOCRenderTexture(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        void SetViewportData(const gfnd::ViewportData& viewportData);
        needle::Texture* GetTexture(unsigned int id) const;
        void SetUnk0(bool unk0);

        GOCOMPONENT_CLASS_DECLARATION(GOCRenderTexture);
    };
}
