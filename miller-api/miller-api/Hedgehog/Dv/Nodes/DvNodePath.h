#pragma once

namespace hh::dv{
    class DvNodePath : public DvNodeBase {
    public:
        struct Description : DvNodeBase::Description {
        public:
            csl::math::Matrix44 matrix;
            int unk[4];
        };

        Description binaryData;
        csl::math::Matrix44 worldMat;
        csl::math::Transform transform;
        long nodeSize;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodePath)
    };
}
