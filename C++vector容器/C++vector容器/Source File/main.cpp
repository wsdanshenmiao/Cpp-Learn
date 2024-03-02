
#include "Vector.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>

class Entity
{
public:
	int m_X, m_Y;

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
	bool operator!=(const Entity& e) {
		return m_X != e.m_X || m_Y != e.m_Y;
	}
};

std::ostream& operator<<(std::ostream& stream, const Entity& e)
{
	stream << e.m_X << " " << e.m_Y << std::endl;
	return stream;
}

#if 1
int main()
{
	mystl::Vector<int> v1;
	mystl::Vector<int> v2;
	for (int i = 0; i < 5; i++) {
		v1.push_back(1);
	}
	for (int i = 0; i < 5; i++) {
		v2.push_back(1);
	}
	std::cout << (v1 > v2);

	//mystl::Vector<Entity> v1;
	//for (int i = 0; i < 5; i++) {
	//	v1.push_back(Entity(i, i + 1));
	//}
	//v1.pop_back();
	//v1.pop_back();
	//std::cout << v1.size() << v1.capacity() << std::endl;
	//v1.reserve(10);
	//v1[3] = Entity(10, 10);
	//v1.resize(20, Entity(5, 5));
	////try {
	////	v1.at(100);
	////}
	////catch(std::out_of_range& msg){
	////	std::cout << msg.what() << std::endl;
	////}
	//v1.insert(v1.begin(), 2, Entity(6, 6));
	//for (int i = 0; i < 2; i++) {
	//	v1.insert(v1.begin(), Entity(4, 4));
	//}
	//v1.erase(v1.begin(), v1.end() - 3);

	//mystl::Vector<Entity> v1;
	//v1.push_back(Entity(1, 1));
	//for (int i = 0; i < 4; i++) {
	//	v1.insert(v1.begin(), Entity(1, 1));
	//}
	//
	//
	//mystl::Vector<Entity> v2;
	//v2.push_back(Entity(2, 2));
	//for (int i = 0; i < 4; i++) {
	//	v2.insert(v2.begin(), Entity(2, 2));
	//}
	//
	//std::cout << (v1 < v2);
	//
	//for (mystl::Vector<Entity>::iterator it = v1.begin(); it < v1.end(); it++) {
	//	std::cout << *it << std::endl;
	//}
	//for (mystl::Vector<Entity>::iterator it = v2.begin(); it < v2.end(); it++) {
	//	std::cout << *it << std::endl;
	//}
}

#else
int main()
{
	//mystl::Vector<int> v;
	//v.reserve(20);
	//v.push_back(false);
	//for (int i = 0; i < 10; i++) {
	//	v.insert(v.begin(), true);
	//}
	//for (int i = 0; i < 10000; i++) {
	//	v.insert(v.begin(), false);
	//}
	//for (mystl::Vector<int>::iterator it = v.begin(); it < v.end(); it++) {
	//	std::cout << *it << std::endl;
	//}

	std::vector<Entity> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(Entity(1,1));
	}
	std::vector<Entity> v2;
	for (int i = 0; i < 5; i++) {
		v2.push_back(Entity(2, 2));
	}
		
	v1.resize(1000, Entity(0, 0));
	v1.resize(5, Entity(0, 0));
	std::vector<Entity>(v1).swap(v1);
	for (std::vector<Entity>::iterator it = v1.begin(); it < v1.end(); it++) {
		std::cout << *it << std::endl;
	}

	//std::vector<int> v1;
	//for (int i = 0; i < 5; i++) {
	//	v1.push_back(i);
	//}
	//v1.resize(10);
	//std::cout << v1.at(1) << std::endl;
	//std::vector<int>::iterator it1(v1.begin());
	//std::vector<int>::reverse_iterator it2 = v1.rbegin();
	//for (int i = 0; i < 2; i++) {
	//	v1.insert(v1.begin(), 1);
	//}
	//for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
	//	std::cout << *it << std::endl;
	//}
	//v1.erase(v1.begin());
	//for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
	//	std::cout << *it << std::endl;
	//}

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