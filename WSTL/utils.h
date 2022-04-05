#ifndef WSTL_UTILS_H_
#define WSTL_UTILS_H_

//----------include----------
#include <cstddef>
#include "type_traits.h"

//---------------------------

namespace WSTL
{
//move


//forward
template <class T>
T&& forward(typename std::remove_reference<T>::type& arg) noexcept
{
	return static_cast<T&&>(arg);
}

template <class T>
T&& forward(typename std::remove_reference<T>::type&& arg) noexcept
{
	static_assert(!std::is_lvalue_reference<T>::value, "bad forward");
	return static_cast<T&&>(arg);
}

template <class Ty1, class Ty2>
struct pair
{
	typedef Ty1		first_type;
	typedef Ty2		second_type;

	first_type	first;
	second_type second;

	template<class Other1 = Ty1, class Other2 = Ty2,
		typename = typename std::enable_if<
		std::is_default_constructible<Other1>::value &&
		std::is_default_constructible<Other2>::value, void>::type>
		constexpr pair() : first(), second()
	{}

	template<class U1 = Ty1, class U2 = Ty2,
		typename std::enable_if<
		std::is_copy_constructible<U1>::value &&
		std::is_copy_constructible<U2>::value &&
		std::is_convertible<const U1&, Ty1>::value &&
		std::is_convertible<const U2&, Ty2>::value, int>::type = 0>
		constexpr pair(const Ty1& a, const Ty2& b) : first(a), second(b)
	{}




};


}


#endif // !WSTL_UTIL_H_
