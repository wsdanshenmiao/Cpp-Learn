#include <iostream>

class Entity
{
public:
	float X, Y;

	void Move(float ax, float ay)
	{
		X += ax;
		Y += ay;
	}
};

class Player :public Entity
{
public:
	const char* name;

	void PrintName()
	{
		std::cout << name << std::endl;
	}
};

int main()
{

}