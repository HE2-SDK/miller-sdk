#pragma once

namespace hh::gfx {
    class GOCVisualUserModel : public GOCVisualTransformed {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;

            char pad[0x1F80];
        };

        struct Vertex {
            needle::float_vector3 position;
            needle::float_vector3 normal;
            char pad[24];
            unsigned int color;
            csl::math::Vector2 uv;
            char pad2[56];

            Vertex() {}
            Vertex(const csl::math::Vector3& position, const csl::ut::Color8& color);
            Vertex(const csl::math::Vector3& position, const csl::ut::Color8& color, const csl::math::Vector2& uv);
        };

        struct Description : GOCVisualTransformed::SetupInfo {
            struct UserModelDescription {
                Vertex* vertices;
                uint32_t vertexCount;
                unsigned short* indices;
                uint32_t indexCount;
                uint32_t qword1C;
                uint32_t dword20;
                uint32_t qword24;
                uint32_t qword28;
                uint32_t dword2C;
                needle::CNameIDObject* renderingTypeOrSomething;
                uint64_t qword38;
                uint64_t qword40;
                needle::VertexShader* vertexShader;
                needle::PixelShader* pixelShader;

                UserModelDescription();
            };

            csl::ut::Bitset<GOCVisualModelDescription::Flag> flags;
            uint32_t dword14;
            uint32_t dword18;
            uint32_t dword1C;
            uint32_t dword20;
            uint64_t qword28;
            void* qword30;
            uint64_t qword38;
            uint64_t qword40;
            bool isOccluder;
            bool disableColorDraw; // looks unused maybe?
            bool useGIPRT;
            bool useGISG;
            uint32_t nameHash;
            UserModelDescription userModel;
            needle::UserModelShaderParamter shaderParameter;
            uint8_t byteD0;
            csl::fnd::IAllocator* vertexBufferAllocator;

            Description();
        };

        needle::PBRModelInstance* modelInstance;
        float unk301;
        float unk301a;
        float unk302;
        float unk302a;
        float unk303;
        float unk303a;
        int unk304;
        uint32_t unk305;
        uint32_t vertexCount;
        Vertex* vertices;
        csl::fnd::IAllocator* vertexBufferAllocator;
        needle::intrusive_ptr<needle::Buffer> vertexBuffer;
        Unk1 unk310;
        needle::intrusive_ptr<needle::ParameterValueObject> shaderParameters;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;

        void Setup(const Description& setupInfo);
        void SetTexture(needle::CNameIDObject* parameterName, needle::Texture* texture);
        void SetTexture(needle::CNameIDObject* parameterName, gfnd::ResTexture* texture);
        void SetShaderParameterFloatByName(needle::CNameIDObject* parameterName, const float* value, unsigned int size);
        void SetVertexBuffer(const Vertex* vertices);
        needle::PBRModelInstance* GetModelInstance() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualUserModel);
    };
}
