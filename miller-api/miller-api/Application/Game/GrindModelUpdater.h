#pragma once

namespace app::game {
    class GrindModelUpdater : public hh::fnd::BaseObject {
    public:
        enum class Flag : unsigned char {
            UNK0,
            UPDATE,
            UNK2,
            UNK3,
        };

        void* grindService;
        uint64_t qword8;
        hh::gfx::GOCVisualModel* model10;
        hh::gfx::GOCVisualModel* model18;
        hh::gfx::GOCVisualModel* model20;
        uint64_t qword28;
        csl::math::Matrix34 csl__math__matrix3440;
        csl::math::Vector4 oword80;
        csl::math::Vector4 oword90;
        int dwordA0;
        int dwordA4;
        float dwordA8;
        csl::ut::Bitset<Flag> flags;

        CREATE_FUNC(GrindModelUpdater, bool unkParam);
    };
}
