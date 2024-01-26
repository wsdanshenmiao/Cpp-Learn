#include <iostream>

class Entity
{
private:
	std::string Name;
public:
	Entity()
		:Name("Unknown") {}
	Entity(const std::string name)
		:Name(name) {}
	std::string Get_Name() { return Name; }
};

int main()
{
	int a = 2;
	int* b = new int[10];
	//���ߵ��������new�ؼ��ֻ�����ù��캯��
	Entity* e1 = new Entity();
	Entity* e2 = (Entity*)malloc(sizeof(Entity));
	delete[] b;
	delete e1;
	delete e2;
}