#pragma once

namespace hh::game {
    struct ObjectId {
        uint64_t objectId;
        uint64_t groupId;

        ObjectId();
        inline ObjectId(uint64_t objectId, uint64_t groupId) : objectId{ objectId }, groupId{ groupId } {}
        inline ObjectId(const ObjectId& other) = default;
        void CopyTo(ObjectId& target);
        bool IsNonNull() const;
        void Print(csl::ut::VariableString& str) const;
        void PrintGUID(csl::ut::VariableString& str) const;
        bool operator==(const ObjectId& other) const;
        bool operator!=(const ObjectId& other) const;
    };
}