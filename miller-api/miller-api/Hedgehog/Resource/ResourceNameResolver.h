#pragma once

namespace hh::fnd {
    class ResourceNameResolver {
    public:
        virtual ~ResourceNameResolver() = default;
        virtual const char* RNR_UnkFunc1(const char* name);
        virtual char* ResolveName(const char *name, hh::fnd::ResourceTypeInfo* typeInfo, char* buffer, size_t bufferSize);
    };
}
