#pragma once

namespace hh::dv{
    class DvNodeModelNode : public DvNodeBase {
    public:
        struct Description : DvNodeBase::Description {
            int field00;
            char nodeName[64];
            int padding[3];
        };

        Description binaryData;
        int nodeID;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeModelNode)
    };
}
