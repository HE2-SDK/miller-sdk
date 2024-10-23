#pragma once

namespace SurfRide {
    struct SrTexCoord {
        float u;
        float v;

        SrTexCoord();
    };

    enum class EPivotType {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        CENTER_LEFT,
        CENTER_CENTER,
        CENTER_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT,
        CUSTOM,
    };

    enum class EOrientation {
        UP,
        LEFT,
        DOWN,
        RIGHT,
    };

#ifndef EXPORTING_TYPES
	template<typename T>
	class CountedCollection {
		T* arr;
		size_t size;

	public:
		class iterator {
			CountedCollection collection;
			size_t index;

		public:
			iterator(CountedCollection collection, size_t index) : collection{ collection }, index{ index } {}

			iterator operator++() {
				index++;
				return *this;
			}

			bool operator==(const iterator& other) {
				return collection.arr == other.collection.arr && index == other.index;
			}

			bool operator!=(const iterator& other) {
				return collection.arr != other.collection.arr || index != other.index;
			}

			T operator*() {
				return collection.arr[index];
			}
		};

		CountedCollection(T* arr, size_t size) : arr{ arr }, size{ size } {}

		iterator begin() {
			return { *this, 0 };
		}

		iterator end() {
			return { *this, size };
		}

		bool empty() const {
			return size == 0;
		}
	};
	
	template<typename T, T* (*next)(T*)>
	class NullTerminatedCollection {
		T* first;

	public:
		class iterator {
		    T* current;

		public:
			iterator(T* current) : current{ current } {}

			iterator operator++() {
				current = next(current);
				return *this;
			}

			bool operator==(const iterator& other) {
				return current == other.current;
			}

			bool operator!=(const iterator& other) {
				return current != other.current;
			}

			T* operator*() {
				return current;
			}
		};

		NullTerminatedCollection(T* first) : first{ first } {}

		iterator begin() {
			return { first };
		}

		iterator end() {
			return { nullptr };
		}

		bool empty() const {
			return first == nullptr;
		}
	};
#endif
}
