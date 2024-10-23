#pragma once

// Reusing this here because I don't want to redefine this...
typedef csl::math::Position float_vector3;

namespace hh::needle {
    struct uint_vector4 {
        unsigned int x;
        unsigned int y;
        unsigned int z;
        unsigned int w;
    };

    struct float_vector3 {
        float x;
        float y;
        float z;
    };

    struct float_vector4 {
        float x;
        float y;
        float z;
        float w;
    };

    enum class MemoryType {
        UNK0,
    };

    enum class PrimitiveTopology {
        POINT_LIST,
        LINE_LIST,
        LINE_STRIP,
        TRIANGLE_LIST,
        TRIANGLE_STRIP,
    };

    enum class TextureWrapMode : uint8_t
    {
        REPEAT = 0,
        MIRROR = 1,
        CLAMP = 2,
        MIRROR_ONCE = 3,
        BORDER = 4,
        UNK5 = 5,
        UNK6 = 6,
    };

    enum class CullMode : uint32_t {
        NONE,
        FRONT,
        BACK,
    };

    enum class FillMode {

    };

    enum class BlendMode : uint32_t {
        ZERO,
        ONE,
    };

    enum class BlendOp : uint32_t {
        ADD,
    };

    enum class ComparisonFunc {

    };

    enum class StencilOp {

    };

    enum class ShaderStage : uint32_t {
        VERTEX_SHADER,
        PIXEL_SHADER,
        COMPUTE_SHADER,
    };

    enum class MapType : uint32_t {
        READ,
        WRITE,
        READ_WRITE,
        WRITE_DISCARD,
        WRITE_NO_OVERWRITE,
    };

    struct DebugVisualizeParameter {
        uint8_t unk1;
        uint8_t unk2;
        float unk3;
        float unk4;
        uint32_t unk5;
    };

    struct PickColorParameter {
        uint8_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
    };

    struct SmoothnessParameter {
        float unk1;
        float unk2;
    };

    void EntryUniqueElementControl(unsigned int uniqueElementHash);
    void LeaveUniqueElementControl(unsigned int uniqueElementHash);
}
