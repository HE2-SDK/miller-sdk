#pragma once

namespace hh::game {
    struct ObjectDataAccessor {
        const GameObjectClass* gameObjectClass;
        ObjectData* objectData;

        ObjectDataAccessor(const GameObjectClass* gameObjectClass, ObjectData* objectData);

        csl::math::Vector3 GetPosition() const;
        csl::math::Quaternion GetRotation() const;
    };
}
