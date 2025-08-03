#pragma once

namespace hh::gfx {
    class ModelNodeHFrame : public fnd::HFrame {
    public:
        GOCVisualModel* gocVisualModel;
        int nodeIndex;
        
        CREATE_FUNC(ModelNodeHFrame, GOCVisualModel* gocVisualModel, const char* nodeName);
        ModelNodeHFrame(csl::fnd::IAllocator* allocator, GOCVisualModel* gocVisualModel, int nodeIndex);
        virtual void* GetRuntimeTypeInfo() const;
        virtual void OnSync(const csl::math::Transform& parentTransform, csl::math::Transform* targetTransform);
    };
}
