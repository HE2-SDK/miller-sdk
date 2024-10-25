#pragma once

namespace hh::path {
    class PathManager;
    class PathComponent : public game::GOComponent, public fnd::HFrameListener {
    public:
        struct Description {
            ResPathObject* resource;
            fnd::HFrame* frame;
            bool unk1;
        };

        fnd::Reference<fnd::HFrame> frame;
        fnd::Reference<ResPathObject> resource;
        PathManager* pathManager;
        uint64_t qwordA0;
        uint32_t dwordA8;
        csl::math::Matrix34 matrixB0;
        csl::math::Matrix34 matrixF0;
        bool unk130;

        PathComponent(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        void SetFrame(fnd::HFrame* frame);
        void Setup(const Description& description);
        const char* GetName() const;

        GOCOMPONENT_CLASS_DECLARATION(PathComponent);
    };
}
