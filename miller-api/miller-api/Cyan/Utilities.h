#pragma 

namespace Cyan {
    unsigned short ConvertToHalfFloat(float value);

    template<typename T>
    class MemObject {
    public:
        T* object;
    };

    class Matrix23 {
    public:
        float m11; float m12; float m13; float m14;
        float m21; float m22; float m23; float m24;
    };
}
