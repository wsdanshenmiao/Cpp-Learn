#include <iostream>

//输出运算符
class Entity
{
private:
	int m_X, m_Y;
public:
	Entity(int x,int y)
		:m_X(x),m_Y(y){}
	friend std::ostream& operator<<(std::ostream& stream, Entity& e);
};

std::ostream& operator<<(std::ostream& stream, Entity& e)
{
	stream << e.m_X << " " << e.m_Y;
	return stream;
}

int main()
{
	Entity e(10, 10);
	std::cout << e << std::endl;
}

//#include <iostream>
//
//class Entity
//{
//public:
//	int m_X, m_Y;
//
//	Entity(){}
//	Entity(int x, int y)
//		:m_X(x), m_Y(y){}
//	//成员函数重载
//	//Entity operator+ (Entity& e)
//	//{
//	//	Entity temp;
//	//	temp.m_X = m_X + e.m_X;
//	//	temp.m_Y = m_Y + e.m_Y;
//	//	return temp;
//	//}
//};
//
////全局函数重载
////Entity operator+ (Entity& e1,Entity& e2)
////{
////	Entity temp;
////	temp.m_X = e1.m_X + e2.m_X;
////	temp.m_Y = e1.m_Y + e2.m_Y;
////	return temp;
////}
//
//Entity operator+ (Entity& e, int num)
//{
//	Entity temp;
//	temp.m_X = e.m_X + num;
//	temp.m_Y = e.m_Y + num;
//	return temp;
//}
//
//int main()
//{
//	Entity e1(10, 10);
//	Entity e2(20, 20);
//	////成员函数重载调用本质
//	//e1 = e1.operator+(e2);
//	////全局函数重载调用本质
//	//e1 = operator+(e1, e2);
//	//e1 = e1 + e2;
//	//运算符重载也可以发生函数重载
//	e1 = e2 + 20;	//Entity + int
//	std::cout << e1.m_X << e1.m_Y << std::endl;
//}