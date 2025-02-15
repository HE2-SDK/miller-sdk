#pragma once

namespace hh::dv {
    class DvResourceBase : public fnd::ReferencedObject {
    public:
        enum class ResourceType : unsigned int {
            CHARACTER = 2,
            CAMERA_MOTION = 4,
            CHARACTER_MOTION = 7,
            MODEL = 10
        };

        char guid[16];
        ResourceType type;
        char unk0[12];
        DvResourceBase* anotherResource;

        virtual bool UnkFunc0();

        DvResourceBase(csl::fnd::IAllocator* allocator);
    };
}
