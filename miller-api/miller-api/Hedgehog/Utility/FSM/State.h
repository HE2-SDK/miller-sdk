#pragma once

namespace hh::ut {
    namespace internal {
        class StateImpl : public fnd::ReferencedObject {
        public:
            int id;
            const char* name;
            void* context;

            virtual bool DoInit() = 0;
            virtual void DoEnter(int previousStateId) = 0;
            virtual void DoLeave(int nextStateId) = 0;
            virtual bool DoStep(float deltaTime) = 0;
            virtual bool DoUpdate(fnd::UpdatingPhase phase, float deltaTime) = 0;
            virtual bool DoUpdateAsync(fnd::UpdatingPhase phase, float deltaTime) = 0;
            virtual bool DoProcessMessage(const hh::fnd::Message& message) = 0;
        };
    }

    template<typename T>
    class StateBase : public internal::StateImpl {
    public:
        virtual bool DoInit() override;
        virtual void DoEnter(int previousStateId) override;
        virtual void DoLeave(int nextStateId) override;
        virtual bool DoStep(float deltaTime) override;
        virtual bool DoUpdate(fnd::UpdatingPhase phase, float deltaTime) override;
        virtual bool DoUpdateAsync(fnd::UpdatingPhase phase, float deltaTime) override;
        virtual bool DoProcessMessage(const hh::fnd::Message& message) override;

        virtual bool Init(T& context) { return false; }
        virtual void Enter(T& context, int previousState) {}
        virtual void Leave(T& context, int nextState) {}
        virtual bool ProcessMessage(T& context, const hh::fnd::Message& message) { return false; }
        virtual bool Step(T& context, float deltaTime) { return false; }
        virtual bool Update(T& context, fnd::UpdatingPhase phase, float deltaTime) { return false; }
        virtual bool UpdateAsync(T& context, fnd::UpdatingPhase phase, float deltaTime) { return false; }
    };
}
