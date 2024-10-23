#pragma once

namespace SurfRide {
    class ReferencedObject : public Base {
		uint16_t RefCount{};
    public:
        inline void AddRef() {
            RefCount++;
        }
        void Free();
    };

	template<typename T>
	class RefPtr {
		T* ptr{ nullptr };
	public:
		RefPtr() {
		}

		RefPtr(RefPtr& other) {
			*this = other;
		}

		RefPtr(RefPtr&& other) {
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		RefPtr(T* rawPtr) {
			if (rawPtr != nullptr)
				rawPtr->AddRef();

			ptr = rawPtr;
		}

		~RefPtr() {
			if (ptr != nullptr)
				ptr->Free();

			ptr = nullptr;
		}

		inline RefPtr<T>& operator=(T* const other) {
			T* old = ptr;

			if (other != nullptr)
				other->AddRef();

			ptr = other;

			if (old != nullptr)
				old->Free();

			return *this;
		}

		inline RefPtr<T>& operator=(const RefPtr<T>& other) {
			*this = other.ptr;
			return *this;
		}

		inline RefPtr<T>& operator=(RefPtr<T>&& other) {
			T* old = ptr;

			ptr = other.ptr;
			other.ptr = nullptr;

			if (old != nullptr)
				old->Free();

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

		inline bool operator==(const RefPtr<T>& other) const {
			return ptr == other.ptr;
		}

		inline bool operator==(T* const other) const {
			return ptr == other;
		}
	};
}
