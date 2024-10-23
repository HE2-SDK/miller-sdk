#pragma once

namespace hh::needle {
    template<size_t ResourceId, typename T>
    class TNeedleRefcountResource : public T {
        uint64_t tnrcrUnk1;
    public:
        static constexpr size_t resourceId = ResourceId;

        virtual void* QueryResource(size_t id) {
            switch (id) {
                case resourceId: return this;
                default: return nullptr;
            }
        }

        virtual const void* QueryResource(size_t id) const {
            switch (id) {
                case resourceId: return this;
                default: return nullptr;
            }
        }
    };
}
