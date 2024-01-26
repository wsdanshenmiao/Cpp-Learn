#include <iostream>

//static
struct Entity
{
	static int x, y;
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

int Entity::x;
int Entity::y;

int main()
{
	Entity e0;
	e0.x = 2;
	e0.y = 3;
	Entity e1;
	e1.x = 6;
	e1.y = 7;
	e0.Print();
	e1.Print();
}