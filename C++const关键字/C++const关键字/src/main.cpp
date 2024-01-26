#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
public:
	int GetX()const	//表明该方法不会修改任何实际的类，只可在类中使用
	{
		//m_X = 3;	//const修饰后不可改变，mutable修饰的变量除外
		return m_X;
	}
};

int main()
{
	const int a = 2;
	//a = 10;	//const修饰变量后变量不可改变
	int b = 3;
	int c = 6;

	const int* p = &b;	//常量指针
	//const int* p == int const* p
	//*p = 8;	//指针指向的内容不可改变

	int* const p1 = &b;	//指针常量
	//p1 = &c;	//指针的指向不可改变
}