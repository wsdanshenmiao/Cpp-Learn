
//vector����Ƕ��vector����,ʵ�ֶ�ά����
 #include <vector>
#include <iostream>

int main()
{
	std::vector<std::vector<int>> arr;
	for (int i = 0; i < 4; i++) {
		arr.push_back(std::vector<int>{i, i + 1, i + 2});
	}
	for (std::vector<std::vector<int>>::iterator arrit = arr.begin(); arrit != arr.end(); arrit++) {
		for (std::vector<int>::iterator it = arrit->begin(); it != arrit->end(); it++) {
			std::cout << *it;
		}
		std::cout << std::endl;
	}
}

////vector����Զ�����������
//#include <vector>
//#include <iostream>
//
//class Entity
//{
//private:
//	float m_X, m_Y;
//
//public:
//	Entity(){}
//	Entity(float x, float y)
//		:m_X(x), m_Y(y){}
//	float GetX()
//	{
//		return m_X;
//	}
//	float GetY()
//	{
//		return m_Y;
//	}
//};
//
//int main()
//{
//	std::vector<Entity> e;
//	e.push_back(Entity(1.0f, 1.0f));
//	e.push_back(Entity(2.0f, 2.0f));
//	e.push_back(Entity(3.0f, 3.0f));
//	e.push_back(Entity(4.0f, 4.0f));
//	for(std::vector<Entity>::iterator it = e.begin(); it != e.end(); it++) {
//		std::cout << it->GetX() << it->GetY() << std::endl;
//	}
//}

////vector���������������
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//void Print(int a)
//{
//	std::cout << a << std::endl;
//}
//
//int main()
//{
//	int a = 10;
//	//����һ��vector����
//	std::vector<int> v;
//
//	//�������в�������
//	v.push_back(a);
//	v.push_back(20);
//	v.push_back(30);
//	
//	//ͨ�����������������е�����
//	std::vector<int>::iterator itBegin = v.begin();	//��ʼ������	ָ�������еĵ�һ��Ԫ��
//	std::vector<int>::iterator itEnd = v.end();	//����������	ָ�����������һ��Ԫ�ص���һ��λ��
//
//	//��������
//	//��һ�ֱ�����ʽ
//	while(itBegin != itEnd) {
//		std::cout << *itBegin << std::endl;
//		itBegin++;
//	}
//	//�ڶ��� 
//	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		std::cout << *it << std::endl;
//	}
//	//�����֣�ʹ��STL�ṩ�ı����㷨
//	std::for_each(v.begin(), v.end(), Print);
//}