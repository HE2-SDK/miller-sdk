#pragma once

namespace hh::gfx {
    class LightComponent : public RenderingComponent {
        class Impl : public fnd::ReferencedObject {
        public:
            class MyReloadListener : public fnd::ReloaderListener {
                Impl* lightComponentImplementation;
            };

        private:
            csl::ut::MoveArray<void*> unk1;
            MyReloadListener reloadListener;
        };

        fnd::Reference<Impl> implementation;

    public:
        LightComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override {}
        virtual int UnkFunc4() override;
        virtual const char* GetName() override;
    };
}
