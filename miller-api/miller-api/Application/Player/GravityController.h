#pragma once

namespace app::player {
    class GravityController : public hh::fnd::ReferencedObject {
    public:
        struct Unk1 {
            uint64_t qword50;
            uint32_t dword58;
        };
    
        uint64_t gravityPhantomListener_vtable;
        app::game::GOCGravity* gocGravity;
        float mass { 35.0f };
        float dword2C { 1.0f };
        csl::math::Vector3 gravity;
        csl::math::Vector3 gravity2;
        Unk1 unk50;
        uint8_t byte5C; // & 2 != 0, will return gravity2

        GravityController(csl::fnd::IAllocator* allocator);
        csl::math::Vector3* GetGravity() const;

    };
}
