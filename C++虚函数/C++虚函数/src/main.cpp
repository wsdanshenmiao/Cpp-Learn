#include <iostream>

class Printable	//�ӿ�
{
public:
	virtual std::string GetClassName() = 0;	//���촿�麯��
};

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }
	std::string GetClassName() override { return "Entity"; }
};

class Player :public Entity
{
private:
	std::string m_name;
public:
	Player(const std::string& name)
		:m_name(name) {}
	std::string GetName() override { return m_name; }
	std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetClassName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	Player* p = new Player("wsdsm");
	PrintName(e);
	PrintName(p);
	delete e;
	delete p;
}