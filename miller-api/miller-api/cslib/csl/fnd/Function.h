#pragma once

namespace csl::fnd {
    template<typename Signature>
    class Function;
    
    template<typename R, typename... Args>
    class Function<R (Args...)> {
    public:
        class alignas(16) HolderBase {
        public:
            virtual ~HolderBase() = default;
            virtual R operator()(Args... args) const = 0;
            virtual size_t GetSize() const = 0;
            virtual size_t GetAlignment() const = 0;
            virtual HolderBase Clone() const = 0;
            virtual HolderBase Move() = 0;
        };

        template<typename F>
        class Holder : public HolderBase {
            F fn;
        public:
            virtual ~Holder() override;
            virtual R operator()(Args... args) const override { fn(args...); }
            virtual size_t GetSize() const override { return sizeof(Holder<F>); }
            virtual size_t GetAlignment() const override { return alignof(Holder<F>); }
            virtual Holder<F> Clone() const override { return *this; }
            virtual Holder<F> Move() override { return std::move(*this); }
        };

        struct alignas(16) FakeHolder {
            char reserved[sizeof(HolderBase) + 32];
        };

        csl::fnd::IAllocator* allocator{};
        HolderBase* holder{};
        FakeHolder reserved;

        ~Function() {
            Clear();
        }

        Function<R (Args...)>& operator=(const Function<R (Args...)>& other) {
            if (this == &other)
                return;

            Clear();

            if (other.holder == nullptr)
                holder = nullptr;
            else {
                size_t size = other.holder->GetSize();
                size_t alignment = other.holder->GetAlignment();

                holder = size > sizeof(FakeHolder) || alignment > alignof(FakeHolder) ? allocator->Alloc(size, alignment) : (HolderBase*)&reserved;
                
                *holder = other.holder->Clone();
            }
        }

        Function<R (Args...)>& operator=(Function<R (Args...)>&& other) {
            if (this == &other)
                return;

            Clear();

            if (other.holder == nullptr)
                holder = nullptr;
            else {
                size_t size = other.holder->GetSize();
                size_t alignment = other.holder->GetAlignment();

                holder = size > sizeof(FakeHolder) || alignment > alignof(FakeHolder) ? allocator->Alloc(size, alignment) : (HolderBase*)&reserved;
                
                *holder = other.holder->Move();
            }
        }

    private:
        void Clear() {
            if (holder == nullptr)
                return;

            holder->~HolderBase();

            if (holder != (HolderBase*)&reserved)
                allocator->Free(holder);
            
            holder = nullptr;
        }
    };
}
