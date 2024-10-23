#pragma once

namespace hh::fnd {
    class ManagedResource;
    class ReloaderListener {
    public:
        virtual ~ReloaderListener() = default;
        virtual void PreResourceReloadCallback(ManagedResource* resource) {}
        virtual void PostResourceReloadCallback(ManagedResource* resource) {}
    };
}
