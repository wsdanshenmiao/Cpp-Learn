#include <iostream>

class Entity
{
public:
	float x, y;
	Entity(float a, float b)	//构造函数
	{
		x = a;
		y = b;
		std::cout << "构造函数" << std::endl;
	}
	~Entity()
	{
		std::cout << "析构函数" << std::endl;
	}
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};
class Log
{
public:
	Log() = delete;
};
int main()
{
	Entity e = Entity(5.0f, 9.0f);
	//e.Print();
}