#include <iostream>
#include <string>

class Entity
{
	//���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
	friend void Function(Entity* e);

public:

	Entity()
	{
		this->m_X = 1;
		this->m_Y = 1;
	}


public:
	int m_X; //����

private:
	int m_Y; //����
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