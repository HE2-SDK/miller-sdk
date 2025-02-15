#pragma once

namespace hh::dv{
    class DvSceneTimeline : public fnd::ReferencedObject {
    public:
        int currentFrame0;
        int currentFrame1;
        int frameStart;
        int frameEnd;
        int currentCut;
        int currentPage;
        bool looping;
        int unk3;
        csl::ut::MoveArray<float> cuts;
        csl::ut::MoveArray<void*> unkArray0;
        csl::ut::MoveArray<DvPage*> authPages;
        int64_t unk4;
        int64_t unk5;
        int64_t unk6;
        int ticksEnabled;
        int unk8;

        DvSceneTimeline(csl::fnd::IAllocator* allocator);
    };
}
