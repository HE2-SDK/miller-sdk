#pragma once

namespace hh::needle {
	struct SRefCountAddReleaseNeedleObject {
        static void AddRef(NeedleRefcountObject* o) {
            o->AddRef();
        }
        static void Release(NeedleRefcountObject* o) {
            o->Release();
        }
    };

    template<typename T, typename Impl = SRefCountAddReleaseNeedleObject, bool TUnk = true>
    class intrusive_ptr {
        T* ptr{ nullptr };
    
    public:
		intrusive_ptr() {

		}

		intrusive_ptr(intrusive_ptr<T, Impl, TUnk>& other) {
			*this = other;
		}

		intrusive_ptr(intrusive_ptr<T, Impl, TUnk>&& other) {
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		intrusive_ptr(T* rawPtr) {
			if (rawPtr != nullptr)
				Impl::AddRef(rawPtr);

			ptr = rawPtr;
		}

		~intrusive_ptr() {
			if (ptr != nullptr)
				Impl::Release(ptr);

			ptr = nullptr;
		}

		inline intrusive_ptr<T, Impl, TUnk>& operator=(T* const other) {
			T* old = ptr;

			if (other != nullptr)
				Impl::AddRef(other);

			ptr = other;

			if (old != nullptr)
				Impl::Release(old);

			return *this;
		}

		inline intrusive_ptr<T, Impl, TUnk>& operator=(const intrusive_ptr<T, Impl, TUnk>& other) {
			*this = other.ptr;
			return *this;
		}

		inline intrusive_ptr<T, Impl, TUnk>& operator=(intrusive_ptr<T, Impl, TUnk>&& other) {
			T* old = ptr;

			ptr = other.ptr;
			other.ptr = nullptr;

			if (old != nullptr)
				Impl::Release(old);

			return *this;
		}

		inline T& operator*() const {
			return *ptr;
		}

		inline T* operator->() const {
			return ptr;
		}

		inline operator T&() const {
			return *ptr;
		}

		inline operator T*() const {
			return ptr;
		}

		inline bool operator==(const intrusive_ptr<T, Impl, TUnk>& other) const {
			return ptr == other.ptr;
		}

		inline bool operator==(T* const other) const {
			return ptr == other;
		}
    };
}