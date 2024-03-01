
#include "Vector.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>

class Entity
{
public:
	int m_X, m_Y;

	Entity()
		:m_X(0),m_Y(0){}
	Entity(int x, int y)
		:m_X(x), m_Y(y) {}

	Entity& operator++()
	{
		m_X++;
		m_Y++;
		return *this;
	}
	Entity& operator++(int)
	{
		Entity e = *this;
		m_X++;
		m_Y++;
		return e;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Entity& e);

};

std::ostream& operator<<(std::ostream& stream, const Entity& e)
{
	stream << e.m_X << " " << e.m_Y << std::endl;
	return stream;
}

#if 1
int main()
{
	mystl::Vector<Entity> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(Entity(i, i + 1));
	}
	v1.pop_back();
	v1.pop_back();
	std::cout << v1.size() << v1.capacity() << std::endl;
	v1.reserve(10);
	v1[3] = Entity(10, 10);
	v1.resize(15);
	v1.resize(20, Entity(5, 5));
	v1.resize(5);
	//try {
	//	v1.at(100);
	//}
	//catch(std::out_of_range& msg){
	//	std::cout << msg.what() << std::endl;
	//}
	v1.insert(v1.begin(), 20, Entity(6, 6));
	for (int i = 0; i < 20; i++) {
		v1.insert(v1.begin(), Entity(4, 4));
	}
	for (mystl::Vector<Entity>::iterator it = v1.begin(); it < v1.end(); it++) {
		std::cout << *it << std::endl;
	}

}

#else
int main()
{
	std::vector<int> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
	}
	v1.resize(10);
	std::cout << v1.at(1) << std::endl;
	std::vector<int>::iterator it1(v1.begin());
	std::vector<int>::reverse_iterator it2 = v1.rbegin();
	for (int i = 0; i < 20; i++) {
		v1.insert(v1.begin(), 1);
	}
	for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
		std::cout << *it << std::endl;
	}
	//std::cout << typeid(v1.end() - v1.begin()).name();
}
#endif

//#include <vector>
//#include <iostream>
//
//int main()
//{
//	std::vector<int> v1; //无参构造
//	v1.push_back(1);
//	std::vector<int>v2 = v1;
//	v2.assign(v1.begin(), v1.end());
//	v2.assign(10, 2);
//	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
//		std::cout << *it << std::endl;
//	}
//
//}

////vector容器嵌套vector容器,实现二维数组
// #include <vector>
//#include <iostream>
//
//int main()
//{
//	std::vector<std::vector<int>> arr;
//	for (int i = 0; i < 4; i++) {
//		arr.push_back(std::vector<int>{i, i + 1, i + 2});
//	}
//	for (std::vector<std::vector<int>>::iterator arrit = arr.begin(); arrit != arr.end(); arrit++) {
//		for (std::vector<int>::iterator it = arrit->begin(); it != arrit->end(); it++) {
//			std::cout << *it;
//		}
//		std::cout << std::endl;
//	}
//}

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