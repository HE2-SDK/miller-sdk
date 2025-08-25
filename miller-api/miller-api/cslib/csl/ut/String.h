#pragma once

namespace csl::ut {
    class String : public csl::ut::MoveArray32<char> {
    public:
        String(csl::fnd::IAllocator* pAllocator) : csl::ut::MoveArray32<char>{ pAllocator } {}

        void reserve(uint32_t len) {
            csl::ut::MoveArray32<char>::reserve(len + 1);
            m_capacity = len;
        }

        char* c_str() const {
            return m_pBuffer;
        }

        void copyFrom(const char* str, size_t len, size_t srcOffset = 0, size_t dstOffset = 0);

        template<size_t Len>
        inline void copyFrom(const char (&str)[Len], size_t srcOffset = 0, size_t dstOffset = 0) {
            copyFrom(str, Len - 1, srcOffset, dstOffset);
        }
    };
}
