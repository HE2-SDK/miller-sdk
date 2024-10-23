#pragma once

namespace hh::text {
    class TagReplaceableCollection : public TagReplaceable {
        csl::ut::MoveArray<void*> unk101;
    public:
        TagReplaceableCollection(csl::fnd::IAllocator* pAllocator);
    };
}
