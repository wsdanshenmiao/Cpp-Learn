#include <iostream>

template<typename T, int N>
class Array
{
private:
	T Array[N];

public:
	int GetSize() { return N; }
};

int main()
{
	Array<int, 10> array;
	std::cout << array.GetSize() << std::endl;
}

//template<typename X>	
//void Print(X value)
//{
//	std::cout << value << std::endl;
//}
//
//int main()
//{
//	Print(5);
//	Print("CLANNAD");
//}