#pragma once

namespace hh::gfx {
    class CaptureComponent : public RenderingComponent {
        class Impl : public fnd::ReferencedObject {
        public:
            class MyCaptureListener : public needle::SupportFX::CaptureIBLListener {
                Impl* captureComponentImplementation;
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
            };

        private:
            csl::ut::InplaceMoveArray<void*, 1> unk1;
            uint64_t unk2;
            uint64_t unk3;
            MyCaptureListener captureListener;
        };

        fnd::Reference<Impl> implementation;

    public:
        CaptureComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override {}
        virtual int UnkFunc4() override;
        virtual const char* GetName() override;
    };
}
