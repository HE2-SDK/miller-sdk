#pragma once

namespace hh::gfx {
    class GOCVisualTransformed : public GOCVisual, public fnd::HFrame::Listener {
    public:
        struct SetupInfo {
            fnd::HFrame* frame{};
            bool visibilityEnabled{};
            uint8_t unk1;
        };

        fnd::Reference<fnd::HFrame> frame1;
        fnd::Reference<fnd::HFrame> frame2;
        csl::math::Transform localTransform;
        csl::math::Matrix34 worldMatrix; // ??
        bool transformIsDirty;
        bool visibilityEnabled;
        bool hasManualModelSpaceAabb;
        void* visibilityManager; // VisibilityManager* visibilityManager;
        uint8_t visibilityHandle; // Might actually include the next items
        uint8_t unk205b;
        uint16_t handle2; // copied from messenger handle in ctor
        uint16_t unk206b;
        csl::geom::Aabb* pTransformedAabb;
        csl::geom::Aabb aabb;
        csl::geom::Aabb transformedAabb;
        GOCVisualTransformed(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;
        void Setup(const SetupInfo& setupInfo);
        void UpdateTransform();
        void SetModelSpaceAabb(const csl::geom::Aabb& aabb); // calling this sets aabb and hasManualModelSpaceAabbhh::gfx::GOCVisualTransformed::SetWorldMatrix((csl::math::Matrix34 const &))	.text	02A159BC	000000B0	00000008	00000008	R	.	.	.	.	.	.	.
        void SetModelSpaceAabbInternal(const csl::geom::Aabb& aabb); // calling this sets aabb and transformedAabb
        void SetFrame(fnd::HFrame* frame);
        void SetVisibilityEnabled(bool enabled);
        void SetVisibilityAabb(const csl::geom::Aabb& aabb);
        void SetLocalTranslation(const csl::math::Vector3& position);
        void SetLocalTransform(const csl::math::Transform& transform);
        void SetLocalTransform(const csl::math::Matrix34& transform);
        void SetLocalScale(const csl::math::Vector3& scale);
        void SetLocalRotation(const csl::math::Quaternion& rotation);
        void SetLocalRotation(float x, float y , float z);
        void SetWorldMatrix(const csl::math::Matrix34& matrix);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualTransformed)
    };
}
