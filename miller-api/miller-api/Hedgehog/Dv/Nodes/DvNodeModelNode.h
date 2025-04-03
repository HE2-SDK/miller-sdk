#pragma once

namespace hh::dv{
    class DvNodeModelNode : public DvNodeBase {
    public:
        struct Data {
            int field00;
            char nodeName[64];
            int padding[3];
        };

        Data binaryData;
        int nodeID;

        virtual void Setup(void* setupInfo) override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeModelNode)
    };
}
