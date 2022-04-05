#ifndef WSTL_CONSTRUCT_H_
#define WSTL_CONSTRUCT_H_

#include <new>

//#ifdef _MSC_VER
//#pragma warning(push)
//#pragma warning(disable : 4100)
//#endif //_MSC_VER

namespace WSTL
{

template<class Ty>
void construct(Ty* ptr)
{
	::new ((void*)ptr) Ty();
}

template <class Ty1,class Ty2>
void construct(Ty1* ptr, const Ty2& value)
{
	::new ((void*)ptr) Ty1(value);
}

template <class Ty, class... Args>
void construct(Ty* ptr, Args&&... args)
{
	::new ((void*)ptr) Ty(WSTL::forward<Args>(args)...);
}

//destroy 将对象析构
template <class Ty>
void destroy_one(Ty*, std::true_type) {}




}









#endif // !WSTL_CONSTRUCT_H_
