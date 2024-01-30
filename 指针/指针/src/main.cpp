#include <iostream>
#include <vector>

void ForEach(std::vector<int>& values, void(*print)(int))
{
	for (int value : values) {
		print(value);
	}
}

int main()
{
	std::vector<int> values = { 0,1,2,3,4,5 };
	auto lambda = [](int value) {std::cout << value << std::endl; };
	ForEach(values, lambda);
}

////º¯ÊýÖ¸Õë
//void Print(int value)
//{
//	std::cout << value << std::endl;
//}
//
//void ForEach(std::vector<int>& values, void(*print)(int))
//{
//	for (int value : values) {
//		print(value);
//	}
//}
//
//int main()
//{
//	std::vector<int> values = { 0,1,2,3,4,5 };
//	ForEach(values, Print);
//}
////void HelloWorld()
////{
////	std::cout << "Hello world" << std::endl;
////}
////
////int main()
////{
////	auto function = HelloWorld;
////	void(*functionname) = HelloWorld;
////}

//int main()
//{
//	char* butter = new char[8];
//	memset(butter, 10, 8);
//
//	delete[] butter;
//}