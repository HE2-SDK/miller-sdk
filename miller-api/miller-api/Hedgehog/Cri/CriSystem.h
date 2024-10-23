#pragma once

namespace hh::cri {
    class CriSystem : public fnd::BaseObject {
    public:
        fnd::ThreadSafeTlsfHeapAllocator* hedgehogAllocator;
        static CriSystem* instance;
    };
}
