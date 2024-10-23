#pragma once

namespace hh::fnd {
    class ResourceLoader : public ReferencedObject, public FileInfoListener, public FileBindListener {
    public:
        struct Locale {
            uint32_t localeId{ 1 };
            const char* localeName{ "" };
        };

        struct Unk3 {
            uint64_t unk1;
            bool unk2;
            csl::ut::VariableString unk3;

            Unk3(csl::fnd::IAllocator* allocator);
        };

        UnpackedResourceContainer unpackedResourceContainer;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        Unk3 unk5;
        csl::fnd::IAllocator* otherAllocator;
        csl::ut::VariableString unk6;
        csl::ut::MoveArray<void*> unk7;
        uint16_t unk8;

        ResourceLoader(csl::fnd::IAllocator* allocator);
        inline static ResourceLoader* Create(csl::fnd::IAllocator* allocator) {
            return new (allocator) ResourceLoader(allocator);
        }

        void LoadPackfile(const char* uri, uint32_t unk);
        void LoadResource(const Uri& uri, const ResourceTypeInfo* resourceTypeInfo, int unk, uint32_t unk2, Locale& locale);
    };
}
