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
	Entity e0;	//��ջ�д�������
	Entity* e1 = new Entity;	//�ڶ��д�������
	delete e1;	//���еĶ������ֶ��ͷ�
}