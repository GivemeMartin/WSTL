#ifndef WSTL_TYPE_TRAITS_H_
#define WSTL_TYPE_TRAITS_H_

//本头文件用于提取类型信息

#include <type_traits>

namespace WSTL
{

// helper struct
template <class T, T v>
struct m_intergral_constant
{
	static constexpr T value = v;
};

template<bool b>
using m_bool_constant = m_intergral_constant<bool, b>;
typedef m_bool_constant<true> m_true_type;
typedef m_bool_constant<false> m_false_type;


// --- forward declaration begin
template <class T1, class T2>
struct pair;
// forward declaration end

template <class T>
struct is_pair : WSTL::m_false_type {};;

template <class T1, class T2>
struct is_pair<WSTL::pair<T1, T2>> : WSTL::m_true_type {};

}



#endif // WSTL_TYPE_TRAITS_H_

