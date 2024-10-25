#pragma once

namespace hh::game {
    class GOCTransform : public GOComponent {
        csl::ut::LinkListNode node;
        GOCTransform* parent;
        csl::ut::LinkList<GOCTransform> children;
    public:
        csl::math::Transform transform;
        fnd::HFrame* frame;
        char unk9;
        char unk10;
        char gocTransformFlags;
        bool unk11;
        uint32_t unk12;

        enum class Flag : unsigned char {
            TRANSFORM_POSITION = 1,
            TRANSFORM_ROTATION = 2,
        };

        struct SetupInfo {
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            GOCTransform* parent;
            uint8_t unk1;

            SetupInfo();
        };

        GOCTransform(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        void SetInheritedFlags(Flag flags);
        void SetLocalTransform(const csl::math::Transform& transform);
        void SetLocalTranslation(const csl::math::Vector3& position);
        void SetLocalRotation(const csl::math::Quaternion& rotation);
        void SetLocalTranslationAndRotation(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
        void SetParent(GOCTransform* parent);
        bool IsExistParent();
        
        inline GOCTransform* GetParent() {
            return parent;
        }

        inline const csl::ut::LinkList<GOCTransform>& GetChildren() {
            return children;
        }

        inline csl::math::Transform& GetTransform() {
            return transform;
        }

        inline fnd::HFrame& GetFrame() {
            return *frame;
        }
        
        GOCOMPONENT_CLASS_DECLARATION(GOCTransform)
    };
}
