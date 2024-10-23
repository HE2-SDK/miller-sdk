#pragma once

namespace hh::ut {
    struct BvWorldHandle {
        unsigned int idx;
        csl::geom::Aabb aabb;
    };

    class BvWorld : public fnd::ReferencedObject {
        csl::ut::MoveArray<BvWorldHandle*> volumes;

    public:
        DEFAULT_CREATE_FUNC(BvWorld);

        void AddObject(BvWorldHandle* handle);
        csl::ut::MoveArray<BvWorldHandle*>& GetObjects() const;
    };
}
