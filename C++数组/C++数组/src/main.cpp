#include <iostream>
#include <array>

class Entity
{
public:
	std::array<int, 5> another;
	Entity()
	{
		for (int i = 0; i < another.size(); i++) {
			another[i] = 2;
		}
	}
};

int main()
{
	Entity e;
}

//class Entity
//{
//public:
//	static constexpr int size = 5;
//	int arr[size];
//	Entity()
//	{
//		for (int i = 0; i < size; i++) {
//			arr[i] = 2;
//		}
//	}
//};
//
//int main()
//{
//	Entity e;
//}