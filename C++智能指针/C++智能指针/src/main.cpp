#include <iostream>

class Entity
{
public:
	Entity()
	{
		std::cout << "creat" << std::endl;
	}
	~Entity()
	{
		std::cout << "destory" << std::endl;
	}
};

int main()
{
	{
		std::shared_ptr<Entity> e0;
		{
			std::unique_ptr<Entity> e1 = std::make_unique<Entity>();
			std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
			e0 = e2;
		}
	}
}