#include <iostream>

class Entity
{
private:
	std::string Name;
public:
	Entity()
		:Name("Unknown"){}
	Entity(const std::string name)
		:Name(name) {}
	std::string Get_Name() { return Name; }
};

int main()
{
	Entity e0;	//在栈中创建对象
	Entity* e1 = new Entity;	//在堆中创建对象
	delete e1;	//堆中的对象需手动释放
}