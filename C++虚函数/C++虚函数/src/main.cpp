#include <iostream>

class Entity
{
public:
	virtual std::string GetName() { return "Entity"; }	//虚函数
	virtual ~Entity() = 0;	//声明一个纯虚函数
};

Entity::~Entity(){}	//纯虚函数必须具体实现函数

class Player :public Entity
{
private:
	std::string* m_name;
public:
	Player(const std::string& name)
	{
		m_name = new std::string(name);	//在堆区创建内存
	}
	~Player()
	{
		if (m_name) {	//若m_name不为空，释放内存
			delete m_name;
			m_name = NULL;
		}
	}
	std::string GetName() override { return *m_name; }	//覆写函数
};

int main()
{
	Entity* p = new Player("wsdsm");
	std::cout << p->GetName() << std::endl;
}

//#include <iostream>
//
//class Printable	//接口
//{
//public:
//	virtual std::string GetClassName() = 0;	//构造纯虚函数
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