#include <iostream>

class Entity
{
public:
	float x, y;
	~Entity()	//��������
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