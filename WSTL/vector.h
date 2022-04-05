#ifndef WSTL_VECTOR_H
#define WSTL_VECTOR_H


#include <initializer_list>

namespace WSTL
{
#ifdef max
#pragma message("#undefing marco max")
#undef max
#endif // max

#ifdef  min
#pragma message("#undefing marco min")
#undef min
#endif //  min

template <class T>
class vector
{
	//静态断言。第一个参数接受一个bool值，为真就跳过，为假就产生一个编译错误，错误位置为当前行，错误信息为第二个string参数
	static_assert(!std::is_same<bool,T>::value,"vector<bool> is abandoned in WSTL");
public:

};


}
#endif