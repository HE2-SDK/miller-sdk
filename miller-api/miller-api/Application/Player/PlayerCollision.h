#pragma once

namespace app::player {
    class PlayerCollision : public hh::fnd::ReferencedObject {
    public:
        struct Unk2 {
            csl::math::Vector3 pad1[5];
        };
        uint64_t qword18;
        hh::game::GOComponent* gocCollisionCache;
        float distance;
        float qword2C;
        float dword30;
        uint32_t collisionMask;
        csl::ut::InplaceMoveArray<Unk2, 64> unk40;
        csl::ut::MoveArray<void*> unk1460;
        uint8_t byte1480;

        DEFAULT_CREATE_FUNC(PlayerCollision);
    };
}
