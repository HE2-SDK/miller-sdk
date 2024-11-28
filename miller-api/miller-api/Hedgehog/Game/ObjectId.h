#pragma once
#include <ucsl/object-id.h>

namespace hh::game {
    struct ObjectId : public ucsl::objectids::ObjectIdV2 {
        ObjectId();
        inline ObjectId(uint64_t objectId, uint64_t groupId) : ObjectIdV2{ objectId, groupId } {}
        inline ObjectId(const ObjectId& other) = default;
        void CopyTo(ObjectId& target);
        bool IsNonNull() const;
        void Print(csl::ut::VariableString& str) const;
        void PrintGUID(csl::ut::VariableString& str) const;
        bool operator==(const ObjectId& other) const;
        bool operator!=(const ObjectId& other) const;
    };
}
