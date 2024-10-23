#pragma once

namespace csl::fnd {
    template<typename Signature>
    class Function;
    
    template<typename R, typename... Args>
    class Function<R (Args...)> {
    public:
        class HolderBase {
        public:
            virtual ~HolderBase();
            virtual R operator()(Args... args) const;
            virtual size_t GetInnerSize() const;
            virtual size_t GetHeaderSize() const;
            virtual HolderBase Clone() const;
            virtual HolderBase Move();
        };

        template<typename F>
        class Holder : public HolderBase {
            F fn;
        public:
            virtual ~HolderBase() override;
            virtual R operator()(Args... args) const override;
            virtual size_t GetInnerSize() const override;
            virtual size_t GetHeaderSize() const override;
            virtual HolderBase Clone() const override;
            virtual HolderBase Move() override;
        };
    };
}
