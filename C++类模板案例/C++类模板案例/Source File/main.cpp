#include "MyArray.hpp"
#include <iostream>

class Entity
{
public:
	int m_X, m_Y;
	Entity(){}
	Entity(int x,int y)
		:m_X(x),m_Y(y){}
};

int main()
{
	int num = 10;
	MyArray<int>arr1(num);
	for (int i = 0; i < num; i++) {
		arr1.PushData(i);
		std::cout << arr1[i] << std::endl;
	}
	MyArray<int>arr2(arr1);
	arr2.PopData();
	for (int i = 0; i < arr2.GetElements(); i++) {
		std::cout << arr2[i] << std::endl;
	}

	std::cout << arr1.GetCapacity() << std::endl;
	std::cout << arr1.GetElements() << std::endl;
	std::cout << arr2.GetCapacity() << std::endl;
	std::cout << arr2.GetElements() << std::endl;
	

	MyArray<Entity>arr3(num);
	Entity e1(1, 2);
	for (int i = 0; i < num; i++) {
		arr3.PushData(Entity(i,i+1));
		std::cout << arr3[i].m_Y << std::endl;
	}
}