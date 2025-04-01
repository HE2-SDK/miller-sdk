#pragma once

namespace hh::fmv{
    class MovieRenderObject : public fnd::ReferencedObject {
    public:
        class TextureData : public fnd::ReferencedObject {
        public:
            int width;
            int height;
            int type;
            hh::needle::Texture* needleTexture;
        };

        enum class Flags : unsigned char {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
        };

        needle::ShaderMaterialContainer* qword18; //0x143a1af00
        needle::ShaderMaterialContainer* qword20; //0x143a1af00
        void* qword28;
        needle::ParameterValueObject* qword30;
        needle::ParameterValueObject* qword38;
        int64_t qword40;
        void* qword48; //0x143a19460
        gfnd::ResTexture* resTexture;
        int64_t* qword58;
        int64_t* qword60;
        int qword68;
        int qword6C;
        csl::ut::MoveArray<TextureData*> textures;
        int dword90;
        csl::ut::Bitset<Flags> flags;

        virtual void* UnkFunc0(unsigned int a2, unsigned int a3, void* a4);
        virtual void* UnkFunc1(unsigned int a2, unsigned int a3, void* a4);
        virtual void UnkFunc2();
        virtual void UnkFunc3();
        virtual void UpdateTextureData(csl::ut::MoveArray<char>& textureInfos); //hh::fmv::MoviePlayerCri::TextureInfo

        MovieRenderObject(csl::fnd::IAllocator* allocator);
    };
}
