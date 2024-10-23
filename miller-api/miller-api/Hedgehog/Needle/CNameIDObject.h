#pragma once

namespace hh::needle {
    class CNameIDObject : public TNeedleRefcountUniqueObjectBase<NeedleRefcountObject> {
    public:
        const char* name;
        uint32_t length;

        CNameIDObject();
        // Returns a hash
        unsigned int Setup(const char* name);
        static CNameIDObject* RegisterUniqueObject(const char* name, CNameIDObject* obj);
    };
}
