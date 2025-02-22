#pragma once

#define DV_NODE_DECLARATION_BASE(ClassName)\
		ClassName(csl::fnd::IAllocator* allocator);

namespace hh::dv {
    class DiEventManager;

    class DvSceneControl : public game::GameObject, game::GameStepListener, game::ObjectUpdateListener{
    public:
        enum class Flags : char {
            UNK0, // pauses qte, i think
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7
        };

        DiEventManager* diEvtMgr;
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        DvSceneNodeTree* nodeTree;
        DvSceneTimeline* timeline;
        ut::TinyFsm<DvSceneControl, ut::TinyFsmEvent> fsm;
        csl::ut::VariableString cutsceneName;
        int dvsceneDvCommon34;
        int unk3;
        int64_t state;
        ResDvScene* resource;
        int unk4;
        int unk5;
        float speed;
        bool update;
        bool unkBool0;
        bool play;
        csl::ut::Bitset<Flags> flags;
        bool unkBool1;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
        virtual void PreObjectUpdateCallback(game::GameManager* gameManager, fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;

        const char* GetCutsceneName();

        GAMEOBJECT_CLASS_DECLARATION(DvSceneControl)
    };
}
