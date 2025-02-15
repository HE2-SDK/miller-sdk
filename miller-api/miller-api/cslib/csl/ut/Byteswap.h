#pragma once

namespace csl::ut {
    void NativeFromBig16(void* dest, const void* src, int count);
    void NativeFromBig32(void* dest, const void* src, int count);
    void NativeFromBigPtr(void* dest, const void* src, int count);
}
