#pragma once

namespace hh::dv {
    class DiEventManager;

    class DvSceneControl : public game::GameObject, game::GameStepListener, game::ObjectUpdateListener {
    public:
        DiEventManager* diEvtPrevMgr;
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        DvSceneNodeTree* nodeTree;
        DvSceneTimeline* timeline;
        ut::TinyFsm<DvSceneControl, ut::TinyFsmEvent> fsm;
        csl::ut::VariableString cutsceneName;
        int64_t unk2;
        int64_t state;
        ResDvScene* resource;
        int unk3;
        int unk4;
        float unk5;
        int flags;

        GAMEOBJECT_CLASS_DECLARATION(DvSceneControl)
    };
}
