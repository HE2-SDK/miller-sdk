#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
        struct JumpInfo {
            csl::math::Vector3 unk1;
            csl::math::Vector3 groundNormal;
            float altitude;
            uint32_t dword24; // bitset
            uint32_t dword28;
            hh::fnd::HandleBase dword2C;
            uint32_t dword30;
            uint8_t byte34;
            bool HasGround : 1;
            bool Grounded : 1;
            bool : 6;

            JumpInfo();
        };
        struct Unk2 {
            uint64_t unk1;
            csl::math::Matrix44 unk2;
            csl::math::Vector4 unk3;
            Unk2();
        };
        struct Unk3 {
            struct Unk1 {
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
                uint64_t unk4;
                uint64_t unk5;
                uint64_t unk6;
                uint64_t unk7;
                uint64_t unk8;
                csl::math::Vector4 unk9;
                Unk1();
            };

            uint64_t unk1;
            Unk1 unk2;
            Unk3();
        };
        struct Unk4 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            csl::math::Vector4 unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint64_t unk6;
            uint8_t unk7;
            Unk4();
        };
        struct Unk5 : Unk4 {
            csl::math::Vector4 unk102;
            csl::math::Matrix44 unk103;
            csl::math::Vector4 unk104;
            csl::math::Vector4 unk105;
            Unk5();
        };
        struct Unk6 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint8_t unk5;
            Unk6();
        };
        struct Unk7 {
            csl::ut::MoveArray<csl::math::Vector4> unk1;
            Unk7();
        };
        struct Unk8 {
            uint32_t unk1;
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            Unk8();
        };
        // csl::math::Transform transform;
        // hh::fnd::WorldPosition worldPosition;
        // csl::math::Vector4 velocity;
        // csl::math::Vector4 unk1;
        // csl::math::Vector4 unk2;
        // csl::math::Vector4 unk3;
        // csl::math::Vector4 unk4;
        // csl::math::Vector4 unk5;
        // csl::math::Vector4 unk6;
        // csl::math::Vector4 vector140;
        // csl::math::Matrix44 unk7;
        // uint64_t unk8;
        // JumpInfo unk9;
        // JumpInfo unk10;
        // Unk2 unk11;
        // Unk2 unk12;
        // Unk2 unk12a;
        // Unk5 unk13;
        // Unk5 unk14;
        // Unk6 unk15;
        // GravityController* gravityController;
        // csl::math::Vector4 vector500;
        // Unk7 unk16;
        // uint32_t dword530;
        // uint32_t unk17;
        // csl::math::Matrix44 matrix540;
        // void *unk18;
        // void *unk19;
        // void *unk20;
        // void *unk21;
        // uint64_t qword5A0;
        // csl::fnd::IAllocator *allocator;
        // uint16_t unk22;
        // uint8_t unk23;
        // uint64_t unk24;
        // uint32_t unk25;
        // csl::math::Vector4 vector5D0;
        // csl::math::Vector4 vector5E0;
        csl::math::Transform transform;
        hh::fnd::WorldPosition worldPosition;
        csl::math::Vector4 velocity;
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        csl::math::Vector4 worldInput;
        csl::math::Vector4 vector140;
        csl::math::Matrix44 unk7;
        uint64_t unk8;
        JumpInfo unk9;
        JumpInfo unk10;
        Unk2 unk11;
        Unk2 unk12;
        Unk2 unk12a;
        Unk5 unk13;
        Unk5 unk14;
        Unk6 unk15;
        app::player::GravityController *gravityController;
        csl::math::Vector4 vector500;
        Unk7 unk16;
        uint32_t dword530;
        csl::math::Matrix44 matrix540;
        void *unk17;
        void *unk18;
        void *unk19;
        void *unk20;
        uint64_t qword5A0;
        csl::fnd::IAllocator *allocator;
        uint16_t unk24;
        uint8_t unk25;
        uint64_t unk26;
        uint32_t unk27;
        csl::math::Vector4 vector5D0;
        csl::math::Vector4 vector5E0;


		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        const csl::math::Transform& GetTransform() const;
        csl::math::Matrix34 GetWorldMatrix() const;
        void SetPosition(const csl::math::Vector4& position);
        void SetRotation(const csl::math::Matrix34& rotation);
        const csl::math::Quaternion& GetRotation() const;
        void SetRotation(const csl::math::Quaternion& rotation);
        void SetVelocity(const csl::math::Vector4& velocity);
        void SetGravityScale(float gravityScale);
        float GetSpeed() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
