#include <iostream>

//菱形继承
//两个派生类继承同一个基类
//?又有某个类同时继承者两个派生类
//?这种继承被称为菱形继承，或者钻石继承
class Animal
{
public:
	int m_Age;
};

class Tiger :virtual public Animal {};

class Lion :virtual public Animal{};

class Liger :public Tiger, public Lion{};

int main()
{
	Liger st;
	st.Tiger::m_Age = 100;
	st.Lion::m_Age = 200;

	std::cout << st.Tiger::m_Age << std::endl;
	std::cout << st.Lion::m_Age << std::endl;
	std::cout << st.m_Age << std:: endl;
}

//#include <iostream>
//
//class Entity
//{
//public:
//	float X, Y;
//
//	void Move(float ax, float ay)
//	{
//		X += ax;
//		Y += ay;
//	}
//};
//
//class Player :public Entity
//{
//public:
//	const char* name;
//
//	void PrintName()
//	{
//		std::cout << name << std::endl;
//	}
//};
//
//int main()
//{
//
//}