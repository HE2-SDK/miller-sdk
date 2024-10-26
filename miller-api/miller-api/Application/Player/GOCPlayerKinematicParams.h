#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
        struct Unk1 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            uint64_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            int unk6;
            uint16_t unk7;

            Unk1();
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
            uint64_t unk101;
            csl::math::Vector4 unk102;
            csl::math::Vector4 unk103;
            csl::math::Matrix44 unk104;
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
        csl::math::Transform transform;
        hh::fnd::WorldPosition worldPosition;
        csl::math::Vector4 velocity;
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        csl::math::Vector4 unk6;
        csl::math::Matrix44 unk7;
        uint32_t unk8;
        Unk1 unk9;
        Unk1 unk10;
        Unk2 unk11;
        Unk2 unk12;
        Unk3 unk13;
        Unk5 unk14;
        Unk5 unk15;
        Unk6 unk16;
        GravityController* gravityController;
        csl::math::Vector4 unk18;
        Unk7 unk19;
        uint32_t unk20;
        csl::math::Matrix44 unk21;
        void* unk22;
        void* unk23;
        void* unk24;
        void* unk25;
        uint64_t unk26;
        csl::fnd::IAllocator* allocator;
        uint16_t unk27;
        uint8_t unk28;
        Unk8 unk29;


		virtual void* GetRuntimeTypeInfo() override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        const csl::math::Transform& GetTransform() const;
        csl::math::Matrix34 GetWorldMatrix() const;
        void SetPosition(const csl::math::Vector4& position);
        void SetRotation(const csl::math::Matrix34& rotation);
        void SetRotation(const csl::math::Quaternion& rotation);
        void SetVelocity(const csl::math::Vector4& velocity);
        void SetGravityScale(float gravityScale);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
