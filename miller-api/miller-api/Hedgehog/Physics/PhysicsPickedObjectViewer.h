#pragma once

namespace hh::physics {
    class PhysicsPickedObjectViewer : public PhysicsViewerBase {
    public:
        PickedObjectInfo pickedObject;
        ShapeHolder shapeHolder;
        fnd::WorldPosition worldPos;

        virtual int OnLifeCycleChange(bool created) override;
        virtual void PVCL_UnkFunc3() override;

        VIEWER_CLASS_DECLARATION(PhysicsPickedObjectViewer)
    };
}
