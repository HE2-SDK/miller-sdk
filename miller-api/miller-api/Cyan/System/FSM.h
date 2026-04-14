#pragma once

namespace Cyan::System {
    class FSMState;

    class FSMContext {
    public:
        void* owner;
        float time;
        FSMState* nextState;
        bool unk0;
        bool unk1;

        void TransitState(FSMState* state, bool unk);
    };

    class FSMState {
    public:
        unsigned int id;

        virtual void OnEnter(FSMContext* ctx) = 0;
        virtual void OnUpdate(FSMContext* ctx) = 0;
        virtual void OnExit(FSMContext* ctx) = 0;
    };

    class FSM {
    public:
        void* owner;
        FSMState* currentState;
        FSMState* newState;

        FSM();
        virtual ~FSM();
        virtual void OnStateChanged(FSMState* currentState, FSMState* newState) {} // Cyan::Emitter::UpdateEmitter puts itself as the second argument

        void TransitState(FSMState* state);
        void Update(float time);
    };
}
