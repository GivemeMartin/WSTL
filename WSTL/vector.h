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
	//��̬���ԡ���һ����������һ��boolֵ��Ϊ���������Ϊ�پͲ���һ��������󣬴���λ��Ϊ��ǰ�У�������ϢΪ�ڶ���string����
	static_assert(!std::is_same<bool,T>::value,"vector<bool> is abandoned in WSTL");
public:

};


}
#endif