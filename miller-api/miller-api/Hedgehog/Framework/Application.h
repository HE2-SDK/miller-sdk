#pragma once

namespace hh::fw {
    class ApplicationListener {
    public:
        virtual ~ApplicationListener() = default;
        virtual void AL_UnkFunc1();
    };

    class Application : public hh::fnd::ReferencedObject, hh::fw::KeyEventHandler, hh::fw::MouseEventHandler {
    public:
        FrameworkEnvironment* frameworkEnvironment;
        csl::ut::MoveArray<ApplicationListener*> listeners;
        csl::ut::MoveArray<void*> unk3;

        static Application* instance;
        Application(csl::fnd::IAllocator* pAllocator, FrameworkEnvironment* frameworkEnvironment);

        static Application* GetInstance();

        void AddListener(ApplicationListener* listener);
        void RemoveListener(ApplicationListener* listener);
        inline void AddKeyEventHandler(KeyEventHandler* handler, uint32_t unkParam2) {
            this->frameworkEnvironment->eventStack->AddKeyEventHandler(handler, 0, unkParam2);
        }
        inline void RemoveKeyEventHandler(KeyEventHandler* handler) {
            this->frameworkEnvironment->eventStack->RemoveKeyEventHandler(handler);
        }
        void AddMouseEventHandler(MouseEventHandler* handler, uint32_t unkParam1);
        void RemoveMouseEventHandler(MouseEventHandler* handler);

        virtual void Startup() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void Reset() {} // Actually startup or something
        virtual void Shutdown() {}
        virtual uint64_t UnkFunc9();
    };
}
