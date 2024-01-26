#include <iostream>

class Entity
{
public:
	float x, y;
	Entity(float a, float b)	//¹¹Ôìº¯Êı
	{
		x = a;
		y = b;
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
	Entity e(5.0f, 9.0f);
	e.Print();
}