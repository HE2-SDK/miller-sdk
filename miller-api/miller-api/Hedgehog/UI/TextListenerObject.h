#pragma once

namespace hh::ui {
    class TextListenerObject : public fnd::ReferencedObject, public font::TextListener {
    public:
        TextListenerObject(csl::fnd::IAllocator* pAllocator);

        virtual void* UnkFunc1();
    };
}
