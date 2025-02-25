#pragma once

namespace hh::dv{
    class DvNodeFolderCondition : public DvNodeBase{
    public:
        char unk0[212];
        int64_t qword284;

        virtual void Setup(void* setupInfo) override;
        virtual void Update(int currentFrame) override;
        virtual void PreStepUpdate(int currentFrame) override;
        virtual bool UnkFunc3() override;

        DV_NODE_DECLARATION_BASE(DvNodeFolderCondition)
    };
}