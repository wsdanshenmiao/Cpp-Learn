#include <iostream>

class Entity
{
public:
	float x, y;
	Entity(float a, float b)	//���캯��
	{
		x = a;
		y = b;
		std::cout << "���캯��" << std::endl;
	}
	~Entity()
	{
		std::cout << "��������" << std::endl;
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