#pragma once

namespace hh::needle {
    class RenderingContextManager : public NeedleRefcountObject {
    public:
        csl::fnd::IAllocator* allocator;
        RenderingDevice* renderingDevice;
        volatile int nextDrawContextIndex;
        SyncDrawContext* nextDrawContext;
        csl::ut::MoveArray<intrusive_ptr<SyncDrawContext>> drawContextQueue;
        csl::ut::MoveArray<intrusive_ptr<SyncDrawContext>> renderingDrawContexts;
        char unk4;
        bool unk5;

        RenderingContextManager(RenderingDevice* renderingDevice, csl::fnd::IAllocator* allocator, unsigned int drawContextCount);
        void EnterNextDrawContext();
        void ResetDrawContexts();
        SyncDrawContext* GetNextDrawContext();
        void AddDrawContext(SyncDrawContext* drawContext);
    };
}
