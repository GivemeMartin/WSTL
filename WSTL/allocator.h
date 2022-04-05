#ifndef WSTL_ALLOCATOR_H_
#define WSTL_ALLOCATOR_H_

//----------include----------



//----------include----------


template<class T>
class allocator
{
public:
	typedef T			value_type;
	typedef T*			pointer;
	typedef const T*	const_pointer;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

	static T* allocate();
	static T* allocate(size_type n);

	static void deallocate(T* ptr);
	static void deallocate(T* ptr, size_type n);

	static void construct(T* ptr);
	static void construct(T* ptr, const T& value);
	static void construct(T* ptr, T&& value);

	template <class... Args>
	static void construct(T* ptr, Args&& ...args);

	static void destroy(T* ptr);
	static void destroy(T* first, T* last);

};

template <class T>
T* allocator<T>::allocate()
{
	//调用全局操作符::operator new(size_t);
	return static_cast<T*>(::operator new(sizeof(T)));
}

//运用size_type类型，声明长度为n的vector或者string
template <class T>
T* allocator<T>::allocate(size_type n)
{
	if (n == 0)
		return nullptr;
	return static_cast<T*>(::operator new(n * sizeof(T)));
}

template <class T>
void allocator<T>::deallocate(T* ptr)
{
	if (ptr == nullptr)
		return;
	::operator delete(ptr);
}

//template <class T>
//void allocator<T>::deallocate(T* ptr, size_type)
//{
//	if (ptr == nullptr)
//		return;
//	::operator delete(ptr);
//}

template <class T>
void allocator<T>::construct(T* ptr)
{

}


