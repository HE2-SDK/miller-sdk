#pragma once

namespace hh::rsdx {
    template<typename JobDesc, typename JobDispatcher, typename JobInitializer>
    class CSimpleJobDispatcher {
    public:
        rsdx::SJobJoint* unk1;
        rsdx::SJobJoint* unk2;
        JobDesc* desc;
        JobDispatcher* dispatcher;
        uint32_t m_currDispatchCount;
        uint32_t unk4;
        uint32_t unk4b;
        uint32_t unk4c;
        uint32_t unk4d;
        rsdx::SJobJoint* unk5;
        rsdx::SJobJoint* unk6;
        JobInitializer* initializer;
        const char** name;
    };
}