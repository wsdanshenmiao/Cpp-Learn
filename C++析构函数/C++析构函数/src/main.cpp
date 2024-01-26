#include <iostream>

class Entity
{
public:
	float x, y;
	~Entity()	//Îö¹¹º¯Êı
	{
		x = 0;
		y = 0;
		std::cout << "destroy entity" << std::endl;
	}
};

void Function()
{
	Entity e;
}

int main()
{
	Function();
}