#pragma once

namespace hh::game {
    class GameJobQueue : public fnd::BaseObject {
    public:
        struct JobDesc {

        };

        struct JobInitializer {
        };

        struct Unk2 {
            uint64_t unk1;
            uint64_t unk2;
        };
        struct JobDispatcher {
            uint32_t unkPad1;
            uint32_t unk9;
            Unk2 unk10[2];
        };

        rsdx::CSimpleJobDispatcher<JobDesc, JobDispatcher, JobInitializer> dispatcher;
        JobDispatcher myDispatcher;

        DEFAULT_CREATE_FUNC(GameJobQueue);
    };
}
