#pragma once

namespace app_cmn::rfl {
    template<typename T>
    struct alignas(8) RangeAttribute {
        T start;
        T end;
        T step;
    };

    typedef RangeAttribute<float> RangleFloatAttribute;
    typedef RangeAttribute<uint32_t> RangeUint32Attribute;
    typedef RangeAttribute<int32_t> RangeSint32Attribute;
    typedef RangeAttribute<uint64_t> RangeUint64Attribute;
    typedef RangeAttribute<int64_t> RangeSint64Attribute;
}
