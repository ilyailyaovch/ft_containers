#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

/**
 * https://en.cppreference.com/w/cpp/header/type_traits
 * https://en.cppreference.com/w/cpp/types/enable_if
 * https://en.cppreference.com/w/cpp/types/integral_constant
 * https://en.cppreference.com/w/cpp/types/is_integral
 */

namespace	ft
{
	/**		Integral_constant
	 * std::integral_constant wraps a static constant of specified type.
	 * It is the base class for the C++ type traits.
	 * The behavior of a program that adds specializations for 
	 * integral_constant is undefined.
	 */

	template <typename T, T v>
	struct	integral_constant
	{
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T					value = v;
		operator T() {return v;}
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	/**		Is_integral 
	 * Checks whether T is an integral type.
	 * Provides the member constant value which is equal to true,
	 * if T is the type bool, char, char8_t (since C++20), char16_t,
	 * char32_t, wchar_t, short, int, long, long long,
	 * or any implementation-defined extended integer types,
	 * including any signed, unsigned, and cv-qualified variants.
	 * Otherwise, value is equal to false.
	*/

	template <typename T> struct	is_integral : ft::integral_constant<bool, false> {};
	
	template <> struct	is_integral<bool> : ft::integral_constant<bool, true> {};
	template <> struct	is_integral<char> : ft::integral_constant<char, true> {};
	template <> struct	is_integral<signed char> : ft::integral_constant<signed char, true> {};
	template <> struct	is_integral<unsigned char> : ft::integral_constant<unsigned char, true> {};
	template <> struct	is_integral<short> : ft::integral_constant<short, true> {};
	template <> struct	is_integral<unsigned short> : ft::integral_constant<unsigned short, true> {};
	template <> struct	is_integral<int> : ft::integral_constant<int, true> {};
	template <> struct	is_integral<unsigned int> : ft::integral_constant<unsigned int, true> {};
	template <> struct	is_integral<long> : ft::integral_constant<long, true> {};
	template <> struct	is_integral<unsigned long> : ft::integral_constant<unsigned long, true> {};
	template <> struct	is_integral<long long> : ft::integral_constant<long long, true> {};
	template <> struct	is_integral<unsigned long long> : ft::integral_constant<unsigned long long, true> {};
	template <> struct	is_integral<wchar_t> : ft::integral_constant<wchar_t, true> {};
	template <> struct	is_integral<char16_t> : ft::integral_constant<char16_t, true> {};

	/**		Enable_if 
	 * If B is true, std::enable_if has a public member typedef type, equal to T;
	 * Otherwise, there is no member typedef.
	*/

	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };

}	//end of "namespace	ft"

#endif