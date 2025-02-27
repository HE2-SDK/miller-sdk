#pragma once

namespace hh::dv{
    class DvNodePath : public DvNodeBase {
    public:
        struct Data {
        public:
            csl::math::Matrix44 matrix;
            int unk[4];
        };

        Data binaryData;
        csl::math::Matrix44 worldMat;
        csl::math::Transform transform;
        long nodeSize;

        virtual void Setup(void* setupInfo) override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodePath)
    };
}