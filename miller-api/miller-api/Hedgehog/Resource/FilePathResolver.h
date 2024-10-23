#pragma once

namespace hh::fnd {
    class FilePathResolver : public ReferencedObject, public ResourceNameResolver {
        const char* extension;
    public:
        FilePathResolver(csl::fnd::IAllocator* allocator, const char* extension);
        virtual const char* RNR_UnkFunc1(const char* name) override;
        virtual char* ResolveName(const char *name, hh::fnd::ResourceTypeInfo* typeInfo, char* buffer, size_t bufferSize) override;
    };
}
