#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
public:
	int GetX()const	//�����÷��������޸��κ�ʵ�ʵ��ֻ࣬��������ʹ��
	{
		//m_X = 3;	//const���κ󲻿ɸı䣬mutable���εı�������
		return m_X;
	}
};

int main()
{
	const int a = 2;
	//a = 10;	//const���α�����������ɸı�
	int b = 3;
	int c = 6;

	const int* p = &b;	//����ָ��
	//const int* p == int const* p
	//*p = 8;	//ָ��ָ������ݲ��ɸı�

	int* const p1 = &b;	//ָ�볣��
	//p1 = &c;	//ָ���ָ�򲻿ɸı�
}