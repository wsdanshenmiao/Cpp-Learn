#ifndef __ENTITY__HPP__
#define __ENTITY__HPP__

#include <string>

template<typename T>
class Entity {
public:
	T m_X;
	T m_Y;
	Entity(T x, T y);
	void Function();
};

template<typename T>
Entity<T>::Entity(T x, T y)
	:m_X(x),m_Y(y){}

template<typename T>
void Entity<T>::Function()
{
}



#endif // !__ENTITY__HPP__