
//vector容器嵌套vector容器,实现二维数组
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

////vector存放自定义数据类型
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

////vector存放内置数据类型
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
//	//创建一个vector容器
//	std::vector<int> v;
//
//	//向容器中插入数据
//	v.push_back(a);
//	v.push_back(20);
//	v.push_back(30);
//	
//	//通过迭代器访问容器中的数据
//	std::vector<int>::iterator itBegin = v.begin();	//起始迭代器	指向容器中的第一个元素
//	std::vector<int>::iterator itEnd = v.end();	//结束迭代器	指向容器中最后一个元素的下一个位置
//
//	//遍历容器
//	//第一种遍历方式
//	while(itBegin != itEnd) {
//		std::cout << *itBegin << std::endl;
//		itBegin++;
//	}
//	//第二种 
//	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		std::cout << *it << std::endl;
//	}
//	//第三种，使用STL提供的遍历算法
//	std::for_each(v.begin(), v.end(), Print);
//}