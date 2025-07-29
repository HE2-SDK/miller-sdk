#pragma once

namespace hh::dv {
    class DvSceneObjectBase : public fnd::ReferencedObject {
    public:
        fnd::Handle<DvStandardCharacter> dvStandardChar;
        void* pose;
        int visualModelNameHash;
        int unk2;
        int64_t qword30;
        int64_t qword38;
        int64_t qword40;
        int64_t qword48;
        int64_t qword50;
        int64_t qword60;
        csl::ut::MoveArray<void*> qword68;
        csl::ut::MoveArray<void*> qword88;

        DvSceneObjectBase(csl::fnd::IAllocator* allocator, hh::dv::DvStandardCharacter* character);
    };
}
