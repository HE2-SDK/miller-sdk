#pragma once

namespace csl::ut
{
#ifdef EXPORTING_TYPES
	template <typename T, typename U = T>
#else
	template <typename T, bool isenum> class bitset_type {};
	template <typename T> class bitset_type<T, true> { public: typedef std::underlying_type_t<T> type;  };
	template <typename T> class bitset_type<T, false> { public: typedef T type; };

	template <typename T, typename U = typename bitset_type<T, std::is_enum<T>::value>::type>
#endif
	class Bitset
	{
	public:
		typedef U underlying_type;
		U m_dummy;
		
		Bitset()
		{
			reset();
		}

		Bitset(U value) : m_dummy(value){}

#ifndef EXPORTING_TYPES
		// This doesn't actually exist, i just want to make bits easily
		template<typename... TArgs>
		constexpr Bitset(TArgs... bits)
		{
			reset();
			(set(bits), ...);
		}
		
		constexpr void reset()
		{
			m_dummy = U{};
		}

		constexpr void reset(T bit)
		{
			m_dummy = m_dummy & ~(1 << static_cast<U>(bit));
		}

		constexpr void flip(T bit)
		{
			set(bit, !test(bit));
		}
		
		constexpr void set(T bit)
		{
			m_dummy = m_dummy | (1 << static_cast<U>(bit));
		}

		void set(T bit, bool flag)
		{
			if (flag)
				set(bit);
			else
				reset(bit);
		}

		constexpr U value() const
		{
			return m_dummy;
		}
		
		constexpr bool test(T bit) const
		{
			return m_dummy & (1 << static_cast<U>(bit));
		}
		
		operator U() const { return m_dummy; }
#endif
	};
}
