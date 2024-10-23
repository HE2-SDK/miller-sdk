#pragma once

namespace hh::needle {
    class CNameIDObjectStatic : public CNameIDObject {
    public:
        CNameIDObject* uniqueObject;

        CNameIDObjectStatic(const char* name);
    };
}
