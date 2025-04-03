#pragma once

namespace hh::dv{
    class DvSceneTimeline : public fnd::ReferencedObject {
    public:
        struct DisableFrame {
        public:
            float start;
            float end;
        };

        int preCurrentFrame;
        int postCurrentFrame;
        int frameStart;
        int frameEnd;
        int currentFrame2;
        int unk1;
        int currentCut;
        int currentPage;
        bool looping;
        csl::ut::MoveArray<float> cuts;
        csl::ut::MoveArray<DisableFrame> disableFrames;
        csl::ut::MoveArray<DvPage*> pages;
        int cameraFrameProgressionCount;
        float* cameraFrameProgression;
        float* cameraFrameProgressionSpeed;
        int ticksEnabled;

        DvSceneTimeline(csl::fnd::IAllocator* allocator);
    };
}
