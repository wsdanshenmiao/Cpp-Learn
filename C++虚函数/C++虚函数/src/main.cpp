#include <iostream>

class Entity
{
public:
	virtual std::string GetName() { return "Entity"; }	//�麯��
	virtual ~Entity() = 0;	//����һ�����麯��
};

Entity::~Entity(){}	//���麯���������ʵ�ֺ���

class Player :public Entity
{
private:
	std::string* m_name;
public:
	Player(const std::string& name)
	{
		m_name = new std::string(name);	//�ڶ��������ڴ�
	}
	~Player()
	{
		if (m_name) {	//��m_name��Ϊ�գ��ͷ��ڴ�
			delete m_name;
			m_name = NULL;
		}
	}
	std::string GetName() override { return *m_name; }	//��д����
};

int main()
{
	Entity* p = new Player("wsdsm");
	std::cout << p->GetName() << std::endl;
}

//#include <iostream>
//
//class Printable	//�ӿ�
//{
//public:
//	virtual std::string GetClassName() = 0;	//���촿�麯��
//};
//
//class Entity : public Printable
//{
//public:
//	virtual std::string GetName() { return "Entity"; }
//	std::string GetClassName() override { return "Entity"; }
//};
//
//class Player :public Entity
//{
//private:
//	std::string m_name;
//public:
//	Player(const std::string& name)
//		:m_name(name) {}
//	std::string GetName() override { return m_name; }
//	std::string GetClassName() override { return "Player"; }
//};
//
//void PrintName(Entity* entity)
//{
//	std::cout << entity->GetClassName() << std::endl;
//}
//
//int main()
//{
//	Entity* e = new Entity();
//	Player* p = new Player("wsdsm");
//	PrintName(e);
//	PrintName(p);
//	delete e;
//	delete p;
//}