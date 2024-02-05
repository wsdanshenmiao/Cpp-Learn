

//#include <iostream>
//
//class MyInteger
//{
//private:
//	int m_Num1, m_Num2;
//public:
//	MyInteger()
//		:m_Num1(0),m_Num2(0){}
//	//前置++
//	MyInteger& operator++()	//必须要返回引用
//	{
//		m_Num1++;
//		m_Num2++;
//		return *this;
//	}
//	//后置++,使用占位参数加以区别
//	MyInteger operator++(int)	//不能返回引用，因为返回的是局部变量
//	{
//		MyInteger ret = *this;
//		m_Num1++;
//		m_Num2++;
//		return ret;
//	}
//	//前置--
//	MyInteger& operator--()
//	{
//		m_Num1--;
//		m_Num2--;
//		return *this;
//	}
//	MyInteger operator--(int)
//	{
//		MyInteger ret = *this;
//		m_Num1--;
//		m_Num2--;
//		return ret;
//	}
//	friend std::ostream& operator<<(std::ostream& stream, const MyInteger& mint);
//};
//
////输入操作符重载
//std::ostream& operator<<(std::ostream& stream, const MyInteger& mint)
//{
//	stream << mint.m_Num1 << " " << mint.m_Num2;
//	return stream;
//}
//
//int main()
//{
//	MyInteger mint;
//	std::cout << mint++ << std::endl;
//	std::cout << ++mint << std::endl;
//	std::cout << --mint << std::endl;
//	std::cout << mint-- << std::endl;
//	std::cout << mint << std::endl;
//}

//#include <iostream>
//
////输出运算符
//class Entity
//{
//private:
//	int m_X, m_Y;
//public:
//	Entity(int x,int y)
//		:m_X(x),m_Y(y){}
//	friend std::ostream& operator<<(std::ostream& stream, Entity& e);
//};
//
//std::ostream& operator<<(std::ostream& stream, Entity& e)
//{
//	stream << e.m_X << " " << e.m_Y;
//	return stream;
//}
//
//int main()
//{
//	Entity e(10, 10);
//	std::cout << e << std::endl;
//}

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