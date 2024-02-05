#include <iostream>
#include <string>

class Entity
{
	//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
	friend void Function(Entity* e);

public:

	Entity()
	{
		this->m_X = 1;
		this->m_Y = 1;
	}


public:
	int m_X; //客厅

private:
	int m_Y; //卧室
};


void Function(Entity* e)
{
	e->m_X = 2;
	e->m_Y = 2;
}


void test01()
{
	Entity e;
	Function(&e);
}

int main() {

	test01();

	system("pause");
	return 0;
}