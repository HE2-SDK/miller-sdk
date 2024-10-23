#pragma once

namespace hh::gfx {
    class ResModelNeedle : public ResModelBase, public ResModelParameterInterface<ResModelNeedle> {
    public:
        uint64_t unk201;
        uint64_t unk202;
        csl::ut::MoveArray<void*> unk203;
        csl::ut::MoveArray<void*> unk204;

        ResModelNeedle();

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual void* GetParameterInterface() override;
    };
}
