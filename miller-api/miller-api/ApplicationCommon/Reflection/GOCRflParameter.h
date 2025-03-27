#pragma once

namespace app_cmn::rfl {
    class GOCRflParameter : public hh::game::GOComponent {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<hh::fnd::ResReflection>> parameters;

        struct SetupInfo {
            unsigned int capacity;
        };

        GOCRflParameter(csl::fnd::IAllocator* allocator);
        void Setup(const SetupInfo& setupInfo);
		virtual void* GetRuntimeTypeInfo() const override;
        void SetParameter(hh::fnd::ResReflection* resource, int idx);
        hh::fnd::ResReflection* GetParameter(int idx, hh::fnd::RflClass* rflClass) const;

        template<typename T>
        inline T* GetParameter(int idx) const {
            return static_cast<T*>(GetParameter(idx, &RESOLVE_STATIC_VARIABLE(T::rflClass)));
        }

        GOCOMPONENT_CLASS_DECLARATION(GOCRflParameter);
    };
}
