#pragma once

namespace hh::gfx {
    class GOCVisualDebugDraw : public GOCVisualTransformed {
    public:
        struct SetupInfo {
            void* unk1;
            uint16_t unk2;
            fnd::Geometry* geometry;
            uint64_t unk3;
            uint64_t unk4;
            csl::ut::Color8 color;
            uint8_t unk6;
        };

    public:
        inline GOCVisualDebugDraw(csl::fnd::IAllocator* allocator) : GOCVisualTransformed{ allocator } {
            gocEventMask.bits = 5;
        }
        void Setup(const SetupInfo& setupInfo);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override {}
        
        GOCOMPONENT_CLASS_DECLARATION(GOCVisualDebugDraw)
    };
}
