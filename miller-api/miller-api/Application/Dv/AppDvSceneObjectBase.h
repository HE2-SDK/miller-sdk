#pragma once

namespace app::dv {
    class AppDvSceneObjectBase : public hh::dv::DvSceneObjectBase/*, public hh::eff::EffectManager::Listener*/ {
        int64_t effMgrListnrVftable;
    public:
        int64_t qwordB8;
        int64_t qwordC0;
        int64_t qwordC8;
        int64_t qwordD0;
        int64_t qwordD8;
        int64_t qwordE0;
        csl::ut::MoveArray<void*> qwordE8;
        int64_t qword100;
        int16_t word108;
        int64_t qword110;
        int64_t qword118;
        int64_t qword120;
        int16_t word128;
        int64_t qword130;
        int64_t qword138;

        AppDvSceneObjectBase(csl::fnd::IAllocator* allocator, hh::dv::DvStandardCharacter* character);
    };
}
