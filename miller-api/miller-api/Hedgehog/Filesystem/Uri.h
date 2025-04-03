#pragma once

namespace hh::fnd {
    class Uri {
        csl::ut::String buffer;
    public:
        Uri(csl::fnd::IAllocator* allocator);
        Uri(char* buffer, size_t bufSize, const char* str, size_t strlen, csl::fnd::IAllocator* allocator);
        virtual ~Uri();

        Uri& Append(const char* subpath);
        // Uri& Appendf(const char* subpathFmt, ...);
        void GetPath(csl::ut::String& path) const;
        Uri& SetPath(const char* path);
        void GetProtocol(csl::ut::String& protocol) const;
        Uri& SetProtocol(const char* protocol);
        const char* GetUri() const;
    };
}
