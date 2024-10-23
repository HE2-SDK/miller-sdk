#pragma once

namespace hh::needle {
    class SyncDrawContext : public NeedleRefcountObject {
    public:
        RenderingDeviceContext* deviceContext;
        rsdx::SJobJoint* finishedRenderingJoint;
        intrusive_ptr<RenderingCommandList> commandList;
        bool isRendering;
        bool shouldDraw; // previous finished, should check why
        SyncDrawContext* next;

        SyncDrawContext();
    };
}
