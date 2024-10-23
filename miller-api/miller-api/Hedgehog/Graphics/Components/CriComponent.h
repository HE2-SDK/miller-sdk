#pragma once

namespace hh::gfx {
    class CriComponent : public RenderingComponent {
        hh::cri::CriSystem* criSystem;

    public:
        CriComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() override {}
        virtual void UnkFunc2() override {}
        virtual void UnkFunc3() override {}
        virtual int UnkFunc4() override;
        virtual const char* GetName() override;
    };
}
