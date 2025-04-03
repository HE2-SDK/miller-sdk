#pragma once

namespace hh::dv{
    class DvSceneNodeTree : public fnd::ReferencedObject{
    public:
        DvNodeBase* mainNode;
        DvParamUpdater* paramUpdater;
        DvSceneControl* parent;
        int diEventManagerDWORDC0;

        void FindNodeByType(DvNodeBase::NodeType type, DvNodeBase** result);

        DvSceneNodeTree(csl::fnd::IAllocator* allocator, DvSceneControl* dvSceneControl, int diEvtMgrUnk);
    };
}
